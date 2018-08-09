// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <cstdint>
#include <cstdio>
#include <unordered_map>
#include <jit/jit-dump.h>
#include <iostream>
#include "../manda_src.h"

using namespace manda;

manda::Interpreter::Interpreter(manda::VM *vm) {
    this->abi = jit_abi_cdecl;
    this->currentFiber = nullptr;
    this->vm = vm;
    jit = jit_context_create();
}

Interpreter::~Interpreter() {
    jit_context_destroy(jit);
}

jit_function_t Interpreter::GetCurrentFunction() {
    return functionStack.top();
}

void Interpreter::LoadProgram(Program *program) {
    this->program = program;
}

void Interpreter::Run() {
    bool anyFibersAreAlive = false;

    do {
        for (auto *fiber : vm->GetFibers()) {
            anyFibersAreAlive = false;

            if (!fiber->HasExited()) {
                anyFibersAreAlive = true;
                // TODO: Actual multitasking
                currentFiber = fiber;

                // TODO: Won't always have to lock the context
                jit_context_build_start(jit);
                auto function = VisitFunction(fiber->GetFunction());
                jit_function_compile(function);
                jit_context_build_end(jit);
                jit_ulong result;
                // jit_dump_function(stdout, function, "JIT [compiled]");
                //jit_function_apply(function, nullptr, &result);
                currentFiber->SetResult((uint64_t) result);
                currentFiber = nullptr;
                fiber->Exit();
            }
        }
    } while (anyFibersAreAlive);

    // Clean up!
    delete allocatedVariables;
    allocatedVariables = nullptr;
}
