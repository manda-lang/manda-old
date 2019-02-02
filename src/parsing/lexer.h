// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_SCANNER_H
#define MANDA_SCANNER_H

#include <unordered_map>
#include <string>
#include <vector>
#include "token.h"

namespace manda::parsing
{
    struct syntax_error
    {
        enum syntax_error_severity
        {
            ERROR,
            WARNING,
            HINT,
            INFO
        };

        syntax_error_severity severity;
        source_span span;
        std::string message;
    };

    class lexer
    {
    public:
        explicit lexer(string_scanner &scanner);

        const std::vector<syntax_error> errors() const;

        const std::vector<token> tokens() const;

        void scan();

    private:
        class lexer_pattern
        {
        public:
            lexer_pattern(std::regex rgx);
            lexer_pattern(std::string str);

            bool is_regex() const;

            const std::regex & as_regex() const;

            const std::string & as_string() const;

        private:
            bool m_is_match;
            std::regex m_rgx;
            std::string m_str;
        };

        std::vector<syntax_error> m_errors;
        std::vector<token> m_tokens;
        std::vector<std::pair<token::token_type, lexer_pattern>> patterns;
        string_scanner &scanner;
    };
}


#endif //MANDA_SCANNER_H
