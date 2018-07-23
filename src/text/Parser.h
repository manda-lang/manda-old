// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_PARSER_H
#define MANDA_PARSER_H

#include <vector>
#include "DecimalLiteralNode.h"
#include "ExpressionStatementNode.h"
#include "Lexer.h"
#include "ProgramNode.h"

namespace manda
{
    class Parser
    {
    public:
        explicit Parser(Lexer *lexer);

        const std::vector<Error *> &GetErrors() const;

        const Token *GetCurrentToken() const;

        bool IsDone() const;

        bool Next(Token::TokenType type);

        const Token *Peek() const;

        void ParseStatements(std::vector<StatementNode *> &statements);

        ProgramNode *ParseProgram();

        StatementNode *ParseStatement();

        ExpressionStatementNode *ParseExpressionStatement();

        ExpressionNode *ParseExpression();

        DecimalLiteralNode *ParseDecimalLiteral();

    private:
        std::vector<Error *> errors;
        int64_t index;
        Lexer *lexer;
    };
}

#endif //MANDA_PARSER_H
