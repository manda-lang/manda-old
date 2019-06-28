%token <Lexing.position * string> ID
%token ARROW COLON COMMA LCURLY RCURLY LPAREN RPAREN
%token ABSTRACT CLASS EXTENDS FINAL FN GET IMPLEMENTS
%token PROTECTED PUBLIC RETURN SET
%token EOF

%start <Ast.prog_ctx option> prog

%%

prog:
  | t=list(top_level); EOF
    { 
      Some (Ast.ProgCtx { top_level=t })
    }
  | EOF { None }
;

top_level:
  | c=class_ { Ast.TopLevelClassCtx c }
  | f=function_ { Ast.TopLevelFunctionCtx f }
;

class_:
  a=boption(ABSTRACT);
  CLASS;
  n=ID;
  e=option(extends);
  i=implements;
  LCURLY;
  m=list(member);
  RCURLY;
  {
    Ast.ClassCtx
    {
      name=n;
      abstract=a;
      extends=e;
      implements=i;
      members=m;
    }
  }
;

extends: EXTENDS; t=type_ { t };

implements:
  | IMPLEMENTS; t=separated_list(COMMA, type_) { t }
  | { [] }
;

member:
  | f=field { Ast.MemberFieldCtx f }
  | m=method_ { Ast.MemberMethodCtx m }
;

field:
  m=list(method_modifier);
  n=ID;
  t=option(extends);
  b=option(stmt);
  {
    Ast.FieldCtx
    {
      name=n;
      modifiers=m;
      field_type=t;
      body=b;
    }
  }
;

method_:
  | m=list(method_modifier); f=function_ { Ast.RegularMethodCtx (m, f) }
  | m=list(method_modifier); a=accessor_type; n=ID; b=option(stmt)
    {
      Ast.AccessorMethodCtx (m, a, n, b)
    }
;

accessor_type:
  | GET { Ast.Getter }
  | SET { Ast.Setter }

method_modifier:
  | PUBLIC { Ast.Public }
  | PROTECTED { Ast.Protected }
  | FINAL { Ast.Final }
;

function_:
  FN;
  n=ID;
  LPAREN;
  p=separated_list(COMMA, param);
  RPAREN;
  r=option(returns);
  b=option(stmt);
  {
    Ast.FunctionCtx
    {
      name=n;
      params=p;
      returns=r;
      body=b;
    }
  }
;

param: n=ID; r=option(returns) { (n, r) };

returns: COLON; t=type_ { t };

type_:
  n=ID { Ast.RefTypeCtx n }
;

stmt:
  | RETURN; e=expr { Ast.ReturnStmtCtx e }
  | LCURLY; s=list(stmt); RCURLY { Ast.BlockStmtCtx s }
  | ARROW; e=expr { Ast.ReturnStmtCtx e }
;

expr:
  | n=ID; { Ast.RefExprCtx n }
  | t=expr; LPAREN; a=separated_list(COMMA, expr); RPAREN { Ast.CallExprCtx (t, a) }
  | LPAREN; e=expr; RPAREN { e }
