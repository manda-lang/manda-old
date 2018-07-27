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
#include "ArrowFunctionBodyNode.h"
#include "CompilationUnitNode.h"
#include "ExpressionStatementNode.h"
#include "FunctionSignatureNode.h"
#include "InfixParselet.h"
#include "Lexer.h"
#include "NumberLiteralNode.h"
#include "SimpleIdentifierNode.h"
#include "TracksErrors.h"
#include "TypeReferenceNode.h"
#include "VariableDeclarationStatementNode.h"

namespace manda
{
    class Parser : public TracksErrors
    {
    public:
        explicit Parser(Lexer *lexer);

        ~Parser();

        const Token *GetCurrentToken() const;

        int GetPrecedence() const;

        bool IsDone() const;

        bool Next(Token::TokenType type);

        bool Next(Token::TokenType *types, int typeCount);

        const Token *Peek() const;

        const Token *Consume();

        void ParseStatements(std::vector<StatementNode *> &statements);

        CompilationUnitNode *ParseCompilationUnit();

        StatementNode *ParseStatement();

        FunctionBodyNode *ParseFunctionBody();

        ArrowFunctionBodyNode *ParseArrowFunctionBody();

        FunctionSignatureNode *ParseFunctionSignature();

        ParameterListNode *ParseParameterList();

        ParameterNode *ParseParameter();

        VariableDeclarationStatementNode *ParseVariableDeclarationStatement();

        TypeNode *ParseType();

        TypeReferenceNode *ParseTypeReference();

        ExpressionStatementNode *ParseExpressionStatement();

        ExpressionNode *ParseExpression(int precedence = 0);

        ExpressionNode *ParsePrefixExpression();

        SimpleIdentifierNode *ParseSimpleIdentifier();

        NumberLiteralNode *ParseNumberLiteral();

    private:
        std::unordered_map<int, InfixParselet *> infixParselets;
        int64_t index;
        Lexer *lexer;
    };
}

#endif //MANDA_PARSER_H
