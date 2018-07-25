// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "../manda_src.h"

using namespace manda;

manda::ExpressionStatementNode::ExpressionStatementNode(manda::ExpressionNode *expression) {
    this->expression = expression;
}

manda::ExpressionStatementNode::~ExpressionStatementNode() {
    delete expression;
}

ExpressionNode *manda::ExpressionStatementNode::GetExpression() {
    return expression;
}

const manda::SourceSpan *manda::ExpressionStatementNode::GetSourceSpan() const {
    return expression->GetSourceSpan();
}

bool ExpressionStatementNode::HasFunctionDeclaration() const {
    return false;
}

bool ExpressionStatementNode::IsExpressionStatement() const {
    return true;
}

void ExpressionStatementNode::AcceptAnalyzer(Analyzer *analyzer) {
    analyzer->VisitExpressionStatement(this);
}
