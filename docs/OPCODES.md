# MVM Opcodes
This is the exhaustive list of opcodes for the
[Manda Virtual Machine](MACHINE.md).

## Reserved
The opcodes `0-10` are reserved.

### Notation and Values
The following mnemonics are used for values:
* `reg`: An 8-bit unsigned integer representing a register
* `u8`: An 8-bit unsigned integer.
* `u64`: A 64-bit unsigned integer`

### 0xA: `syscall u8`
Perhaps the most important instruction of all. `syscall` triggers a known routine within the
machine itself.

View the list of system calls [here](SYSCALLS.md).

### 0xB: `mov dest:reg, src:reg`
Copies the contents of `src` into `dest`.

### 0xC: `and dest:reg, a:reg, b:reg`
Performs a btiwise `AND` operation against `a` and `b`, and stores the result in `dest`.

### 0xD: `or dest:reg, a:reg, b:reg`
Performs a btiwise `OR` operation against `a` and `b`, and stores the result in `dest`.

### 0xE: `xor dest:reg, a:reg, b:reg`
Performs a btiwise `XOR` operation against `a` and `b`, and stores the result in `dest`.

### 0xF: `add dest:reg, a:reg, b:reg`
Adds the contents of `a` to `b`, and stores the sum in `dest`.

### 0x10: `sub dest:reg, a:reg, b:reg`
Subtracts the contents of `b` from `a`, and stores the difference in `dest`.

### 0x11: `mul dest:reg, a:reg, b:reg`
Multiplies the contents of `a` by `b`, and stores the product in `dest`.

### 0x12: `div dest:reg, a:reg, b:reg`
Divides the contents of `a` by `b`, and stores the quotient in `dest`.

If `b` is `0`, the system will panic.

### 0x13: `div_r q_dest:reg, r_dest:reg, a:reg, b:reg`
Divides the contents of `a` by `b`, stores the quotient in `q_dest`, and stores the remainder in `r_dest`.

## Signed Arithmetic
The following instructions treat the involved registers as signed integers, but
perform the same semantic operations as their counterparts:
* 0x14: `ands dest:reg, a:reg, b:reg`
* 0x15: `ors dest:reg, a:reg, b:reg`
* 0x16: `xors dest:reg, a:reg, b:reg`
* 0x17: `adds dest:reg, a:reg, b:reg`
* 0x18: `subs dest:reg, a:reg, b:reg`
* 0x19: `muls dest:reg, a:reg, b:reg`
* 0x1A: `divs dest:reg, a:reg, b:reg`
* 0x1B: `div_rs dest:reg, a:reg, b:reg`

### 0x1B: `jmp offset:u64`
Jumps to `offset`.

### 0x1C: `call offset:u64`
Pushes the next instruction offset to the stack, and then jumps to `offset`.

### 0x1D: `ret`
Pops a 64-bit unsigned return address from stack, and jumps to it.
Causes a system panic if the stack is empty.

### 0x1E: `panic exc:reg`
If the error handler stack is not empty, then its first value, an address `n`, is popped,
`reg` is copied into `a0`, and execution jumps to `n`.

If the error handler *is* empty, then a system panic is triggered.

### 0x1F: `push_error offset:reg`
Pushes the `offset` to the error handler stack.

### 0x20: `pop_error`
Pops the first value from the error handler stack. Causes a system panic if the error handler stack is empty.

### 0x21: `li dest:reg, value:u64`
Loads an unsigned integer, `value`, into `dest`.
Assemblers can include a pseudo-instruction, `la`, that loads the offset of an address.

### 0x22: `signed r:reg`
Converts register `r` from an unsigned value to a signed value.

### 0x23: `unsigned r:reg`
Converts register `r` from a signed value to an unsigned value.
