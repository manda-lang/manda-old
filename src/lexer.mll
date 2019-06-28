{
  open Lexing
  open Parser

  type error_severity =
    | Error
    | Warning
    | Info

  exception MandaError of Lexing.position * error_severity * string

  let next_line lexbuf =
  let pos = lexbuf.lex_curr_p in
  lexbuf.lex_curr_p <-
    { pos with pos_bol = lexbuf.lex_curr_pos;
               pos_lnum = pos.pos_lnum + 1
    }
}

let white = [' ' '\t']+
let newline = '\r' | '\n' | "\r\n"
let id = ['A'-'Z' 'a'-'z' '_']['A'-'Z' 'a'-'z' '0'-'9' '_']*

rule read =
  parse
  | white { read lexbuf }
  | newline { read lexbuf }
  | "=>" { ARROW }
  | ":" { COLON }
  | "," { COMMA }
  | "{" { LCURLY }
  | "}" { RCURLY }
  | "(" { LPAREN }
  | ")" { RPAREN }
  | "abstract" { ABSTRACT }
  | "class" { CLASS }
  | "extends" { EXTENDS }
  | "final" { FINAL }
  | "fn" { FN }
  | "get" { GET }
  | "implements" { IMPLEMENTS }
  | "protected" { PROTECTED }
  | "public" { PUBLIC }
  | "return" { RETURN }
  | "set" { SET }
  | id { ID (lexbuf.lex_curr_p, (Lexing.lexeme lexbuf)) }
  | _ { raise (MandaError (lexbuf.lex_curr_p, Error, ("Unexpected char: " ^ Lexing.lexeme lexbuf))) }
  | eof { EOF }
