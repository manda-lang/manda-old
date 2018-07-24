// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_PARSER_H
#define MANDA_PARSER_H

#include <unordered_map>
#include <vector>
#include "InfixParselet.h"
#include "Lexer.h"
#include "NumberLiteralNode.h"
#include "ExpressionStatementNode.h"
#include "ProgramNode.h"
#include "SimpleIdentifierNode.h"
#include "VariableDeclarationStatementNode.h"

namespace manda
{
    class Parser
    {
    public:
        explicit Parser(Lexer *lexer);
        ~Parser();

        const std::vector<Error *> &GetErrors() const;

        const Token *GetCurrentToken() const;

        int GetPrecedence() const;

        bool IsDone() const;

        bool Next(Token::TokenType type);

        bool Next(Token::TokenType *types, int typeCount);

        const Token *Peek() const;

        const Token *Consume();

        void ParseStatements(std::vector<StatementNode *> &statements);

        void AddError(Error::ErrorSeverity severity, const char *message, const SourceSpan *span);

        void AddError(Error::ErrorSeverity severity, const std::string& message, const SourceSpan *span);

        void AddError(const char *message, const SourceSpan *span);

        void AddError(const std::string& message, const SourceSpan *span);

        ProgramNode *ParseProgram();

        StatementNode *ParseStatement();

        VariableDeclarationStatementNode *ParseVariableDeclarationStatement();

        ExpressionStatementNode *ParseExpressionStatement();

        ExpressionNode *ParseExpression(int precedence = 0);

        ExpressionNode *ParsePrefixExpression();

        SimpleIdentifierNode *ParseSimpleIdentifier();

        NumberLiteralNode *ParseNumberLiteral();

    private:
        std::unordered_map<int, InfixParselet *> infixParselets;
        std::vector<Error *> errors;
        int64_t index;
        Lexer *lexer;
    };
}

#endif //MANDA_PARSER_H
