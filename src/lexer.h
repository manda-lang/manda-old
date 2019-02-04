// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by a
// license that can be found in the LICENSE file.
#ifndef MANDA_LEXER_H
#define MANDA_LEXER_H

#include <sstream>
#include <scanner.hpp>
#include <vector>
#include "token.h"

namespace manda
{
    class lexer : public MandaBaseFlexLexer
    {
    public:
        lexer(std::string text);

        const std::vector<manda::token> &tokens() const;

        void scan();

    private:
        int col;
        std::istringstream m_input;
        std::ostringstream m_output;
        std::vector<token> m_tokens;
    };
}


#endif //MANDA_LEXER_H
