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
#include "../analysis/analysis.h"
#include "../text/text.h"
#include "VM.h"

namespace manda
{
    class Analyzer;

    class Block;

    class ExpressionNode;

    class Program;

    class Interpreter
    {
    public:
        explicit Interpreter(VM *vm);

        ~Interpreter();

        jit_function_t GetCurrentFunction();

        void LoadProgram(Program *program);

        void Run();

        jit_value_t Zero(jit_function_t function);

        jit_value_t GetValue(jit_function_t function, jit_value_t nan);

        jit_value_t SetValue(jit_function_t function, jit_value_t nan, jit_value_t newValue);

        jit_value_t GetType(jit_function_t function, jit_value_t nan);

        jit_value_t SetType(jit_function_t function, jit_value_t nan, TaggedPointer::TaggedPointerType type);

        jit_value_t SetType(jit_function_t function, jit_value_t nan, jit_value_t type);

        jit_function_t VisitFunction(const Function *ctx);

    private:
        struct OnDemandCompilationOptions
        {
            Fiber *fiber;
            const manda::Function *function;
            Program *program;
        };

        static int CompileFunction(jit_function_t function);

        static int CompileBlock(jit_function_t function, OnDemandCompilationOptions &options, Block *block);

        static uint8_t SymbolTableStore(Interpreter *interpreter, const char *name, double value);

        static uint8_t SymbolTableRetrieve(Interpreter *interpreter, const char *name, double *value);

        Analyzer *analyzer;
        Program *program = nullptr;
        std::stack<jit_function_t> functionStack;
        jit_context_t jit;
        jit_function_t entryPoint;
        VM *vm;
        Fiber *currentFiber;
        jit_abi_t abi;
    };
}

#endif //MANDA_INTERPRETER_H
