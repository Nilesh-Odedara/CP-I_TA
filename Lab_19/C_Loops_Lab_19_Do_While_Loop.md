# C Loops Lab – 19
## Topic: Do-While Loop

A `do-while` loop repeats a block of code while a condition is true. The important difference from a `while` loop is that **the body runs at least once**, because the condition is checked after the body.

### Syntax

```c
do
{
    // statements
} while (condition);
```

Notice the semicolon `;` after `while (condition)`.

---

## Program 1: Print the Sum of Numbers from 1 to N

### Problem
Read a positive integer `n` and calculate `1 + 2 + 3 + ... + n` using a `do-while` loop.

### Algorithm
1. Start.
2. Read `n`.
3. Set `i = 1` and `sum = 0`.
4. Add `i` to `sum`.
5. Increase `i` by 1.
6. Repeat while `i <= n`.
7. Print `sum`.
8. Stop.

### C Program

```c
#include <stdio.h>

int main(void)
{
    int n, i = 1, sum = 0;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n < 1)
    {
        printf("Please enter a positive integer.\\n");
        return 0;
    }

    do
    {
        sum = sum + i;
        i++;
    } while (i <= n);

    printf("Sum from 1 to %d = %d\\n", n, sum);

    return 0;
}
```

### Sample Output

```text
Enter a positive integer: 5
Sum from 1 to 5 = 15
```

### Why do we write this?

- `n` stores the last number entered by the user.
- `i = 1` because counting starts from 1.
- `sum = 0` because no numbers have been added yet. Zero is the correct starting total.
- `sum = sum + i` adds the current number to the running total.
- `i++` moves to the next number so the loop makes progress.
- `i <= n` includes `n` in the sum.
- The `if` check ensures that the input is positive. A `do-while` loop runs once even if its condition would initially be false, so validating the input first avoids adding an unwanted value.

### Dry Run (n = 5)

| `i` before addition | `sum = sum + i` | `sum` after addition | `i` after `i++` |
|---:|---|---:|---:|
| 1 | 0 + 1 | 1 | 2 |
| 2 | 1 + 2 | 3 | 3 |
| 3 | 3 + 3 | 6 | 4 |
| 4 | 6 + 4 | 10 | 5 |
| 5 | 10 + 5 | 15 | 6 |

When `i` becomes 6, `i <= 5` is false, so the loop stops.

---

## Program 2: Count Odd and Even Numbers from 10 Inputs

### Problem
Read 10 integers from the user and count how many are even and how many are odd.

### Algorithm
1. Start.
2. Set `count = 1`, `even = 0`, and `odd = 0`.
3. Read a number.
4. If `number % 2 == 0`, increase `even`; otherwise, increase `odd`.
5. Increase `count`.
6. Repeat while `count <= 10`.
7. Print the even and odd counts.
8. Stop.

### C Program

```c
#include <stdio.h>

int main(void)
{
    int number, count = 1;
    int even = 0, odd = 0;

    do
    {
        printf("Enter number %d: ", count);
        scanf("%d", &number);

        if (number % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }

        count++;
    } while (count <= 10);

    printf("Even numbers: %d\\n", even);
    printf("Odd numbers: %d\\n", odd);

    return 0;
}
```

### Sample Output

```text
Enter number 1: 12
Enter number 2: 7
Enter number 3: 4
Enter number 4: 9
Enter number 5: 10
Enter number 6: 3
Enter number 7: 8
Enter number 8: 5
Enter number 9: 2
Enter number 10: 11
Even numbers: 5
Odd numbers: 5
```

### Why do we write this?

- `number` stores the current input. We reuse it for all 10 inputs because we only need to classify each number immediately.
- `count = 1` labels the first input as number 1.
- `even = 0` and `odd = 0` because no values have been counted at the beginning.
- `number % 2` gives the remainder after division by 2. A remainder of zero means the number is even.
- `even++` or `odd++` increases the appropriate count by one.
- `count++` advances to the next input.
- `count <= 10` makes the loop process inputs 1 through 10. It stops after the tenth input, when `count` becomes 11.

### Quick Trace

For inputs `12, 7, 4, 9`, the counts change as follows:

| Input | Check | Even count | Odd count |
|---:|---|---:|---:|
| 12 | Even | 1 | 0 |
| 7 | Odd | 1 | 1 |
| 4 | Even | 2 | 1 |
| 9 | Odd | 2 | 2 |

The same process continues until all 10 numbers are read.

---

## Program 3: Print Numbers Between 100 and 200 Divisible by 7 but Not by 5

### Problem
Print all integers that are greater than 100 and less than 200, divisible by 7, and not divisible by 5.

### Algorithm
1. Start.
2. Set `i = 101`.
3. If `i % 7 == 0` and `i % 5 != 0`, print `i`.
4. Increase `i` by 1.
5. Repeat while `i < 200`.
6. Stop.

### C Program

```c
#include <stdio.h>

int main(void)
{
    int i = 101;

    do
    {
        if (i % 7 == 0 && i % 5 != 0)
        {
            printf("%d ", i);
        }

        i++;
    } while (i < 200);

    printf("\\n");

    return 0;
}
```

### Sample Output

```text
112 119 126 133 147 154 161 168 182 189 196
```

### Why do we write this?

- `i = 101` because the question says greater than 100. Starting at 100 would include a value that is not allowed.
- `i < 200` because 200 itself must not be included.
- `i % 7 == 0` checks whether 7 divides the number exactly.
- `i % 5 != 0` rejects numbers that divide exactly by 5.
- `&&` means both conditions must be true at the same time.
- `i++` checks the next integer each time.
- `printf("%d ", i)` prints each matching number on the same line with a space after it.

### Common Mistake
Do not use `i <= 200`; that would test 200 even though the problem says the number must be less than 200. Also, 105 is excluded because it is divisible by 5.

---

## Program 4: Print the Multiplication Table of a Given Number

### Problem
Read an integer and print its multiplication table from 1 to 10.

### Algorithm
1. Start.
2. Read `n`.
3. Set `i = 1`.
4. Print `n * i`.
5. Increase `i` by 1.
6. Repeat while `i <= 10`.
7. Stop.

### C Program

```c
#include <stdio.h>

int main(void)
{
    int n, i = 1;

    printf("Enter a number: ");
    scanf("%d", &n);

    do
    {
        printf("%d x %d = %d\\n", n, i, n * i);
        i++;
    } while (i <= 10);

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

### Why do we write this?

- `n` stores the number whose table is needed.
- `i = 1` starts the multiplier at 1.
- `n * i` calculates the current table result.
- `i++` moves from one multiplier to the next.
- `i <= 10` prints entries from 1 through 10.
- The `do` body prints before checking the condition, so the table always prints at least one line.

### Dry Run (n = 5)

| `i` | Calculation | Result |
|---:|---|---:|
| 1 | 5 × 1 | 5 |
| 2 | 5 × 2 | 10 |
| 3 | 5 × 3 | 15 |
| ... | ... | ... |
| 10 | 5 × 10 | 50 |

---

## Program 5: Print the First 50 Terms of the Series 1, 4, 7, 10, ...

### Problem
Print the first 50 terms of a series that starts at 1 and increases by 3 each time.

### Algorithm
1. Start.
2. Set `term = 1` and `count = 1`.
3. Print `term`.
4. Add 3 to `term`.
5. Increase `count` by 1.
6. Repeat while `count <= 50`.
7. Stop.

### C Program

```c
#include <stdio.h>

int main(void)
{
    int term = 1, count = 1;

    do
    {
        printf("%d ", term);
        term = term + 3;
        count++;
    } while (count <= 50);

    printf("\\n");

    return 0;
}
```

### Sample Output (first terms shown)

```text
1 4 7 10 13 16 19 22 25 28 ... 148
```

The program prints all 50 terms; the sample shortens the middle with `...` to keep it readable. The 50th term is 148.

### Why do we write this?

- `term = 1` stores the first term given in the series.
- `count = 1` records that the first term is about to be printed.
- `printf` displays the current term before it is changed.
- `term = term + 3` creates the next term. For example, 1 becomes 4, 4 becomes 7, and 7 becomes 10.
- `count++` records one more printed term.
- `count <= 50` ensures exactly 50 terms are printed.

### Dry Run

| Count | Printed term | Next term after adding 3 |
|---:|---:|---:|
| 1 | 1 | 4 |
| 2 | 4 | 7 |
| 3 | 7 | 10 |
| 4 | 10 | 13 |
| 5 | 13 | 16 |

**Remember:** update the term by 3, not by 1. The count increases by 1 because it counts how many terms have been printed.

---

## Program 6: Find the Sum of the Series 1² + 2² + 3² + ... + N²

### Problem
The given series is written as `1 + 4 + 9 + 16 + 25 + 36 + n`. This is commonly understood as the sum of squares: `1² + 2² + 3² + ... + N²`. This program reads `N` and calculates the sum of squares from 1 through `N`.

### Algorithm
1. Start.
2. Read `n`.
3. Set `i = 1` and `sum = 0`.
4. Calculate `i * i` and add it to `sum`.
5. Increase `i` by 1.
6. Repeat while `i <= n`.
7. Print `sum`.
8. Stop.

### C Program

```c
#include <stdio.h>

int main(void)
{
    int n, i = 1, sum = 0;

    printf("Enter the value of N: ");
    scanf("%d", &n);

    if (n < 1)
    {
        printf("Please enter a positive integer.\\n");
        return 0;
    }

    do
    {
        sum = sum + (i * i);
        i++;
    } while (i <= n);

    printf("Sum of squares from 1 to %d = %d\\n", n, sum);

    return 0;
}
```

### Sample Output

```text
Enter the value of N: 6
Sum of squares from 1 to 6 = 91
```

Because `1² + 2² + 3² + 4² + 5² + 6² = 1 + 4 + 9 + 16 + 25 + 36 = 91`.

### Why do we write this?

- `n` is the last integer whose square should be included.
- `i = 1` starts with the first square, `1 * 1`.
- `sum = 0` gives the running total a correct starting value.
- `i * i` calculates the square of the current number. For example, when `i = 4`, `i * i` is 16.
- `sum = sum + (i * i)` adds that square to the total.
- `i++` moves to the next integer.
- `i <= n` includes the square of `n`.
- The positive-input check prevents a `do-while` loop from calculating a term when `n` is not positive.

### Dry Run (n = 4)

| `i` | Square (`i * i`) | Running sum |
|---:|---:|---:|
| 1 | 1 | 1 |
| 2 | 4 | 5 |
| 3 | 9 | 14 |
| 4 | 16 | 30 |

The final answer is 30.

---

## Important Rules for `do-while`

1. The loop body executes at least once.
2. The condition is checked after the body.
3. A semicolon is required after `while (condition);`.
4. Update the loop variable so the loop can eventually stop.
5. Choose the starting value carefully to match the question.
6. Use `<=` when the endpoint should be included; use `<` when it should not be included.
7. Initialize counters and running totals before the loop.

## Common Beginner Mistakes

- Forgetting the semicolon after `while (condition)`.
- Forgetting to update the loop variable, causing an infinite loop.
- Starting at 100 when the requirement says greater than 100.
- Using `i <= 200` when the requirement says less than 200.
- Starting `sum` at 1 instead of 0.
- Updating a series term by 1 instead of by 3.
- Confusing the number of loop repetitions with the value printed by the loop.

## Quick Revision

| Task | Key logic |
|---|---|
| Sum from 1 to N | `sum = sum + i` |
| Count even numbers | `number % 2 == 0` |
| Count odd numbers | `number % 2 != 0` |
| Divisible by 7 | `i % 7 == 0` |
| Not divisible by 5 | `i % 5 != 0` |
| Multiplication table | `n * i` |
| Series 1, 4, 7, 10, ... | `term = term + 3` |
| Sum of squares | `sum = sum + (i * i)` |

## Practice Questions

1. Print the sum of all even numbers from 1 to N using `do-while`.
2. Count how many of 10 input numbers are positive, negative, or zero.
3. Print all numbers between 1 and 100 that are divisible by both 3 and 4.
4. Print the multiplication table of a number up to 20.
5. Print the first 30 terms of the series 2, 5, 8, 11, ...
6. Calculate `1² + 2² + ... + N²` and show the running total after each term.

## Learning Outcome

After completing this lab, students should be able to use a `do-while` loop, update counters and totals, apply conditions with the modulus operator, generate number series, and trace how variables change during loop execution.
