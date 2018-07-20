section .bss
  lib_core: resd 1

section .data
  symbol_core: db "Core", 0
  symbol_print: db "print", 0

section .text
  main:
    ; Load the location of library "Core", so that it can be referenced.
    push symbol_core
    call open
    mov [lib_core], eax

    ; Load the location of the "print" function, so that we can jump to it.
    push symbol_print
    push [lib_core]

    ; Push our message.
    push message
    
    ; Far call the address in eax.
    call [eax]

    ; Success... Return an exit code.
    mov eax, 0
    ret
