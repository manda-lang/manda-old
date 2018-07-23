// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "SimpleIdentifierNode.h"

manda::SimpleIdentifierNode::SimpleIdentifierNode(const Token *token) {
    this->token = token;
}

manda::SimpleIdentifierNode::~SimpleIdentifierNode() {
    delete token;
}

const manda::SourceSpan *manda::SimpleIdentifierNode::GetSourceSpan() const {
    return token->GetSourceSpan();
}

bool manda::SimpleIdentifierNode::HasConstantValue() {
    return false;
}

const std::string &manda::SimpleIdentifierNode::GetName() const {
    return token->GetSourceSpan()->GetText();
}
