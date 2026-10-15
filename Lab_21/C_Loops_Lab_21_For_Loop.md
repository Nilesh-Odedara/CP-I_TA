# C Loops Lab – 21
## Topic: `for` Loop

This lab introduces the `for` loop and uses it for counting, calculations, factors, Fibonacci numbers, digit frequency, and ASCII values.

## What Is a `for` Loop?

A `for` loop is useful when we know how many times a task should repeat or when we can describe the repetition with a counter.

### Syntax

```c
for (initialization; condition; update)
{
    // statements
}
```

- **Initialization:** runs once before the loop starts, such as `i = 1`.
- **Condition:** checked before each repetition. The loop continues while it is true.
- **Update:** changes the loop variable, such as `i++`.

For example, `for (i = 1; i <= 10; i++)` starts at 1, includes 10, and increases `i` by 1 each time.

---

## Program 1: Print 1 to 10, Then Modify It to Print 1 to N

### Problem
First print numbers from 1 to 10. Then use the same idea to read `n` from the user and print numbers from 1 to `n`.

### Algorithm
1. Start.
2. Set `i = 1`.
3. Print `i`.
4. Increase `i` by 1.
5. Repeat while `i <= 10`.
6. Read `n`.
7. Set `i = 1` and print numbers while `i <= n`.
8. Stop.

### C Program

```c
#include <stdio.h>

int main()
{
    int i, n;

    printf("Numbers from 1 to 10:\\n");
    for (i = 1; i <= 10; i++)
    {
        printf("%d ", i);
    }

    printf("\\nEnter the value of n: ");
    scanf("%d", &n);

    if (n < 1)
    {
        printf("Please enter a positive integer.\\n");
        return 0;
    }

    printf("Numbers from 1 to %d:\\n", n);
    for (i = 1; i <= n; i++)
    {
        printf("%d ", i);
    }

    printf("\\n");

    return 0;
}
```

### Sample Output

```text
Numbers from 1 to 10:
1 2 3 4 5 6 7 8 9 10
Enter the value of n: 5
Numbers from 1 to 5:
1 2 3 4 5
```

### Why do we write this?

- `i` is the counter that holds the number currently being printed.
- In `for (i = 1; i <= 10; i++)`, `i = 1` starts at the first required number, `i <= 10` includes 10, and `i++` moves to the next number.
- In the second loop, `n` stores the user's endpoint, so `i <= n` prints through that endpoint.
- We set `i = 1` again because the second sequence must start from 1, not continue from the value left by the first loop.
- The input check avoids printing an invalid 1-to-`n` range when `n` is less than 1.

### Dry Run (second loop when n = 5)

| `i` | Is `i <= 5`? | Action |
|---:|---|---|
| 1 | Yes | Print 1 |
| 2 | Yes | Print 2 |
| 3 | Yes | Print 3 |
| 4 | Yes | Print 4 |
| 5 | Yes | Print 5 |
| 6 | No | Stop |

---

## Program 2: Find the Sum of Numbers from 1 to N

### Problem
Read a positive integer `n` and calculate `1 + 2 + 3 + ... + n`.

### Algorithm
1. Start.
2. Read `n`.
3. Set `sum = 0`.
4. For each `i` from 1 to `n`, add `i` to `sum`.
5. Print `sum`.
6. Stop.

### C Program

```c
#include <stdio.h>

int main()
{
    int n, i, sum = 0;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n < 1)
    {
        printf("Please enter a positive integer.\\n");
        return 0;
    }

    for (i = 1; i <= n; i++)
    {
        sum = sum + i;
    }

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

- `n` is the last number included in the sum.
- `i` represents the current number being added.
- `sum = 0` is necessary because the total starts with no numbers added.
- `i = 1` starts the sequence at 1.
- `i <= n` includes the final number `n`.
- `sum = sum + i` adds the current number to the running total.
- `i++` moves to the next number after each addition.

### Dry Run (n = 5)

| `i` | Calculation | New `sum` |
|---:|---|---:|
| 1 | 0 + 1 | 1 |
| 2 | 1 + 2 | 3 |
| 3 | 3 + 3 | 6 |
| 4 | 6 + 4 | 10 |
| 5 | 10 + 5 | 15 |

---

## Program 3: Print the Multiplication Table of a Given Number

### Problem
Read an integer and print its multiplication table from 1 to 10.

### Algorithm
1. Start.
2. Read `n`.
3. For each `i` from 1 to 10, print `n * i`.
4. Stop.

### C Program

```c
#include <stdio.h>

int main()
{
    int n, i;

    printf("Enter a number: ");
    scanf("%d", &n);

    for (i = 1; i <= 10; i++)
    {
        printf("%d x %d = %d\\n", n, i, n * i);
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

### Why do we write this?

- `n` stores the number whose table is required.
- `i = 1` starts with the first multiplier.
- `i <= 10` creates ten table entries, ending at multiplier 10.
- `n * i` calculates the result for the current multiplier.
- `i++` moves to the next multiplier.

### Dry Run (n = 5)

| `i` | `n * i` | Result |
|---:|---|---:|
| 1 | 5 × 1 | 5 |
| 2 | 5 × 2 | 10 |
| 3 | 5 × 3 | 15 |
| ... | ... | ... |
| 10 | 5 × 10 | 50 |

---

## Program 4: Calculate X to the Power Y Without Using a Power Function

### Problem
Read `x` and a non-negative integer `y`, then calculate `x^y` without using `pow()`.

### Algorithm
1. Start.
2. Read `x` and `y`.
3. Set `result = 1`.
4. Multiply `result` by `x`, `y` times.
5. Print `result`.
6. Stop.

### C Program

```c
#include <stdio.h>

int main()
{
    int x, y, i;
    long long result = 1;

    printf("Enter the base (x): ");
    scanf("%d", &x);

    printf("Enter the non-negative exponent (y): ");
    scanf("%d", &y);

    if (y < 0)
    {
        printf("Please enter a non-negative exponent.\\n");
        return 0;
    }

    for (i = 1; i <= y; i++)
    {
        result = result * x;
    }

    printf("%d raised to the power %d = %lld\\n", x, y, result);

    return 0;
}
```

### Sample Output

```text
Enter the base (x): 2
Enter the non-negative exponent (y): 5
2 raised to the power 5 = 32
```

### Why do we write this?

- `x` is the base and `y` is the exponent.
- `result = 1` is used because 1 is the multiplicative identity. It also correctly handles `x^0 = 1`.
- The loop repeats `y` times because an exponent tells us how many times to multiply by the base.
- `result = result * x` multiplies the current result by one more `x`.
- If `y` is 0, the loop runs zero times and `result` remains 1.
- `long long` allows a larger result than a typical `int`, but very large powers can still overflow.

### Dry Run (x = 2, y = 5)

| `i` | Calculation | `result` |
|---:|---|---:|
| Start | Initial value | 1 |
| 1 | 1 × 2 | 2 |
| 2 | 2 × 2 | 4 |
| 3 | 4 × 2 | 8 |
| 4 | 8 × 2 | 16 |
| 5 | 16 × 2 | 32 |

---

## Program 5: Find the Factorial of a Given Number

### Problem
The factorial of a non-negative integer `n`, written as `n!`, is the product of all integers from 1 through `n`. By definition, `0! = 1`.

### Algorithm
1. Start.
2. Read a non-negative integer `n`.
3. Set `fact = 1`.
4. Multiply `fact` by each number from 1 through `n`.
5. Print `fact`.
6. Stop.

### C Program

```c
#include <stdio.h>

int main()
{
    int n, i;
    unsigned long long fact = 1;

    printf("Enter a non-negative integer (0 to 20): ");
    scanf("%d", &n);

    if (n < 0 || n > 20)
    {
        printf("Please enter a number from 0 to 20.\\n");
        return 0;
    }

    for (i = 1; i <= n; i++)
    {
        fact = fact * i;
    }

    printf("%d! = %llu\\n", n, fact);

    return 0;
}
```

### Sample Output

```text
Enter a non-negative integer (0 to 20): 5
5! = 120
```

### Why do we write this?

- `n` stores the number whose factorial is needed.
- `fact = 1` is important because factorial uses multiplication. Starting at 0 would make every product zero.
- `i = 1` starts multiplying from the first positive integer.
- `i <= n` includes every factor up to `n`.
- `fact = fact * i` keeps multiplying the running product by the current integer.
- For `n = 0`, the loop does not run, so `fact` stays 1, which correctly gives `0! = 1`.
- The program limits input to 20 because factorials grow quickly and larger results do not fit in a typical `unsigned long long`.

### Dry Run (n = 5)

| `i` | Calculation | `fact` |
|---:|---|---:|
| Start | Initial value | 1 |
| 1 | 1 × 1 | 1 |
| 2 | 1 × 2 | 2 |
| 3 | 2 × 3 | 6 |
| 4 | 6 × 4 | 24 |
| 5 | 24 × 5 | 120 |

---

## Program 6: Print All Factors of a Given Number

### Problem
Read a positive integer and print all its positive factors. A factor divides the number exactly, leaving remainder zero.

### Algorithm
1. Start.
2. Read a positive integer `n`.
3. For each `i` from 1 to `n`, check `n % i == 0`.
4. If true, print `i`.
5. Stop.

### C Program

```c
#include <stdio.h>

int main()
{
    int n, i;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n < 1)
    {
        printf("Please enter a positive integer.\\n");
        return 0;
    }

    printf("Factors of %d are: ", n);

    for (i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            printf("%d ", i);
        }
    }

    printf("\\n");

    return 0;
}
```

### Sample Output

```text
Enter a positive integer: 12
Factors of 12 are: 1 2 3 4 6 12
```

### Why do we write this?

- `i` tries every possible factor from 1 through `n`.
- `i = 1` is needed because 1 divides every positive integer.
- `i <= n` includes `n`, because every positive number is a factor of itself.
- `n % i == 0` means dividing `n` by `i` leaves no remainder, so `i` is a factor.
- Only matching values are printed; non-factors are skipped.
- `i++` moves to the next candidate factor.

### Dry Run (n = 12)

| `i` | `12 % i` | Action |
|---:|---:|---|
| 1 | 0 | Print 1 |
| 2 | 0 | Print 2 |
| 3 | 0 | Print 3 |
| 4 | 0 | Print 4 |
| 5 | 2 | Skip |
| 6 | 0 | Print 6 |
| ... | ... | ... |
| 12 | 0 | Print 12 |

---

## Program 7: Print the Fibonacci Series

### Problem
Print the first `n` terms of the Fibonacci series, starting with 0 and 1. Each term after the first two is the sum of the previous two terms.

### Algorithm
1. Start.
2. Read the number of terms `n`.
3. Set `first = 0` and `second = 1`.
4. Repeat `n` times:
   - Print `first`.
   - Calculate `next = first + second`.
   - Move `second` into `first`.
   - Move `next` into `second`.
5. Stop.

### C Program

```c
#include <stdio.h>

int main()
{
    int n, i;
    long long first = 0, second = 1, next;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    if (n < 1)
    {
        printf("Please enter a positive number of terms.\\n");
        return 0;
    }

    printf("Fibonacci series: ");

    for (i = 1; i <= n; i++)
    {
        printf("%lld ", first);

        next = first + second;
        first = second;
        second = next;
    }

    printf("\\n");

    return 0;
}
```

### Sample Output

```text
Enter the number of terms: 8
Fibonacci series: 0 1 1 2 3 5 8 13
```

### Why do we write this?

- `n` stores how many terms the user wants.
- `first = 0` and `second = 1` are the first two Fibonacci terms.
- `i = 1` starts counting the first term, and `i <= n` prints exactly `n` terms.
- `next = first + second` calculates the next term from the current pair.
- `first = second` shifts the second term into the first position.
- `second = next` stores the newly calculated term in the second position.
- The values must be shifted in this order so the old values are used to calculate `next` before being replaced.
- `long long` supports larger values than `int`, although the Fibonacci sequence will eventually exceed its range.

### Dry Run (first 6 terms)

| Loop iteration | Printed `first` | `next = first + second` | New `first` | New `second` |
|---:|---:|---:|---:|---:|
| 1 | 0 | 0 + 1 = 1 | 1 | 1 |
| 2 | 1 | 1 + 1 = 2 | 1 | 2 |
| 3 | 1 | 1 + 2 = 3 | 2 | 3 |
| 4 | 2 | 2 + 3 = 5 | 3 | 5 |
| 5 | 3 | 3 + 5 = 8 | 5 | 8 |
| 6 | 5 | 5 + 8 = 13 | 8 | 13 |

---

## Program 8: Count the Frequency of Each Digit in an Integer

### Problem
Read a non-negative integer and count how many times each digit from 0 to 9 appears. For example, in `12231`, digit 1 appears twice, digit 2 appears twice, and digit 3 appears once.

### Algorithm
1. Start.
2. Read a non-negative integer `n`.
3. Initialize an array `frequency[10]` to zero.
4. If `n` is zero, count one occurrence of digit 0.
5. Otherwise, repeatedly extract `n % 10`, increase that digit's frequency, and remove the last digit using `/ 10`.
6. Print the frequencies of digits that occurred.
7. Stop.

### C Program

```c
#include <stdio.h>

int main()
{
    int n, temp, digit, i;
    int frequency[10] = {0};

    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Please enter a non-negative integer.\\n");
        return 0;
    }

    if (n == 0)
    {
        frequency[0] = 1;
    }
    else
    {
        temp = n;

        while (temp > 0)
        {
            digit = temp % 10;
            frequency[digit]++;
            temp = temp / 10;
        }
    }

    printf("Digit frequencies:\\n");

    for (i = 0; i <= 9; i++)
    {
        if (frequency[i] > 0)
        {
            printf("%d appears %d time(s)\\n", i, frequency[i]);
        }
    }

    return 0;
}
```

### Sample Output

```text
Enter a non-negative integer: 12231
Digit frequencies:
1 appears 2 time(s)
2 appears 2 time(s)
3 appears 1 time(s)
```

### Why do we write this?

- `frequency[10]` has 10 positions: index 0 stores the count of digit 0, index 1 stores the count of digit 1, and so on through index 9.
- `{0}` initializes every frequency to zero because no digits have been counted yet.
- `temp` is a copy of the input so its digits can be removed without changing `n`.
- `digit = temp % 10` extracts the final digit.
- `frequency[digit]++` increases the count for that exact digit.
- `temp = temp / 10` removes the digit that was counted.
- Zero needs a special case because the loop `while (temp > 0)` would not run for input 0.
- The final `for` loop checks every digit from 0 to 9. It prints only digits whose frequency is greater than zero.

### Dry Run (n = 12231)

Digits are extracted from right to left: `1`, `3`, `2`, `2`, `1`.

| Extracted digit | Frequency update | Counts after update |
|---:|---|---|
| 1 | `frequency[1]++` | 1 → 1 |
| 3 | `frequency[3]++` | 1 → 1, 3 → 1 |
| 2 | `frequency[2]++` | 1 → 1, 2 → 1, 3 → 1 |
| 2 | `frequency[2]++` | 1 → 1, 2 → 2, 3 → 1 |
| 1 | `frequency[1]++` | 1 → 2, 2 → 2, 3 → 1 |

The final output lists digits 1, 2, and 3 because the other digits have frequency zero.

---

## Program 9: Print ASCII Characters with Their Values

### Problem
Print characters and their numeric ASCII values. This program displays the standard printable ASCII range from 32 to 126.

### Algorithm
1. Start.
2. Set `i = 32`.
3. Print the character represented by `i` and its numeric value.
4. Increase `i` by 1.
5. Repeat while `i <= 126`.
6. Stop.

### C Program

```c
#include <stdio.h>

int main()
{
    int i;

    printf("ASCII characters and their values:\\n");

    for (i = 32; i <= 126; i++)
    {
        printf("ASCII value %d = character '%c'\\n", i, i);
    }

    return 0;
}
```

### Sample Output (beginning and end)

```text
ASCII characters and their values:
ASCII value 32 = character ' '
ASCII value 33 = character '!'
ASCII value 34 = character '"'
ASCII value 35 = character '#'
ASCII value 36 = character '$'
...
ASCII value 124 = character '|'
ASCII value 125 = character '}'
ASCII value 126 = character '~'
```

The program prints every value from 32 through 126; the sample output omits the middle lines for readability.

### Why do we write this?

- `i` stores the numeric code being printed.
- `i = 32` starts at the first standard printable ASCII value, which is the space character.
- `i <= 126` includes the final printable ASCII character, tilde (`~`).
- `%d` prints the numeric code.
- `%c` interprets the same value as a character.
- `i++` moves to the next ASCII value.
- ASCII values 0–31 and 127 are control codes, not ordinary printable characters, so this program focuses on 32–126.

### Quick Trace

| `i` | `%c` displays | Meaning |
|---:|---|---|
| 32 | space | Blank space |
| 48 | `0` | Digit zero |
| 65 | `A` | Uppercase A |
| 97 | `a` | Lowercase a |
| 126 | `~` | Tilde |

---

## Common Beginner Mistakes

- Using `i < n` when the endpoint `n` should also be included.
- Forgetting to initialize a running sum or product.
- Starting a factorial at 0 instead of 1.
- Updating Fibonacci variables before calculating the next term.
- Forgetting that `n % i == 0` is the condition for checking a factor.
- Trying to count digits of zero with only `while (temp > 0)`.
- Using `frequency[digit]` before ensuring `digit` is between 0 and 9.
- Confusing the number of Fibonacci terms with the value of the last term.
- Assuming every ASCII code is a printable character.

## Quick Revision

| Task | Key logic |
|---|---|
| Count from 1 to N | `for (i = 1; i <= n; i++)` |
| Sum from 1 to N | `sum = sum + i` |
| Multiplication table | `n * i` |
| Power | Repeat multiplication by `x` |
| Factorial | `fact = fact * i`, starting at 1 |
| Factors | `n % i == 0` |
| Fibonacci | `next = first + second` |
| Extract last digit | `digit = temp % 10` |
| Remove last digit | `temp = temp / 10` |
| Digit frequency | `frequency[digit]++` |
| ASCII character | `%c` with an integer code |

## Practice Questions

1. Print all even numbers from 1 to N using a `for` loop.
2. Find the sum of all odd numbers from 1 to N.
3. Calculate `x^y` using a `for` loop for a floating-point base and a non-negative integer exponent.
4. Print the factors of a number in reverse order.
5. Print the Fibonacci series up to a given maximum value.
6. Count how many digits in a number are even and how many are odd.
7. Print ASCII values for uppercase letters only.

## Learning Outcome

After completing this lab, students should be able to construct `for` loops, use counters and running totals, perform repeated multiplication, generate number sequences, test divisibility, process digits, use arrays for digit frequencies, and display character codes.
