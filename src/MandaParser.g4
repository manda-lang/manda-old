parser grammar MandaParser;

tokens {
ARROW, COLON, LBRACKET, RBRACKET, LCURLY, RCURLY, LPAREN,
RPAREN, TILDE, EQUALS, LET, VAR, ID, SEMI
}

compilation_unit: statement*;

func_decl: LET ID param_list EQUALS block;

param_list:
    param+ #PosParamList
    | named_param+ #NamedParamList
    | param+ named_param+ #MixedParamList
    | LPAREN RPAREN #UnitParamList
;

param:
    ID #RegParam
    | LPAREN param (COLON type)? RPAREN #ParenRegParam
;

named_param:
    TILDE ID #RegNamedParam
    | LPAREN named_param (COLON type)? RPAREN #ParenRegNamedParam
;

type:
    ID #NamedType
;

block:  (statement SEMI)* return_value=expr;

statement:
    expr #ExprStmt
    | (LET | VAR) ID EQUALS expr #VarStmt
    | LET LPAREN RPAREN EQUALS block #ImpureStmt
    | func_decl #FuncDeclStmt
;

expr:
    ID #IdExpr
    | target=expr arg_list #CallExpr
    | LPAREN expr RPAREN #ParenExpr
;

arg_list:
    expr+ #PosArgList
    | named_arg+ #NamedArgList
    | expr+ named_arg+ #MixedArgList
;

named_arg: TILDE ID COLON expr;