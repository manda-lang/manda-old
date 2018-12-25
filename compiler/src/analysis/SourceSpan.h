// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_SOURCESPAN_H
#define PROJECT_SOURCESPAN_H

#include <antlr4-runtime/antlr4-runtime.h>
#include <string>

namespace manda
{
    struct SourceSpan
    {
        SourceSpan(const std::string &text, size_t line, size_t charPositionInLine);

        explicit SourceSpan(const antlr4::ParserRuleContext &ctx);

        const std::string text;
        size_t line;
        size_t charPositionInLine;
    };
}

#endif //PROJECT_SOURCESPAN_H
