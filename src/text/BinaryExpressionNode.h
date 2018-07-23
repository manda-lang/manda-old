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

        const SourceSpan *GetSourceSpan() const override;

        bool HasConstantValue() override;

        jit_value_t acceptInterpreter(Interpreter *interpreter) override;

    private:
        ExpressionNode *left;
        ExpressionNode *right;
        const Token *op;
    };
}

#endif //MANDA_BINARYEXPRESSIONNODE_H
