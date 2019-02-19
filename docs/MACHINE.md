# The Manda Virtual Machine
The Manda Virtual Machine (MVM) is a 64-bit register machine. Its design is influenced by that of the MIPS
processor, and includes 256 64-bit registers.

# Registers
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

# Stack

# Bytecode Format and Execution
The MVM accepts one executable file at a time.
At runtime, the contents of this file are loaded into memory.
The program is able to read, write, and/or execute regions of memory,
depending on the access granted by the machine.

## Parallelism and Forking
The MVM can run units of code in parallel, at the behest of the user.
A program can `fork` itself; this operation starts a new, parallel context,
copying the entire contents of memory into the new context.

In addition to memory, the values of the `a`-series registers are also copied;
this allows for arguments to be passed to spawned threads.

## Message Passing
MVM threads do not share memory at all; however, the MVM allows for
message passing by means of  *message ports*. Each port maintains a single queue
of binary data, and can be used like a socket. Serialization and deserialization of
data is left up to the user.

## Executable File
An executable file consists of multiple sections.
 
```
executable_file: section*;
```

## Sections
Each section starts with a single byte - an unsigned value
representing which type of section it is. This byte is
followed by a 64-bit unsigned value representing the length of
the section.

Sections may be readable, writable, or executable, or a combination
thereof.

The machine **must**:
* Prevent reading or writing of executable code
* Prevent execution of readable or writable code

### Data Section
A data section is both readable and writable by the program, and effectively
has no purpose to the system. Such a section can hold either initialized or
unitialized data (or, of course, a mix of the two). The distinction is up to
the user.

A data section is preceded by the 8-bit number `0`, and followed by a 64-bit
unsigned value, corresponding to the length of the section.

```
data_section: 8-bit-zero, n=64-bit-unsigned, { n bytes of data }
```

A data section can be marked as completely read-only
(i.e., `.rodata`) by heading it with an 8-bit `2`, instead of
`0`.

### Code Section
A code is only executable.

A code section is encoded similarly to a data section, but is preceded by
the 8-bit unsigned number `1`, instead of `0`:

```
code_section: 8-bit-one, n=64-bit-unsigned, labels=label*

(* where the combined length of labels == n *)
```

Users can jump to anywhere in executable memory, but labels are
special locations with additional semantic information attached.

```
label = label_header label_data;
label_header =
  8-bit-zero
  | 8-bit-one, n=64-bit-unsigned, { string of length n }
;
label_data = { n bytes of data};
```

Labels preceded by `1` may indicate their name by means of
encoding a string.

The opcode numbers `0-9` are reserved for label headers. At the moment,
there are only two types of header, but this could potentially change in the future.

### Instructions
Within a label are an arbitrary number of instructions.
Each instruction consists of an 8-bit unsigned opcode (`10-255`),
and is followed by a number of operands.

The number and size of these operands is tightly coupled to the instruction.

Find the list of opcodes [here](OPCODES.md).
