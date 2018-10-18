// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "JITInterpreter.h"

#define func functionStack.top()

manda::JITInterpreter::JITInterpreter(MandaAnalyzer &analyzer)
        : analyzer(analyzer) {
    ctx = jit_context_create();
    result = 0.0;

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

    jit_context_build_start(ctx);
    jit_function_compile(mainFunction);
    jit_context_build_end(ctx);
    jit_function_apply(mainFunction, nullptr, &result);
}

int manda::JITInterpreter::GetExitCode() const {
    return 0;
}

jit_float64 manda::JITInterpreter::GetResult() const {
    return result;
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
            auto *returnValue = value->AsObject()->Accept(*this);
            if (returnValue == nullptr) {
                std::cout << "nullptr!!!" << std::endl;
            } else {
                jit_insn_return(func, returnValue);
            }
        }
    }

    return Any();
}
