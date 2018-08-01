// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <iostream>
#include "../manda_src.h"

manda::CallExpressionNode::CallExpressionNode(const manda::ExpressionNode *callee,
                                              const manda::ArgumentListNode *argumentList) {
    this->callee = callee;
    this->argumentList = argumentList;
}

manda::CallExpressionNode::~CallExpressionNode() {
    delete callee;
    delete argumentList;
}

const manda::ExpressionNode *manda::CallExpressionNode::GetCallee() const {
    return callee;
}

const manda::ArgumentListNode *manda::CallExpressionNode::GetArgumentList() const {
    return argumentList;
}

const manda::SourceSpan *manda::CallExpressionNode::GetSourceSpan() const {
    return argumentList->GetSourceSpan();
}

bool manda::CallExpressionNode::HasConstantValue() {
    // TODO: When can calls be constant???
    return false;
}

manda::Object *manda::CallExpressionNode::AcceptAnalyzer(manda::Analyzer *analyzer) const {
    return analyzer->VisitCallExpression(this);
}

bool manda::CallExpressionNode::CanStandAlone() const {
    return true;
}
