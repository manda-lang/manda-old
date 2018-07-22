// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <manda/ast.h>
#include <manda/manda.h>

void yyerror(BisonLocation location, manda_parser_context_t* ctx, const char *s) {
    // TODO: better way?
    printf("Error lolfao: %s\n", s);
}

int manda_run(manda_options_t options) {
    // TODO: Actually do something
    manda_parser_context_t *parser_context = manda_parse(options);
    return 0;
}