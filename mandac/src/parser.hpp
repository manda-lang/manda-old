// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by a
// license that can be found in the LICENSE file.
#ifndef MANDA_PARSER_HPP
#define MANDA_PARSER_HPP

#include <vector>
#include "scanner.hpp"

namespace mandac
{
    class Parser
    {
    public:
        Parser(const std::vector<Token>& tokens);

    private:
        const std::vector<Token>& tokens;
    };
}

#endif //MANDA_PARSER_HPP
