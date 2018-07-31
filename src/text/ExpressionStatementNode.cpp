// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "../manda_src.h"

using namespace manda;

manda::ExpressionStatementNode::ExpressionStatementNode(const ExpressionNode *expression) {
    this->expression = expression;
}

manda::ExpressionStatementNode::~ExpressionStatementNode() {
    delete expression;
}

const ExpressionNode * manda::ExpressionStatementNode::GetExpression() const {
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

void ExpressionStatementNode::AcceptAnalyzer(Analyzer *analyzer) const {
    analyzer->VisitExpressionStatement(this);
}
