// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "Interpreter.h"

using namespace manda;

manda::Interpreter::Interpreter(manda::VM *vm, manda::Fiber *fiber) {
    this->vm = vm;
    this->fiber = fiber;
    jit = jit_context_create();
}

Object *Interpreter::VisitProgram(ProgramNode *ctx) {
    // Create the entry point.
    jit_context_build_start(jit);
    jit_type_t entryPointReturnType = jit_type_create_signature(jit_abi_cdecl, jit_type_ulong, nullptr, 0, 0);
    entryPoint = jit_function_create(jit, entryPointReturnType);
    functionStack.push(entryPoint);

    // TODO: Collect all functions.

    // We only want to compile what's being used, in theory.
    // Only go through expression statements.
    for (auto *statement: ctx->GetStatements()) {
        statement->acceptInterpreter(this);
    }


//    Object *result = nullptr;
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
    jit_function_compile(entryPoint);
    jit_context_build_end(jit);

    // Execute it
    jit_ulong result;
    jit_function_apply(entryPoint, nullptr, &result);
    return new Object(result);
}

jit_value_t Interpreter::VisitDecimalLiteral(DecimalLiteralNode *ctx) {
    // Get the raw value.
    long value = strtol(ctx->GetSourceSpan()->GetText().c_str(), nullptr, 0);

    // Create a ulong constant.
    auto asUlong = jit_value_create_long_constant(GetCurrentFunction(), jit_type_ulong, value);
    auto zero = Zero(GetCurrentFunction());
    auto withValue = SetValue(GetCurrentFunction(), zero, asUlong);
    return SetType(GetCurrentFunction(), withValue, Object::NUMBER);
}

jit_function_t Interpreter::GetCurrentFunction() {
    return functionStack.top();
}

void Interpreter::VisitExpressionStatement(ExpressionStatementNode *ctx) {
    auto returnValue = ctx->GetExpression()->acceptInterpreter(this);
    jit_insn_return(GetCurrentFunction(), returnValue);
}

jit_value_t Interpreter::GetValue(jit_function_t function, jit_value_t nan) {
    // Shift right by three.
    auto three = jit_value_create_nint_constant(function, jit_type_int, 3);
    return jit_insn_shl(function, nan, three);
}

jit_value_t Interpreter::SetValue(jit_function_t function, jit_value_t nan, jit_value_t newValue) {
    //  ObjectType currentType = GetType();
    jit_value_t currentType = GetType(function, nan);

    // raw = data << 3;
    auto three = jit_value_create_nint_constant(function, jit_type_int, 3);
    auto shifted = jit_insn_shl(function, newValue, three);

    // SetType(currentType);
    return SetType(function, shifted, currentType);
}

jit_value_t Interpreter::SetType(jit_function_t function, jit_value_t nan, Object::ObjectType type) {
    auto numberType = jit_value_create_nint_constant(function, jit_type_ubyte, type);
    return jit_insn_or(function, nan, numberType);
}

jit_value_t Interpreter::SetType(jit_function_t function, jit_value_t nan, jit_value_t type) {
    return jit_insn_or(function, nan, type);
}

jit_value_t Interpreter::Zero(jit_function_t function) {
    return jit_value_create_long_constant(function, jit_type_ulong, 0);
}

jit_value_t Interpreter::GetType(jit_function_t function, jit_value_t nan) {
    // Get the bottom 3 bits
    // auto bottom3 = (uint8_t) (raw & 0x7);
    auto seven = jit_value_create_nint_constant(function, jit_type_ubyte, 0x7);
    auto bottom3 = jit_insn_and(function, nan, seven);
    return jit_insn_convert(function, bottom3, jit_type_ubyte, 0);
}

void manda::ExpressionStatementNode::acceptInterpreter(manda::Interpreter *interpreter) {
    interpreter->VisitExpressionStatement(this);
}

jit_value_t DecimalLiteralNode::acceptInterpreter(Interpreter *interpreter) {
    return interpreter->VisitDecimalLiteral(this);
}

