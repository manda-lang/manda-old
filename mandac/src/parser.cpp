// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by a
// license that can be found in the LICENSE file.
#include "parser.hpp"

mandac::Parser::Parser(const std::vector<mandac::Token> &tokens) : tokens(tokens)
{
    index = -1;
}

bool mandac::Parser::next(mandac::TokenType::Enum type)
{
    if (done()) {
        return false;
    } else {
        auto peek = tokens.at(static_cast<unsigned long>(index + 1));
        if (peek.type == type) {
            current = peek;
            index++;
        } else {
            return false;
        }
    }
}

bool mandac::Parser::done()
{
    return index >= tokens.size();
}
