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

        TaggedPointer *VisitProgram(ProgramNode *ctx);

        jit_value_t VisitNumberLiteral(NumberLiteralNode *ctx);

        void VisitExpressionStatement(ExpressionStatementNode *ctx);

        jit_value_t Zero(jit_function_t function);

        jit_value_t GetValue(jit_function_t function, jit_value_t nan);

        jit_value_t SetValue(jit_function_t function, jit_value_t nan, jit_value_t newValue);

        jit_value_t GetType(jit_function_t function, jit_value_t nan);

        jit_value_t SetType(jit_function_t function, jit_value_t nan, TaggedPointer::TaggedPointerType type);

        jit_value_t SetType(jit_function_t function, jit_value_t nan, jit_value_t type);

        jit_value_t VisitSimpleIdentifier(SimpleIdentifierNode *ctx);

    private:
        std::stack<jit_function_t> functionStack;
        jit_context_t jit;
        jit_function_t entryPoint;
        VM *vm;
        Fiber *fiber;
    };
}

#endif //MANDA_INTERPRETER_H
