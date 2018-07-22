// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <manda/ast.h>
#include <manda_parser.h>

manda_parser_context_t *manda_parse(manda_options_t options) {
    manda_parser_context_t *ctx = (manda_parser_context_t *) malloc(sizeof(manda_parser_context_t));

    if (ctx != NULL) {
        if (yyparse(ctx) != 0) {
            // TODO: Better way to handle error?
            free(ctx);
            return NULL;
        }
    }

    return ctx;
}