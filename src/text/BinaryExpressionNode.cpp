// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "../runtime/runtime.h"

manda::BinaryExpressionNode::BinaryExpressionNode(manda::ExpressionNode *left, const manda::Token *op,
                                                  manda::ExpressionNode *right) {
    this->left = left;
    this->right = right;
    this->op = op;
}

manda::BinaryExpressionNode::~BinaryExpressionNode() {
    delete left;
    delete right;
    delete op;
}

const manda::SourceSpan *manda::BinaryExpressionNode::GetSourceSpan() const {
    return op->GetSourceSpan();
}

bool manda::BinaryExpressionNode::HasConstantValue() {
    return left->HasConstantValue() && right->HasConstantValue();
}

jit_value_t manda::BinaryExpressionNode::acceptInterpreter(manda::Interpreter *interpreter) {
    return interpreter->VisitBinaryExpression(this);
}

manda::ExpressionNode *manda::BinaryExpressionNode::GetLeft() const {
    return left;
}

manda::ExpressionNode *manda::BinaryExpressionNode::GetRight() const {
    return right;
}

const manda::Token *manda::BinaryExpressionNode::GetOperator() const {
    return op;
}
