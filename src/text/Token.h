// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_TOKEN_H
#define MANDA_TOKEN_H

#include <string>
#include "SourceSpan.h"

namespace manda
{
    class Token
    {
    public:
        enum TokenType
        {
            DECIMAL
        };

        Token(TokenType type, const std::string &text, const SourceSpan *span);
        const SourceSpan *GetSourceSpan() const;
        TokenType GetType() const;
        const std::string& GetText() const;

    private:
        TokenType type;
        std::string text;
        const SourceSpan *sourceSpan;
    };
}

#endif //MANDA_TOKEN_H
