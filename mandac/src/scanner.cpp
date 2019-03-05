// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by a
// license that can be found in the LICENSE file.
#include <lexer.hpp>
#include "scanner.hpp"

mandac::Scanner::Scanner(const std::string &sourceUrl) : sourceUrl(sourceUrl)
{
    line = 1;
    column = 0;
    manda_flex_lex_init(&yyscanner);
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

void mandac::Scanner::scan(FILE *file)
{
    manda_flex_set_in(file, yyscanner);
    scan();
}

void mandac::Scanner::add(mandac::TokenType::Enum type, std::string text)
{
    // TODO: Flush errors
    Token token = {type, sourceUrl, text, line, column};
    tokens.push_back(token);
    column += text.length();
}

void mandac::Scanner::addError(const std::string &text)
{
    // TODO: Add to error buf
}

void mandac::Scanner::newline()
{
    line++;
    column = 0;
}

void mandac::Scanner::whitespace()
{
    column++;
}
