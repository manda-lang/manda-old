// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by a
// license that can be found in the LICENSE file.
#ifndef MANDA_TOKEN_HPP
#define MANDA_TOKEN_HPP

#include <string>

namespace mandac
{
    namespace TokenType
    {
        enum Enum
        {
            arrow, colon, dot, lCurly, rCurly, lParen, rParen,
            lBracket, rBracket, fn, with, id
        };
    }

    struct Token
    {
        TokenType::Enum type;
        std::string sourceUrl, text;
        unsigned long line, column;
    };
}


#endif //MANDA_TOKEN_HPP
