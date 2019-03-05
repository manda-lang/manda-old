// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by a
// license that can be found in the LICENSE file.
#include <lexer.hpp>
#include "scanner.hpp"

mandac::Scanner::Scanner()
{
    manda_flex_lex_init(yyscanner);
}

mandac::Scanner::~Scanner()
{
    manda_flex_lex_destroy(yyscanner);
}

const std::vector<mandac::Token> &mandac::Scanner::getTokens() const
{
    return tokens;
}

void mandac::Scanner::scan(const std::string &text)
{
    manda_flex__scan_string(text.c_str(), yyscanner);
    scan();
}

void mandac::Scanner::add(mandac::TokenType::Enum type, std::string text)
{
    // TODO: Flush errors
    // TODO: Add tokens
    // TODO: Increment lines, etc.
}

void mandac::Scanner::addError(char ch)
{
    // TODO: Add to error buf
}

void mandac::Scanner::newline()
{
    // TODO: Advance by one line
}

void mandac::Scanner::whitespace()
{
    // TODO: Advance by one column
}
