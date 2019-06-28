type prog_ctx = 
  ProgCtx of
  {
    top_level: top_level_ctx list;
  } 
and top_level_ctx =
  | TopLevelClassCtx of class_ctx
and class_ctx =
  ClassCtx of
  {
    name: name_ctx;
    abstract: bool;
    extends: type_ctx option;
    implements: type_ctx list;
    members: member_ctx list;
  }
and member_ctx =
  | MemberFieldCtx of field_ctx
  | MemberMethodCtx of method_ctx
and accessor_type =
  | Getter
  | Setter
and method_modifier =
  | Public
  | Protected
  | Final
and method_ctx =
  | RegularMethodCtx of (method_modifier list) * function_ctx
  | AccessorMethodCtx of (method_modifier list) *  accessor_type * name_ctx * (stmt_ctx option)
and field_ctx =
  FieldCtx of
  {
    name: name_ctx;
    modifiers: method_modifier list;
    field_type: type_ctx option;
    body: stmt_ctx option;
  }
and function_ctx =
  FunctionCtx of
  {
    name: name_ctx;
    params: param_ctx list;
    returns: type_ctx option;
    body: stmt_ctx option;
  }
and param_ctx = name_ctx * (type_ctx option)
and stmt_ctx =
  | ReturnStmtCtx of expr_ctx
  | BlockStmtCtx of stmt_ctx list
and type_ctx =
  | RefTypeCtx of name_ctx
and expr_ctx =
  | RefExprCtx of name_ctx
  | CallExprCtx of expr_ctx * (expr_ctx list)
and name_ctx = Lexing.position * string
