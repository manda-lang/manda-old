// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_LEXER_H
#define MANDA_LEXER_H

#include <istream>
#include <string>
#include <vector>
#include "Error.h"
#include "Token.h"

namespace manda
{
    class Lexer
    {
    public:
        std::vector<Error *> errors;
        std::vector<Token *> tokens;

        void Scan(std::istream &stream, std::string& sourceUri);
    };
}

#endif //MANDA_LEXER_H
