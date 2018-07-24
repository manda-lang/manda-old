// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_VARIABLEDECLARATIONNODE_H
#define MANDA_VARIABLEDECLARATIONNODE_H

#include "ExpressionNode.h"
#include "SimpleIdentifierNode.h"
#include "StatementNode.h"
#include "Token.h"

namespace manda
{
    class VariableDeclarationStatementNode : StatementNode
    {
    public:
        explicit VariableDeclarationStatementNode(const Token *let, SimpleIdentifierNode *identifier, const Token *equals,
                                         ExpressionNode *initializer);

        ~VariableDeclarationStatementNode() override;

        const Token *GetLet() const;

        SimpleIdentifierNode *GetIdentifier() const;

        const Token *GetEquals() const;

        ExpressionNode *GetInitializer() const;

        void acceptInterpreter(Interpreter *interpreter) override;

        const SourceSpan *GetSourceSpan() const override;

    private:
        const Token *let;
        SimpleIdentifierNode *identifier;
        const Token *equals;
        ExpressionNode *initializer;
    };
}

#endif //MANDA_VARIABLEDECLARATIONNODE_H
