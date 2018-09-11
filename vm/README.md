# manda
A VM for high-level languages that desire high performance
and concurrency.

The Manda VM includes high-level constructs for:
* Enqueuing tasks
* Memory management
* Parallelism

The Manda VM's object file format, `*.mo`,
is a text-based format, and is more expressive than
a simple Assembly language.

That being said, it is designed to be extremely precise
and type-safe, so that the VM may produce efficient programs.