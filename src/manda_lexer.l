%{
#include <string.h>
%}

DECIMAL [0-9]+(\.[0-9]+)?
%%

{DECIMAL} { yylval.text = strdup(yytext); return T_DECIMAL;};