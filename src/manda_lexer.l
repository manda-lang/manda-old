%{
#include <manda/ast.h>
#include <string.h>
%}

DECIMAL [0-9]+(\.[0-9]+)?

void capture_line_info() {
    yylval.text = strdup(yytext);
}
%%

{DECIMAL} { capture_line_info(); return T_DECIMAL;}