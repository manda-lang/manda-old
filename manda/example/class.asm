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

    la a1, animal_makeSound ; Add the "makeSound" method to "Animal"
    la a2, szMakeSound
    li v0, 1
    syscall

    ; Make an instance of Animal
    pusha szName
    la a0, dog
    la a1, szMakeSound

    ; Look up "makeSound" dynamically
    li v0, 2
    la a0, animalClass
    la a1, szMakeSound
    syscall

    ; The pointer will be in v0, call it.
    pusha dog
    call v0
