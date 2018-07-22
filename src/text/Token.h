// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_TOKEN_H
#define MANDA_TOKEN_H

#include <regex>
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

        explicit Token(TokenType type, const SourceSpan *span);
        ~Token();
        const SourceSpan *GetSourceSpan() const;
        TokenType GetType() const;

        bool HasMatch() const;

        const std::smatch &GetMatch() const;

        void SetMatch(std::smatch &match);
    private:
        bool hasMatch;
        std::smatch match;
        TokenType type;
        const SourceSpan *sourceSpan;
    };
}

#endif //MANDA_TOKEN_H
