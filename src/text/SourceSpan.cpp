// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <sstream>
#include <string>
#include "SourceSpan.h"

manda::SourceSpan::SourceSpan(std::string &sourceUri, std::string &text, int64_t line, int64_t column) {
    this->sourceUri += sourceUri;
    this->text += text;
    this->length = (int64_t) text.length();
    this->line = line;
    this->column = column;
}

manda::SourceSpan::SourceSpan(const manda::SourceSpan *other) {
    this->sourceUri += other->sourceUri;
    this->text += other->text;
    this->length = (int64_t) other->text.length();
    this->line = other->line;
    this->column = other->column;
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

const std::string manda::SourceSpan::GetToolString() const {
    std::ostringstream ss;
    ss << sourceUri << ":" << line << ":" << column;
    return ss.str();
}

const std::string manda::SourceSpan::Highlight(std::string &sourceText) const {
    std::ostringstream context;
    context << GetContext(sourceText) << std::endl;

    for (int64_t i = 0; i < column; i++) {
        context << ' ';
    }

    for (int64_t i = 0; i < length; i++) {
        context << '^';
    }

    return context.str();
}

const std::string manda::SourceSpan::GetContext(std::string &sourceText) const {
    std::istringstream ss(sourceText);
    std::string s;

    //for performance
    s.reserve(255);

    //skip N lines
    for(int i = 0; i < line; ++i)
        std::getline(ss, s);

    std::getline(ss,s);
    return s;
}

const std::string &manda::SourceSpan::GetText() const {
    return text;
}

int64_t manda::SourceSpan::GetLength() const {
    return length;
}