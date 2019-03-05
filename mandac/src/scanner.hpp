// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by a
// license that can be found in the LICENSE file.
#ifndef MANDA_SCANNER_HPP
#define MANDA_SCANNER_HPP

#include <string>
#include <vector>
#include "token.hpp"

namespace mandac
{
    class Scanner
    {
    public:
        Scanner();

        ~Scanner();

        void scan(const std::string &text);

        void add(TokenType::Enum type, std::string text);

        void addError(char ch);

        void newline();

        void whitespace();

    private:
        void **yyscanner;

        int scan();
    };
}

#endif //MANDA_SCANNER_HPP
