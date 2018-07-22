// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_AST_H
#define MANDA_AST_H
#define YYLTYPE_IS_DECLARED
//#include <manda_parser.h>
#include "linked_list.h"
#include "struct.h"

struct _manda_expression_ast;
struct _manda_literal_ast;

typedef struct
{
    int first_line;
    int first_column;
    int last_line;
    int last_column;
} YYLTYPE;

typedef YYLTYPE *BisonLocation;
typedef struct _manda_expression_ast manda_expression_t;
typedef struct _manda_literal_ast manda_literal_t;

typedef struct
{
    const char *source_uri;
    int line;
    int column;
} manda_source_location_t;

typedef enum
{
    MANDA_SEVERITY_ERROR, MANDA_SEVERITY_WARNING, MANDA_SEVERITY_INFO, MANDA_SEVERITY_HINT
} manda_error_severity;

typedef struct
{
    manda_error_severity severity;
    const char *message;
    manda_source_location_t location;
} manda_error_t;

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
    MANDA_LITERAL_DECIMAL,
    MANDA_LITERAL_STRING
} manda_literal_type;

struct _manda_literal_ast
{
    manda_literal_type type;
    const char *text;
    manda_source_location_t location;
};

typedef struct
{
    manda_linked_list_t *directives;
    manda_linked_list_t *statements;
} manda_program_t;

typedef struct
{
    manda_program_t *program;
    manda_linked_list_t *errors;
    const char *source_uri;
} manda_parser_context_t;

manda_parser_context_t *manda_parse(manda_options_t options);

manda_statement_t *manda_new_statement(manda_statement_type type);

manda_expression_t *manda_new_expression(manda_expression_type type);

manda_literal_t *manda_new_literal(manda_literal_type type, const char *text, BisonLocation location);

#endif //MANDA_AST_H
