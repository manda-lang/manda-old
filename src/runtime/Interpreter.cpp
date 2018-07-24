// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <unordered_map>
#include <jit/jit-dump.h>
#include <iostream>
#include "Interpreter.h"
#include "../analysis/Object.h"

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
                VisitFunction(fiber->GetFunction());
                jit_context_build_end(jit);
                currentFiber = nullptr;
                fiber->Exit();
            }
        }
    } while (anyFibersAreAlive);
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

jit_function_t Interpreter::VisitFunction(const Function *ctx) {
    // TODO: What if it's already been compiled???
    // TODO: Return value
    // TODO: Parameters
    // TODO: Ref counting
    auto signature = jit_type_create_signature(abi, jit_type_void, nullptr, 0, 0);
    auto function = jit_function_create(jit, signature);

    // TODO: Declare that we will on-demand compile this function.
    // jit_function_set_on_demand_compiler(function, CompileFunction);

    // Attach a pointer to the fiber, the program, and the function itself.
    auto *opts = new OnDemandCompilationOptions;
    opts->function = ctx;
    opts->program = program;
    opts->fiber = currentFiber;

    // Affix this to the function as metadata.
    if ((jit_function_set_meta(function, 0, opts, nullptr, 1)) == 0) {
        jit_function_abandon(function);
    }

    CompileFunction(function);

    jit_dump_function(stdout, function, "JIT");
    return function;
}

int Interpreter::CompileFunction(jit_function_t function) {
    // Retrieve the compilation options;
    auto *optsPtr = (OnDemandCompilationOptions *) jit_function_get_meta(function, 0);

    if (optsPtr == nullptr) {
        return 0;
    }

    // Crawl through all the blocks.
    OnDemandCompilationOptions opts(*optsPtr);
    CompileBlock(function, opts, opts.function->GetStartBlock());

    // TODO: Compile all other labels
    // std::unordered_map<Block *, jit_label_t> labels;
    return 1;
}

int Interpreter::CompileBlock(jit_function_t function, Interpreter::OnDemandCompilationOptions &options,
                              Block *block) {
    for (auto *instruction : block->GetInstructions()) {
        // TODO: Polymorphism
        auto *os = (ObjectInstruction *) instruction;
        auto *obj = os->GetObject();
        TaggedPointer p;
        p.SetType(TaggedPointer::ACTUAL_NUMBER);
        p.SetFloatData(obj->rawObject.asUint64);
        auto constant = jit_value_create_float64_constant(function, jit_type_float64, p.GetRawDouble());
        jit_insn_throw(function, constant);
    }

    return 0;
}

uint8_t Interpreter::SymbolTableStore(Interpreter *interpreter, const char *name, double value) {
    std::string n(name);
    interpreter->currentFiber->GetScope()->Add(n, value);
    return 1;
}

uint8_t Interpreter::SymbolTableRetrieve(Interpreter *interpreter, const char *name, double *value) {
    std::string n(name);
    auto *symbol = interpreter->currentFiber->GetScope()->Resolve(n);

    if (symbol == nullptr) {
        return 0;
    } else {
        *value = symbol->GetValue();
        return 1;
    }
}
