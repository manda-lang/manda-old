// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <manda/ast.h>
#include <manda_parser.h>
#include <manda_lexer.h>
#include <manda/struct.h>

manda_parser_context_t *manda_parse(manda_options_t options) {
    manda_parser_context_t *ctx = (manda_parser_context_t *) malloc(sizeof(manda_parser_context_t));

    if (ctx != NULL) {
        yyscan_t scanner;
        yylex_init(&scanner);

        if (options.run_from_text == 1) {
            yy_scan_string(options.text, scanner);
        } else {
            yyset_in(options.input_file, scanner);
        }


        int result = yyparse(ctx) != 0;

        if (result != 0) {
            // TODO: Better way to handle error?
            yylex_destroy(scanner);
            free(ctx);
            return NULL;
        } else {

            yylex_destroy(scanner);
        }

    }

    return ctx;
}