section .data
  szAnimal: db "Animal", 0
  szMakeSound: db "makeSound", 0
  szName: db "Fido", 0 ; The name of the dog

section .bss
  animalClass: resq ; The pointer to the Animal class
  dog: resq ; Our instance of Animal

section .code
  _start:
    li v0, 0
    la a0, animalClass ; Create a class named "Animal", stored in `animalClass`
    la a1, szAnimal
    syscall

    ; Specify field - a string "pointer"
    li v0, 5
    la a0, animalClass
    li a1, 0
    li a2, 8
    syscall

    li v0, 1 ; Add the constructor
    la a0, animalClass
    la a1, animal_constructor
    syscall

    la a1, animal_makeSound ; Add the "makeSound" method to "Animal"
    la a2, szMakeSound
    li v0, 2
    syscall

    ; Make an instance of Animal
    la a0, dog
    la a1, animalClass
    la a2, szName
    syscall

    ; Look up "makeSound" dynamically
    li v0, 3
    la a0, animalClass
    la a1, szMakeSound
    syscall

    ; The pointer will be in v0, call it.
    la a0, dog
    call v0
    ret

  animal_constructor:
    ; Copy pointer in a1 to offset 0 of a0
    lq t0, 0(a1)
    sq 0(a0), t0
    ; Manda will automatically create a GC dependency...
    ret

  animal_makeSound:
    ; The name string is at offset 0 of a0
    ; Do a print syscall
    li v0, 4
    syscall
    ret
