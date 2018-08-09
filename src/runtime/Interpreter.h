// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_INTERPRETER_H
#define MANDA_INTERPRETER_H

#include <jit/jit.h>
#include <stack>
#include <unordered_map>
#include "VM.h"

namespace manda
{
    class Analyzer;

    class AssignmentInstruction;

    class Block;

    class ExpressionNode;

    class Instruction;

    class ObjectInstruction;

    class Program;

    class Reference;

    class Interpreter
    {
    public:
        explicit Interpreter(VM *vm);

        ~Interpreter();

        jit_function_t GetCurrentFunction();

        void LoadProgram(Program *program);

        void Run();

    private:
        struct OnDemandCompilationOptions
        {
            Interpreter *interpreter;
            Fiber *fiber;
            const manda::Function *function;
            Program *program;
        };

        Analyzer *analyzer;
        Program *program = nullptr;
        std::stack<jit_function_t> functionStack;
        std::unordered_map<std::string, unsigned long> variableIndices;
        std::unordered_map<const Function *, jit_function_t> compiledFunctions;
        jit_context_t jit;
        jit_function_t entryPoint;
        uint64_t *allocatedVariables = nullptr;
        VM *vm;
        Fiber *currentFiber;
        jit_abi_t abi;
    };
}

#endif //MANDA_INTERPRETER_H
