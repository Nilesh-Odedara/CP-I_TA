# C Loops Lab – 17
## Topic: While Loop

## Aim
To write C programs using the `while` loop for summation, counting, divisibility, multiplication tables, and number series.

## Introduction: What Is a `while` Loop?

A `while` loop repeats a block of code as long as its condition is true.

### Syntax

```c
while (condition)
{
    // statements to repeat
    // update the loop variable
}
```

The condition is checked before each iteration. If the condition is false at the beginning, the loop body does not execute.

### Three Important Parts of a Loop

1. **Initialization:** Give the loop variable its starting value, such as `i = 1`.
2. **Condition:** Decide how long the loop should continue, such as `i <= n`.
3. **Update:** Change the loop variable, such as `i++`, so the loop can eventually stop.

---

# Program 1: Print the Sum of Numbers from 1 to N (A)

## Problem Statement

Accept a number `n` from the user and calculate the sum of all integers from `1` to `n`.

For example, if `n = 5`, the sum is:

`1 + 2 + 3 + 4 + 5 = 15`

## Algorithm

1. Start.
2. Read the value of `n`.
3. Set `i = 1` and `sum = 0`.
4. While `i <= n`:
   - Add `i` to `sum`.
   - Increase `i` by 1.
5. Print `sum`.
6. Stop.

## C Program

```c
#include <stdio.h>

int main(void)
{
    int n, i = 1, sum = 0;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    while (i <= n)
    {
        sum = sum + i;
        i++;
    }

    printf("Sum of numbers from 1 to %d = %d\n", n, sum);

    return 0;
}
```

## Sample Output

```text
Enter a positive integer: 5
Sum of numbers from 1 to 5 = 15
```

## Detailed Explanation: Why Do We Write Each Part?

### 1. Why do we declare `n`, `i`, and `sum`?

```c
int n, i = 1, sum = 0;
```

We need three variables because each one has a different job:

- **`n`** stores the ending number entered by the user. We do not know the ending number before the program runs, so we ask the user.
- **`i`** is the loop variable. It represents the current number we are adding.
- **`sum`** stores the running total of all the numbers added so far.

### 2. Why does `i` start at 1?

The question asks for the sum from **1 to N**. Therefore, the first number we need to add is 1. We initialize `i` to 1 so the loop begins at the correct number.

### 3. Why does `sum` start at 0?

At the beginning, we have not added any numbers. The total is therefore zero. Each time the loop runs, we add the current number to this total.

For example, the total changes like this:

- Initially: `sum = 0`
- Add 1: `sum = 0 + 1`, so `sum = 1`
- Add 2: `sum = 1 + 2`, so `sum = 3`
- Add 3: `sum = 3 + 3`, so `sum = 6`

### 4. Why do we use `scanf()`?

```c
scanf("%d", &n);
```

The user decides the ending number. If the user enters `5`, the loop should add numbers through 5. If the user enters `10`, it should add numbers through 10. `scanf()` stores the entered value in `n`.

### 5. Why do we use `while (i <= n)`?

```c
while (i <= n)
```

We want to include every number from 1 through `n`, including `n` itself. That is why we use `<=` rather than `<`.

If `n = 5`, the loop runs when `i` is 1, 2, 3, 4, and 5. When `i` becomes 6, the condition is false and the loop stops.

### 6. Why do we write `sum = sum + i`?

```c
sum = sum + i;
```

This statement adds the current value of `i` to the total already stored in `sum`. We need to keep the previous total, so we add the new number to it instead of replacing the total with just `i`.

### 7. Why do we write `i++`?

```c
i++;
```

After adding the current number, we need to move to the next number. `i++` increases `i` by 1. Without it, `i` would stay the same and the loop could run forever.

### Dry Run for `n = 5`

| Iteration | `i` | Calculation | New `sum` |
|---:|---:|---|---:|
| 1 | 1 | `0 + 1` | 1 |
| 2 | 2 | `1 + 2` | 3 |
| 3 | 3 | `3 + 3` | 6 |
| 4 | 4 | `6 + 4` | 10 |
| 5 | 5 | `10 + 5` | 15 |

When `i` becomes 6, `i <= n` is false. The loop ends, and the final sum is 15.

---

# Program 2: Read 10 Numbers and Count Odd and Even Numbers (A)

## Problem Statement

Read 10 integers from the user and count how many are even and how many are odd.

## Algorithm

1. Start.
2. Set `i = 1`, `evenCount = 0`, and `oddCount = 0`.
3. While `i <= 10`:
   - Read one number.
   - If `number % 2 == 0`, increase `evenCount`.
   - Otherwise, increase `oddCount`.
   - Increase `i` by 1.
4. Print both counts.
5. Stop.

## C Program

```c
#include <stdio.h>

int main(void)
{
    int number, i = 1;
    int evenCount = 0, oddCount = 0;

    while (i <= 10)
    {
        printf("Enter number %d: ", i);
        scanf("%d", &number);

        if (number % 2 == 0)
        {
            evenCount++;
        }
        else
        {
            oddCount++;
        }

        i++;
    }

    printf("Even numbers count = %d\n", evenCount);
    printf("Odd numbers count = %d\n", oddCount);

    return 0;
}
```

## Sample Output

```text
Enter number 1: 12
Enter number 2: 7
Enter number 3: 4
Enter number 4: 9
Enter number 5: 10
Enter number 6: 3
Enter number 7: 8
Enter number 8: 11
Enter number 9: 6
Enter number 10: 5
Even numbers count = 5
Odd numbers count = 5
```

## Detailed Explanation: Why Do We Write Each Part?

### 1. Why do we declare `number`, `i`, `evenCount`, and `oddCount`?

```c
int number, i = 1;
int evenCount = 0, oddCount = 0;
```

- **`number`** stores each number entered by the user. We can reuse the same variable because we only need to check one input at a time.
- **`i`** counts how many inputs have been taken. It starts at 1 because we are asking for the first number.
- **`evenCount`** counts how many even numbers have been entered.
- **`oddCount`** counts how many odd numbers have been entered.

Both counters start at 0 because we have not entered or counted any numbers yet.

### 2. Why is the condition `i <= 10`?

The question specifically says to get 10 numbers. Starting `i` at 1 and continuing while `i <= 10` makes the loop run exactly 10 times.

If we used `i <= 5`, the program would ask for only five numbers. If we forgot to increase `i`, the loop might never stop.

### 3. Why do we use `scanf()` inside the loop?

We need a new number during every iteration. Placing `scanf()` inside the loop allows the user to enter one number each time the loop repeats.

### 4. Why do we check `number % 2 == 0`?

The `%` operator gives the remainder after division.

- If `number % 2` is `0`, the number is even.
- Otherwise, the number is odd.

For example, `8 % 2` is 0, so 8 is even. `7 % 2` is 1, so 7 is odd.

### 5. Why do we write `evenCount++` and `oddCount++`?

We want to count how many numbers belong to each group. Whenever an even number is found, we increase `evenCount` by 1. Whenever an odd number is found, we increase `oddCount` by 1.

### 6. Why do we write `i++` at the end?

After processing one number, we must move to the next input number. `i++` increases the input count by 1. After the tenth number, `i` becomes 11, the condition becomes false, and the loop stops.

### Example Dry Run

Suppose the first four inputs are `12, 7, 4, 9`.

| Input | Remainder when divided by 2 | Result | Even count | Odd count |
|---:|---:|---|---:|---:|
| 12 | 0 | Even | 1 | 0 |
| 7 | 1 | Odd | 1 | 1 |
| 4 | 0 | Even | 2 | 1 |
| 9 | 1 | Odd | 2 | 2 |

The same process continues until all 10 numbers have been checked.

---

# Program 3: Print Numbers Greater Than 100 and Less Than 200 That Are Divisible by 7 but Not by 5 (A)

## Problem Statement

Print all integers that satisfy these three conditions:

1. The number is greater than 100.
2. The number is less than 200.
3. The number is divisible by 7 but not divisible by 5.

## Algorithm

1. Start.
2. Set `i = 101`.
3. While `i < 200`:
   - Check whether `i % 7 == 0` and `i % 5 != 0`.
   - If both conditions are true, print `i`.
   - Increase `i` by 1.
4. Stop.

## C Program

```c
#include <stdio.h>

int main(void)
{
    int i = 101;

    printf("Required numbers are:\n");

    while (i < 200)
    {
        if (i % 7 == 0 && i % 5 != 0)
        {
            printf("%d ", i);
        }

        i++;
    }

    printf("\n");

    return 0;
}
```

## Sample Output

```text
Required numbers are:
112 119 126 133 147 154 161 168 182 189 196
```

## Detailed Explanation: Why Do We Write Each Part?

### 1. Why does `i` start at 101?

The question asks for numbers **greater than 100**. The first integer greater than 100 is 101, so we start at `i = 101`.

If we started at 100, the program would check 100 even though it is not allowed by the question.

### 2. Why is the loop condition `i < 200`?

The question says **less than 200**, so 200 must not be printed. The condition `i < 200` allows the loop to check numbers through 199. When `i` reaches 200, the loop stops.

### 3. Why do we use an `if` statement inside the loop?

The loop checks every number from 101 to 199, but not every number meets the divisibility rules. The `if` statement decides whether the current number should be printed.

### 4. Why do we write `i % 7 == 0`?

A number is divisible by 7 when dividing it by 7 leaves a remainder of 0.

For example, `112 % 7` is 0, so 112 is divisible by 7.

### 5. Why do we write `i % 5 != 0`?

The phrase “not divisible by 5” means the remainder after division by 5 must **not** be zero. The operator `!=` means “not equal to.”

For example, 112 is not divisible by 5 because `112 % 5` is 2.

### 6. Why do we use `&&`?

```c
if (i % 7 == 0 && i % 5 != 0)
```

`&&` means **AND**. Both conditions must be true for a number to be printed. A number divisible by 7 but also divisible by 5 must be rejected.

### 7. Why do we write `i++` outside the `if` statement?

We need to check every number in the range, whether or not it is printed. Therefore, `i++` must run after every check. If we placed it only inside the `if`, the loop could get stuck on a number that does not satisfy the conditions.

### Check One Valid and One Invalid Number

- **112:** `112 % 7 == 0` is true and `112 % 5 != 0` is true. Print 112.
- **105:** divisible by 7 is true, but `105 % 5 != 0` is false. Do not print 105.

---

# Program 4: Print the Multiplication Table of a Given Number (A)

## Problem Statement

Read a number from the user and print its multiplication table from 1 to 10.

## Algorithm

1. Start.
2. Read `number`.
3. Set `i = 1`.
4. While `i <= 10`:
   - Calculate `number * i`.
   - Print the multiplication expression and result.
   - Increase `i` by 1.
5. Stop.

## C Program

```c
#include <stdio.h>

int main(void)
{
    int number, i = 1;

    printf("Enter a number: ");
    scanf("%d", &number);

    while (i <= 10)
    {
        printf("%d x %d = %d\n", number, i, number * i);
        i++;
    }

    return 0;
}
```

## Sample Output

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

## Detailed Explanation: Why Do We Write Each Part?

### 1. Why do we declare `number` and `i`?

- **`number`** stores the number whose table we want. It comes from the user, so the program can print the table of any number.
- **`i`** is the multiplier. It changes from 1 to 10.

### 2. Why does `i` start at 1?

A normal multiplication table begins with the number multiplied by 1, such as `5 x 1 = 5`. Therefore, the first multiplier is 1.

### 3. Why do we use `scanf()` before the loop?

We need to know which number's table to print before calculating the products. The user enters the number once, and the loop uses that same number for all 10 calculations.

### 4. Why is the condition `i <= 10`?

We want to print the table through the multiplier 10. The `<=` ensures that 10 is included.

### 5. Why do we calculate `number * i`?

The table value changes with each multiplier. If `number = 5`, then the results are `5 * 1`, `5 * 2`, `5 * 3`, and so on.

### 6. Why do we write `i++`?

After printing one line, the multiplier must increase from 1 to 2, then 3, and eventually 10. When it becomes 11, the loop condition is false and the program stops printing the table.

### Small Dry Run for `number = 5`

| `i` | Calculation | Result |
|---:|---|---:|
| 1 | `5 * 1` | 5 |
| 2 | `5 * 2` | 10 |
| 3 | `5 * 3` | 15 |
| 10 | `5 * 10` | 50 |

---

# Program 5: Print the First 50 Terms of the Series 1, 4, 7, 10, ... (B)

## Problem Statement

Print the first 50 terms of the series:

`1, 4, 7, 10, 13, ...`

## Understanding the Series

Look at the difference between consecutive terms:

- `4 - 1 = 3`
- `7 - 4 = 3`
- `10 - 7 = 3`

Each new term is the previous term plus 3. We start with 1 and keep adding 3 to generate the series.

## Algorithm

1. Start.
2. Set `term = 1` and `count = 1`.
3. While `count <= 50`:
   - Print `term`.
   - Add 3 to `term`.
   - Increase `count` by 1.
4. Stop.

## C Program

```c
#include <stdio.h>

int main(void)
{
    int term = 1, count = 1;

    printf("First 50 terms of the series:\n");

    while (count <= 50)
    {
        printf("%d ", term);
        term = term + 3;
        count++;
    }

    printf("\n");

    return 0;
}
```

## Sample Output

```text
First 50 terms of the series:
1 4 7 10 13 16 19 22 25 28
31 34 37 40 43 46 49 52 55 58
61 64 67 70 73 76 79 82 85 88
91 94 97 100 103 106 109 112 115 118
121 124 127 130 133 136 139 142 145 148
```

## Detailed Explanation: Why Do We Write Each Part?

### 1. Why do we need `term` and `count`?

```c
int term = 1, count = 1;
```

These variables have two different jobs:

- **`term`** stores the current number in the series. It starts at 1 because 1 is the first term.
- **`count`** counts how many terms have been printed. It also starts at 1 because we are about to print the first term.

We need `count` because the question asks for 50 terms, not all terms below a particular value. The term value itself is not the number of terms printed.

### 2. Why is the condition `count <= 50`?

The program must print exactly 50 terms. The counter starts at 1 and the loop continues through 50, so the body runs 50 times. If we used `count <= 10`, only 10 terms would be printed.

### 3. Why do we print `term` before updating it?

At the start, `term` is 1, which is the first term we need to print. After printing it, we update it to 4 for the next iteration. This order ensures the first term is not skipped.

### 4. Why do we write `term = term + 3`?

The series increases by 3 each time. This statement generates the next term:

- Start: `term = 1`
- Next: `term = 1 + 3 = 4`
- Next: `term = 4 + 3 = 7`
- Next: `term = 7 + 3 = 10`

We do not use `term++` because that would increase the value by only 1.

### 5. Why do we write `count++` separately?

Updating `term` creates the next series value, while updating `count` tracks the number of terms printed. These are different jobs, so we need both variables and both updates.

### Dry Run for the First Five Terms

| Iteration | `term` printed | `term` after adding 3 | `count` after update |
|---:|---:|---:|---:|
| 1 | 1 | 4 | 2 |
| 2 | 4 | 7 | 3 |
| 3 | 7 | 10 | 4 |
| 4 | 10 | 13 | 5 |
| 5 | 13 | 16 | 6 |

The loop continues in the same way until 50 terms have been printed.

---

# Program 6: Find the Sum of the Series 1 + 4 + 9 + 16 + 25 + 36 + ... (C)

## Problem Statement

The terms `1, 4, 9, 16, 25, 36, ...` are squares of the natural numbers:

- `1 = 1 * 1`
- `4 = 2 * 2`
- `9 = 3 * 3`
- `16 = 4 * 4`
- `25 = 5 * 5`
- `36 = 6 * 6`

This program reads `n` and calculates:

`1² + 2² + 3² + ... + n²`

For example, when `n = 6`, the sum is `1 + 4 + 9 + 16 + 25 + 36 = 91`.

## Algorithm

1. Start.
2. Read `n`.
3. Set `i = 1` and `sum = 0`.
4. While `i <= n`:
   - Calculate `i * i`.
   - Add the square to `sum`.
   - Increase `i` by 1.
5. Print `sum`.
6. Stop.

## C Program

```c
#include <stdio.h>

int main(void)
{
    int n, i = 1, sum = 0;

    printf("Enter the last number n: ");
    scanf("%d", &n);

    while (i <= n)
    {
        sum = sum + (i * i);
        i++;
    }

    printf("Sum of squares from 1 to %d = %d\n", n, sum);

    return 0;
}
```

## Sample Output

```text
Enter the last number n: 6
Sum of squares from 1 to 6 = 91
```

## Detailed Explanation: Why Do We Write Each Part?

### 1. Why do we declare `n`, `i`, and `sum`?

- **`n`** stores the last number entered by the user. If the user enters 6, we need to add the squares from 1 through 6.
- **`i`** represents the current number whose square we are calculating. It starts at 1 because the first term is `1 * 1`.
- **`sum`** stores the running total. It starts at 0 because no squares have been added yet.

### 2. Why do we use `i <= n`?

We need the square of every number from 1 through `n`, including `n`. Therefore, the loop continues while `i` is less than or equal to `n`.

### 3. Why do we write `i * i`?

The terms in the given series are squares. Multiplying the current number by itself calculates its square. For example, when `i = 4`, `i * i` is `4 * 4`, which equals 16.

### 4. Why do we add `i * i` to `sum`?

```c
sum = sum + (i * i);
```

We need the total of all the squares, not just the last square. This statement adds each newly calculated square to the previous total.

### 5. Why do we write `i++`?

After adding the square of the current number, we need to calculate the square of the next number. `i++` changes `i` from 1 to 2, then 3, and so on. When `i` becomes greater than `n`, the loop stops.

### Dry Run for `n = 4`

| `i` | Square (`i * i`) | Calculation | New `sum` |
|---:|---:|---|---:|
| 1 | 1 | `0 + 1` | 1 |
| 2 | 4 | `1 + 4` | 5 |
| 3 | 9 | `5 + 9` | 14 |
| 4 | 16 | `14 + 16` | 30 |

The result for `n = 4` is 30.

**Note about the question:** The listed series suggests squares, so this program treats `n` as the last natural number and calculates `1² + 2² + ... + n²`. If your instructor intends a different final term, confirm the exact series before submitting.

---

# Common Mistakes in `while` Loops

## 1. Forgetting to initialize the loop variable

Incorrect or missing initialization can make the loop behave unpredictably. Give the variable a suitable starting value, such as `i = 1`.

## 2. Forgetting to update the loop variable

If `i` never changes, a condition such as `i <= n` may remain true forever. Use `i++` or another suitable update.

## 3. Using the wrong loop condition

- Use `i <= n` when the final value `n` must be included.
- Use `i < 200` when 200 must not be included.
- Use `count <= 50` to repeat 50 times when `count` begins at 1.

## 4. Confusing `=` and `==`

- `=` assigns a value, for example `sum = 0`.
- `==` compares values, for example `number % 2 == 0`.

## 5. Using `%` incorrectly

- `number % 2 == 0`: the number is divisible by 2.
- `number % 7 == 0`: the number is divisible by 7.
- `number % 5 != 0`: the number is not divisible by 5.

## 6. Starting a counter at the wrong value

If the question asks for 50 terms and the counter starts at 1, use `count <= 50` to print exactly 50 terms.

## 7. Updating a series incorrectly

For `1, 4, 7, 10, ...`, add 3 each time. For the square series, calculate `i * i`. First identify the pattern, then choose the correct update or calculation.

## 8. Adding a semicolon after `while`

```c
while (i <= 10);  // Usually a mistake when a loop body follows
{
    printf("%d", i);
    i++;
}
```

The semicolon creates an empty loop body. Do not put it after the `while` condition when the loop body is written in braces.

---

# Quick Revision Table

| Program | Important logic | Why it is used |
|---|---|---|
| Sum from 1 to `n` | `sum = sum + i` | Adds each current number to the running total |
| Count odd/even | `number % 2 == 0` | Checks whether a number is even |
| Divisibility | `i % 7 == 0 && i % 5 != 0` | Requires divisibility by 7 and not by 5 |
| Multiplication table | `number * i` | Calculates each table value |
| Series `1, 4, 7, 10, ...` | `term = term + 3` | Generates the next term |
| Sum of squares | `sum = sum + (i * i)` | Adds each square to the running total |

# Practice Questions

1. Modify Program 1 to calculate the sum from 1 to 100.
2. Modify Program 2 to count positive and negative numbers from 10 inputs.
3. Print numbers between 1 and 100 that are divisible by both 3 and 5.
4. Print a multiplication table up to 20.
5. Print the first 30 terms of `2, 5, 8, 11, ...`.
6. Calculate the sum of cubes from 1 to `n`.

# Key Takeaways

- Initialize every variable with a value that makes sense for its job.
- Start the loop at the first value required by the problem.
- Choose a condition that includes or excludes the endpoint correctly.
- Use a counter to track iterations and a sum variable to store a running total.
- Update the loop variable so the loop can finish.
- For number series, identify the pattern before writing the code.
- Always ask: **Why do we need this variable, why does it start here, and how does its value change?**
