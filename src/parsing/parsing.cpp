// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <parser.hpp>
#include "parsing.h"

void yy_scan_string(const char *str);

int manda::parse_ast(const std::string &text) {
    yy_scan_string(text.c_str());
    return yyparse();
}
