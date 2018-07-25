// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "../manda_src.h"

manda::VariableDeclarationStatementNode::VariableDeclarationStatementNode(const manda::Token *let,
                                                        manda::SimpleIdentifierNode *identifier,
                                                        const manda::Token *equals,
                                                        manda::ExpressionNode *initializer) {
    this->let = let;
    this->identifier = identifier;
    this->equals = equals;
    this->initializer = initializer;
}

manda::VariableDeclarationStatementNode::~VariableDeclarationStatementNode() {
    delete let;
    delete identifier;
    delete equals;
    delete initializer;
}

const manda::Token *manda::VariableDeclarationStatementNode::GetLet() const {
    return let;
}

manda::SimpleIdentifierNode *manda::VariableDeclarationStatementNode::GetIdentifier() const {
    return identifier;
}

const manda::Token *manda::VariableDeclarationStatementNode::GetEquals() const {
    return equals;
}

manda::ExpressionNode *manda::VariableDeclarationStatementNode::GetInitializer() const {
    return initializer;
}

const manda::SourceSpan *manda::VariableDeclarationStatementNode::GetSourceSpan() const {
    return identifier->GetSourceSpan();
}

bool manda::VariableDeclarationStatementNode::HasFunctionDeclaration() const {
    return false;
}

bool manda::VariableDeclarationStatementNode::IsExpressionStatement() const {
    return false;
}

void manda::VariableDeclarationStatementNode::AcceptAnalyzer(manda::Analyzer *analyzer) {
    analyzer->VisitVariableDeclarationStatement(this);
}
