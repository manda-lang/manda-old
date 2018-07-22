// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_SOURCESPAN_H
#define MANDA_SOURCESPAN_H

#include <cstdint>

namespace manda
{
    class SourceSpan
    {
    public:
        SourceSpan(std::string &sourceUri, int64_t line, int64_t column);

        const std::string &GetSourceUri() const;
        int64_t GetLine() const;
        int64_t GetColumn() const;

    private:
        std::string sourceUri;
        int64_t line;
        int64_t column;
    };
}

#endif //MANDA_SOURCESPAN_H
