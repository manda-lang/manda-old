// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <iostream>
#include "BinaryExpressionParselet.h"
#include "Parser.h"

using namespace manda;

manda::Parser::Parser(manda::Lexer *lexer) {
    this->lexer = lexer;
    this->index = -1;

    for (auto *error : lexer->GetErrors()) {
        errors.push_back(error);
    }

    int precedence = 4;
    infixParselets[Token::TIMES] = new BinaryExpressionParselet(precedence--);
    infixParselets[Token::DIV] = new BinaryExpressionParselet(precedence--);
    infixParselets[Token::MODULO] = new BinaryExpressionParselet(precedence--);
    infixParselets[Token::PLUS] = new BinaryExpressionParselet(precedence--);
    infixParselets[Token::MINUS] = new BinaryExpressionParselet(precedence--);
}

Parser::~Parser() {
    // TODO: Delete all infix parselets
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

const manda::Token *manda::Parser::Consume() {
    if (IsDone()) {
        return nullptr;
    } else {
        return lexer->GetTokens().at((unsigned long) ++index);
    }
}

ProgramNode *Parser::ParseProgram() {
    auto *program = new ProgramNode;

    while (!IsDone()) {
        auto *statement = ParseStatement();

        if (statement != nullptr) {
            program->GetMutableStatements().push_back(statement);
        } else {
            std::ostringstream message;
            auto *token = Consume();

            if (token != nullptr) {
                message << "Unexpected text '";
                message << token->GetSourceSpan()->GetText();
                message << "'.";
                auto *error = new Error(Error::ERROR, message.str(), new SourceSpan(token->GetSourceSpan()));
                errors.push_back(error);
                delete token;
            }
        }
    }

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
    StatementNode *result = nullptr;
    if ((result = ParseVariableDeclarationStatement()) != nullptr) return result;
    if ((result = ParseExpressionStatement()) != nullptr) return result;
    return result;
}

VariableDeclarationStatementNode *Parser::ParseVariableDeclarationStatement() {
    if (!Next(Token::LET)) {
        return nullptr;
    }

    auto *let = GetCurrentToken();
    auto *id = ParseSimpleIdentifier();

    if (id == nullptr) {
        AddError("Missing identifier after 'let' keyword.", let->GetSourceSpan());
        delete let;
        return nullptr;
    }

    if (!Next(Token::EQUALS)) {
        AddError("Missing '=' in variable declaration.", id->GetSourceSpan());
        delete let;
        delete id;
        return nullptr;
    }

    auto *equals = GetCurrentToken();
    auto *initializer = ParseExpression(0);

    if (initializer == nullptr) {
        AddError("Missing expression after '=' in variable declaration.", equals->GetSourceSpan());
        delete let;
        delete id;
        delete equals;
        return nullptr;
    }

    return new VariableDeclarationStatementNode(let, id, equals, initializer);
}

ExpressionStatementNode *Parser::ParseExpressionStatement() {
    auto *expression = ParseExpression();
    return expression == nullptr ? nullptr : new ExpressionStatementNode(expression);
}

manda::ExpressionNode *manda::Parser::ParsePrefixExpression() {
    ExpressionNode *result = nullptr;
    if ((result = ParseSimpleIdentifier()) != nullptr) return result;
    if ((result = ParseNumberLiteral()) != nullptr) return result;
    return result;
}

ExpressionNode *Parser::ParseExpression(int precedence) {
    auto *left = ParsePrefixExpression();

    while (left != nullptr && precedence < GetPrecedence()) {
        auto *token = Consume();

        if (token != nullptr) {
            auto it = infixParselets.find(token->GetType());

            if (it != infixParselets.end()) {
                InfixParselet *infix = infixParselets.at(token->GetType());
                left = infix->Parse(this, left, token);
            }
        } else {
            break;
        }
    }

    return left;
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

int Parser::GetPrecedence() const {
    auto *token = Peek();

    if (token != nullptr) {
        auto it = infixParselets.find(token->GetType());

        if (it != infixParselets.end()) {
            InfixParselet *infix = infixParselets.at(token->GetType());
            return infix->GetPrecedence();
        }
    }

    return 0;
}

void Parser::AddError(Error::ErrorSeverity severity, const char *message, const SourceSpan *span) {
    std::string msg(message);
    AddError(severity, msg, span);
}

void Parser::AddError(Error::ErrorSeverity severity, const std::string &message, const SourceSpan *span) {
    auto *error = new Error(severity, message, new SourceSpan(span));
    errors.push_back(error);
}

void Parser::AddError(const char *message, const SourceSpan *span) {
    AddError(Error::ERROR, message, span);
}

void Parser::AddError(const std::string &message, const SourceSpan *span) {
    AddError(Error::ERROR, message, span);
}
