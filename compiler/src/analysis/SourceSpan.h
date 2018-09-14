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
    class SourceSpan
    {
    public:
        SourceSpan(std::string text, int line, int charPositionInLine);

        const std::string &GetText() const;

        int GetLine() const;

        int GetCharPositionInLine() const;

        static SourceSpan fromParserRuleContext(antlr4::ParserRuleContext *ctx);

    private:
        const std::string text;
        int line;
        int charPositionInLine;
    };
}

#endif //PROJECT_SOURCESPAN_H
