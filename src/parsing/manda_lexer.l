%{

#include <string>
#include <parser.hpp>

%}

%option noyywrap

%%

[ \n\r\t]   ; // ignore whitespace


\/\/[^\n]*  {yylval.sval = strdup(yytext); return T_COMMENT;}
"=>"        {return T_ARROW;}
";"         {return T_COLON;}
","         {return T_COMMA;}
"{"         {return T_LCURLY;}
"}"         {return T_RCURLY;}
"("         {return T_LPAREN;}
")"         {return T_RPAREN;}

[A-Za-z][A-Za-z0-9_]*   {yylval.sval = strdup(yytext); return T_ID;}

%%