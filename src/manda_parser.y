%{
#include <manda/ast.h>
#include <stdio.h>
#include <stdlib.h>

extern int yylex();
//extern int yyparse();
extern FILE* yyin;

void yyerror(const char *s);
%}

%union {
    manda_expression_t *expression;
    manda_literal_t *literal;
    const char *text;
    manda_source_location_t source_location;
}

%token<literal> T_DECIMAL

%type <expression> expression
%type<literal> literal
%type<literal> decimal

%start expression

%%

expression:
    literal { $$ = manda_new_expression(MANDA_EXPRESSION_LITERAL); if ($$ != NULL) $$->literal = $1; }
;

literal:
    decimal { $$ = $1; }
;

decimal: T_DECIMAL { $$ = manda_new_literal(MANDA_LITERAL_DECIMAL, $1->text, &@1); };