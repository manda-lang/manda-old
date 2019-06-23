type class_ctx =
  {
    class_name: name_ctx;
    class_abstract: bool;
    class_extends: type_ctx option;
    class_implements: type_ctx list;
    class_methods: method_ctx list;
    class_fields: field_ctx list;
  }
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
  {
    field_name: name_ctx;
    field_modifiers: method_modifier list;
    field_type: type_ctx option;
    field_body: stmt_ctx option;
  }
and function_ctx =
  {
    fn_name: name_ctx;
    fn_params: param_ctx list;
    fn_returns: type_ctx option;
    fn_body: stmt_ctx option;
  }
and param_ctx = Lexing.position * string * (type_ctx option)
and stmt_ctx =
  | ReturnStmtCtx of expr_ctx
  | BlockStmtCtx of stmt_ctx list
and type_ctx =
  | RefTypeCtx of name_ctx
and expr_ctx =
  | RefExprCtx of name_ctx
  | CallExprCtx of expr_ctx * (expr_ctx list)
and name_ctx = Lexing.position * string
