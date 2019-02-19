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

### 0xB: `mov dest:reg, src:reg`
Copies the contents of `src` into `dest`.

### 0xC: `and dest:reg, a:reg, b:reg`
Performs a btiwise `AND` operation against `a` and `b`, and stores the result in `dest`.


### 0xD: `or dest:reg, a:reg, b:reg`
Performs a btiwise `OR` operation against `a` and `b`, and stores the result in `dest`.


### 0xD: `xor dest:reg, a:reg, b:reg`
Performs a btiwise `XOR` operation against `a` and `b`, and stores the result in `dest`.

### 0xE: `add dest:reg, a:reg, b:reg`
Adds the contents of `a` to `b`, and stores the sum in `dest`.

### 0xF: `sub dest:reg, a:reg, b:reg`
Subtracts the contents of `b` from `a`, and stores the difference in `dest`.

### 0x10: `mul dest:reg, a:reg, b:reg`
Multiplies the contents of `a` by `b`, and stores the product in `dest`.

### 0x11: `div dest:reg, a:reg, b:reg`
Divides the contents of `a` by `b`, and stores the quotient in `dest`.

### 0x12: `div_r q_dest:reg, r_dest:reg, a:reg, b:reg`
Divides the contents of `a` by `b`, stores the quotient in `q_dest`, and stores the remainder in `r_dest`.

### 0x13: `jmp offset:u64`
Jumps to `offset`.

### 0x14: `call offset:u64`
Pushes the next instruction offset to the stack, and then jumps to `offset`.

### 0x15: `ret`
Pops a 64-bit unsigned return address from stack, and jumps to it.
