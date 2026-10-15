# C Loops Lab – 18
## Topic: While Loop

## Aim
To practise using `while` loops in C to process digits, calculate totals and averages, and check prime, perfect, palindrome, and Armstrong numbers.

## Introduction: Understanding the `while` Loop

A `while` loop repeats a block of code as long as its condition is true.

### Syntax

```c
while (condition)
{
    // statements to repeat
    // update a variable so the loop can finish
}
```

A loop usually needs three things:

1. **Initialization:** Give a variable its starting value.
2. **Condition:** Decide when the loop should continue.
3. **Update:** Change a variable during each iteration.

For number-digit problems, two especially useful operators are:

- `number % 10` gets the last digit of a number. For example, `583 % 10` gives `3`.
- `number / 10` removes the last digit when `number` is an integer. For example, `583 / 10` gives `58`.

These operations are often used together to examine a number one digit at a time.

---

# Program 1: Find the Sum of the First and Last Digit of a Given Number (A)

## Problem Statement

Read an integer and calculate the sum of its first digit and last digit.

For example, for `5832`:
- First digit = `5`
- Last digit = `2`
- Sum = `5 + 2 = 7`

## Algorithm

1. Start.
2. Read `number`.
3. Make a copy of the number in `temp`.
4. Find the last digit using `number % 10`.
5. Repeatedly divide `temp` by 10 until only one digit remains.
6. The remaining digit is the first digit.
7. Add the first and last digits and print the sum.
8. Stop.

## C Program

```c
#include <stdio.h>

int main(void)
{
    int number, temp, firstDigit, lastDigit, sum;

    printf("Enter a positive integer: ");
    scanf("%d", &number);

    temp = number;
    lastDigit = number % 10;

    while (temp >= 10)
    {
        temp = temp / 10;
    }

    firstDigit = temp;
    sum = firstDigit + lastDigit;

    printf("First digit = %d\n", firstDigit);
    printf("Last digit = %d\n", lastDigit);
    printf("Sum of first and last digit = %d\n", sum);

    return 0;
}
```

## Sample Output

```text
Enter a positive integer: 5832
First digit = 5
Last digit = 2
Sum of first and last digit = 7
```

## Detailed Explanation: Why Do We Write Each Part?

### 1. Why do we declare these variables?

```c
int number, temp, firstDigit, lastDigit, sum;
```

- **`number`** stores the number entered by the user.
- **`temp`** is a working copy used to find the first digit. We use a copy so that the original input remains available.
- **`lastDigit`** stores the last digit.
- **`firstDigit`** stores the first digit.
- **`sum`** stores the addition of the first and last digits.

### 2. Why do we write `temp = number`?

We need to repeatedly remove digits to find the first digit. If we changed `number` directly, we would lose the original number. Copying it into `temp` lets us work on `temp` without changing `number`.

### 3. Why does `number % 10` give the last digit?

When a whole number is divided by 10, the remainder is its last digit. For example, `5832 % 10` is `2`.

### 4. Why do we use `while (temp >= 10)`?

If `temp` has more than one digit, it is at least 10. We keep removing its last digit until it is a single digit. That single digit is the first digit of the original positive number.

### 5. Why do we write `temp = temp / 10`?

Integer division by 10 removes the last digit:
- `5832 / 10` becomes `583`
- `583 / 10` becomes `58`
- `58 / 10` becomes `5`

Now `temp` is 5, so the loop stops.

### Dry Run for `5832`

| Step | `temp` before division | `temp` after division |
|---:|---:|---:|
| 1 | 5832 | 583 |
| 2 | 583 | 58 |
| 3 | 58 | 5 |

The last digit is 2, the first digit is 5, and their sum is 7.

**Note:** This beginner version expects a positive integer. If your course requires negative inputs, the program should first convert the input to a non-negative value safely.

---

# Program 2: Find the Sum and Average of as Many Numbers as the User Wants (A)

## Problem Statement

Keep accepting numbers from the user for as long as the user wants. At the end, display the sum and average of all entered numbers.

This program asks the user after each number whether they want to enter another one. Enter `1` to continue and `0` to stop.

## Algorithm

1. Start.
2. Set `sum = 0` and `count = 0`.
3. Read a number.
4. Add it to `sum` and increase `count`.
5. Ask whether the user wants to enter another number.
6. Repeat while the answer is `1`.
7. If `count > 0`, calculate `average = (float)sum / count`.
8. Print the sum and average.
9. Stop.

## C Program

```c
#include <stdio.h>

int main(void)
{
    int number, choice = 1, count = 0;
    int sum = 0;
    float average;

    while (choice == 1)
    {
        printf("Enter a number: ");
        scanf("%d", &number);

        sum = sum + number;
        count++;

        printf("Do you want to enter another number? (1 = Yes, 0 = No): ");
        scanf("%d", &choice);
    }

    if (count > 0)
    {
        average = (float)sum / count;

        printf("Sum = %d\n", sum);
        printf("Average = %.2f\n", average);
    }
    else
    {
        printf("No numbers were entered.\n");
    }

    return 0;
}
```

## Sample Output

```text
Enter a number: 10
Do you want to enter another number? (1 = Yes, 0 = No): 1
Enter a number: 20
Do you want to enter another number? (1 = Yes, 0 = No): 1
Enter a number: 30
Do you want to enter another number? (1 = Yes, 0 = No): 0
Sum = 60
Average = 20.00
```

## Detailed Explanation: Why Do We Write Each Part?

### 1. Why do we need `sum` and `count`?

- **`sum`** stores the total of all numbers entered. It starts at 0 because nothing has been added yet.
- **`count`** stores how many numbers the user entered. It also starts at 0 because no numbers have been entered yet.

We need both variables because the average is calculated by dividing the sum by the number of values.

### 2. Why is `choice = 1`?

The condition of the loop is `choice == 1`. Setting `choice` to 1 before the loop lets the program start by asking for the first number. After each number, the user chooses whether to continue.

### 3. Why do we use `while (choice == 1)`?

The number of inputs is not fixed. We cannot write a condition such as `count <= 10` because the user may want to enter 3, 10, or 20 numbers. Instead, the user's choice controls when the loop stops.

### 4. Why do we write `sum = sum + number`?

Each new input must be added to the total already calculated. For example, if the inputs are 10, 20, and 30:
- After 10: `sum = 0 + 10 = 10`
- After 20: `sum = 10 + 20 = 30`
- After 30: `sum = 30 + 30 = 60`

### 5. Why do we write `count++`?

Every time the user enters a number, the count increases by one. If the user enters three numbers, `count` becomes 3.

### 6. Why do we use `(float)sum / count`?

Average means total divided by the number of values. We convert `sum` to `float` so division can produce a decimal answer. Without the conversion, integer division could discard the fractional part.

### 7. Why do we check `count > 0`?

We must not divide by zero. If no number has been entered, `count` is zero and an average cannot be calculated. The `if` statement handles that situation safely.

---

# Program 3: Check Whether a Number Is Prime or Not (A)

## Problem Statement

Read an integer and check whether it is a prime number.

A **prime number** is a whole number greater than 1 that has exactly two positive factors: 1 and itself. Examples include 2, 3, 5, and 7.

## Algorithm

1. Start.
2. Read `n`.
3. If `n < 2`, report that it is not prime.
4. Otherwise, set `i = 2`.
5. While `i < n`:
   - If `n % i == 0`, mark the number as not prime and stop checking.
   - Otherwise, increase `i` by 1.
6. If no divisor was found, report that the number is prime.
7. Stop.

## C Program

```c
#include <stdio.h>

int main()
{
    int n, i = 2, isPrime = 1;

    printf("Enter an integer: ");
    scanf("%d", &n);

    if (n < 2)
    {
        isPrime = 0;
    }
    else
    {
        while (i < n)
        {
            if (n % i == 0)
            {
                isPrime = 0;
                break;
            }

            i++;
        }
    }

    if (isPrime == 1)
    {
        printf("%d is a prime number.\n", n);
    }
    else
    {
        printf("%d is not a prime number.\n", n);
    }

    return 0;
}
```

## Sample Output

```text
Enter an integer: 7
7 is a prime number.
```

## Detailed Explanation: Why Do We Write Each Part?

### 1. Why do we use `n`, `i`, and `isPrime`?

- **`n`** stores the number to test.
- **`i`** is a possible divisor. We start at 2 because every positive integer is divisible by 1, and checking 1 would not help us decide whether the number is prime.
- **`isPrime`** records the result. It starts at 1, meaning “assume prime until a divisor proves otherwise.” If we find a divisor, we set it to 0.

### 2. Why is every number less than 2 not prime?

Prime numbers must be greater than 1. Therefore, negative numbers, 0, and 1 are not prime.

### 3. Why does the loop start with `i = 2`?

We test divisors beginning at 2. If any number from 2 through `n - 1` divides `n` evenly, then `n` has a factor other than 1 and itself and is not prime.

### 4. Why do we use `n % i == 0`?

The `%` operator finds the remainder. If the remainder is 0, `n` is divisible by `i`.

For example, `8 % 2` is 0, so 8 is not prime. But none of 2, 3, 4, 5, or 6 divides 7 evenly, so 7 is prime.

### 5. Why do we use `break`?

As soon as one divisor is found, we already know the number is not prime. There is no need to test more divisors, so `break` exits the loop immediately.

### Dry Run for `n = 7`

| `i` | `7 % i` | Meaning |
|---:|---:|---|
| 2 | 1 | Not divisible |
| 3 | 1 | Not divisible |
| 4 | 3 | Not divisible |
| 5 | 2 | Not divisible |
| 6 | 1 | Not divisible |

No divisor is found, so `isPrime` remains 1 and 7 is reported as prime.

---

# Program 4: Print the Digits of a Given Number (A)

## Problem Statement

Read an integer and print its digits one by one.

For example, for `583`, the digit-extraction process gets 3, then 8, then 5. This program prints digits from **last to first**: `3 8 5`.

## Algorithm

1. Start.
2. Read `number`.
3. While `number > 0`:
   - Find the last digit using `number % 10`.
   - Print the digit.
   - Remove the last digit using `number / 10`.
4. Stop.

## C Program

```c
#include <stdio.h>

int main(void)
{
    int number, digit;

    printf("Enter a positive integer: ");
    scanf("%d", &number);

    if (number == 0)
    {
        printf("0");
    }
    else
    {
        while (number > 0)
        {
            digit = number % 10;
            printf("%d ", digit);
            number = number / 10;
        }
    }

    printf("\n");

    return 0;
}
```

## Sample Output

```text
Enter a positive integer: 583
3 8 5
```

## Detailed Explanation: Why Do We Write Each Part?

### 1. Why do we declare `number` and `digit`?

- **`number`** stores the input and is gradually shortened as digits are removed.
- **`digit`** stores the last digit extracted during each iteration.

Here we intentionally change `number` because we need to remove one digit at a time.

### 2. Why do we use `while (number > 0)`?

As long as `number` is greater than zero, it has digits left to process. When all digits have been removed, integer division makes `number` become 0 and the loop stops.

### 3. Why do we use `number % 10`?

The remainder after dividing by 10 gives the last digit. For example, `583 % 10` is 3.

### 4. Why do we print the digit before dividing?

We need to save and print the current last digit before removing it from `number`. If we divide first, we would lose that digit.

### 5. Why do we use `number = number / 10`?

Integer division by 10 removes the last digit:
- `583 / 10` becomes 58
- `58 / 10` becomes 5
- `5 / 10` becomes 0

The loop then ends.

### Dry Run for `583`

| `number` before | `number % 10` | Printed digit | `number` after `/ 10` |
|---:|---:|---:|---:|
| 583 | 3 | 3 | 58 |
| 58 | 8 | 8 | 5 |
| 5 | 5 | 5 | 0 |

**Note:** This program expects a non-negative integer and prints digits in reverse order. Printing them in the original left-to-right order requires a different approach.

---

# Program 5: Check Whether a Number Is Perfect or Not (B)

## Problem Statement

A **perfect number** is a positive integer equal to the sum of its positive divisors excluding itself.

For example, 6 is perfect because its proper divisors are 1, 2, and 3, and `1 + 2 + 3 = 6`.

## Algorithm

1. Start.
2. Read `n`.
3. Set `i = 1` and `sum = 0`.
4. While `i < n`:
   - If `n % i == 0`, add `i` to `sum`.
   - Increase `i` by 1.
5. If `sum == n` and `n > 0`, print that the number is perfect.
6. Otherwise, print that it is not perfect.
7. Stop.

## C Program

```c
#include <stdio.h>

int main(void)
{
    int n, i = 1, sum = 0;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    i = 1;

    while (i < n)
    {
        if (n % i == 0)
        {
            sum = sum + i;
        }

        i++;
    }

    if (n > 0 && sum == n)
    {
        printf("%d is a perfect number.\n", n);
    }
    else
    {
        printf("%d is not a perfect number.\n", n);
    }

    return 0;
}
```

## Sample Output

```text
Enter a positive integer: 6
6 is a perfect number.
```

## Detailed Explanation: Why Do We Write Each Part?

### 1. Why do we need `n`, `i`, and `sum`?

- **`n`** stores the number we want to check.
- **`i`** checks possible divisors of `n`. It begins at 1 because 1 can be a proper divisor.
- **`sum`** stores the total of the proper divisors. It begins at 0 because no divisors have been added yet.

### 2. Why is the condition `i < n`?

A perfect number uses divisors **excluding the number itself**. Therefore, we check from 1 through `n - 1`, not including `n`.

### 3. Why do we use `n % i == 0`?

A value `i` is a divisor of `n` when the remainder is zero. For example, 6 is divisible by 1, 2, and 3, so those values are added to `sum`.

### 4. Why do we add `i` to `sum` only inside the `if` statement?

Not every number below `n` is a divisor. We add only those numbers that divide `n` evenly. For 6, we add 1, 2, and 3, but not 4 or 5.

### 5. Why do we compare `sum == n`?

The definition says that a perfect number equals the sum of its proper divisors. If the sum is equal to `n`, the number is perfect. The extra condition `n > 0` ensures the input is a positive integer.

### Dry Run for `n = 6`

| `i` | Is `6 % i == 0`? | New `sum` |
|---:|---|---:|
| 1 | Yes | 1 |
| 2 | Yes | 3 |
| 3 | Yes | 6 |
| 4 | No | 6 |
| 5 | No | 6 |

The final sum is 6, which equals `n`, so 6 is perfect.

---

# Program 6: Check Whether a Number Is Prime Using a Flag (B)

## Problem Statement

Check whether a number is prime using a **flag variable**.

A flag is a variable used to remember whether a condition has been found. Here, `flag = 0` means no divisor has been found yet, and `flag = 1` means a divisor has been found.

## Algorithm

1. Start.
2. Read `n`.
3. Set `flag = 0` and `i = 2`.
4. If `n < 2`, it is not prime.
5. Otherwise, while `i < n`:
   - If `n % i == 0`, set `flag = 1` and stop the loop.
   - Otherwise, increase `i` by 1.
6. If `flag == 0` and `n >= 2`, print prime.
7. Otherwise, print not prime.
8. Stop.

## C Program

```c
#include <stdio.h>

int main(void)
{
    int n, i = 2, flag = 0;

    printf("Enter an integer: ");
    scanf("%d", &n);

    if (n < 2)
    {
        flag = 1;
    }
    else
    {
        while (i < n)
        {
            if (n % i == 0)
            {
                flag = 1;
                break;
            }

            i++;
        }
    }

    if (flag == 0)
    {
        printf("%d is a prime number.\n", n);
    }
    else
    {
        printf("%d is not a prime number.\n", n);
    }

    return 0;
}
```

## Sample Output

```text
Enter an integer: 9
9 is not a prime number.
```

## Detailed Explanation: Why Do We Write Each Part?

### 1. What is a flag, and why do we need it?

A flag is a variable that remembers whether something has happened. We use `flag` to remember whether a divisor has been found.

- `flag = 0`: no divisor has been found yet.
- `flag = 1`: a divisor has been found, so the number is not prime.

We start with 0 because we have not tested any divisors yet.

### 2. Why does `i` start at 2?

We do not need to test 1 because every positive integer is divisible by 1. We start at 2 to search for a divisor other than 1 and the number itself.

### 3. Why do we check `n < 2` separately?

Prime numbers must be greater than 1. Without this check, values such as 0 or 1 might incorrectly be treated as prime because the loop would not run.

In this program, setting `flag = 1` for `n < 2` marks the number as not prime.

### 4. Why do we set `flag = 1` when a divisor is found?

If `n % i == 0`, the number divides evenly by `i`. This proves that the number is not prime, so we change the flag to 1.

### 5. Why do we use `break`?

Once a divisor has been found, checking more values cannot change the result. `break` stops the loop and saves unnecessary checks.

### 6. Why do we check `flag == 0` at the end?

If the flag is still 0, no divisor was found and `n` is at least 2, so the number is prime. If the flag is 1, the number is not prime.

**Difference from Program 3:** Both programs check primality. Program 3 uses a variable named `isPrime` that starts at 1 and changes to 0 when a divisor is found. This program uses a flag that starts at 0 and changes to 1 when a divisor is found. Both approaches are valid; the important thing is to use the flag consistently.

---

# Program 7: Check Whether a Number Is a Palindrome or Not (C)

## Problem Statement

A **palindrome number** reads the same from left to right and right to left.

Examples: `121`, `1331`, and `7` are palindrome numbers. `123` is not a palindrome because reversing it gives `321`.

## Algorithm

1. Start.
2. Read `n`.
3. Store the original number in `original`.
4. Set `reverse = 0` and `temp = n`.
5. While `temp > 0`:
   - Get the last digit: `digit = temp % 10`.
   - Add it to the reversed number: `reverse = reverse * 10 + digit`.
   - Remove the last digit: `temp = temp / 10`.
6. Compare `original` with `reverse`.
7. Print whether it is a palindrome.
8. Stop.

## C Program

```c
#include <stdio.h>

int main(void)
{
    int n, original, temp, digit, reverse = 0;

    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    original = n;
    temp = n;

    while (temp > 0)
    {
        digit = temp % 10;
        reverse = reverse * 10 + digit;
        temp = temp / 10;
    }

    if (original == reverse)
    {
        printf("%d is a palindrome number.\n", original);
    }
    else
    {
        printf("%d is not a palindrome number.\n", original);
    }

    return 0;
}
```

## Sample Output

```text
Enter a non-negative integer: 121
121 is a palindrome number.
```

## Detailed Explanation: Why Do We Write Each Part?

### 1. Why do we need `original`, `temp`, `digit`, and `reverse`?

- **`n`** receives the user's input.
- **`original`** saves the original number so we can compare it with the reversed number later.
- **`temp`** is a working copy whose digits we remove one by one.
- **`digit`** stores the last digit extracted in each iteration.
- **`reverse`** builds the number in reverse order. It starts at 0 because no digits have been added yet.

### 2. Why do we copy `n` into `original` and `temp`?

The process changes `temp` until it becomes 0. We need `original` to preserve the original input for the final comparison. `n` is also kept unchanged.

### 3. Why is `reverse` initialized to 0?

We need an empty starting value before constructing the reversed number. Each digit is added to this value as the loop runs.

### 4. Why do we write `digit = temp % 10`?

The remainder after dividing by 10 gives the last digit. For 121, the digits are extracted in this order: 1, then 2, then 1.

### 5. Why do we write `reverse = reverse * 10 + digit`?

Multiplying `reverse` by 10 shifts its existing digits one place to the left, creating an empty ones place for the new digit. Adding `digit` puts the extracted digit in that place.

For 121:
- Start: `reverse = 0`
- Extract 1: `0 * 10 + 1 = 1`
- Extract 2: `1 * 10 + 2 = 12`
- Extract 1: `12 * 10 + 1 = 121`

### 6. Why do we write `temp = temp / 10`?

Integer division removes the last digit already processed. This lets the loop move to the next digit and eventually stop when `temp` becomes 0.

### 7. Why do we compare `original == reverse`?

A number is a palindrome when reversing its digits produces the same number. If both values are equal, it is a palindrome; otherwise, it is not.

### Dry Run for `n = 121`

| `temp` before | `digit` | Calculation for `reverse` | `reverse` after | `temp` after |
|---:|---:|---|---:|---:|
| 121 | 1 | `0 * 10 + 1` | 1 | 12 |
| 12 | 2 | `1 * 10 + 2` | 12 | 1 |
| 1 | 1 | `12 * 10 + 1` | 121 | 0 |

The original number and reversed number are both 121, so it is a palindrome.

**Note:** This beginner program is intended for non-negative integers. For very large values, reversing a number may exceed the range of `int`.

---

# Program 8: Check Whether a Number Is an Armstrong Number or Not (C)

## Problem Statement

An **Armstrong number** is a number equal to the sum of each of its digits raised to the power of the number of digits.

For a three-digit number, each digit is cubed and the cubes are added.

Example: `153` has three digits:

`1³ + 5³ + 3³ = 1 + 125 + 27 = 153`

So, 153 is an Armstrong number.

## Algorithm

1. Start.
2. Read `n`.
3. Save the original number in `original` and `temp`.
4. Count the number of digits in `temp`.
5. Reset `temp = n` and set `sum = 0`.
6. While `temp > 0`:
   - Extract the last digit.
   - Calculate that digit raised to the number of digits using repeated multiplication.
   - Add the result to `sum`.
   - Remove the last digit.
7. Compare `sum` with `original`.
8. Print whether the number is an Armstrong number.
9. Stop.

## C Program

```c
#include <stdio.h>

int main(void)
{
    int n, original, temp, digit;
    int digits = 0, sum = 0, power, i;

    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    original = n;
    temp = n;

    /* Count the digits. */
    if (temp == 0)
    {
        digits = 1;
    }
    else
    {
        while (temp > 0)
        {
            digits++;
            temp = temp / 10;
        }
    }

    /* Calculate the sum of each digit raised to 'digits'. */
    temp = n;

    while (temp > 0)
    {
        digit = temp % 10;
        power = 1;
        i = 1;

        while (i <= digits)
        {
            power = power * digit;
            i++;
        }

        sum = sum + power;
        temp = temp / 10;
    }

    if (sum == original)
    {
        printf("%d is an Armstrong number.\n", original);
    }
    else
    {
        printf("%d is not an Armstrong number.\n", original);
    }

    return 0;
}
```

## Sample Output

```text
Enter a non-negative integer: 153
153 is an Armstrong number.
```

## Detailed Explanation: Why Do We Write Each Part?

### 1. Why do we need `original`, `temp`, `digit`, `digits`, `power`, and `sum`?

- **`n`** stores the number entered by the user.
- **`original`** preserves the number for the final comparison.
- **`temp`** is a working copy that can be divided by 10 repeatedly.
- **`digit`** stores the digit currently being processed.
- **`digits`** counts how many digits are in the number.
- **`power`** calculates the current digit raised to the required power.
- **`sum`** stores the total of all digit powers.
- **`i`** controls the inner loop that multiplies a digit by itself the required number of times.

### 2. Why do we count the digits first?

The power used in an Armstrong number depends on how many digits the number has. For a three-digit number, use the third power; for a four-digit number, use the fourth power.

For example:
- `153` has 3 digits, so calculate `1³ + 5³ + 3³`.
- `9474` has 4 digits, so calculate `9⁴ + 4⁴ + 7⁴ + 4⁴`.

### 3. Why do we divide `temp` by 10 while counting digits?

Every integer division by 10 removes one digit:
- `153 / 10` becomes 15
- `15 / 10` becomes 1
- `1 / 10` becomes 0

We increase `digits` once for each removal. The special case `temp == 0` sets the digit count to 1 because the number 0 has one digit.

### 4. Why do we reset `temp = n` after counting digits?

The first loop changes `temp` until it becomes 0. We still need to process all the original digits, so we restore the copy from `n` before starting the second loop.

### 5. Why do we set `power = 1` for each digit?

We need a fresh multiplication result for every new digit. Starting at 1 allows repeated multiplication to work correctly: multiplying 1 by the digit `digits` times calculates the required power.

### 6. Why is there another `while` loop inside the first digit-processing loop?

The outer loop processes each digit. The inner loop multiplies the current digit by itself `digits` times.

For digit 5 in a three-digit number:
- Start: `power = 1`
- First multiplication: `1 * 5 = 5`
- Second multiplication: `5 * 5 = 25`
- Third multiplication: `25 * 5 = 125`

Therefore, `power` becomes \(5^3 = 125\).

### 7. Why do we add `power` to `sum`?

Each digit contributes its own power to the Armstrong total. After calculating a digit's power, we add it to `sum`. Once every digit has been processed, `sum` contains the total required by the definition.

### 8. Why do we compare `sum == original`?

An Armstrong number is equal to the sum of its digit powers. If the calculated sum matches the original number, it is an Armstrong number.

### Dry Run for `153`

There are 3 digits, so each digit is cubed.

| Digit | Calculation | Power | Running sum |
|---:|---|---:|---:|
| 3 | `3 * 3 * 3` | 27 | 27 |
| 5 | `5 * 5 * 5` | 125 | 152 |
| 1 | `1 * 1 * 1` | 1 | 153 |

The final sum is 153, equal to the original number. Therefore, 153 is an Armstrong number.

**Note:** This program is intended for non-negative integers. The repeated-multiplication method avoids needing the `pow()` function and helps beginners see how the power is calculated.

---

# Common Mistakes in `while` Loop Programs

1. **Forgetting to update a variable:** Without `i++` or `temp = temp / 10`, a loop may never finish.
2. **Changing the original number too early:** Save a copy if you need the original value later, as in palindrome and Armstrong programs.
3. **Using `/ 10` before saving the last digit:** First use `% 10` to get the digit, then divide by 10 to remove it.
4. **Starting a sum at the wrong value:** Running totals such as `sum` should normally start at 0.
5. **Using an incorrect divisor condition:** `n % i == 0` means `i` divides `n` evenly.
6. **Forgetting the special case for numbers below 2:** 0 and 1 are not prime.
7. **Dividing by zero when calculating an average:** Check that at least one number was entered before dividing by `count`.
8. **Mixing up the flag meaning:** Decide whether 0 means “not found” or “false” and use the same meaning throughout the program.
9. **Not resetting a working copy:** If one loop changes `temp` to 0, restore it before using it in another loop.
10. **Assuming digits print from left to right:** Using `% 10` processes digits from right to left.

# Quick Revision Table

| Program | Key concept | Important statement |
|---|---|---|
| Sum of first and last digit | Extract first and last digits | `number % 10`, repeated `/ 10` |
| Sum and average | Running total and count | `sum = sum + number` |
| Prime number | Search for divisors | `n % i == 0` |
| Print digits | Extract and remove digits | `digit = number % 10` |
| Perfect number | Add proper divisors | `sum = sum + i` |
| Prime using flag | Remember whether a divisor exists | `flag = 1` when found |
| Palindrome | Reverse and compare | `reverse = reverse * 10 + digit` |
| Armstrong | Add each digit's required power | `sum = sum + power` |

# Practice Questions

1. Find the sum of the first and last digits of a number such as 4729.
2. Modify Program 2 to also display how many numbers were entered.
3. Print all prime numbers from 1 to 100.
4. Print the digits of a number in reverse order and then try to print them in original order.
5. Check whether 28 is a perfect number.
6. Test the flag-based prime program with 1, 2, 9, and 13.
7. Check whether 1331 is a palindrome.
8. Test the Armstrong program with 153, 370, 9474, and 123.

# Key Takeaways

- Use `% 10` to extract the last digit and integer `/ 10` to remove it.
- Keep a copy of the original number if you need to compare it later.
- A running total should start at 0.
- A counter should increase once for each item counted.
- A prime number is greater than 1 and has no divisor between 2 and itself minus 1.
- A perfect number equals the sum of its proper divisors.
- A palindrome equals its reverse.
- An Armstrong number equals the sum of its digits raised to the number of digits.
- When using nested loops, clearly identify what the outer loop does and what the inner loop does.
