// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "ArrowFunctionBodyNode.h"

manda::ArrowFunctionBodyNode::ArrowFunctionBodyNode(const manda::ExpressionNode *expression) {
    expressionStatement = new ExpressionStatementNode(expression);
}

manda::ArrowFunctionBodyNode::~ArrowFunctionBodyNode() {
    delete expressionStatement;
    expressionStatement = nullptr;
}

const manda::SourceSpan *manda::ArrowFunctionBodyNode::GetSourceSpan() const {
    return expressionStatement->GetSourceSpan();
}

unsigned long manda::ArrowFunctionBodyNode::GetStatementCount() {
    return 1;
}

const manda::StatementNode *manda::ArrowFunctionBodyNode::GetStatements() {
    return expressionStatement;
}
