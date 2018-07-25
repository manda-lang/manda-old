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
#include "../analysis/analysis.h"
#include "../text/text.h"
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

        jit_function_t VisitFunction(const Function *ctx);

        void VisitInstruction(const Instruction *ctx);

        void VisitAssignmentInstruction(const AssignmentInstruction *ctx);

        void VisitObjectInstruction(const ObjectInstruction *ctx);

        jit_value_t VisitObject(const Object *ctx);

        jit_value_t VisitReference(const Reference *ctx);

    private:
        struct OnDemandCompilationOptions
        {
            Interpreter *interpreter;
            Fiber *fiber;
            const manda::Function *function;
            Program *program;
        };

        static int CompileFunction(jit_function_t function);

        static int CompileBlock(jit_function_t function, OnDemandCompilationOptions &options, Block *block);

        Analyzer *analyzer;
        Program *program = nullptr;
        std::stack<jit_function_t> functionStack;
        std::unordered_map<std::string, unsigned long> variableIndices;
        jit_context_t jit;
        jit_function_t entryPoint;
        uint64_t *allocatedVariables = nullptr;
        VM *vm;
        Fiber *currentFiber;
        jit_abi_t abi;
    };
}

#endif //MANDA_INTERPRETER_H
