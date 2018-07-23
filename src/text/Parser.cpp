// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <iostream>
#include "Parser.h"
#include "SimpleIdentifierNode.h"

using namespace manda;

manda::Parser::Parser(manda::Lexer *lexer) {
    this->lexer = lexer;
    this->index = -1;

    for (auto *error : lexer->GetErrors()) {
        errors.push_back(error);
    }
}

const std::vector<Error *> &manda::Parser::GetErrors() const {
    return errors;
}

const manda::Token *manda::Parser::GetCurrentToken() const {
    return lexer->GetTokens().at((unsigned long) index);
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

bool Parser::Next(Token::TokenType *types, int typeCount) {
    for (int i = 0; i < typeCount; i++) {
        if (Next(types[i])) {
            return true;
        }
    }

    return false;
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
    ExpressionNode *result = nullptr;
    if ((result = ParseSimpleIdentifier()) != nullptr) return result;
    if ((result = ParseNumberLiteral()) != nullptr) return result;
    return result;
}

manda::SimpleIdentifierNode *Parser::ParseSimpleIdentifier() {
    if (!Next(Token::ID)) {
        return nullptr;
    } else {
        return new SimpleIdentifierNode(GetCurrentToken());
    }
}

manda::NumberLiteralNode *manda::Parser::ParseNumberLiteral() {
    Token::TokenType numberTypes[5] = {Token::DECIMAL, Token::FLOAT, Token::BINARY, Token::HEX, Token::OCTAL};

    if (Next(numberTypes, sizeof(numberTypes) / sizeof(Token::TokenType))) {
        return new NumberLiteralNode(GetCurrentToken());
    } else {
        return nullptr;
    }
}
