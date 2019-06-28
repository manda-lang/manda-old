open Manda

let read_file filename = 
  let rec read_s s lines =
    try
      let line = input_line s in
      read_s s (lines @ [line])
    with
      | End_of_file ->
        close_in s;
        String.concat "\n" lines
      | e ->
        close_in_noerr s;
        raise e
  in
  let s = open_in filename in
  read_s s []

let () =
  match Array.to_list Sys.argv with
    | [] ->
        prerr_endline "fatal error: process spawned incorrectly; no argv at all";
        ignore (exit 1)
    | _ :: [] ->
        prerr_endline "fatal error: no input file provided";
        ignore (exit 65)
    | _ :: filename :: _ ->
        try
          let contents = read_file filename in
          let lexbuf = Lexing.from_string contents in
          lexbuf.lex_curr_p <- { lexbuf.lex_curr_p with pos_fname = filename};
          match Parser.prog Lexer.read lexbuf with
          | None -> ()
          | Some (Ast.ProgCtx prog) ->
              let l = List.length prog.top_level in
              let ls = string_of_int l in
              print_endline ls
        with e ->
          prerr_endline ("fatal error: " ^ (Printexc.to_string e));
          ignore (exit 1)
