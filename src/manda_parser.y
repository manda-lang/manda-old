%{
#include <manda/ast.h>
#include <stdio.h>
#include <stdlib.h>

extern int yylex(void* yylval, BisonLocation location, manda_parser_context_t* ctx);
extern int yyparse();
extern FILE* yyin;

void yyerror(BisonLocation location, manda_parser_context_t* ctx, const char *s);
%}

%define api.pure full
%locations
%param {manda_parser_context_t *ctx}

%union {
    manda_program_t* program;
    manda_statement_t *statement;
    manda_expression_t *expression;
    manda_literal_t *literal;
    manda_linked_list_t *linked_list;
    manda_source_location_t location;
    const char *text;
}

%token<literal> T_DECIMAL

%type <program> program
%type <linked_list> statement_list
%type <statement> statement
%type <expression> expression
%type<literal> literal
%type<literal> decimal

%start program

%%

program:
    statement_list {
        $$ = (manda_program_t*) malloc(sizeof(manda_program_t));

        if ($$ != NULL) {
            $$->statements = $1;
        }

        ctx->program = $$;
    }
;

statement_list:
    statement { $$ = manda_new_linked_list(); manda_linked_list_push_back($$, $1); }
    | statement_list statement { $$ = $1; manda_linked_list_push_back($1, $2); }
;

statement:
    expression { $$ = manda_new_statement(MANDA_STATEMENT_EXPRESSION); if ($$ != NULL) $$->expression = $1; }
;

expression:
    literal { $$ = manda_new_expression(MANDA_EXPRESSION_LITERAL); if ($$ != NULL) $$->literal = $1; }
;

literal:
    decimal { $$ = $1; }
;

decimal: T_DECIMAL { $$ = manda_new_literal(MANDA_LITERAL_DECIMAL, $1->text, &@1); };