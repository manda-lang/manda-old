// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "ArgumentNode.h"

manda::ArgumentNode::ArgumentNode(manda::ExpressionNode *expression) {
    this->expression = expression;
    this->identifier = nullptr;
}

manda::ArgumentNode::~ArgumentNode() {
    delete expression;
    delete identifier;
    expression = nullptr;
    identifier = nullptr;
}

const manda::SimpleIdentifierNode *manda::ArgumentNode::GetIdentifier() const {
    return identifier;
}

const manda::ExpressionNode *manda::ArgumentNode::GetExpression() const {
    return expression;
}

void manda::ArgumentNode::SetIdentifier(const manda::SimpleIdentifierNode *identifier) {
    this->identifier = identifier;
}

const manda::SourceSpan *manda::ArgumentNode::GetSourceSpan() const {
    if (identifier != nullptr) {
        return identifier->GetSourceSpan();
    } else {
        return expression->GetSourceSpan();
    }
}
