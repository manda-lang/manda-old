// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "../manda_src.h"

manda::CallExpressionParselet::CallExpressionParselet(int precedence) {
    this->precedence = precedence;
}

manda::ExpressionNode *
manda::CallExpressionParselet::Parse(manda::Parser *parser, manda::ExpressionNode *left, const manda::Token *token) {
    auto *argumentList = parser->ParseArgumentList(token);

    if (argumentList == nullptr) {
        parser->AddError("Missing argument list after '('.", token->GetSourceSpan());
        delete token;
        delete left;
        return nullptr;
    }

    return new CallExpressionNode(left, argumentList);
}

int manda::CallExpressionParselet::GetPrecedence() {
    return precedence;
}
