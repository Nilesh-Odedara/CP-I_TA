# Header File in C

## 1. Understand It First — Without Technical Terms

Imagine you have a **toolbox**. You don't build every tool yourself whenever you need it. You simply take the required tool and use it.

A **header file in C is similar to a toolbox**. It provides information about useful functions and features that our program can use.

For example, instead of creating a function for displaying output ourselves, C already provides `printf()`.

---

## 2. A Simple Example

```c
#include <stdio.h>

int main() {
    printf("Hello World");
    return 0;
}
```

The important line is:

```c
#include <stdio.h>
```

For now, understand it as:

> **"I want to use the features provided by `stdio.h`."**

`stdio.h` stands for **Standard Input/Output Header**.

It provides declarations for functions such as:

```c
printf()
scanf()
```

---

## 3. What Does `#include` Mean?

```c
#include <stdio.h>
```

`#include` is a **preprocessor directive**.

It tells the preprocessor to make the contents/information from the specified header available to the source file before compilation.

In simple words:

> **"Bring the required information from this header so my program can use it."**

---

## 4. What Is a Function?

A **function** is a block of code that performs a particular task.

For example:

```c
printf()
```

displays output.

```c
scanf()
```

takes input.

We don't need to write the complete implementation of these standard functions ourselves. C provides them through its standard library.

---

## 5. Header File vs Library

These are related but not the same.

### Header File

A header mainly provides **declarations and other information** about things we can use.

Example:

```text
stdio.h
```

### Library

A library contains the actual implementation of functions.

A simple analogy:

```text
Header File → Menu
              ↓
        Tells you what is available

Library → Kitchen
          ↓
      Does the actual work
```

---

## 6. Common Header Files

| Header File | Used For |
|---|---|
| `stdio.h` | Input and output |
| `string.h` | String operations |
| `math.h` | Mathematical functions |
| `stdlib.h` | General utility functions |

Examples:

```c
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
```

---

## 7. Can We Create Our Own Header File?

Yes.

For example:

### `calculator.h`

```c
int add(int a, int b);
```

This is a **function declaration**.

Another file can use it:

```c
#include "calculator.h"
```

The actual function can be defined in another `.c` file:

```c
int add(int a, int b) {
    return a + b;
}
```

This becomes useful when programs become larger and are divided into multiple files.

---

## 8. Declaration vs Definition

### Declaration

Tells the compiler **what exists**:

```c
int add(int a, int b);
```

### Definition

Contains **how it works**:

```c
int add(int a, int b) {
    return a + b;
}
```

Header files commonly contain declarations.

---

## 9. What Happens When We Use `#include`?

A simplified view is:

```text
C Program
   ↓
Preprocessor
   ↓
Header information is processed
   ↓
Compiler
   ↓
Object Code
   ↓
Linker
   ↓
Executable Program
```

The preprocessor handles directives such as:

```c
#include
#define
```

---

## 10. `< >` vs `" "`

You will commonly see:

```c
#include <stdio.h>
```

and:

```c
#include "calculator.h"
```

Generally:

- `< >` → system/standard headers
- `" "` → your own header files

---

## 11. Final Definition

### For Beginners

> **A header file is like a toolbox that gives our C program information about useful functions and features that we can use.**

### Technical Definition

> **A header file is usually a `.h` file containing declarations, macros, type definitions, and other information that can be included in a C source file using the `#include` preprocessor directive.**

---

## Quick Revision

```text
Header File
     ↓
Usually ends with .h
     ↓
Provides declarations and other information
     ↓
Included using #include
     ↓
Processed by the preprocessor
```

### Most Important Example

```c
#include <stdio.h>
```

Remember:

> **`stdio.h` → Standard Input/Output → `printf()`, `scanf()`, etc.**
