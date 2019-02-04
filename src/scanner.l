%option c++
%option yylineno
%option prefix="MandaBase"

%%

[ \n\r\t] { return T_WHITESPACE; }

%%