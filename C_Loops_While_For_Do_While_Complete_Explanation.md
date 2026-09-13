# Loops in C – Complete Beginner-Friendly Explanation

## Topics: `while`, `for`, and `do-while`

---

# 1. Introduction to Loops

A **loop** is used to execute the same block of code repeatedly.

For example, suppose we want to print:

```text
Hello
Hello
Hello
Hello
Hello
```

Without a loop, we would have to write:

```c
printf("Hello\n");
printf("Hello\n");
printf("Hello\n");
printf("Hello\n");
printf("Hello\n");
```

This is repetitive.

Using a loop:

```c
for (int i = 1; i <= 5; i++)
{
    printf("Hello\n");
}
```

The same statement is executed 5 times.

Therefore:

> **A loop allows us to repeat a block of statements until a particular condition is satisfied.**

---

# 2. Why Do We Need Loops?

Loops are useful when the same task needs to be performed multiple times.

Common examples:

- Print numbers from 1 to 10
- Print a multiplication table
- Find the sum of numbers
- Find factorial
- Read multiple values
- Count digits
- Reverse a number
- Find prime numbers
- Print patterns
- Process array elements

---

# 3. Types of Loops in C

C mainly provides three loops:

1. `while`
2. `for`
3. `do-while`

They can be divided into two categories.

### Entry-Controlled Loops

The condition is checked **before** executing the loop body.

```text
while
for
```

### Exit-Controlled Loop

The condition is checked **after** executing the loop body.

```text
do-while
```

---

# 4. Basic Structure of a Loop

Most loops involve three important parts:

```text
1. Initialization
2. Condition
3. Update
```

Example:

```c
int i = 1;       // Initialization

while (i <= 5)   // Condition
{
    printf("%d\n", i);

    i++;         // Update
}
```

### Understand the Three Parts

```text
Initialization → Where should counting start?
Condition      → How long should the loop continue?
Update         → How should the value change?
```

---

# 5. The `while` Loop

The `while` loop is used when we want to repeat statements **while a condition is true**.

## Syntax

```c
while (condition)
{
    // statements
}
```

The condition is checked before the loop body executes.

---

# 6. How Does `while` Work?

Example:

```c
int i = 1;

while (i <= 5)
{
    printf("%d\n", i);
    i++;
}
```

Execution:

```text
i = 1
   ↓
1 <= 5 → TRUE → print 1
   ↓
i = 2
   ↓
2 <= 5 → TRUE → print 2
   ↓
i = 3
   ↓
3 <= 5 → TRUE → print 3
   ↓
i = 4
   ↓
4 <= 5 → TRUE → print 4
   ↓
i = 5
   ↓
5 <= 5 → TRUE → print 5
   ↓
i = 6
   ↓
6 <= 5 → FALSE
   ↓
Loop ends
```

---

# 7. Program: Print Numbers from 1 to 10 Using `while`

```c
#include <stdio.h>

int main()
{
    int i = 1;

    while (i <= 10)
    {
        printf("%d\n", i);
        i++;
    }

    return 0;
}
```

### Output

```text
1
2
3
4
5
6
7
8
9
10
```

---

# 8. Important Parts of a `while` Loop

Consider:

```c
int i = 1;

while (i <= 10)
{
    printf("%d\n", i);
    i++;
}
```

### Initialization

```c
int i = 1;
```

The counter starts at `1`.

### Condition

```c
i <= 10
```

The loop continues while this condition is true.

### Update

```c
i++;
```

The value of `i` increases by 1.

---

# 9. `while` Loop May Execute Zero Times

Because the condition is checked first, the loop body may never execute.

Example:

```c
int i = 10;

while (i < 5)
{
    printf("%d", i);
}
```

The condition:

```text
10 < 5
```

is false.

Therefore, the loop body executes:

```text
0 times
```

This is an important property of the `while` loop.

---

# 10. Program: Print Even Numbers Using `while`

```c
#include <stdio.h>

int main()
{
    int i = 2;

    while (i <= 20)
    {
        printf("%d ", i);
        i = i + 2;
    }

    return 0;
}
```

### Output

```text
2 4 6 8 10 12 14 16 18 20
```

---

# 11. Program: Print Odd Numbers Using `while`

```c
#include <stdio.h>

int main()
{
    int i = 1;

    while (i <= 20)
    {
        printf("%d ", i);
        i = i + 2;
    }

    return 0;
}
```

### Output

```text
1 3 5 7 9 11 13 15 17 19
```

---

# 12. The `for` Loop

The `for` loop is commonly used when we know how many times the loop should run.

## Syntax

```c
for (initialization; condition; update)
{
    // statements
}
```

Example:

```c
for (int i = 1; i <= 5; i++)
{
    printf("%d\n", i);
}
```

---

# 13. Three Parts of a `for` Loop

Consider:

```c
for (int i = 1; i <= 5; i++)
```

There are three parts.

### 1. Initialization

```c
int i = 1
```

Executed once at the beginning.

### 2. Condition

```c
i <= 5
```

Checked before each iteration.

### 3. Update

```c
i++
```

Executed after the loop body.

---

# 14. How Does a `for` Loop Work?

Example:

```c
for (int i = 1; i <= 5; i++)
{
    printf("%d\n", i);
}
```

Execution order:

```text
Initialization
      ↓
Condition
      ↓
Loop body
      ↓
Update
      ↓
Condition
      ↓
Loop body
      ↓
Update
      ↓
...
      ↓
Condition becomes FALSE
      ↓
Loop ends
```

---

# 15. Program: Print Numbers from 1 to 10 Using `for`

```c
#include <stdio.h>

int main()
{
    int i;

    for (i = 1; i <= 10; i++)
    {
        printf("%d\n", i);
    }

    return 0;
}
```

### Output

```text
1
2
3
4
5
6
7
8
9
10
```

---

# 16. `for` Loop vs `while` Loop

These two programs produce the same output.

### Using `while`

```c
int i = 1;

while (i <= 5)
{
    printf("%d ", i);
    i++;
}
```

### Using `for`

```c
for (int i = 1; i <= 5; i++)
{
    printf("%d ", i);
}
```

The `for` loop puts initialization, condition, and update together.

Therefore, it is often convenient for counting loops.

---

# 17. Program: Print Numbers in Reverse

```c
#include <stdio.h>

int main()
{
    int i;

    for (i = 10; i >= 1; i--)
    {
        printf("%d ", i);
    }

    return 0;
}
```

### Output

```text
10 9 8 7 6 5 4 3 2 1
```

Notice:

```c
i--
```

decreases the value by 1.

---

# 18. Program: Print Multiplication Table

```c
#include <stdio.h>

int main()
{
    int num, i;

    printf("Enter a number: ");
    scanf("%d", &num);

    for (i = 1; i <= 10; i++)
    {
        printf("%d x %d = %d\n", num, i, num * i);
    }

    return 0;
}
```

### Sample Output

```text
Enter a number: 5
5 x 1 = 5
5 x 2 = 10
5 x 3 = 15
5 x 4 = 20
5 x 5 = 25
5 x 6 = 30
5 x 7 = 35
5 x 8 = 40
5 x 9 = 45
5 x 10 = 50
```

---

# 19. The `do-while` Loop

The `do-while` loop is different from `while` and `for`.

Its main feature is:

> **The loop body executes at least once.**

## Syntax

```c
do
{
    // statements
}
while (condition);
```

Notice the semicolon:

```c
while (condition);
```

The semicolon is required.

---

# 20. How Does `do-while` Work?

Example:

```c
int i = 1;

do
{
    printf("%d\n", i);
    i++;
}
while (i <= 5);
```

Execution:

```text
Start
  ↓
Execute loop body
  ↓
Check condition
  ↓
TRUE → Repeat
  ↓
FALSE → Stop
```

Unlike `while`, the body executes before the condition is checked.

---

# 21. Program: Print Numbers from 1 to 10 Using `do-while`

```c
#include <stdio.h>

int main()
{
    int i = 1;

    do
    {
        printf("%d\n", i);
        i++;
    }
    while (i <= 10);

    return 0;
}
```

### Output

```text
1
2
3
4
5
6
7
8
9
10
```

---

# 22. Important Difference: `while` vs `do-while`

Consider:

```c
int i = 10;
```

### `while`

```c
while (i < 5)
{
    printf("Hello");
}
```

Condition:

```text
10 < 5 → FALSE
```

Output:

```text
Nothing
```

### `do-while`

```c
do
{
    printf("Hello");
}
while (i < 5);
```

The body executes first.

Output:

```text
Hello
```

Therefore:

> **`do-while` executes at least once, even if the condition is initially false.**

---

# 23. Main Difference Between the Three Loops

| Feature | `while` | `for` | `do-while` |
|---|---|---|---|
| Type | Entry-controlled | Entry-controlled | Exit-controlled |
| Condition checked | Before body | Before body | After body |
| Minimum executions | 0 | 0 | 1 |
| Initialization | Usually before loop | Inside loop syntax | Usually before loop |
| Update | Usually inside body | In loop syntax | Usually inside body |
| Best for | Unknown repetitions | Counting/repetitions | Must execute once |

---

# 24. When Should We Use `while`?

Use `while` when:

- The number of repetitions may not be known.
- The loop depends mainly on a condition.
- Input continues until a condition changes.

Example:

```c
while (num != 0)
{
    scanf("%d", &num);
}
```

---

# 25. When Should We Use `for`?

Use `for` when:

- You know the number of repetitions.
- You are counting.
- You need initialization, condition, and update together.

Example:

```c
for (int i = 1; i <= 100; i++)
{
    printf("%d ", i);
}
```

---

# 26. When Should We Use `do-while`?

Use `do-while` when:

> The program must execute the loop body at least once.

A common example is a menu.

```text
1. Add
2. Subtract
3. Exit
```

The menu should be displayed at least once.

---

# 27. Program: Menu Using `do-while`

```c
#include <stdio.h>

int main()
{
    int choice;

    do
    {
        printf("\n1. Add");
        printf("\n2. Subtract");
        printf("\n3. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Addition selected");
                break;

            case 2:
                printf("Subtraction selected");
                break;

            case 3:
                printf("Program ended");
                break;

            default:
                printf("Invalid choice");
        }

    }
    while (choice != 3);

    return 0;
}
```

Here, the menu appears at least once.

---

# 28. Increment Operators in Loops

Two commonly used increment operators are:

```c
i++
```

and:

```c
++i
```

Both increase `i` by 1.

For simple loop counting, they usually produce the same result.

Example:

```c
for (i = 1; i <= 5; i++)
```

---

# 29. Decrement Operators

The decrement operator is:

```c
--
```

Example:

```c
i--
```

It decreases the value by 1.

Example:

```c
for (i = 10; i >= 1; i--)
{
    printf("%d ", i);
}
```

Output:

```text
10 9 8 7 6 5 4 3 2 1
```

---

# 30. Infinite Loop

An **infinite loop** never stops.

Example:

```c
while (1)
{
    printf("Hello");
}
```

Because:

```c
1
```

is always true.

Another example:

```c
for (;;)
{
    printf("Hello");
}
```

Both create infinite loops.

---

# 31. Common Cause of an Infinite Loop

Consider:

```c
int i = 1;

while (i <= 5)
{
    printf("%d", i);
}
```

There is no:

```c
i++;
```

Therefore, `i` remains `1`.

The condition:

```text
1 <= 5
```

always remains true.

The loop never ends.

Correct:

```c
int i = 1;

while (i <= 5)
{
    printf("%d", i);
    i++;
}
```

---

# 32. Common Mistake: Wrong Semicolon After `while`

Wrong:

```c
while (i <= 10);
{
    printf("%d", i);
    i++;
}
```

The semicolon creates an empty loop body.

Correct:

```c
while (i <= 10)
{
    printf("%d", i);
    i++;
}
```

### Important

Do not confuse this with `do-while`.

For `do-while`, the semicolon is required:

```c
do
{
    // statements
}
while (condition);
```

---

# 33. Common Mistake: Semicolon After `for`

Wrong:

```c
for (i = 1; i <= 10; i++);
{
    printf("%d", i);
}
```

Usually, the semicolon is not intended here.

Correct:

```c
for (i = 1; i <= 10; i++)
{
    printf("%d", i);
}
```

---

# 34. Common Mistake: Forgetting Initialization

Wrong:

```c
int i;

while (i <= 10)
{
    printf("%d", i);
    i++;
}
```

`i` has not been initialized.

Correct:

```c
int i = 1;

while (i <= 10)
{
    printf("%d", i);
    i++;
}
```

---

# 35. Common Mistake: Wrong Update

Suppose:

```c
int i = 1;

while (i <= 10)
{
    printf("%d", i);
    i--;
}
```

The value becomes:

```text
1, 0, -1, -2, ...
```

It will never reach a value greater than `10`.

This can create an infinite loop.

For counting upward:

```c
i++;
```

For counting downward:

```c
i--;
```

---

# 36. Common Mistake: Using `=` Instead of `==`

Wrong:

```c
while (choice = 1)
```

This assigns `1` to `choice`.

For comparison, use:

```c
while (choice == 1)
```

Remember:

```text
=  → assignment
== → comparison
```

---

# 37. Common Mistake: Forgetting Braces

For multiple statements, use braces.

Good:

```c
while (i <= 10)
{
    printf("%d", i);
    i++;
}
```

Without braces:

```c
while (i <= 10)
    printf("%d", i);
    i++;
```

Only the `printf` belongs to the loop.

The `i++` executes outside the loop.

---

# 38. `break` Statement

`break` is used to immediately exit a loop.

Example:

```c
for (int i = 1; i <= 10; i++)
{
    if (i == 5)
    {
        break;
    }

    printf("%d ", i);
}
```

Output:

```text
1 2 3 4
```

When `i` becomes `5`, `break` ends the loop.

---

# 39. `continue` Statement

`continue` skips the current iteration and moves to the next iteration.

Example:

```c
for (int i = 1; i <= 5; i++)
{
    if (i == 3)
    {
        continue;
    }

    printf("%d ", i);
}
```

Output:

```text
1 2 4 5
```

When `i` is `3`, the `printf` is skipped.

---

# 40. `break` vs `continue`

| Statement | Meaning |
|---|---|
| `break` | Completely exits the loop |
| `continue` | Skips current iteration and continues the loop |

Remember:

```text
break    → Stop the loop
continue → Skip this turn
```

---

# 41. Nested Loops

A loop inside another loop is called a **nested loop**.

Example:

```c
for (int i = 1; i <= 3; i++)
{
    for (int j = 1; j <= 3; j++)
    {
        printf("%d %d\n", i, j);
    }
}
```

The inner loop runs completely for every iteration of the outer loop.

---

# 42. Example of Nested Loop

```c
#include <stdio.h>

int main()
{
    int i, j;

    for (i = 1; i <= 3; i++)
    {
        for (j = 1; j <= 3; j++)
        {
            printf("* ");
        }

        printf("\n");
    }

    return 0;
}
```

### Output

```text
* * *
* * *
* * *
```

Nested loops are commonly used for:

- Patterns
- Tables
- Matrix operations
- Two-dimensional arrays

---

# 43. Loop for Finding Sum of Numbers

Example: Find the sum from 1 to 10.

```c
#include <stdio.h>

int main()
{
    int i, sum = 0;

    for (i = 1; i <= 10; i++)
    {
        sum = sum + i;
    }

    printf("Sum = %d", sum);

    return 0;
}
```

### Output

```text
Sum = 55
```

---

# 44. Understanding the Accumulator

In:

```c
int sum = 0;
```

`sum` is called an **accumulator**.

Each iteration adds a new value:

```c
sum = sum + i;
```

Execution:

```text
sum = 0

i = 1 → sum = 0 + 1 = 1
i = 2 → sum = 1 + 2 = 3
i = 3 → sum = 3 + 3 = 6
...
```

This technique is very common in loop programs.

---

# 45. Factorial Using a Loop

Factorial of 5:

```text
5! = 5 × 4 × 3 × 2 × 1
```

Program:

```c
#include <stdio.h>

int main()
{
    int n, i;
    int fact = 1;

    printf("Enter a number: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        fact = fact * i;
    }

    printf("Factorial = %d", fact);

    return 0;
}
```

### Sample Output

```text
Enter a number: 5
Factorial = 120
```

---

# 46. Reverse a Number Using `while`

```c
#include <stdio.h>

int main()
{
    int num, digit, reverse = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    while (num != 0)
    {
        digit = num % 10;
        reverse = reverse * 10 + digit;
        num = num / 10;
    }

    printf("Reverse = %d", reverse);

    return 0;
}
```

### Sample Output

```text
Enter a number: 1234
Reverse = 4321
```

This is an important example of using a `while` loop when the number of iterations depends on the number of digits.

---

# 47. Count Digits Using `while`

```c
#include <stdio.h>

int main()
{
    int num, count = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    while (num != 0)
    {
        num = num / 10;
        count++;
    }

    printf("Number of digits = %d", count);

    return 0;
}
```

For:

```text
12345
```

Output:

```text
Number of digits = 5
```

---

# 48. Important Special Case: Zero

The digit-count program above needs special handling when the input is `0`.

Why?

Because:

```c
while (num != 0)
```

is false immediately.

Therefore, the loop executes zero times.

A safer version is:

```c
if (num == 0)
{
    count = 1;
}
else
{
    while (num != 0)
    {
        num = num / 10;
        count++;
    }
}
```

This is a good example of thinking about **edge cases**.

---

# 49. Loop Dry Run

A **dry run** means manually following the program step by step.

Example:

```c
int i;

for (i = 1; i <= 3; i++)
{
    printf("%d ", i);
}
```

Dry run:

| Step | `i` | Condition | Output |
|---|---:|---|---|
| 1 | 1 | `1 <= 3` TRUE | 1 |
| 2 | 2 | `2 <= 3` TRUE | 2 |
| 3 | 3 | `3 <= 3` TRUE | 3 |
| 4 | 4 | `4 <= 3` FALSE | Stop |

Output:

```text
1 2 3
```

Dry runs are very useful for understanding loops.

---

# 50. Loop Counter

A variable used to control the number of repetitions is often called a **loop counter**.

Example:

```c
for (int i = 1; i <= 10; i++)
```

Here:

```text
i → loop counter
```

It controls how many times the loop executes.

---

# 51. General Pattern for Counting Up

```c
for (i = start; i <= end; i++)
{
    // statements
}
```

Example:

```c
for (i = 1; i <= 10; i++)
{
    printf("%d ", i);
}
```

---

# 52. General Pattern for Counting Down

```c
for (i = start; i >= end; i--)
{
    // statements
}
```

Example:

```c
for (i = 10; i >= 1; i--)
{
    printf("%d ", i);
}
```

---

# 53. General Pattern for Step Values

We do not always need to increase by 1.

Example:

```c
for (i = 2; i <= 20; i = i + 2)
{
    printf("%d ", i);
}
```

Output:

```text
2 4 6 8 10 12 14 16 18 20
```

Similarly:

```c
for (i = 10; i >= 0; i = i - 2)
```

counts:

```text
10 8 6 4 2 0
```

---

# 54. Loop with User Input

A loop can repeatedly accept input.

Example:

```c
int i, num;

for (i = 1; i <= 5; i++)
{
    printf("Enter number: ");
    scanf("%d", &num);
}
```

The user is asked for a number 5 times.

---

# 55. Loop Selection Guide

Use this simple rule:

### Use `for`

When you know the count:

```text
Print 1 to 100
Repeat 10 times
Print table 1 to 10
```

### Use `while`

When repetition depends on a condition:

```text
Read until zero
Process digits until number becomes zero
Continue while password is incorrect
```

### Use `do-while`

When the body must execute at least once:

```text
Menu
User input validation
Repeat a game/menu
```

---

# 56. Common Mistakes Summary

### Mistake 1

Forgetting initialization:

```c
int i;
```

instead of:

```c
int i = 1;
```

### Mistake 2

Forgetting update:

```c
while (i <= 10)
{
    printf("%d", i);
}
```

### Mistake 3

Wrong update direction:

```c
i--
```

when you need to count upward.

### Mistake 4

Unwanted semicolon:

```c
while (condition);
```

### Mistake 5

Missing semicolon in `do-while`:

```c
do
{
}
while (condition)
```

Correct:

```c
do
{
}
while (condition);
```

### Mistake 6

Using `=` instead of `==`.

### Mistake 7

Incorrect loop boundary:

```c
i < 10
```

versus:

```c
i <= 10
```

These produce different results.

### Mistake 8

Creating an infinite loop.

Always check:

```text
Does the loop variable eventually make the condition false?
```

---

# 57. `<` vs `<=` in Loops

This is a very common beginner mistake.

Consider:

```c
for (i = 1; i < 5; i++)
```

Output:

```text
1 2 3 4
```

But:

```c
for (i = 1; i <= 5; i++)
```

Output:

```text
1 2 3 4 5
```

Remember:

```text
<  → excludes the ending value
<= → includes the ending value
```

---

# 58. Loop Checklist

Before running a loop, ask:

### 1. Where does the loop start?

```c
i = 1
```

### 2. What is the condition?

```c
i <= 10
```

### 3. How does the value change?

```c
i++
```

### 4. Will the condition eventually become false?

If not, you may have an infinite loop.

### 5. Should the loop execute zero times?

If yes, `while` or `for` may be suitable.

### 6. Must it execute at least once?

If yes, consider `do-while`.

---

# 59. Quick Comparison

```text
                 LOOP
                   |
       ┌───────────┼───────────┐
       ↓           ↓           ↓
     while        for       do-while
       |           |           |
 condition      init +      body first
 first          condition    then condition
       |           |           |
    0 or more    0 or more    1 or more
```

---

# 60. Final Summary

## `while`

Syntax:

```c
while (condition)
{
    // statements
}
```

Use when the condition should be checked before every iteration.

---

## `for`

Syntax:

```c
for (initialization; condition; update)
{
    // statements
}
```

Use mainly for counting and when the loop structure is known.

---

## `do-while`

Syntax:

```c
do
{
    // statements
}
while (condition);
```

Use when the loop body must execute at least once.

---

# Golden Rules

> **A loop repeats a block of code.**

> **`while` checks the condition before execution.**

> **`for` combines initialization, condition, and update in one place.**

> **`do-while` executes the body at least once.**

> **Always make sure the loop can eventually stop.**

> **Be careful with `<` and `<=`.**

> **Do not forget the update of the loop variable.**

> **Use `break` to exit a loop early.**

> **Use `continue` to skip the current iteration.**

---

# Practice Questions

Try solving these using loops:

1. Print numbers from 1 to 100.
2. Print numbers from 100 to 1.
3. Print all even numbers from 1 to 100.
4. Print all odd numbers from 1 to 100.
5. Print the multiplication table of a number.
6. Find the sum of numbers from 1 to `n`.
7. Find the average of `n` numbers.
8. Find the factorial of a number.
9. Count the digits of a number.
10. Find the reverse of a number.
11. Find the sum of digits of a number.
12. Check whether a number is a palindrome.
13. Check whether a number is prime.
14. Print all prime numbers between 1 and 100.
15. Print a multiplication table using nested loops.
16. Create a menu using `do-while`.
17. Create a simple calculator using `do-while` and `switch`.
18. Print star patterns using nested `for` loops.

---

# One-Line Revision

```text
for      → Usually used when the number of repetitions is known.

while    → Usually used when repetition depends on a condition.

do-while → Used when the body must execute at least once.
```
