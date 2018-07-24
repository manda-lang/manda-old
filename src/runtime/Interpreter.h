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
    class Analyzer;
    class ExpressionNode;

    class Interpreter
    {
    public:
        explicit Interpreter(VM *vm, Fiber *fiber);

        jit_function_t GetCurrentFunction();

        jit_value_t Zero(jit_function_t function);

        jit_value_t GetValue(jit_function_t function, jit_value_t nan);

        jit_value_t SetValue(jit_function_t function, jit_value_t nan, jit_value_t newValue);

        jit_value_t GetType(jit_function_t function, jit_value_t nan);

        jit_value_t SetType(jit_function_t function, jit_value_t nan, TaggedPointer::TaggedPointerType type);

        jit_value_t SetType(jit_function_t function, jit_value_t nan, jit_value_t type);

        TaggedPointer *VisitCompilationUnit(CompilationUnitNode *ctx);

        jit_value_t VisitExpression(ExpressionNode *ctx);

        jit_value_t VisitBinaryExpression(BinaryExpressionNode *ctx);

        jit_value_t VisitSimpleIdentifier(SimpleIdentifierNode *ctx);

        jit_value_t VisitNumberLiteral(NumberLiteralNode *ctx);

        void VisitExpressionStatement(ExpressionStatementNode *ctx);

        void VisitVariableDeclarationStatement(VariableDeclarationStatementNode *ctx);

    private:
        static uint8_t SymbolTableStore(Interpreter *interpreter, const char *name, double value);

        static uint8_t SymbolTableRetrieve(Interpreter *interpreter, const char *name, double *value);

        Analyzer *analyzer;
        std::stack<jit_function_t> functionStack;
        jit_context_t jit;
        jit_function_t entryPoint;
        VM *vm;
        Fiber *fiber;
    };
}

#endif //MANDA_INTERPRETER_H
