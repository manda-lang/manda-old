// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_TOKEN_H
#define PROJECT_TOKEN_H

#include <string>
#include "source_span.h"
#include "token_type.h"

namespace manda
{
    struct Token
    {
        std::string text;
        SourceSpan span;
        TokenType type;
    };
}


#endif //PROJECT_TOKEN_H
