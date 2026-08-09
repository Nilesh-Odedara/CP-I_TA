# `printf()` and `scanf()` in C

## 1. Understand It First — Without Technical Terms

Imagine you are talking to a computer.

There are two basic things you may want to do:

1. **Tell the computer to show something to you.**
2. **Give some information to the computer.**

In C:

```text
printf() → Computer talks to us
scanf()  → We give information to the computer
```

So, simply remember:

> **`printf()` is used for output.**
>
> **`scanf()` is used for input.**

---

# 2. `printf()` — Displaying Output

Suppose we want the computer to display:

```text
Hello World
```

We write:

```c
#include <stdio.h>

int main() {
    printf("Hello World");

    return 0;
}
```

Output:

```text
Hello World
```

Here:

```c
printf("Hello World");
```

means:

> "Display `Hello World` on the screen."

---

# 3. Why Do We Use `stdio.h`?

At the beginning we write:

```c
#include <stdio.h>
```

`printf()` and `scanf()` are standard input/output functions.

Their declarations are provided by:

```text
stdio.h
```

So for basic programs, remember:

```c
#include <stdio.h>
```

when using `printf()` or `scanf()`.

---

# 4. Printing Variables

We can also print the value stored in a variable.

```c
#include <stdio.h>

int main() {
    int age = 20;

    printf("%d", age);

    return 0;
}
```

Output:

```text
20
```

Here:

```c
%d
```

means:

> "The value I want to print is an integer."

---

# 5. Format Specifiers

A **format specifier** tells `printf()` what type of data we want to display.

Some important ones are:

| Format Specifier | Data Type | Example |
|---|---|---|
| `%d` | `int` | `25` |
| `%f` | `float` | `25.50` |
| `%c` | `char` | `A` |
| `%s` | String | `Hello` |
| `%lf` | `double` | `25.50` |

Example:

```c
#include <stdio.h>

int main() {
    int age = 20;
    float marks = 85.5;
    char grade = 'A';

    printf("Age = %d\n", age);
    printf("Marks = %.1f\n", marks);
    printf("Grade = %c", grade);

    return 0;
}
```

Output:

```text
Age = 20
Marks = 85.5
Grade = A
```

---

# 6. What Is `
`?

You will often see:

```c


```

It means:

> **Move to the next line.**

Example:

```c
printf("Hello\n");
printf("World");
```

Output:

```text
Hello
World
```

Without `
`:

```c
printf("Hello");
printf("World");
```

Output:

```text
HelloWorld
```

---

# 7. `scanf()` — Taking Input

Now suppose we want the user to enter their age.

We can use:

```c
scanf()
```

Example:

```c
#include <stdio.h>

int main() {
    int age;

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Your age is %d", age);

    return 0;
}
```

Example output:

```text
Enter your age: 20
Your age is 20
```

The user enters:

```text
20
```

and that value is stored in:

```c
age
```

---

# 8. Why Do We Write `&age`?

This is one of the most important things to understand about `scanf()`.

We write:

```c
scanf("%d", &age);
```

The `&` means:

> **"Give `scanf()` the address of the variable where the input should be stored."**

Think of a variable as a box.

```text
age
┌─────────┐
│   20    │
└─────────┘
```

`scanf()` needs to know **where this box is located** so it can put the user's input into it.

Therefore:

```c
&age
```

gives the address of `age`.

---

# 9. `scanf()` Format Specifiers

Just like `printf()`, `scanf()` uses format specifiers.

```c
int age;
float price;
char grade;

scanf("%d", &age);
scanf("%f", &price);
scanf(" %c", &grade);
```

Common ones:

| Data Type | `scanf()` Format |
|---|---|
| `int` | `%d` |
| `float` | `%f` |
| `char` | `%c` |
| `double` | `%lf` |

---

# 10. Taking Multiple Inputs

We can take multiple values using one `scanf()`.

```c
#include <stdio.h>

int main() {
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("A = %d\n", a);
    printf("B = %d", b);

    return 0;
}
```

Example:

```text
Enter two numbers: 10 20
A = 10
B = 20
```

---

# 11. `printf()` vs `scanf()`

| `printf()` | `scanf()` |
|---|---|
| Used for output | Used for input |
| Displays information | Takes information |
| Computer → User | User → Computer |
| Usually doesn't need `&` | Usually needs `&` for variables |
| Example: `printf("%d", age);` | Example: `scanf("%d", &age);` |

Think:

```text
             COMPUTER
             ↙     ↖
       printf()   scanf()
          ↓          ↑
        OUTPUT      INPUT
          ↓          ↑
             USER
```

---

# 12. A Complete Example

Let's combine both.

```c
#include <stdio.h>

int main() {
    int age;

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("You are %d years old.", age);

    return 0;
}
```

Example output:

```text
Enter your age: 20
You are 20 years old.
```

The flow is:

```text
Program starts
      ↓
printf()
      ↓
Ask user for age
      ↓
scanf()
      ↓
User enters 20
      ↓
20 is stored in age
      ↓
printf()
      ↓
Display age
```

---

# 13. Important Things to Remember

### `printf()`

```c
printf("Hello");
```

Used to **display output**.

### `scanf()`

```c
scanf("%d", &age);
```

Used to **take input**.

### Format specifier

```c
%d
```

Tells C that the value is an integer.

### Address operator

```c
&
```

Used with `scanf()` to provide the address of a variable.

---

# Quick Revision

```text
printf()
   ↓
Output
   ↓
Computer → User


scanf()
   ↓
Input
   ↓
User → Computer
```

### One-line definitions

> **`printf()` is a standard C library function used to display formatted output.**

> **`scanf()` is a standard C library function used to read formatted input from the user.**
