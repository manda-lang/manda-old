#include <utility>

// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "lexer.h"

using namespace manda::parsing;

lexer::lexer_pattern::lexer_pattern(std::regex rgx) {
    m_rgx = std::move(rgx);
    m_is_match = true;
}

lexer::lexer_pattern::lexer_pattern(std::string str) {
    m_str = std::move(str);
    m_is_match = false;
}

bool lexer::lexer_pattern::is_regex() const {
    return false;
}

const std::regex & lexer::lexer_pattern::as_regex() const {
    return m_rgx;
}

const std::string & lexer::lexer_pattern::as_string() const {
    return m_str;
}

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
    patterns.emplace_back(token::KW_VAR, std::regex("y[A-Za-z]s"));

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
            auto pattern = pair.second;
            auto matches = pattern.is_regex()
                           ? scanner.matches(pattern.as_regex())
                           : scanner.matches(
                            pattern.as_string());

            if (matches) {
                if (scanner.matches(pattern.as_string())) {
                    token tok = {pair.first, scanner.last_span()};
                    provisional.push_back(tok);
                }
            }

            // TODO: Parse values
        }

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
