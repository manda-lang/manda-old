%{

#include <iostream>
#include <string>

extern int yylex();
extern int yyparse();
extern FILE* yyin;

void yyerror(const char* s) {
    std::cerr << "fatal error: " << s << std::endl;
}
%}

%union {
   char* sval;
}

// Symbols
%token T_ARROW T_COLON T_COMMA T_LCURLY T_RCURLY T_LPAREN T_RPAREN

// Values
%token<sval> T_COMMENT T_ID

// Node types

%start placeholder

%%

placeholder: T_ID;