// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_INTERPRETER_H
#define MANDA_INTERPRETER_H

#include <stack>
#include <symbol_table.cpp>
#include "../manda_text/manda_text.h"
#include "Object.h"
#include "VM.h"

namespace manda
{
    class Interpreter : public manda_text::MandaBaseVisitor
    {
    public:
        explicit Interpreter(VM *vm, Fiber *fiber);

        antlrcpp::Any visitProgram(manda_text::MandaParser::ProgramContext *ctx) override;

        antlrcpp::Any visitExpressionStatement(manda_text::MandaParser::ExpressionStatementContext *ctx) override;

        antlrcpp::Any visitLiteralExpression(manda_text::MandaParser::LiteralExpressionContext *ctx) override;

        antlrcpp::Any visitDecimalLiteral(manda_text::MandaParser::DecimalLiteralContext *ctx) override;

    private:
        VM *vm;
        Fiber *fiber;
        SymbolTable<Object *> *scope;
        std::stack<SymbolTable<Object *> *> scopes;

        void pushScope();

        void popScope();
    };
}

#endif //MANDA_INTERPRETER_H
