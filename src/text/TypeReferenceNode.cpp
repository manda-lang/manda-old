// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "TypeReferenceNode.h"

manda::TypeReferenceNode::TypeReferenceNode(const manda::SimpleIdentifierNode *identifier) {
    this->identifier = identifier;
}

manda::TypeReferenceNode::~TypeReferenceNode() {
    delete identifier;
    identifier = nullptr;
}

const std::string &manda::TypeReferenceNode::GetName() const {
    return identifier->GetName();
}

const manda::SourceSpan *manda::TypeReferenceNode::GetSourceSpan() const {
    return identifier->GetSourceSpan();
}
