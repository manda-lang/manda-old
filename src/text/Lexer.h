// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_LEXER_H
#define MANDA_LEXER_H

#include <istream>
#include <sstream>
#include <regex>
#include <string>
#include <vector>
#include "Error.h"
#include "Token.h"

namespace manda
{
    class Lexer
    {
    public:
        explicit Lexer();

        const std::vector<Error *> &GetErrors() const;

        const std::vector<Token *> &GetTokens() const;

        void Scan(std::string &sourceText, std::string &sourceUri);

    private:
        bool hasErrantText;
        int64_t errantLine, errantColumn;
        std::ostringstream errantText;
        std::vector<std::pair<std::regex, Token::TokenType>> patterns;
        std::vector<Error *> errors;
        std::vector<Token *> tokens;

        void FlushErrantText(std::string &sourceUri);
    };
}

#endif //MANDA_LEXER_H
