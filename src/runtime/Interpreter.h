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
#include "../text/text.h"
#include "VM.h"

namespace manda
{
    class ExpressionNode;

    class Interpreter
    {
    public:
        explicit Interpreter(VM *vm, Fiber *fiber);

        jit_function_t GetCurrentFunction();

        Object * VisitProgram(ProgramNode *ctx);

        jit_value_t VisitDecimalLiteral(DecimalLiteralNode *ctx);

        void VisitExpressionStatement(ExpressionStatementNode *ctx);

    private:
        std::stack<jit_function_t> functionStack;
        jit_context_t jit;
        jit_function_t entryPoint;
        VM *vm;
        Fiber *fiber;
    };
}

#endif //MANDA_INTERPRETER_H
