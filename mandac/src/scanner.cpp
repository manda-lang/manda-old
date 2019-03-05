// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by a
// license that can be found in the LICENSE file.
#include "scanner.hpp"

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
