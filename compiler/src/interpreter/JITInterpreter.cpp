// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <jit/jit-dump.h>
#include "JITInterpreter.h"
#include "../analysis/MandaObject.h"

#define func functionStack.top()


typedef jit_float64 (*MandaEntryPoint)();

manda::JITInterpreter::JITInterpreter(MandaAnalyzer &analyzer)
        : analyzer(analyzer) {
    ctx = jit_context_create();
    nanbox_true();
    result = nanbox_from_double(0.0);

    // double main()
    auto mainSignature = jit_type_create_signature(jit_abi_cdecl, jit_type_float64, nullptr, 0, 0);
    mainFunction = jit_function_create(ctx, mainSignature);

    // Initialize function stack
    functionStack.push(mainFunction);
}

manda::JITInterpreter::~JITInterpreter() {
    jit_context_destroy(ctx);
}

jit_function_t manda::JITInterpreter::GetMainFunction() const {
    return mainFunction;
}

void manda::JITInterpreter::Run() {
    // Compile all top-level statements into the main function, and run.
    auto *unit = analyzer.GetCompilationUnit();

    for (auto *stmt : unit->stmt()) {
        stmt->accept(this);
    }

    // Return 0, just-in-case.
    auto zero = jit_value_create_float64_constant(func, jit_type_float64, 4.0);
    jit_insn_return(func, zero);

    jit_dump_function(stdout, func, "[uncompiled]");

    jit_context_build_start(ctx);
    jit_function_compile(mainFunction);
    jit_context_build_end(ctx);


    auto entry = (MandaEntryPoint) jit_function_to_closure(mainFunction);
    result.as_double = entry();
}

int manda::JITInterpreter::GetExitCode() const {
    return 0;
}

nanbox_t manda::JITInterpreter::GetResult() const {
    return result;
}

jit_value_t manda::JITInterpreter::CompileObject(const manda::MandaObject *obj) {
    //std::cout << "Found object" << std::endl;
    //std::cout << "Type: " << obj->GetType()->GetQualifiedName() << std::endl;

    if (obj->constantValueType != manda::MandaObject::kNone) {
        switch (obj->constantValueType) {
            case manda::MandaObject::kUnsigned: {
                auto value = nanbox_from_double(obj->constantValue.asUnsigned);
                return jit_value_create_float64_constant(func, jit_type_float64, value.as_double);
            }
            case manda::MandaObject::kSigned: {
                auto value = nanbox_from_double(obj->constantValue.asSigned);
                return jit_value_create_float64_constant(func, jit_type_float64, value.as_double);
            }
            case manda::MandaObject::kString:
                std::cout << "String literal: \"" << obj->constantValue.asString << "\"" << std::endl;
                break;
            case manda::MandaObject::kBool: {
                auto value = nanbox_from_boolean(obj->constantValue.asBool);
                return jit_value_create_float64_constant(func, jit_type_float64, value.as_double);
            }
            default:
                break;

        }
    }

    return nullptr;
}

Any manda::JITInterpreter::visitWhileStmt(MandaParser::WhileStmtContext *ctx) {
    auto *condCtx = ctx->expr();
    auto condAny = condCtx->accept(&analyzer);

    if (!condAny.is<MandaObjectOrType *>()) {
        // todo: err
        std::cout << "while loop faileddd" << std::endl;
    } else {
        auto *condObjectOrType = condAny.as<MandaObjectOrType *>();
        if (condObjectOrType->IsType()) {
            std::cout << "This is a type, fool COND." << std::endl;
        } else
            // Make sure it's a bool.
        if (!analyzer.GetCoreTypes().GetBoolType()->IsAssignableTo(condObjectOrType->AsObject()->GetType())) {
            std::cout << "NOT A BOOL!!!!" << std::endl;
        } else {


            // We've got an object, compile it.
            auto *cond = CompileObject(condObjectOrType->AsObject());

            if (cond == nullptr) {
                std::cout << "nullptr cond!!!" << std::endl;
            } else {

                // While loops are simple:
                // 1. Make a START and END label
                // 2. Check if condition
                // 3. If not, jump to END
                jit_label_t startLabel = jit_label_undefined;
                auto endLabel = jit_function_reserve_label(func);
                auto jitTrue = jit_value_create_float64_constant(func, jit_type_float64, nanbox_true().as_double);
                auto valueIsTrue = jit_insn_eq(func, cond, jitTrue);
                jit_insn_label(func, &startLabel); // start:
                jit_insn_branch_if_not(func, valueIsTrue, &endLabel); // End loop if not true
                ctx->block()->accept(this);
                jit_insn_label(func, &endLabel); // end:
            }
        }
    }

    return Any();
}

Any manda::JITInterpreter::visitReturnStmt(MandaParser::ReturnStmtContext *ctx) {
    // Get the value, it should ultimately return a MandaObjectOrType.
    auto *exprCtx = ctx->expr();
    auto valueAny = exprCtx->accept(&analyzer);

    if (!valueAny.is<MandaObjectOrType *>()) {
        // todo: err
        std::cout << "huh???" << std::endl;
    } else {
        auto *value = valueAny.as<MandaObjectOrType *>();
        if (value->IsType()) {
            std::cout << "This is a type, fool." << std::endl;
        } else {
            // We've got an object, compile it.
            auto *returnValue = CompileObject(value->AsObject());

            if (returnValue == nullptr) {
                std::cout << "nullptr!!!" << std::endl;
            } else {
                jit_insn_return(func, returnValue);
            }
        }
    }

    return Any();
}
