%{
#include <scanner.hpp>
#define YY_DECL int mandac::Scanner::scan()
//#define YY_DECL_OLD int mandaflex_scan(mandac::Scanner* scanner, yyscan_t yyscanner)
%}

%option reentrant

%%

'c' {}

%%