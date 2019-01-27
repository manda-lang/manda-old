// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_SCANNER_H
#define MANDA_SCANNER_H

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

        void scan();

    private:
        std::vector<syntax_error> m_errors;
        string_scanner &scanner;
    };
}


#endif //MANDA_SCANNER_H
