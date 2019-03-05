%{
#include <scanner.hpp>
#define YY_DECL int mandac::Scanner::scan()
%}

%option reentrant batch stack noyywrap

id [A-Za-z_][A-Za-z0-9_]*

%%

%{
using namespace mandac::TokenType;
%}

\n          { newline(); }
[\r\t ]     { whitespace(); }
=>          { add(arrow, yytext); }
:           { add(colon, yytext); }
\.          { add(dot, yytext); }
{           { add(lCurly, yytext); }
}           { add(rCurly, yytext); }
\(          { add(lParen, yytext); }
\)          { add(rParen, yytext); }
\[          { add(lBracket, yytext); }
\]          { add(rBracket, yytext); }
fn          { add(fn, yytext); }
with        { add(with, yytext); }
{id}        { add(id, yytext); }
.           { addError(yytext); }

%%