// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_LEXER_H
#define MANDA_LEXER_H

#include <istream>
#include <unordered_map>
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
        Lexer();

        const std::vector<Error *> &GetErrors() const;

        const std::vector<Token *> &GetTokens() const;

        void Scan(std::string &sourceText, std::string &sourceUri);

    private:
        std::unordered_map<std::string, Token::TokenType> keywords;
        std::vector<std::pair<std::regex, Token::TokenType>> patterns;
        std::vector<Error *> errors;
        std::vector<Token *> tokens;
    };
}

#endif //MANDA_LEXER_H
