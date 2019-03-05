%{
#include <scanner.hpp>
#define YY_DECL int mandac::Scanner::scan()
%}

%option reentrant batch stack noyywrap

%%

%{
using namespace mandac::TokenType;
%}

\( { add(lParen, yytext); }

%%