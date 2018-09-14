grammar Manda;

compilationUnit: directive* typeAliasDecl* funcDecl*;

directive: importDirective;

importDirective:
    'import' symbol=Identifier
;

typeAliasDecl: 'type' alias=Identifier '=' type;

funcDecl: 'func' name=Identifier parameterList ':' returnType=type functionBody;

functionBody: block;

parameterList: '(' ((parameter ',')* parameter)? ')';

parameter: propertyKeyword='property'? name=Identifier ':' type;

block:
    '=>' expr #ArrowBlock
    | ';' #EmptyBlock
    | '{' stmt* '}' #CurlyBlock
;

type:
    Identifier #IdType
    | '{' structTypeMember* '}' #StructType
    | left=type '|' + right=type #UnionType
    | '(' type ')' #ParenType
;

structTypeMember:
    'constructor' name=Identifier? parameterList functionBody #StructTypeConstructor
    | 'get' name=Identifier ':' type functionBody #StructTypeGetter
    | 'set' name=Identifier ':' type functionBody #StructTypeSetter
    | name=Identifier ':' type #StructTypeField
;

stmt:
    expr #ExprStmt
    | 'let' (varDecl ',')* varDecl #VarDeclStmt
    | 'return' expr #ReturnStmt
    | 'try' expr #TryStmt
;

varDecl: Identifier '=' expr;

expr:
    Identifier #IdentifierExpr
    | FloatLiteral #FloatExpr
    | HexLiteral #HexExpr
    | IntegerLiteral #IntegerExpr
    //| left=(FloatLiteral|IntegerLiteral) ('e'|'E') negative='-'? power=IntegerLiteral #ScientificLiteralExpr
    | '(' expr ')' #ParenExpr
;

Whitespace: [ \n\r\t] -> skip;
FloatLiteral: [0-9]+ '.' [0-9]+;
HexLiteral: '0x' [A-F0-9]+;
IntegerLiteral: [0-9]+;
Identifier: [A-Za-z_] [A-Za-z0-9_]*;