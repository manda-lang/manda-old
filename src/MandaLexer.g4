lexer grammar MandaLexer;

WS: [ \n\r\t]+ -> skip;

// Symbols
ARROW: '->';
COLON: ':';
LBRACKET: '[';
RBRACKET: ']';
LCURLY: '{';
RCURLY: '}';
LPAREN: '(';
RPAREN: ')';
TILDE: '~';
SEMI: ';';

// Operators
EQUALS: '=';

// Keywords
LET: 'let';
VAR: 'var';

// Values
ID: ([A-Za-z_]|'$') ([A-Za-z0-9_]|'$')*;