// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "source_span.h"

manda::SourceSpan::SourceSpan
        (const manda::SourceLocation &start, const manda::SourceLocation &end)
        : start(start), end(end) {}

manda::SourceSpan &manda::SourceSpan::operator+(const manda::SourceSpan &other) {
    SourceSpan out(start, other.end);
    return out;
}
