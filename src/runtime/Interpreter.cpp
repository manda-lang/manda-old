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

    variableIndices.clear();
    allocatedVariables = new uint64_t[program->GetTotalVariableCount()];

    for (unsigned long i = 0; i < program->GetSsaVariables().size(); i++) {
        auto name = program->GetSsaVariables().at(i);
        variableIndices.insert(std::make_pair(name, i));
    }

    // Pre-compile all functions

    for (auto *function : program->GetMainModule()->GetFunctions()) {
        VisitFunction(function);
    }
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

jit_function_t Interpreter::VisitFunction(const Function *ctx) {
    // TODO: What if it's already been compiled???
    auto it = compiledFunctions.find(ctx);

    if (it != compiledFunctions.end()) {
        return compiledFunctions.at(ctx);
    }

    // TODO: Return value
    // TODO: Parameters
    // TODO: Ref counting
    auto signature = jit_type_create_signature(abi, jit_type_ulong, nullptr, 0, 0);
    auto function = jit_function_create(jit, signature);

    // TODO: Declare that we will on-demand compile this function.
    // jit_function_set_on_demand_compiler(function, CompileFunction);

    // Attach a pointer to the fiber, the program, and the function itself.
    auto *opts = new OnDemandCompilationOptions;
    opts->interpreter = this;
    opts->function = ctx;
    opts->program = program;
    opts->fiber = currentFiber;

    // Affix this to the function as metadata.
    if ((jit_function_set_meta(function, 0, opts, nullptr, 1)) == 0) {
        jit_function_abandon(function);
    }

    CompileFunction(function);
    jit_dump_function(stdout, function, "JIT [uncompiled]");
    compiledFunctions.insert(std::make_pair(ctx, function));
    return function;
}

void Interpreter::VisitInstruction(const Instruction *ctx) {
    ctx->AcceptInterpreter(this);
}

void Interpreter::VisitAssignmentInstruction(const AssignmentInstruction *ctx) {
    auto function = functionStack.top();
    auto value = VisitObject(ctx->GetObject());

    // We have a single array in memory that holds all of our variables (hooray, SSA!)
    // Load whatever value we received into a pointer.
    //
    // Instead of having the JIT compute the pointer, compute it NOW.
    auto basePtr = (jit_ulong) allocatedVariables;
    auto index = variableIndices.at(ctx->GetName());
    auto ptr = basePtr + (index * sizeof(uint64_t));

    // JIT it
    auto ulongPointerType = jit_type_create_pointer(jit_type_ulong, 0);
    auto ptrConstant = jit_value_create_long_constant(function, ulongPointerType, jit_ulong_to_long(ptr));
    jit_insn_store_relative(function, ptrConstant, 0, value);
}

void Interpreter::VisitObjectInstruction(const ObjectInstruction *ctx) {
    auto function = functionStack.top();
    auto value = VisitObject(ctx->GetObject());
    jit_insn_return(function, value);

//    // TODO: Actually do a real return
//    // Instead of returning, store the result in &result
//
//    auto ptr = (jit_ulong) currentFiber->GetNanboxPointer();
//    auto ulongPointerType = jit_type_create_pointer(jit_type_ulong, 0);
//    auto ptrConstant = jit_value_create_long_constant(function, ulongPointerType, jit_ulong_to_long(ptr));
//    jit_insn_store(function, ptrConstant, value);
}

jit_value_t Interpreter::VisitObject(const Object *ctx) {
    if (ctx->IsReference()) {
        return VisitReference((const Reference *) ctx);
    } else if (ctx->IsCall()) {
        return VisitCall((const Call *) ctx);
    }

    // TODO: Polymorphism
    auto function = functionStack.top();

    nanbox_t box = nanbox_empty();

    if (ctx->rawObject.type == Object::DOUBLE) {
        box = nanbox_from_double(ctx->rawObject.value.asDouble);
    } else {
        box = nanbox_from_double(ctx->rawObject.value.asUint64);
    }

    return jit_value_create_long_constant(function, jit_type_ulong, jit_ulong_to_long(box.as_int64));
}

jit_value_t Interpreter::VisitCall(const manda::Call *ctx) {
    std::vector<jit_value_t> arguments;
    auto function = functionStack.top();

    for (auto *arg : ctx->GetArguments()) {
        auto argument = VisitObject(arg); // TODO: Handle null
        arguments.push_back(argument);
    }

//    auto *cc = ctx;
//
//    if (ctx->IsReference()) {
//        auto *ref = (const Reference*)
//    }

    if (ctx->rawObject.type == Object::FUNCTION) {
        auto *fn = ctx->rawObject.value.function;
        auto jitFn = VisitFunction(fn);
        auto sig = jit_function_get_signature(jitFn);
        return jit_insn_call(function, fn->GetName(), jitFn, sig, arguments.data(), (unsigned int) arguments.size(), 0);
    } else {
        auto *callee = VisitObject(ctx->GetCallee()); // TODO: Handle null
        std::cout << "ASSERT FALSE" << std::endl;
        assert(false);
        return nullptr;
    }
}

jit_value_t Interpreter::VisitReference(const Reference *ctx) {
    auto function = functionStack.top();

    // We have a single array in memory that holds all of our variables (hooray, SSA!)
    // Load whatever value we received into a pointer.
    //
    // Instead of having the JIT compute the pointer, compute it NOW.
    auto basePtr = (jit_ulong) allocatedVariables;
    auto index = variableIndices.at(ctx->GetName());
    auto ptr = basePtr + (index * sizeof(uint64_t));

    // JIT it
    auto ulongPointerType = jit_type_create_pointer(jit_type_ulong, 0);
    auto ptrConstant = jit_value_create_long_constant(function, ulongPointerType, jit_ulong_to_long(ptr));
    return jit_insn_load_relative(function, ptrConstant, 0, jit_type_ulong);
}

int Interpreter::CompileFunction(jit_function_t function) {
    // Retrieve the compilation options;
    auto *optsPtr = (OnDemandCompilationOptions *) jit_function_get_meta(function, 0);

    if (optsPtr == nullptr) {
        return 0;
    }

    // Crawl through all the blocks.
    OnDemandCompilationOptions opts(*optsPtr);
    opts.interpreter->functionStack.push(function);
    CompileBlock(function, opts, opts.function->GetStartBlock());
    opts.interpreter->functionStack.pop();

    // TODO: Compile all other labels
    // std::unordered_map<Block *, jit_label_t> labels;
    return 1;
}

int Interpreter::CompileBlock(jit_function_t function, Interpreter::OnDemandCompilationOptions &options,
                              Block *block) {
    for (auto *instruction : block->GetInstructions()) {
        options.interpreter->VisitInstruction(instruction);
    }

    return 0;
}
