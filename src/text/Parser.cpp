// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <iostream>
#include "Parser.h"

using namespace manda;

manda::Parser::Parser(manda::Lexer *lexer) {
    this->lexer = lexer;
    this->current = nullptr;
    this->index = -1;

    for (auto *error : lexer->GetErrors()) {
        errors.push_back(error);
    }
}

const std::vector<Error *> &manda::Parser::GetErrors() const {
    return errors;
}

const manda::Token *manda::Parser::GetCurrentToken() const {
    return current;
}

bool manda::Parser::IsDone() const {
    return (index >= (int64_t) (lexer->GetTokens().size() - 1));
}

bool manda::Parser::Next(manda::Token::TokenType type) {
    auto *token = Peek();

    if (token == nullptr) {
        return false;
    } else if (token->GetType() != type) {
        return false;
    } else {
        index++;
        return true;
    }
}

const manda::Token *manda::Parser::Peek() const {
    if (IsDone()) {
        return nullptr;
    } else {
        return lexer->GetTokens().at((unsigned long) index + 1);
    }
}

ProgramNode *Parser::ParseProgram() {
    auto *program = new ProgramNode;
    ParseStatements(program->GetMutableStatements());
    return program;
}

void Parser::ParseStatements(std::vector<StatementNode *> &statements) {
    auto *statement = ParseStatement();

    while (statement != nullptr) {
        statements.push_back(statement);
        statement = ParseStatement();
    }
}

StatementNode *Parser::ParseStatement() {
    return ParseExpressionStatement();
}

ExpressionStatementNode *Parser::ParseExpressionStatement() {
    auto *expression = ParseExpression();
    return expression == nullptr ? nullptr : new ExpressionStatementNode(expression);
}

manda::ExpressionNode *manda::Parser::ParseExpression() {
    return ParseDecimalLiteral();
}

manda::DecimalLiteralNode *manda::Parser::ParseDecimalLiteral() {
    if (!Next(Token::DECIMAL)) {
        return nullptr;
    } else {
        return new DecimalLiteralNode(GetCurrentToken());
    }
}
