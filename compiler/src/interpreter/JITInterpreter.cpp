// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "JITInterpreter.h"

#define fn functionStack.top()

manda::JITInterpreter::JITInterpreter(const MandaAnalyzer &analyzer)
        : analyzer(analyzer) {
    ctx = jit_context_create();

    // double main()
    auto mainParams = jit_type_float64;
    auto mainSignature = jit_type_create_signature(jit_abi_cdecl, jit_type_float64, &mainParams, 1, 0);
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

    jit_function_compile(mainFunction);
    jit_function_apply(mainFunction, nullptr, nullptr);
}

int manda::JITInterpreter::GetExitCode() const {
    return 0;
}
