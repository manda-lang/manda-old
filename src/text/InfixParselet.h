// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_INFIXPARSELET_H
#define MANDA_INFIXPARSELET_H

#include "ExpressionNode.h"
#include "Token.h"

namespace manda
{
    class Parser;

    class InfixParselet
    {
    public:
        virtual ExpressionNode *Parse(Parser *parser, ExpressionNode *left, const Token *token) = 0;

        virtual ~InfixParselet() = default;

        virtual int GetPrecedence() = 0;
    };
}

#endif //MANDA_INFIXPARSELET_H
