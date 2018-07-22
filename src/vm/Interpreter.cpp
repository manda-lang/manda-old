// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <iostream>
#include "Interpreter.h"
#include "Number.h"

using namespace antlrcpp;

antlrcpp::Any manda::Interpreter::visitProgram(manda_text::MandaParser::ProgramContext *ctx) {
    antlrcpp::Any result;

    for (auto statement: ctx->statement()) {
        result = visit(statement);
    }

    return result;
}

antlrcpp::Any manda::Interpreter::visitDecimalLiteral(manda_text::MandaParser::DecimalLiteralContext *ctx) {
    std::string::size_type sz;
    auto *value = new Number(std::stod(ctx->DECIMAL()->getText(), &sz));
    return Any((Object *) value);
}

Any manda::Interpreter::visitExpressionStatement(manda_text::MandaParser::ExpressionStatementContext *ctx) {
    return visit(ctx->expression());
}

Any manda::Interpreter::visitLiteralExpression(manda_text::MandaParser::LiteralExpressionContext *ctx) {
    return visit(ctx->literal());
}

void manda::Interpreter::pushScope() {
    auto *child = scope->CreateChild();
}

void manda::Interpreter::popScope() {
    if (scopes.size() > 1) {
        auto *old = scopes.top();
        scopes.pop();
        delete old;
    }
}

manda::Interpreter::Interpreter(manda::VM *vm, manda::Fiber *fiber) {
    this->vm = vm;
    this->fiber = fiber;
    scope = new SymbolTable<Object *>;
    scopes.push(scope);
}

Any manda::Interpreter::visitVariableDeclarationStatement(
        manda_text::MandaParser::VariableDeclarationStatementContext *ctx) {
    auto value = visit(ctx->expression());
    auto *obj = value.as<Object *>();
    scope->Add(ctx->ID()->getText(), obj);
    return value;
}
