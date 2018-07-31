// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_EXPRESSIONSTATEMENTNODE_H
#define MANDA_EXPRESSIONSTATEMENTNODE_H

#include "ExpressionNode.h"
#include "StatementNode.h"

namespace manda
{
    class ExpressionStatementNode : public StatementNode
    {
    public:
        explicit ExpressionStatementNode(const ExpressionNode *expression);

        ~ExpressionStatementNode();

        const ExpressionNode * GetExpression() const;

        const SourceSpan *GetSourceSpan() const override;

        bool HasFunctionDeclaration() const override;

        bool IsExpressionStatement() const override;

        void AcceptAnalyzer(Analyzer *analyzer) const override;

    private:
        const ExpressionNode *expression;
    };
}

#endif //MANDA_EXPRESSIONSTATEMENTNODE_H
