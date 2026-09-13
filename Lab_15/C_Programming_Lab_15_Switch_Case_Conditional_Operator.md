# C Operators & Decision-Making Statements Lab – 15

## Topic: Decision Making – Switch Case, Conditional Operator

This lab focuses on two important decision-making concepts in C:

- `switch case`
- Conditional (ternary) operator `?:`

The programs are written in a simple beginner-friendly way.

---

## 1. Demonstrate the Behaviour of Switch Case Without Break

### Problem

Write a C program to demonstrate what happens when `break` is not used inside a `switch` case.

### Explanation

Normally, `break` is used to stop the execution of a `switch` after a matching case is completed.

If `break` is **not written**, C continues executing the statements of the next cases also. This is called **fall-through**.

For example, if the user enters `2`, case `2` will execute, but because there is no `break`, case `3` and the `default` statements may also execute.

### Algorithm

1. Start.
2. Declare an integer variable `choice`.
3. Read `choice` from the user.
4. Use `switch(choice)`.
5. Write several cases without using `break`.
6. Display the output of each executed case.
7. Stop.

### C Program

```c
#include <stdio.h>

int main()
{
    int choice;

    printf("Enter a number (1-3): ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Case 1\n");

        case 2:
            printf("Case 2\n");

        case 3:
            printf("Case 3\n");

        default:
            printf("Default case\n");
    }

    return 0;
}
```

### Sample Output

**Input:**
```text
Enter a number (1-3): 2
```

**Output:**
```text
Case 2
Case 3
Default case
```

### Why did this happen?

The program found `case 2`, so it started execution there.

There is no `break` after `case 2`, so execution continues to:

```text
case 3
default
```

This is called **fall-through behaviour**.

### Important Point

```c
case 2:
    printf("Case 2\n");
    break;
```

With `break`, execution stops after case 2.

Without `break`:

```c
case 2:
    printf("Case 2\n");

case 3:
    printf("Case 3\n");
```

execution continues into case 3.

---

# 2. Check Whether Given Number is Positive or Negative Using Conditional Operator

### Problem

Write a C program to check whether a given number is positive or negative using the conditional operator.

### Explanation

The conditional operator is also called the **ternary operator**.

### Syntax

```c
condition ? expression1 : expression2;
```

For this problem:

```c
number >= 0 ? positive : negative
```

If the condition is true, the first expression is selected.

If the condition is false, the second expression is selected.

### Algorithm

1. Start.
2. Declare an integer variable `number`.
3. Read a number from the user.
4. Use the conditional operator to check whether the number is greater than or equal to zero.
5. Display whether the number is positive or negative.
6. Stop.

### C Program

```c
#include <stdio.h>

int main()
{
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    (number >= 0) ? printf("Number is positive") : printf("Number is negative");

    return 0;
}
```

### Sample Output

```text
Enter a number: 25
Number is positive
```

### Important Note About Zero

Mathematically, **zero is neither positive nor negative**.

If your teacher expects zero to be handled separately, use:

```c
#include <stdio.h>

int main()
{
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    (number > 0) ? printf("Number is positive") :
    (number < 0) ? printf("Number is negative") :
                    printf("Number is zero");

    return 0;
}
```

This version correctly handles all three possibilities:

- Greater than `0` → Positive
- Less than `0` → Negative
- Equal to `0` → Zero

---

# 3. Find the Largest Number from Given 3 Numbers Using Conditional Operator

### Problem

Write a C program to find the largest number from three given numbers using the conditional operator.

### Explanation

We need to compare three numbers.

First compare the first two numbers and find the larger one. Then compare that larger value with the third number.

We can use a nested conditional operator:

```c
largest = (a > b) ? a : b;
largest = (largest > c) ? largest : c;
```

### Algorithm

1. Start.
2. Declare variables `a`, `b`, `c`, and `largest`.
3. Read three numbers.
4. Compare `a` and `b` using the conditional operator.
5. Store the larger number in `largest`.
6. Compare `largest` with `c`.
7. Store the largest value.
8. Display the largest number.
9. Stop.

### C Program

```c
#include <stdio.h>

int main()
{
    int a, b, c, largest;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    largest = (a > b) ? a : b;
    largest = (largest > c) ? largest : c;

    printf("Largest number = %d", largest);

    return 0;
}
```

### Sample Output

```text
Enter three numbers: 25 80 45
Largest number = 80
```

### How the Logic Works

Suppose:

```text
a = 25
b = 80
c = 45
```

First:

```c
largest = (a > b) ? a : b;
```

`25 > 80` is false, so:

```text
largest = 80
```

Then:

```c
largest = (largest > c) ? largest : c;
```

`80 > 45` is true, so:

```text
largest = 80
```

Therefore, `80` is the largest number.

---

# 4. Check Whether Number is Even or Odd Using Conditional Operator

### Problem

Write a C program to check whether a number is even or odd using the conditional operator.

### Explanation

A number is **even** if it is exactly divisible by `2`.

We use the modulus operator `%` to find the remainder.

```c
number % 2
```

If the remainder is `0`, the number is even.

If the remainder is not `0`, the number is odd.

We can combine this condition with the conditional operator:

```c
(number % 2 == 0) ? "Even" : "Odd"
```

### Algorithm

1. Start.
2. Declare an integer variable `number`.
3. Read a number from the user.
4. Calculate `number % 2`.
5. If the remainder is `0`, display "Even".
6. Otherwise, display "Odd".
7. Stop.

### C Program

```c
#include <stdio.h>

int main()
{
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    (number % 2 == 0) ? printf("Number is even") : printf("Number is odd");

    return 0;
}
```

### Sample Output

```text
Enter a number: 24
Number is even
```

Another example:

```text
Enter a number: 17
Number is odd
```

---

# Quick Revision

| Problem | Main Concept |
|---|---|
| Switch without `break` | Fall-through behaviour |
| Positive or Negative | Conditional operator |
| Largest of 3 numbers | Conditional operator |
| Even or Odd | `%` + conditional operator |

---

# Important Concepts

## 1. `break` in Switch

`break` stops the execution of the current `switch`.

Example:

```c
switch (choice)
{
    case 1:
        printf("One");
        break;

    case 2:
        printf("Two");
        break;
}
```

Without `break`, execution can continue into the next case.

---

## 2. Conditional Operator

The conditional operator is written using three parts:

```c
condition ? true_value : false_value;
```

Example:

```c
result = (a > b) ? a : b;
```

If `a > b` is true, `result` gets `a`.

Otherwise, `result` gets `b`.

---

## 3. Modulus Operator `%`

The `%` operator gives the remainder.

Examples:

```text
10 % 2 = 0
15 % 2 = 1
20 % 2 = 0
25 % 2 = 1
```

Therefore:

```c
number % 2 == 0
```

means the number is even.

---

# Common Beginner Mistakes

## Mistake 1: Forgetting `break`

```c
case 1:
    printf("One");

case 2:
    printf("Two");
```

This causes fall-through.

If only case 1 should execute, write:

```c
case 1:
    printf("One");
    break;
```

---

## Mistake 2: Using `=` Instead of `==`

Wrong:

```c
number % 2 = 0
```

Correct:

```c
number % 2 == 0
```

`=` is assignment.

`==` is comparison.

---

## Mistake 3: Confusing `%` with `/`

Wrong for checking even/odd:

```c
number / 2 == 0
```

Correct:

```c
number % 2 == 0
```

`%` gives the remainder.

---

## Mistake 4: Forgetting the `:` in Conditional Operator

Wrong:

```c
condition ? value1 value2
```

Correct:

```c
condition ? value1 : value2
```

The conditional operator always has:

```text
condition ? true_part : false_part
```

---

## Mistake 5: Incorrect Switch Syntax

Wrong:

```c
switch choice
```

Correct:

```c
switch (choice)
```

---

## Mistake 6: Writing a Condition with `case`

Wrong:

```c
case choice == 1:
```

Correct:

```c
case 1:
```

---

# Final Revision

### Switch Case

```c
switch (choice)
{
    case 1:
        // statements
        break;

    case 2:
        // statements
        break;

    default:
        // statements
}
```

### Conditional Operator

```c
condition ? true_part : false_part;
```

### Even/Odd

```c
(number % 2 == 0) ? printf("Even") : printf("Odd");
```

### Positive/Negative

```c
(number > 0) ? printf("Positive") : printf("Negative");
```

### Largest of Two

```c
largest = (a > b) ? a : b;
```

---

# Lab 15 – Key Learning

After completing this lab, students should understand:

- How `switch` behaves when `break` is omitted.
- What **fall-through** means in a `switch`.
- How to use the conditional/ternary operator.
- How to find the largest value using `?:`.
- How to use `%` to check even and odd numbers.
- The difference between `=` and `==`.
- How to write simple decision-making programs using different C operators.
