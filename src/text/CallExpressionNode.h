// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_CALLEXPRESSIONNODE_H
#define MANDA_CALLEXPRESSIONNODE_H

#include "ArgumentListNode.h"
#include "ExpressionNode.h"

namespace manda
{
    class CallExpressionNode : public ExpressionNode
    {
        explicit CallExpressionNode(const ExpressionNode *callee, const ArgumentListNode *argumentList);

        ~CallExpressionNode();

        const ExpressionNode *GetCallee() const;

        const ArgumentListNode *GetArgumentList() const;

    public:
        const SourceSpan *GetSourceSpan() const override;

        bool HasConstantValue() override;

        Object *AcceptAnalyzer(Analyzer *analyzer) const override;

    private:
        const ExpressionNode *callee;
        const ArgumentListNode *argumentList;
    };
}

#endif //MANDA_CALLEXPRESSIONNODE_H
