# manda
A gradually-typed programming language designed to replace Python.

# Example
Before all the philosophy, here's some code:

`Hello.mnd`:

```manda
print('Hello, Manda!')
```

`Functions.mnd`:

```manda
func fibonacci(n: Num) {
    if (n <= 1) {
        return n
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2)
    }
}

let fib = fibonacci(n: 13)
print('Result: %fib')
```

`Classes.mnd`:

```manda
class Animal {
    virtual get legCount: Num

    virtual makeSound(): Void
}

class Dog : Animal {
    constructor(property name: String)

    // `override` keyword is optional; it's more for
    // code readability than anything.
    override get legCount => 4

    override makeSound() {
        print('Woof! I am %name.')
    }
}

let fido = Dog(name: 'Fido')
print(fido.legCount)
fido.makeSound()
```

# Goals (for version 1)
Beyond all other goals, the primary focus of Manda is to
**make it easy to write good programs**.

The following are secondary goals, all of which are targets for version 1.

* Easy C interop
* Easy embedding
* Multi-threading
* Garbage collection

Future versions of Manda may feature a JIT compiler.

# Why replace Python?
Frankly, I don't feel that Python is a good enough language to be the
*lingua franca* of machine learning, nor is it a good enough language to be
taught to beginners.

I have several reasons for thinking this, but perhaps the most relevant is how
it handles data types.

There is nothing inherently *wrong* with dynamic languages; however, when it
comes to code *readability*, especially if it's code you haven't touched in a
while, or that someone else wrote, it can be difficult to follow the flow of
what is happening.

I also feel that a language so sensitive to whitespace can make it harder to read
code, especially long blocks of it; visual delimiters like `{` are already
ingrained in the minds of developers, *and* have the added benefit of
explicitly marking the boundaries of different sections of code.

# Gradual typing
Manda is gradually typed; type annotations are *optional* in your own code,
though they are *required* for packages published to the central repository.

Allowing values to be dynamic is nice for small scripts, among other use cases.
However, it requires developers to ensure themselves that data types are matched
properly, which as we've learned from JavaScript and Python, makes it harder
to maintain large-scale projects.

Using type annotations on functions makes it clear to people reading your code
what kind of input is accepted, and also prevents you from having to write it
by hand. In addition, it allows a static analyzer to give you warnings before
your code runs, to prevent runtime failures.

At runtime, however, type annotations are *ignored*. Instead, the runtime
performs actions based on the actual type of data present. Thus, forgetting
a type parameter on a generic call *won't* inexplicably crash your
otherwise-sound program.