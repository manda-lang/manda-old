// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <manda/ast.h>
#include <manda_parser.h>

manda_expression_t *manda_new_expression(manda_expression_type type) {
    manda_expression_t *expression = malloc(sizeof(manda_expression_t));

    if (expression != NULL) {
        expression->type = type;
    }

    return expression;
}

manda_literal_t *manda_new_literal(manda_literal_type type, const char *text, BisonLocation location) {
    manda_literal_t *literal = malloc(sizeof(manda_literal_t));

    if (literal != NULL) {
        literal->type = type;
        literal->text = text;
        literal->source_location.line = location->first_line;
        literal->source_location.column = location->first_column;
    }

    return literal;
}
