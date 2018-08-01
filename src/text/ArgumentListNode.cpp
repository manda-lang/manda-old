// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "ArgumentListNode.h"
using namespace manda;

manda::ArgumentListNode::ArgumentListNode(const manda::Token *lParen) {
    this->lParen = lParen;
}

manda::ArgumentListNode::~ArgumentListNode() {
    delete lParen;
    lParen = nullptr;

    for (auto *argument : arguments) {
        delete argument;
    }

    arguments.clear();
}

const std::vector<const ExpressionNode *> &manda::ArgumentListNode::GetArguments() const {
    return arguments;
}

void manda::ArgumentListNode::AddArgument(const manda::ExpressionNode *expression) {
    arguments.push_back(expression);
}

const SourceSpan *ArgumentListNode::GetSourceSpan() const {
    return lParen->GetSourceSpan();
}
