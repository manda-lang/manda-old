// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_SOURCESPAN_H
#define MANDA_SOURCESPAN_H

#include <cstdint>
#include <string>

namespace manda
{
    class SourceSpan
    {
    public:
        explicit SourceSpan(std::string &sourceUri, std::string &text, int64_t line, int64_t column);

        explicit SourceSpan(const SourceSpan *other);

        const std::string &GetSourceUri() const;

        const std::string &GetText() const;

        int64_t GetLength() const;

        int64_t GetLine() const;

        int64_t GetColumn() const;

        const std::string GetToolString() const;

        const std::string GetContext(std::string &sourceText) const;

        const std::string Highlight(std::string &sourceText) const;

    private:
        std::string sourceUri;
        std::string text;
        int64_t length;
        int64_t line;
        int64_t column;
    };
}

#endif //MANDA_SOURCESPAN_H
