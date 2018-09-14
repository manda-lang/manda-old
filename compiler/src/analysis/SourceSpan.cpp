// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "SourceSpan.h"

#include <utility>
#include <antlr4-runtime/ParserRuleContext.h>

manda::SourceSpan::SourceSpan(std::string text, int line, int charPositionInLine)
        : text(std::move(text)) {
    this->line = line;
    this->charPositionInLine = charPositionInLine;
}

const std::string &manda::SourceSpan::GetText() const {
    return text;
}

int manda::SourceSpan::GetLine() const {
    return line;
}

int manda::SourceSpan::GetCharPositionInLine() const {
    return charPositionInLine;
}

manda::SourceSpan manda::SourceSpan::fromParserRuleContext(antlr4::ParserRuleContext *ctx) {
    auto *token = ctx->start;
    return SourceSpan(ctx->getText(), token->getLine(), token->getCharPositionInLine());
}
