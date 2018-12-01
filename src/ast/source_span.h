// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_SOURCE_SPAN_H
#define PROJECT_SOURCE_SPAN_H

#include "source_location.h"

namespace manda
{
    class SourceSpan
    {
    public:
        SourceSpan(const SourceLocation &start, const SourceLocation &end);

        const SourceLocation start;
        const SourceLocation end;

        SourceSpan &operator+(const SourceSpan &other);
    };
}

#endif //PROJECT_SOURCE_SPAN_H
