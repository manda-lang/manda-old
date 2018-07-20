section .text
  on_error:
    pop eax ; Get the error value, do something with it...
    
  main:
    ; Register an error handler for the current scope.
    push on_error
    int 0xA

    ; Do... stuff
