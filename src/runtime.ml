type rtt =
  | VoidType
  | ObjectType
  | ClassType of 
    {
      position: Lexing.position;
      name: string;
      abstract: bool;
      extends: rtt option;
      implements: rtt list;
      members: member list;
    }
and member =
  | Method of func
  | Field of 
    {
      position: Lexing.position;
      name: string;
      modifiers: Ast.method_modifier list;
      returns: rtt;
      body: stmt option;
    }
and func_type =
  | Constructor
  | Accessor
  | RegularFunc
and func =
  {
    position: Lexing.position;
    name: string;
    synthetic: bool;
    accessor_type: Ast.accessor_type option;
    params: param option;
    returns: rtt;
    body: stmt option;
  }
and param = Lexing.position * string * (rtt option)
and stmt =
  | Block of stmt list
  | Return of obj option
and obj =
  | FuncObj of func
  | AstObj of Ast.expr_ctx
  | BinaryObj of Lexing.position * rtt * bytes
