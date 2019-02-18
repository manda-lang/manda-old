The Manda Virtual Machine (MVM) is a 64-bit register machine. Its design is influenced by that of the MIPS
processor, and includes 256 64-bit registers.

## Registers
Registers are addressed numerically, and divided
into four categories; each category has a one-letter
prefix identifying it.

Registers can be used for any purpose, but by convention,
their uses correlate with their category.

* `a0`-`a63`: Arguments to functions.
* `s0`-`s63`: Values that are expected to be the same after
a function call.
* `v0`-`v63`: Values returned from functions.
* `t0`-`t63`: Temporary/intermediate values.

In MVM bytecode, register offsets are represented by
one-byte values. The range `0-63` corresponds to registers in
the `a` category, while `64-127`, `128-191`, and `192-155`
correspond to `s`, `v`, and `t`, respectively.

## Stack

## Bytecode Format