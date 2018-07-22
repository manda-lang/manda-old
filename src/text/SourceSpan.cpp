// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <string>
#include "SourceSpan.h"

manda::SourceSpan::SourceSpan(std::string &sourceUri, int64_t line, int64_t column) {
    this->sourceUri += sourceUri;
    this->line = line;
    this->column = column;
}

const std::string &manda::SourceSpan::GetSourceUri() const {
    return sourceUri;
}

int64_t manda::SourceSpan::GetLine() const {
    return line;
}

int64_t manda::SourceSpan::GetColumn() const {
    return column;
}
