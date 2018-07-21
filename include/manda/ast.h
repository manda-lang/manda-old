// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_AST_H
#define MANDA_AST_H

#include "linked_list.h"

struct _manda_expression_ast;
struct _manda_literal_ast;

typedef struct _manda_expression_ast manda_expression_t;
typedef struct _manda_literal_ast manda_literal_t;

typedef enum
{
    MANDA_DIRECTIVE_IMPORT,
    MANDA_DIRECTIVE_WITH,
} manda_directive_type;

typedef struct
{
    manda_directive_type type;
} manda_directive_t;

typedef enum
{
    MANDA_STATEMENT_FUNCTION_DECLARATION,
    MANDA_STATEMENT_EXPRESSION,
    MANDA_STATEMENT_RETURN,
} manda_statement_type;

typedef struct
{
    manda_statement_type type;
    manda_expression_t *expression;
} manda_statement_t;

typedef enum
{
    MANDA_EXPRESSION_BINARY,
    MANDA_EXPRESSION_LITERAL
} manda_expression_type;

struct _manda_expression_ast
{
    manda_expression_type type;
    manda_literal_t *literal;
};

typedef enum
{
    MANDA_LITERAL_NUM,
    MANDA_LITERAL_STRING
} manda_literal_type;

struct _manda_literal_ast
{
    manda_literal_type type;
    char *text;
};

typedef struct
{
    manda_linked_list_t *directives;
    manda_linked_list_t *statements;
} manda_program_t;

#endif //MANDA_AST_H
