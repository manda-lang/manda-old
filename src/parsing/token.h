// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_TOKEN_H
#define MANDA_TOKEN_H

#include "string_scanner.h"

namespace manda::parsing
{
    struct token
    {
        enum token_type
        {
            // Symbols
            COLON,
            COMMA,
            LCURLY,
            RCURLY,
            LPAREN,
            RPAREN,

            // Keywords
            KW_ABSTRACT,
            KW_CLASS,
                    KW_FN,
            KW_VAR,

            // Operators
                    EQUALS,

            // Values
                    INT,
            ID,
        };

        token_type type;
        source_span span;
    };
}

#endif //MANDA_TOKEN_H
