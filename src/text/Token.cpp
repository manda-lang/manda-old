// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "Token.h"

manda::Token::Token(manda::Token::TokenType type, const std::string &text, const SourceSpan *span) {
    this->type = type;
    this->text += text;
    this->sourceSpan = span;
}

const manda::SourceSpan *manda::Token::GetSourceSpan() const {
    return sourceSpan;
}

manda::Token::TokenType manda::Token::GetType() const {
    return type;
}

const std::string &manda::Token::GetText() const {
    return text;
}
