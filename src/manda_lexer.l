%{
#include <manda/ast.h>
#include "manda_parser.h"
#include <string.h>
%}

%option noyywrap
%option reentrant
%option bison-bridge

DECIMAL [0-9]+(\.[0-9]+)?
WHITESPACE [ \t\r\n]+
%%

{DECIMAL} { yylval->text = strdup(yytext); return T_DECIMAL;}
{WHITESPACE} ;
