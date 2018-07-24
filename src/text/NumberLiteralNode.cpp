// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "../runtime/runtime.h"
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

jit_value_t NumberLiteralNode::acceptInterpreter(Interpreter *interpreter) {
    return interpreter->VisitNumberLiteral(this);
}