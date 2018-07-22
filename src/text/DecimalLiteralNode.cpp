// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "DecimalLiteralNode.h"

manda::DecimalLiteralNode::DecimalLiteralNode(const manda::Token *token) {
    this->token = token;
}

manda::DecimalLiteralNode::~DecimalLiteralNode() {
    delete token;
}

const manda::Token *manda::DecimalLiteralNode::GetToken() const {
    return token;
}

const manda::SourceSpan *manda::DecimalLiteralNode::GetSourceSpan() const {
    return token->GetSourceSpan();
}

bool manda::DecimalLiteralNode::HasConstantValue() {
    return true;
}
