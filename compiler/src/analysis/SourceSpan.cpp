// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "SourceSpan.h"

#include <utility>
#include <antlr4-runtime/ParserRuleContext.h>

manda::SourceSpan::SourceSpan(const std::string &text, size_t line, size_t charPositionInLine)
        : text(text), line(line), charPositionInLine(charPositionInLine) {
    this->line = line;
    this->charPositionInLine = charPositionInLine;
}

manda::SourceSpan::SourceSpan(const antlr4::ParserRuleContext &ctx)
        : text(ctx.start->getText()),
          line(ctx.start->getLine()),
          charPositionInLine(ctx.start->getCharPositionInLine()) {
}
