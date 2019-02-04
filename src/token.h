// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by a
// license that can be found in the LICENSE file.
#ifndef MANDA_TOKEN_H
#define MANDA_TOKEN_H

#include <string>

namespace manda
{
    enum token_type
    {

    };

    struct token
    {
        token_type type;
        std::string text;
        int line;
        int column;
    };

}

#endif //MANDA_TOKEN_H
