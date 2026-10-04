# C Loops Lab – 16

## Topic: While Loop

This lab focuses on the **`while` loop** in C.

A `while` loop repeats a block of statements as long as a given condition is true.

---

# 1. Print 1 to 10 Using While Loop

## Problem

Write a C program to print numbers from `1` to `10` using a `while` loop.

## Explanation

We start the counter from `1`:

```c
int i = 1;
```

Then the condition is checked:

```c
while (i <= 10)
```

If the condition is true, the number is printed. After that, `i` is increased by `1`.

When `i` becomes `11`, the condition becomes false and the loop stops.

## Algorithm

1. Start.
2. Declare and initialize `i = 1`.
3. Check whether `i <= 10`.
4. If true, print `i`.
5. Increase `i` by `1`.
6. Repeat until the condition becomes false.
7. Stop.

## C Program

```c
#include <stdio.h>

int main()
{
    int i = 1;

    while (i <= 10)
    {
        printf("%d ", i);
        i++;
    }

    return 0;
}
```

## Output

```text
1 2 3 4 5 6 7 8 9 10
```

---

# 2. Print 1 to N Using While Loop

## Problem

Write a C program to print numbers from `1` to `N` using a `while` loop.

## Explanation

Here, `N` is entered by the user.

For example, if:

```text
N = 7
```

the output will be:

```text
1 2 3 4 5 6 7
```

The condition is:

```c
while (i <= n)
```

So the loop continues until `i` becomes greater than `N`.

## Algorithm

1. Start.
2. Declare `n` and `i`.
3. Read `n`.
4. Initialize `i = 1`.
5. Check `i <= n`.
6. If true, print `i`.
7. Increase `i` by `1`.
8. Repeat until `i > n`.
9. Stop.

## C Program

```c
#include <stdio.h>

int main()
{
    int n, i = 1;

    printf("Enter the value of N: ");
    scanf("%d", &n);

    while (i <= n)
    {
        printf("%d ", i);
        i++;
    }

    return 0;
}
```

## Sample Output

```text
Enter the value of N: 7
1 2 3 4 5 6 7
```

---

# 3. Print Odd Numbers Between 1 to N

## Problem

Write a C program to print odd numbers between `1` and `N`.

## Explanation

An odd number is not exactly divisible by `2`.

For example:

```text
1, 3, 5, 7, 9
```

A simple way to generate odd numbers is to start from `1` and increase by `2`:

```c
i = i + 2;
```

This gives:

```text
1 → 3 → 5 → 7 → 9 → ...
```

## Algorithm

1. Start.
2. Read `N`.
3. Initialize `i = 1`.
4. Check whether `i <= N`.
5. Print `i`.
6. Increase `i` by `2`.
7. Repeat until `i > N`.
8. Stop.

## C Program

```c
#include <stdio.h>

int main()
{
    int n, i = 1;

    printf("Enter the value of N: ");
    scanf("%d", &n);

    while (i <= n)
    {
        printf("%d ", i);
        i = i + 2;
    }

    return 0;
}
```

## Sample Output

```text
Enter the value of N: 10
1 3 5 7 9
```

### Another Method

We can also check every number using `%`:

```c
if (i % 2 != 0)
{
    printf("%d ", i);
}
```

Complete version:

```c
#include <stdio.h>

int main()
{
    int n, i = 1;

    printf("Enter the value of N: ");
    scanf("%d", &n);

    while (i <= n)
    {
        if (i % 2 != 0)
        {
            printf("%d ", i);
        }

        i++;
    }

    return 0;
}
```

For this problem, starting at `1` and increasing by `2` is simpler.

---

# 4. Print Numbers Between Two Given Numbers Which Are Divisible by 2

## Problem

Write a C program to print numbers between two given numbers which are divisible by `2`.

## Explanation

A number is divisible by `2` when its remainder after division by `2` is `0`.

We check this using:

```c
i % 2 == 0
```

For example, between `5` and `15`:

```text
6 8 10 12 14
```

are divisible by `2`.

## Algorithm

1. Start.
2. Declare `start`, `end`, and `i`.
3. Read the starting and ending numbers.
4. Set `i = start`.
5. Check `i <= end`.
6. Check whether `i % 2 == 0`.
7. If true, print `i`.
8. Increase `i` by `1`.
9. Repeat until `i > end`.
10. Stop.

## C Program

```c
#include <stdio.h>

int main()
{
    int start, end, i;

    printf("Enter starting number: ");
    scanf("%d", &start);

    printf("Enter ending number: ");
    scanf("%d", &end);

    i = start;

    while (i <= end)
    {
        if (i % 2 == 0)
        {
            printf("%d ", i);
        }

        i++;
    }

    return 0;
}
```

## Sample Output

```text
Enter starting number: 5
Enter ending number: 15
6 8 10 12 14
```

---

# 5. Print Number and Its Square Root for 0 to 9

## Problem

Write a C program to print each number and its square root from `0` to `9`.

## Explanation

C provides the `sqrt()` function to calculate the square root.

We need:

```c
#include <math.h>
```

For example:

```text
sqrt(4) = 2
sqrt(9) = 3
```

The loop starts from `0` and continues until `9`.

## Algorithm

1. Start.
2. Declare `i`.
3. Initialize `i = 0`.
4. Check whether `i <= 9`.
5. Calculate `sqrt(i)`.
6. Print the number and its square root.
7. Increase `i` by `1`.
8. Repeat until `i > 9`.
9. Stop.

## C Program

```c
#include <stdio.h>
#include <math.h>

int main()
{
    int i = 0;

    while (i <= 9)
    {
        printf("%d	%.3f\n", i, sqrt(i));
        i++;
    }

    return 0;
}
```

## Sample Output

```text
0    0.000
1    1.000
2    1.414
3    1.732
4    2.000
5    2.236
6    2.449
7    2.646
8    2.828
9    3.000
```

### Understanding `%.3f`

The `sqrt()` function returns a floating-point value.

```c
%.3f
```

means:

> Display 3 digits after the decimal point.

For example:

```text
sqrt(2) = 1.414213...
```

is displayed as:

```text
1.414
```

### Important

Because we use `sqrt()`:

```c
#include <math.h>
```

is required.

With GCC, some environments may require:

```text
gcc program.c -lm
```

---

# 6. Calculate the Square of Integers 1 Through 10

## Problem

Write a C program to calculate the square of integers from `1` through `10`.

## Explanation

The square of a number is:

```text
number × number
```

For example:

```text
1² = 1 × 1 = 1
2² = 2 × 2 = 4
3² = 3 × 3 = 9
```

In C:

```c
i * i
```

calculates the square.

## Algorithm

1. Start.
2. Declare `i`.
3. Initialize `i = 1`.
4. Check whether `i <= 10`.
5. Calculate `i * i`.
6. Print the number and its square.
7. Increase `i` by `1`.
8. Repeat until `i > 10`.
9. Stop.

## C Program

```c
#include <stdio.h>

int main()
{
    int i = 1;

    while (i <= 10)
    {
        printf("Square of %d = %d\n", i, i * i);
        i++;
    }

    return 0;
}
```

## Output

```text
Square of 1 = 1
Square of 2 = 4
Square of 3 = 9
Square of 4 = 16
Square of 5 = 25
Square of 6 = 36
Square of 7 = 49
Square of 8 = 64
Square of 9 = 81
Square of 10 = 100
```

---

# Understanding the `while` Loop

All six programs in this lab use the `while` loop.

## Syntax

```c
while (condition)
{
    // statements
}
```

The condition is checked **before** the loop body executes.

---

# How the While Loop Works

```text
        Start
          |
          v
    Initialization
          |
          v
      Condition
       /          TRUE      FALSE
     |          |
     v          v
    Body       Stop
     |
     v
   Update
     |
     └──────> Condition
```

Remember:

```text
Initialize → Check → Execute → Update → Repeat
```

---

# Three Important Parts

## 1. Initialization

Decides where the loop starts.

```c
int i = 1;
```

## 2. Condition

Decides whether the loop should continue.

```c
while (i <= 10)
```

## 3. Update

Changes the loop variable.

```c
i++;
```

Without the update, the loop may become infinite.

---

# Dry Run Example

Consider:

```c
int i = 1;

while (i <= 5)
{
    printf("%d ", i);
    i++;
}
```

| Step | `i` | Condition | Output |
|---|---:|---|---|
| 1 | 1 | `1 <= 5` → TRUE | 1 |
| 2 | 2 | `2 <= 5` → TRUE | 2 |
| 3 | 3 | `3 <= 5` → TRUE | 3 |
| 4 | 4 | `4 <= 5` → TRUE | 4 |
| 5 | 5 | `5 <= 5` → TRUE | 5 |
| 6 | 6 | `6 <= 5` → FALSE | Stop |

Final output:

```text
1 2 3 4 5
```

---

# Common Beginner Mistakes

## Mistake 1: Forgetting the Update

Wrong:

```c
int i = 1;

while (i <= 10)
{
    printf("%d ", i);
}
```

`i` never changes, so the condition remains true.

Correct:

```c
while (i <= 10)
{
    printf("%d ", i);
    i++;
}
```

---

## Mistake 2: Wrong Update Direction

If we want:

```text
1 2 3 4 5
```

we need:

```c
i++;
```

Not:

```c
i--;
```

---

## Mistake 3: Using `=` Instead of `==`

Wrong:

```c
if (i % 2 = 0)
```

Correct:

```c
if (i % 2 == 0)
```

Remember:

```text
=   → Assignment
==  → Comparison
```

---

## Mistake 4: Using `/` Instead of `%`

Wrong:

```c
if (i / 2 == 0)
```

Correct:

```c
if (i % 2 == 0)
```

`%` gives the remainder.

---

## Mistake 5: Confusing `<` and `<=`

For:

```c
while (i < 10)
```

the number `10` is not included.

For:

```c
while (i <= 10)
```

the number `10` is included.

Remember:

```text
<  → ending value excluded
<= → ending value included
```

---

## Mistake 6: Putting a Semicolon After `while`

Usually wrong:

```c
while (i <= 10);
{
    printf("%d ", i);
    i++;
}
```

The semicolon creates an empty loop body.

Correct:

```c
while (i <= 10)
{
    printf("%d ", i);
    i++;
}
```

---

## Mistake 7: Forgetting `&` in `scanf`

Wrong:

```c
scanf("%d", n);
```

Correct:

```c
scanf("%d", &n);
```

---

# Important Points for Lab 16

### Odd number

```c
number % 2 != 0
```

### Even number / Divisible by 2

```c
number % 2 == 0
```

### Square

```c
number * number
```

### Square root

```c
sqrt(number)
```

with:

```c
#include <math.h>
```

---

# Quick Revision Table

| Program | Main Logic |
|---|---|
| Print 1 to 10 | `i++` |
| Print 1 to N | `i <= n` |
| Print odd numbers | Start at `1`, increase by `2` |
| Divisible by 2 | `i % 2 == 0` |
| Square root 0 to 9 | `sqrt(i)` |
| Square 1 to 10 | `i * i` |

---

# Lab 16 – Learning Outcome

After completing this lab, students should be able to:

- Understand the purpose of a `while` loop.
- Write a basic `while` loop.
- Use initialization, condition, and update correctly.
- Print a sequence of numbers.
- Print odd numbers.
- Check divisibility using `%`.
- Calculate squares.
- Calculate square roots using `sqrt()`.
- Perform a dry run of a `while` loop.
- Identify and fix common loop mistakes.

---

# Final Golden Rule

> **For every `while` loop, remember: Initialize → Check Condition → Execute → Update → Repeat.**

```text
Initialize
    ↓
Condition
    ↓
Body
    ↓
Update
    ↓
Condition
    ↓
Repeat until FALSE
```
