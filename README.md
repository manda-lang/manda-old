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
func fibonacci(n: Num): Num {
    if (n <= 1) {
        return n
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2)
    }
}

let fib = fibonacci(n: 13)
print('Result: %fib')
```

`Interface.mnd`:

```manda
type Animal = interface {
    get legCount: Num
    
    makeSound(): Void
}

type Dog = class {
    constructor(property name: String)

    get legCount => 4

    makeSound() {
        print('Woof! I am %name.')
    }
}

func helloAnimal(animal: Animal) {
    print(animal.legCount)
    animal.makeSound()
}

let fido = Dog(name: 'Fido')
helloAnimal(fido)
```

# Goals/Features
Beyond all other goals, the primary focus of Manda is to
**make it easy to write good programs**.

The following are secondary features, all of which are targets for version 1.

* JIT compilation - for fast startup, without the slowness of a regular interpreter
* Easy embedding
* Easy FFI - to make it less of a headache to use existing code
* Fibers for asynchrony - Pain free async without having to deal with memory access issues
* Lightweight, isolated threads - for tasks that require preemptive multi-tasking
* Garbage collection - To prevent hard-to-debug memory leaks

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