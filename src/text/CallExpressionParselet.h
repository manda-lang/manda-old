// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_CALLEXPRESSIONPARSELET_H
#define MANDA_CALLEXPRESSIONPARSELET_H

#include "CallExpressionNode.h"
#include "InfixParselet.h"

namespace manda
{
    class CallExpressionParselet : public InfixParselet
    {
    public:
        explicit CallExpressionParselet(int precedence);

        ExpressionNode *Parse(Parser *parser, ExpressionNode *left, const Token *token) override;

        int GetPrecedence() override;

    private:
        int precedence;
    };
}

#endif //MANDA_CALLEXPRESSIONPARSELET_H
