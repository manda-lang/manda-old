// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "lexer.h"

using namespace manda::parsing;

manda::parsing::lexer::lexer(manda::parsing::string_scanner &scanner) : scanner(scanner) {
    // Symbols
    patterns.emplace_back(token::COLON, ":");
    patterns.emplace_back(token::COMMA, ",");
    patterns.emplace_back(token::LCURLY, "{");
    patterns.emplace_back(token::RCURLY, "}");
    patterns.emplace_back(token::LPAREN, "(");
    patterns.emplace_back(token::RPAREN, ")");

    // Keywords
    patterns.emplace_back(token::KW_ABSTRACT, "abstract");
    patterns.emplace_back(token::KW_CLASS, "class");
    patterns.emplace_back(token::KW_FN, "fn");
    patterns.emplace_back(token::KW_VAR, "var");

    // Operators
    patterns.emplace_back(token::EQUALS, "=");
}

const std::vector<manda::parsing::syntax_error> manda::parsing::lexer::errors() const {
    return m_errors;
}

const std::vector<token> lexer::tokens() const {
    return m_tokens;
}

void manda::parsing::lexer::scan() {
    while (!scanner.done()) {
        std::vector<token> provisional;

        for (auto &pair: patterns) {
            if (scanner.matches(pair.second)) {
                token tok = {pair.first, scanner.last_span()};
                provisional.push_back(tok);
            }

            // TODO: Parse values
        }

        throw provisional.size();

        // TODO: Sort tokens
        if (provisional.empty()) {
            // TODO: Better errors
            scanner.read();
            auto span = scanner.last_span();
            syntax_error e{syntax_error::ERROR, span, "Unexpected text"};
            m_errors.push_back(e);
        } else {
            auto token = provisional.front();
            m_tokens.push_back(token);

            for (unsigned long i = 0; i < token.span.length(); i++) {
                scanner.read();
            }
        }
    }
}
