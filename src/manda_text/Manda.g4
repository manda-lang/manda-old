grammar Manda;

WS: [ \r\t\n]+ -> skip;

program: directive* statement* comment*;

comment:
    DOC_COMMENT #DocComment
    | SINGLE_LINE_COMMENT #SingleLineComment
;

directive:
    comment* 'import' ID #ImportDirective
    | comment* 'with' ID #WithDirective
    | comment* 'type' comment* ID comment* '=' type #TypedefDirective
;

statement:
    expression #ExpressionStatement
    | comment* 'return' expression #ReturnStatement
    | variableModifier comment* ID typeAnnotation? comment* '=' expression #VariableDeclarationStatement
;

variableModifier:
    comment* 'let' #LetModifier
    | comment* 'var' #VarModifier
;

type:
    comment* ID typeParameterList? #IdentifierType
    | type comment* '|' type #UnionType
    | comment* '{' ((structTypeField comment* ',')* structTypeField)? comment* '}' #StructType
    | comment* '(' type comment* ')' #ParenthesizedType
;

structTypeField: comment* ID comment* ':' type;

typeAnnotation: comment* ':' type;

typeParameter:
    comment* ID #IdentifierTypeParameter
    | comment* ID comment* 'extends' type #ExtendsTypeParameter
;

typeParameterList:
    comment* '<' ((typeParameter comment* ',' )* typeParameter) comment* '>'
;

typeArgumentList:
    '<' ((type ',' )* type)? '>'
;

argumentList:
    comment* '(' ((expression comment* ',')* expression)? comment* ')' #PositionalParameterList
    | comment* '(' ((namedArgument comment* ',')* namedArgument) comment* ')' #NamedParameterList
    | comment* '(' ((expression comment* ',')* expression) comment* ',' ((namedArgument comment* ',')* namedArgument) comment* ')' #MixedParameterList
;

namedArgument: comment* ID comment* ':' expression;

expression:
    comment* ID #IdExpression
    | comment* literal #LiteralExpression
    | expression comment* '.' comment* ID #MemberExpression
    | target=expression typeArgumentList? argumentList #CallExpression
    | expression comment* 'as' comment* type #AsExpression
;

literal:
    string #StringLiteral
    | DECIMAL #DecimalLiteral
    | BINARY #BinaryLiteral
    | HEX #HexLiteral
    | OCTAL #OctalLiteral
;

string: 'r'? SINGLE_QUOTED_STRING;

DOC_COMMENT: '///' ((~'\n'))+;
SINGLE_LINE_COMMENT: '//' ((~'\n'))+;
SINGLE_QUOTED_STRING: '\'' ((~'\'') | ('\\\'') )* '\'';
DECIMAL: [0-9]+ ('.' [0-9]+)?;
BINARY: '0b' [0-1]+;
HEX: '0x' [A-Fa-f0-9]+;
OCTAL: '0o' [0-7]+;
ID: [A-Za-z_][A-Za-z0-9_]*;