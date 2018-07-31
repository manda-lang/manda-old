// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "ParameterNode.h"

manda::ParameterNode::ParameterNode(const SimpleIdentifierNode *name, const TypeNode *type, const ExpressionNode *defaultValue) {
    this->identifier = name;
    this->defaultValue = defaultValue;
    this->type = type;
}

manda::ParameterNode::ParameterNode(const SimpleIdentifierNode* name) {
    this->identifier = name;
    this->defaultValue = nullptr;
    this->type = nullptr;
}

manda::ParameterNode::ParameterNode(const SimpleIdentifierNode* name, const manda::TypeNode *type) {
    this->identifier = name;
    this->defaultValue = nullptr;
    this->type = type;
}

manda::ParameterNode::ParameterNode(const SimpleIdentifierNode* name, const manda::ExpressionNode *defaultValue) {
    this->identifier = name;
    this->defaultValue = defaultValue;
    this->type = nullptr;
}

const manda::SimpleIdentifierNode *manda::ParameterNode::GetIdentifier() const {
    return nullptr;
}

const manda::ExpressionNode *manda::ParameterNode::GetDefaultValue() const {
    return defaultValue;
}

const manda::TypeNode *manda::ParameterNode::GetType() const {
    return type;
}

manda::ParameterNode::~ParameterNode() {
    delete defaultValue;
    delete type;
    defaultValue = nullptr;
    type = nullptr;
}

const manda::SourceSpan *manda::ParameterNode::GetSourceSpan() const {
    return nullptr;
}
