// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_BINARYEXPRESSIONNODE_H
#define MANDA_BINARYEXPRESSIONNODE_H

#include "ExpressionNode.h"
#include "Token.h"

namespace manda
{
    class BinaryExpressionNode : public ExpressionNode
    {
    public:
        explicit BinaryExpressionNode(ExpressionNode *left, const Token *op, ExpressionNode *right);

        ~BinaryExpressionNode() override;

        ExpressionNode *GetLeft() const;

        ExpressionNode *GetRight() const;

        const Token* GetOperator() const;

        const SourceSpan *GetSourceSpan() const override;

        bool HasConstantValue() override;

        Object *AcceptAnalyzer(Analyzer *analyzer) const override;

    private:
        ExpressionNode *left;
        ExpressionNode *right;
        const Token *op;
    };
}

#endif //MANDA_BINARYEXPRESSIONNODE_H
