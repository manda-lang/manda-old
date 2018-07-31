// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "../manda_src.h"

using namespace manda;

manda::NumberLiteralNode::NumberLiteralNode(const manda::Token *token) {
    this->token = token;
}

manda::NumberLiteralNode::~NumberLiteralNode() {
    delete token;
}

const manda::Token *manda::NumberLiteralNode::GetToken() const {
    return token;
}

const manda::SourceSpan *manda::NumberLiteralNode::GetSourceSpan() const {
    return token->GetSourceSpan();
}

bool manda::NumberLiteralNode::HasConstantValue() {
    return true;
}

Object *NumberLiteralNode::AcceptAnalyzer(Analyzer *analyzer) const {
    return analyzer->VisitNumberLiteral(this);
}
