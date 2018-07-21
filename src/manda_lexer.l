%{
#include <manda/ast.h>
#include <string.h>
#include "manda_parser.h"
%}

%option reentrant
%option bison-bridge

DECIMAL [0-9]+(\.[0-9]+)?

void capture_line_info() {
    yylval.text = strdup(yytext);
}
%%

{DECIMAL} { capture_line_info(); return T_DECIMAL;}