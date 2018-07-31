// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "ParameterListNode.h"

using namespace manda;

manda::ParameterListNode::ParameterListNode(const manda::SourceSpan *span) {
    this->span = new SourceSpan(span);
}

manda::ParameterListNode::~ParameterListNode() {
    delete span;
    span = nullptr;
}

const std::vector<ParameterNode *> &manda::ParameterListNode::GetParameters() const {
    return parameters;
}

void ParameterListNode::AddParameter(ParameterNode *parameter) {
    parameters.push_back(parameter);
}

const manda::SourceSpan *manda::ParameterListNode::GetSourceSpan() const {
    return span;
}
