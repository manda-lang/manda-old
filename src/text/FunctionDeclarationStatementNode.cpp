// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "FunctionDeclarationStatementNode.h"

manda::FunctionDeclarationStatementNode::FunctionDeclarationStatementNode(manda::SimpleIdentifierNode *identifier,
                                                                          manda::FunctionSignatureNode *signature,
                                                                          manda::FunctionBodyNode *body) {
    this->identifier = identifier;
    this->signature = signature;
    this->body = body;
}

manda::FunctionDeclarationStatementNode::~FunctionDeclarationStatementNode() {
    delete identifier;
    delete signature;
    delete body;
    identifier = nullptr;
    signature = nullptr;
    body = nullptr;
}

const manda::SimpleIdentifierNode *manda::FunctionDeclarationStatementNode::GetIdentifier() const {
    return identifier;
}

const manda::FunctionSignatureNode *manda::FunctionDeclarationStatementNode::GetSignature() const {
    return signature;
}

const manda::FunctionBodyNode *manda::FunctionDeclarationStatementNode::GetBody() const {
    return body;
}

const manda::SourceSpan *manda::FunctionDeclarationStatementNode::GetSourceSpan() const {
    return identifier->GetSourceSpan();
}

bool manda::FunctionDeclarationStatementNode::HasFunctionDeclaration() const {
    return true;
}

bool manda::FunctionDeclarationStatementNode::IsExpressionStatement() const {
    return false;
}

void manda::FunctionDeclarationStatementNode::AcceptAnalyzer(manda::Analyzer *analyzer) const {
    
}
