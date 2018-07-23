// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <iostream>
#include "BinaryExpressionNode.h"
#include "BinaryExpressionParselet.h"
#include "Parser.h"

manda::BinaryExpressionParselet::BinaryExpressionParselet(int precedence) {
    this->precedence = precedence;
}

int manda::BinaryExpressionParselet::GetPrecedence() {
    return precedence;
}

manda::ExpressionNode *
manda::BinaryExpressionParselet::Parse(manda::Parser *parser, manda::ExpressionNode *left, const manda::Token *token) {
    auto *right = parser->ParseExpression(precedence);

    if (right == nullptr) {
        parser->AddError("Missing expression after binary operator.", token->GetSourceSpan());
        return nullptr;
    }

    return new BinaryExpressionNode(left, token, right);
}


