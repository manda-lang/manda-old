%{
#include <manda/ast.h>
#include <string.h>
#include "manda_parser.h"
%}

%option noyywrap
%option reentrant
%option bison-bridge

DECIMAL [0-9]+(\.[0-9]+)?
%%

{DECIMAL} { yylval->text = strdup(yytext); return T_DECIMAL;}
