// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by a
// license that can be found in the LICENSE file.
#include "lexer.h"

void manda::lexer::scan()
{
    int line = yylineno;
    int col = 0;
    int type;

    while ((type = yylex()) != 0) {
        // TODO: Handle whitespace
        token t = {static_cast<token_type>(type), YYText(), line, col};
        col += t.text.length();
    }
}

manda::lexer::lexer(std::string text)
        : m_input(std::istringstream(text))
{
    switch_streams(&m_input, &m_output);
}

const std::vector<manda::token> &manda::lexer::tokens() const
{
    return m_tokens;
}
