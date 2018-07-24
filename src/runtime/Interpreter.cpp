// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <jit/jit-dump.h>
#include <iostream>
#include "Interpreter.h"

using namespace manda;

manda::Interpreter::Interpreter(manda::VM *vm, manda::Fiber *fiber) {
    this->vm = vm;
    this->fiber = fiber;
    jit = jit_context_create();
}

TaggedPointer *Interpreter::VisitProgram(ProgramNode *ctx) {
    // Create the entry point.
    jit_context_build_start(jit);
    jit_type_t entryPointReturnType = jit_type_create_signature(jit_abi_cdecl, jit_type_float64, nullptr, 0, 0);
    entryPoint = jit_function_create(jit, entryPointReturnType);
    functionStack.push(entryPoint);

    // TODO: Collect all functions.

    // We only want to compile what's being used, in theory.
    // Only go through expression statements.
    for (auto *statement: ctx->GetStatements()) {
        statement->acceptInterpreter(this);
    }

//    TaggedPointer *result = nullptr;
//
//    for (auto *statement: ctx->GetStatements()) {
//        result = statement->acceptInterpreter(this);
//
//        if (fiber->HasExited()) {
//            break;
//        }
//    }

    // Compile it!
    functionStack.pop();
    jit_dump_function(stdout, entryPoint, "entry point [uncompiled]");
    jit_function_compile(entryPoint);
    jit_context_build_end(jit);

    // Execute it!
    jit_float64 result;
    jit_function_apply(entryPoint, nullptr, &result);
    return new TaggedPointer((double) result);
}

jit_value_t Interpreter::VisitExpression(ExpressionNode *ctx) {
    return ctx->acceptInterpreter(this);
}

jit_value_t Interpreter::VisitNumberLiteral(NumberLiteralNode *ctx) {
    // Create a NanBox object, and just place in the asUlong value.
    TaggedPointer obj;
    auto type = ctx->GetToken()->GetType();
    auto function = GetCurrentFunction();

    if (type == Token::FLOAT) {
        char *pEnd;
        jit_float32 value = strtof(ctx->GetSourceSpan()->GetText().c_str(), &pEnd);
        obj.SetFloatData(value);
        obj.SetType(TaggedPointer::ACTUAL_NUMBER);

    } else {
        //char *pEnd;
        jit_long value = strtol(ctx->GetSourceSpan()->GetText().c_str(), nullptr, 0);
        obj.SetFloatData(value);
    }

    return jit_value_create_float64_constant(function, jit_type_float64, obj.GetRawDouble());
}

jit_function_t Interpreter::GetCurrentFunction() {
    return functionStack.top();
}

void Interpreter::VisitExpressionStatement(ExpressionStatementNode *ctx) {
    auto returnValue = VisitExpression(ctx->GetExpression());
    jit_insn_return(GetCurrentFunction(), returnValue);
}

jit_value_t Interpreter::GetValue(jit_function_t function, jit_value_t nan) {
    // Shift right by three.
    auto three = jit_value_create_nint_constant(function, jit_type_int, 3);
    return jit_insn_shl(function, nan, three);
}

jit_value_t Interpreter::SetValue(jit_function_t function, jit_value_t nan, jit_value_t newValue) {
    //  TaggedPointerType currentType = GetType();
    jit_value_t currentType = GetType(function, nan);

    // asUlong = data << 3;
    auto three = jit_value_create_nint_constant(function, jit_type_int, 3);
    auto shifted = jit_insn_shl(function, newValue, three);

    // SetType(currentType);
    return SetType(function, shifted, currentType);
}

jit_value_t Interpreter::SetType(jit_function_t function, jit_value_t nan, TaggedPointer::TaggedPointerType type) {
    auto numberType = jit_value_create_nint_constant(function, jit_type_ubyte, type);
    return jit_insn_or(function, nan, numberType);
}

jit_value_t Interpreter::SetType(jit_function_t function, jit_value_t nan, jit_value_t type) {
    return jit_insn_or(function, nan, type);
}

jit_value_t Interpreter::Zero(jit_function_t function) {
    return jit_value_create_float64_constant(function, jit_type_float64, 0);
}

jit_value_t Interpreter::GetType(jit_function_t function, jit_value_t nan) {
    // Get the bottom 3 bits
    // auto bottom3 = (uint8_t) (asUlong & 0x7);
    auto seven = jit_value_create_nint_constant(function, jit_type_ubyte, 0x7);
    auto bottom3 = jit_insn_and(function, nan, seven);
    return jit_insn_convert(function, bottom3, jit_type_ubyte, 0);
}

jit_value_t Interpreter::VisitBinaryExpression(BinaryExpressionNode *ctx) {
    // TODO: Handle errors?
    auto rawLeft = VisitExpression(ctx->GetLeft());
    auto rawRight = VisitExpression(ctx->GetLeft());
    auto *function = GetCurrentFunction();
    auto left = GetValue(function, rawLeft);
    auto right = GetValue(function, rawRight);
    auto type = ctx->GetOperator()->GetType();
    jit_value_t returnValue = nullptr;

    // TODO: Custom operators
    if (type == Token::TIMES) {
        returnValue = jit_insn_mul(function, left, right);
    } else if (type == Token::DIV) {
        returnValue = jit_insn_div(function, left, right);
    } else if (type == Token::MODULO) {
        returnValue = jit_insn_rem(function, left, right);
    } else if (type == Token::PLUS) {
        returnValue = jit_insn_add(function, left, right);
    } else if (type == Token::MINUS) {
        returnValue = jit_insn_sub(function, left, right);
    }

    if (returnValue != nullptr) {
        auto leftType = GetType(function, rawLeft);
        auto nan = SetValue(function, Zero(function), returnValue);
        returnValue = SetType(function, nan, leftType);
    }

    return returnValue;
}


jit_value_t Interpreter::VisitSimpleIdentifier(SimpleIdentifierNode *ctx) {
    const auto &name = ctx->GetName();

    // Create a constant of the name.
    auto function = GetCurrentFunction();
    auto *dup = jit_strdup(name.c_str()); // TODO: Delete this string
    jit_type_t type_cstring = jit_type_create_pointer(jit_type_sys_char, 0);
    jit_value_t nameConstant = jit_value_create_long_constant(function, type_cstring, (long) dup);

    // Fetch it from the symbol table.
    jit_type_t symbolTableParams[3];
    symbolTableParams[0] = jit_type_void_ptr;
    symbolTableParams[1] = type_cstring;
    symbolTableParams[2] = jit_type_create_pointer(jit_type_float64, 0);

    jit_value_t symbolTableArgs[3];
    symbolTableArgs[0] = jit_value_create_long_constant(function, jit_type_void_ptr,
                                                        jit_ulong_to_long((jit_ulong) this));
    symbolTableArgs[1] = nameConstant;

    // Create a float64 to hold the result.
    auto valuePtr = jit_value_create(function, jit_type_create_pointer(jit_type_float64, 0));
    symbolTableArgs[2] = valuePtr;

    // TODO: Handle return value
    auto symbolTableSignature = jit_type_create_signature(jit_abi_cdecl, jit_type_ubyte, symbolTableParams, 3, 0);
    auto success = jit_insn_call_native(function, "SymbolTableRetrieve", (void *) &SymbolTableRetrieve,
                                        symbolTableSignature, symbolTableArgs, 3,
                                        JIT_CALL_NOTHROW);

    // TODO: Throw if the identifier is unspecified
    return jit_insn_load(function, valuePtr);
}

void Interpreter::VisitVariableDeclarationStatement(VariableDeclarationStatementNode *ctx) {
    auto name = ctx->GetIdentifier()->GetName();

    // TODO: Prevent redefinition of variables
    auto initializer = VisitExpression(ctx->GetInitializer());

    // Create a constant of the name.
    auto function = GetCurrentFunction();
    auto *dup = jit_strdup(name.c_str());
    jit_type_t type_cstring = jit_type_create_pointer(jit_type_sys_char, 0);
    jit_value_t nameConstant = jit_value_create_long_constant(function, type_cstring, (long) dup);

    // Insert it into the symbol table.
    jit_type_t symbolTableParams[3];
    symbolTableParams[0] = jit_type_void_ptr;
    symbolTableParams[1] = type_cstring;
    symbolTableParams[2] = jit_type_float64;

    jit_value_t symbolTableArgs[3];
    symbolTableArgs[0] = jit_value_create_long_constant(function, jit_type_void_ptr,
                                                        jit_ulong_to_long((jit_ulong) this));
    symbolTableArgs[1] = nameConstant;
    symbolTableArgs[2] = initializer;

    // TODO: Handle return value
    auto symbolTableSignature = jit_type_create_signature(jit_abi_cdecl, jit_type_ubyte, symbolTableParams, 3, 0);
    jit_insn_call_native(function, "SymbolTableStore", (void *) &SymbolTableStore,
                         symbolTableSignature, symbolTableArgs, 3,
                         JIT_CALL_NOTHROW);

    // Delete the allocated string
    // TODO: Do this with GC instead

    // TODO: Remove the return
    jit_insn_return(function, initializer);
}

uint8_t Interpreter::SymbolTableStore(Interpreter *interpreter, const char *name, double value) {
    std::string n(name);
    interpreter->fiber->GetScope()->Add(n, value);
    return 1;
}

uint8_t Interpreter::SymbolTableRetrieve(Interpreter *interpreter, const char *name, double *value) {
    std::string n(name);
    auto *symbol = interpreter->fiber->GetScope()->Resolve(n);

    if (symbol == nullptr) {
        return 0;
    } else {
        *value = symbol->GetValue();
        return 1;
    }
}
