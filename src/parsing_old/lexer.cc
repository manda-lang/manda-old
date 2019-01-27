// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "lexer.h"

manda::parsing::lexer::lexer(manda::parsing::string_scanner &scanner) : scanner(scanner) {

}

const std::vector<manda::parsing::syntax_error> manda::parsing::lexer::errors() const {
    return m_errors;
}

void manda::parsing::lexer::scan() {
    // TODO: Actually do something here
}
