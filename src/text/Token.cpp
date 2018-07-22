// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "Token.h"

manda::Token::Token(manda::Token::TokenType type, const SourceSpan *span) {
    this->type = type;
    this->sourceSpan = span;
    hasMatch = false;
}

const manda::SourceSpan *manda::Token::GetSourceSpan() const {
    return sourceSpan;
}

manda::Token::TokenType manda::Token::GetType() const {
    return type;
}

bool manda::Token::HasMatch() const {
    return hasMatch;
}

const std::smatch &manda::Token::GetMatch() const {
    return match;
}

void manda::Token::SetMatch(std::smatch &match) {
    this->match = match;
}

manda::Token::~Token() {
    delete sourceSpan;
}