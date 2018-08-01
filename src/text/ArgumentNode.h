// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_ARGUMENTNODE_H
#define MANDA_ARGUMENTNODE_H

#include "SimpleIdentifierNode.h"

namespace manda
{
    class ArgumentNode : public AstNode
    {
    public:
        explicit ArgumentNode(ExpressionNode *expression);

        ~ArgumentNode();

        const SimpleIdentifierNode *GetIdentifier() const;

        const ExpressionNode *GetExpression() const;

        void SetIdentifier(const SimpleIdentifierNode *identifier);

    public:
        const SourceSpan *GetSourceSpan() const override;

    private:
        const ExpressionNode *expression;
        const SimpleIdentifierNode *identifier = nullptr;
    };
}

#endif //MANDA_ARGUMENTNODE_H
