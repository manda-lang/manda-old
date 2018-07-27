// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_ARROWFUNCTIONBODY_H
#define MANDA_ARROWFUNCTIONBODY_H

#include "ExpressionNode.h"
#include "ExpressionStatementNode.h"
#include "FunctionBodyNode.h"

namespace manda
{
    class ArrowFunctionBodyNode : FunctionBodyNode
    {
        explicit ArrowFunctionBodyNode(const ExpressionNode *expression);

        ~ArrowFunctionBodyNode();

        const SourceSpan *GetSourceSpan() const override;

        unsigned long GetStatementCount() override;

        const StatementNode *GetStatements() override;

    private:
        ExpressionStatementNode *expressionStatement;
    };
}

#endif //MANDA_ARROWFUNCTIONBODY_H
