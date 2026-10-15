# C Loops Lab – 20
## Topic: Do-While Loop

This lab practices the `do-while` loop using digit operations, counting, averages, prime numbers, perfect numbers, palindromes, and Armstrong numbers.

## What Is a `do-while` Loop?

A `do-while` loop executes its body first and checks the condition afterward. Therefore, its body runs at least once.

### Syntax

```c
do
{
    // statements
} while (condition);
```

Remember the semicolon after `while (condition);`.

---

## Program 1: Find the Sum of the First and Last Digit of a Number

### Problem
Read a positive integer and calculate the sum of its first and last digits.

### Algorithm
1. Start.
2. Read a positive integer `n`.
3. Set `last = n % 10`.
4. Repeatedly divide a copy of `n` by 10 until only one digit remains.
5. The remaining digit is the first digit.
6. Add the first and last digits and print the sum.
7. Stop.

### C Program

```c
#include <stdio.h>

int main()
{
    int n, temp, first, last;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Please enter a non-negative integer.\\n");
        return 0;
    }

    temp = n;
    last = n % 10;

    do
    {
        first = temp % 10;
        temp = temp / 10;
    } while (temp > 0);

    printf("First digit = %d\\n", first);
    printf("Last digit = %d\\n", last);
    printf("Sum of first and last digit = %d\\n", first + last);

    return 0;
}
```

### Sample Output

```text
Enter a positive integer: 5729
First digit = 5
Last digit = 9
Sum of first and last digit = 14
```

### Why do we write this?

- `n` stores the number entered by the user.
- `temp` is a copy of `n`, so we can change it without losing the original input.
- `last = n % 10` gets the last digit. For `5729`, the remainder after dividing by 10 is `9`.
- `temp % 10` gets the current last digit of `temp`.
- `temp = temp / 10` removes the last digit using integer division. For example, `5729 / 10` becomes `572`.
- The loop continues while `temp > 0`. Eventually, `temp` becomes zero after the final digit is removed.
- The last value assigned to `first` is the first digit of the original number.
- Zero is allowed: its first and last digits are both zero.

### Dry Run (n = 5729)

| `temp` before loop body | `temp % 10` (`first`) | `temp / 10` |
|---:|---:|---:|
| 5729 | 9 | 572 |
| 572 | 2 | 57 |
| 57 | 7 | 5 |
| 5 | 5 | 0 |

The final `first` value is `5`; the last digit saved earlier is `9`. Their sum is `14`.

---

## Program 2: Find the Sum and Average of as Many Numbers as the User Wants

### Problem
Allow the user to enter any number of integers. After each input, ask whether they want to enter another number. At the end, display the sum and average.

### Algorithm
1. Start.
2. Initialize `sum = 0` and `count = 0`.
3. Read a number.
4. Add the number to `sum` and increase `count`.
5. Ask whether the user wants to continue.
6. Repeat if the answer is `1`.
7. Calculate `average = (float) sum / count`.
8. Print the sum and average.
9. Stop.

### C Program

```c
#include <stdio.h>

int main()
{
    int number, sum = 0, count = 0, choice;
    float average;

    do
    {
        printf("Enter a number: ");
        scanf("%d", &number);

        sum = sum + number;
        count++;

        printf("Do you want to enter another number? (1 = Yes, 0 = No): ");
        scanf("%d", &choice);
    } while (choice == 1);

    average = (float) sum / count;

    printf("Sum = %d\\n", sum);
    printf("Average = %.2f\\n", average);

    return 0;
}
```

### Sample Output

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

### Why do we write this?

- `number` stores each new input. The same variable can be reused because each number is added to the total immediately.
- `sum = 0` starts the running total at zero because nothing has been added yet.
- `count = 0` records how many numbers have been entered so far.
- `choice` stores the user's decision: `1` means continue, and any other value stops the loop.
- `sum = sum + number` adds the current input to the running total.
- `count++` increases the number of inputs counted.
- `average = (float) sum / count` converts `sum` to a floating-point value so the average can include decimal places.
- The loop always reads at least one number, so `count` is at least 1 and the average does not divide by zero.

### Dry Run

| Number entered | Running sum | Count |
|---:|---:|---:|
| 10 | 10 | 1 |
| 20 | 30 | 2 |
| 30 | 60 | 3 |

Average = `60 / 3 = 20.00`.

---

## Program 3: Check Whether a Number Is Prime or Not

### Problem
A prime number is an integer greater than 1 that has exactly two positive factors: 1 and itself. This program checks whether a number is prime using a `do-while` loop.

### Algorithm
1. Start.
2. Read `n`.
3. If `n < 2`, report that it is not prime.
4. Otherwise, set `i = 2` and `isPrime = 1`.
5. Test whether `n % i == 0`.
6. If divisible, set `isPrime = 0`.
7. Increase `i` and continue testing while `i < n` and `isPrime == 1`.
8. Print the result.
9. Stop.

### C Program

```c
#include <stdio.h>

int main()
{
    int n, i = 2, isPrime = 1;

    printf("Enter an integer: ");
    scanf("%d", &n);

    if (n < 2)
    {
        printf("%d is not a prime number.\\n", n);
        return 0;
    }

    do
    {
        if (n % i == 0)
        {
            isPrime = 0;
            break;
        }

        i++;
    } while (i < n);

    if (isPrime == 1)
    {
        printf("%d is a prime number.\\n", n);
    }
    else
    {
        printf("%d is not a prime number.\\n", n);
    }

    return 0;
}
```

### Sample Output 1

```text
Enter an integer: 7
7 is a prime number.
```

### Sample Output 2

```text
Enter an integer: 8
8 is not a prime number.
```

### Why do we write this?

- `n` stores the number being checked.
- `i = 2` starts testing from 2 because every integer greater than 1 is divisible by 1, and that does not help identify a prime.
- `isPrime = 1` means “assume prime unless a divisor is found.”
- `n % i == 0` checks whether `i` divides `n` exactly.
- If a divisor is found, `isPrime = 0` records that the number is not prime.
- `break` immediately exits the loop when a divisor is found; checking more values is unnecessary.
- `i++` tests the next possible divisor.
- Values below 2 are handled separately because they are not prime.

### Dry Run (n = 8)

| `i` | `8 % i` | Action |
|---:|---:|---|
| 2 | 0 | Divisor found; not prime |

The loop stops immediately because 8 is divisible by 2.

---

## Program 4: Print the Digits of a Given Number

### Problem
Read a non-negative integer and print its digits from right to left.

### Algorithm
1. Start.
2. Read `n`.
3. If `n` is negative, display a message and stop.
4. In each loop, get the last digit using `% 10`.
5. Print the digit.
6. Remove the last digit using `/ 10`.
7. Repeat while the remaining number is greater than zero.
8. Stop.

### C Program

```c
#include <stdio.h>

int main()
{
    int n, temp, digit;

    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Please enter a non-negative integer.\\n");
        return 0;
    }

    temp = n;

    do
    {
        digit = temp % 10;
        printf("%d ", digit);
        temp = temp / 10;
    } while (temp > 0);

    printf("\\n");

    return 0;
}
```

### Sample Output

```text
Enter a non-negative integer: 4826
6 2 8 4
```

### Why do we write this?

- `temp` is used so the original input can remain unchanged.
- `digit = temp % 10` extracts the rightmost digit.
- `printf` displays the digit before it is removed.
- `temp = temp / 10` removes the rightmost digit.
- `temp > 0` keeps the loop going while digits remain.
- The `do-while` loop also prints `0` when the input itself is zero, because the body runs once.

### Dry Run (n = 4826)

| `temp` | `temp % 10` (printed digit) | `temp / 10` |
|---:|---:|---:|
| 4826 | 6 | 482 |
| 482 | 2 | 48 |
| 48 | 8 | 4 |
| 4 | 4 | 0 |

**Note:** This prints digits in reverse order. To print `4826` from left to right, you would need a different approach.

---

## Program 5: Check Whether a Number Is Perfect

### Problem
A perfect number is a positive integer equal to the sum of its positive factors excluding itself. For example, `6 = 1 + 2 + 3`, so 6 is perfect.

### Algorithm
1. Start.
2. Read `n`.
3. Initialize `i = 1` and `sum = 0`.
4. Check each number from 1 to `n / 2`.
5. If `n % i == 0`, add `i` to `sum`.
6. Increase `i` by 1 and repeat.
7. If `sum == n`, the number is perfect; otherwise it is not.
8. Stop.

### C Program

```c
#include <stdio.h>

int main()
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
        if (n % i == 0)
        {
            sum = sum + i;
        }

        i++;
    } while (i <= n / 2);

    if (sum == n)
    {
        printf("%d is a perfect number.\\n", n);
    }
    else
    {
        printf("%d is not a perfect number.\\n", n);
    }

    return 0;
}
```

### Sample Output 1

```text
Enter a positive integer: 6
6 is a perfect number.
```

### Sample Output 2

```text
Enter a positive integer: 10
10 is not a perfect number.
```

### Why do we write this?

- `n` stores the number being checked.
- `i = 1` starts checking possible proper divisors from 1.
- `sum = 0` starts the total of the divisors at zero.
- `n % i == 0` means `i` divides `n` with no remainder, so `i` is a factor.
- `sum = sum + i` adds each factor to the total.
- We only need to check up to `n / 2`, because no positive divisor smaller than `n` can be greater than half of `n`.
- Finally, `sum == n` checks the definition of a perfect number.
- For `n = 1`, the loop adds no proper divisors, so the sum is 0 and 1 is correctly not classified as perfect.

### Dry Run (n = 6)

| `i` | Is `6 % i == 0`? | Running sum |
|---:|---|---:|
| 1 | Yes | 1 |
| 2 | Yes | 3 |
| 3 | Yes | 6 |

The loop ends after `i = 3` because `6 / 2 = 3`. The sum is 6, so the number is perfect.

---

## Program 6: Check Whether a Number Is Prime Using a Flag

### Problem
Check whether a number is prime using a `flag` variable. Here, `flag = 0` means no divisor has been found yet; `flag = 1` means a divisor was found.

### Algorithm
1. Start.
2. Read `n`.
3. If `n < 2`, report that it is not prime.
4. Set `flag = 0` and `i = 2`.
5. Check divisors while `i < n` and no divisor has been found.
6. If `n % i == 0`, set `flag = 1`.
7. Increase `i` and continue if necessary.
8. If `flag == 0`, print prime; otherwise, print not prime.
9. Stop.

### C Program

```c
#include <stdio.h>

int main()
{
    int n, i = 2, flag = 0;

    printf("Enter an integer: ");
    scanf("%d", &n);

    if (n < 2)
    {
        printf("%d is not a prime number.\\n", n);
        return 0;
    }

    do
    {
        if (n % i == 0)
        {
            flag = 1;
            break;
        }

        i++;
    } while (i < n);

    if (flag == 0)
    {
        printf("%d is a prime number.\\n", n);
    }
    else
    {
        printf("%d is not a prime number.\\n", n);
    }

    return 0;
}
```

### Sample Output

```text
Enter an integer: 9
9 is not a prime number.
```

### Why do we write this?

- A **flag** is a variable used to remember whether a condition has occurred.
- `flag = 0` means no divisor has been found at the start.
- `i = 2` starts checking possible divisors from 2.
- If `n % i == 0`, `flag = 1` records that the number has a divisor other than 1 and itself.
- `break` exits as soon as a divisor is found.
- At the end, `flag == 0` means no divisor was found, so `n` is prime. `flag == 1` means it is not prime.
- The special check for `n < 2` is necessary because 0, 1, and negative integers are not prime.

### Difference Between Programs 3 and 6

Both programs use the same basic divisor test. Program 3 uses the variable `isPrime`, while Program 6 uses `flag` to record that a divisor has been found. In Program 6, the flag begins at 0 and changes to 1 when a divisor is discovered.

---

## Program 7: Check Whether a Number Is a Palindrome

### Problem
A palindrome number reads the same from left to right and right to left. Examples include `121`, `1331`, and `7`.

### Algorithm
1. Start.
2. Read a non-negative integer `n`.
3. Save the original number in `original`.
4. Set `reverse = 0` and `temp = n`.
5. Extract the last digit of `temp`.
6. Append that digit to `reverse` using `reverse = reverse * 10 + digit`.
7. Remove the last digit from `temp`.
8. Repeat while `temp > 0`.
9. If `original == reverse`, the number is a palindrome.
10. Stop.

### C Program

```c
#include <stdio.h>

int main()
{
    int n, original, temp, digit, reverse = 0;

    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Please enter a non-negative integer.\\n");
        return 0;
    }

    original = n;
    temp = n;

    do
    {
        digit = temp % 10;
        reverse = reverse * 10 + digit;
        temp = temp / 10;
    } while (temp > 0);

    if (original == reverse)
    {
        printf("%d is a palindrome number.\\n", original);
    }
    else
    {
        printf("%d is not a palindrome number.\\n", original);
    }

    return 0;
}
```

### Sample Output 1

```text
Enter a non-negative integer: 121
121 is a palindrome number.
```

### Sample Output 2

```text
Enter a non-negative integer: 123
123 is not a palindrome number.
```

### Why do we write this?

- `original` preserves the number so it can be compared after the digits have been processed.
- `temp` is a working copy that loses one digit each loop.
- `reverse = 0` starts the reversed number with no digits.
- `digit = temp % 10` extracts the last digit.
- `reverse = reverse * 10 + digit` shifts the existing digits left by one decimal place and places the new digit at the end. For example, if `reverse` is 12 and `digit` is 1, the new value is `12 * 10 + 1 = 121`.
- `temp = temp / 10` removes the digit just processed.
- Comparing `original` with `reverse` tells us whether the number reads the same in both directions.
- The program treats 0 as a palindrome.

### Dry Run (n = 121)

| `temp` | `digit` | `reverse = reverse * 10 + digit` | New `temp` |
|---:|---:|---:|---:|
| 121 | 1 | 0 × 10 + 1 = 1 | 12 |
| 12 | 2 | 1 × 10 + 2 = 12 | 1 |
| 1 | 1 | 12 × 10 + 1 = 121 | 0 |

`original` and `reverse` are both 121, so it is a palindrome.

---

## Program 8: Check Whether a Number Is an Armstrong Number

### Problem
An Armstrong number is a non-negative integer equal to the sum of each digit raised to the power of the number of digits. For example, `153` has three digits and `1³ + 5³ + 3³ = 153`.

### Algorithm
1. Start.
2. Read a non-negative integer `n`.
3. Count the digits in the number. Treat 0 as having one digit.
4. Copy `n` into `temp` and set `sum = 0`.
5. Extract each digit.
6. Calculate that digit raised to the digit count using a loop.
7. Add the power to `sum`.
8. Remove the processed digit and repeat until no digits remain.
9. If `sum == n`, print Armstrong; otherwise, print not Armstrong.
10. Stop.

### C Program

```c
#include <stdio.h>

int main()
{
    int n, temp, digit, digits = 0;
    int power, j, sum = 0;

    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Please enter a non-negative integer.\\n");
        return 0;
    }

    /* Count the digits. */
    temp = n;

    do
    {
        digits++;
        temp = temp / 10;
    } while (temp > 0);

    /* Find the sum of each digit raised to 'digits'. */
    temp = n;

    do
    {
        digit = temp % 10;
        power = 1;
        j = 1;

        do
        {
            power = power * digit;
            j++;
        } while (j <= digits);

        sum = sum + power;
        temp = temp / 10;
    } while (temp > 0);

    if (sum == n)
    {
        printf("%d is an Armstrong number.\\n", n);
    }
    else
    {
        printf("%d is not an Armstrong number.\\n", n);
    }

    return 0;
}
```

### Sample Output 1

```text
Enter a non-negative integer: 153
153 is an Armstrong number.
```

### Sample Output 2

```text
Enter a non-negative integer: 123
123 is not an Armstrong number.
```

### Why do we write this?

- `digits` counts how many digits are in the number. It starts at 0 because no digits have been counted yet.
- The first `do-while` repeatedly divides `temp` by 10. Each division removes one digit, so `digits` increases once per digit. The `do-while` also correctly counts zero as one digit.
- `sum = 0` starts the total of the powered digits.
- `digit = temp % 10` extracts one digit at a time.
- `power = 1` is the starting value for multiplication. The code multiplies by `digit` exactly `digits` times.
- `j = 1` tracks how many multiplications have happened.
- The inner `do-while` calculates `digit` raised to `digits`. For example, for digit 5 in a three-digit number, it calculates `5 * 5 * 5 = 125`.
- `sum = sum + power` adds the current digit's power to the total.
- `temp = temp / 10` moves to the next digit.
- If the final sum equals the original number, the number is an Armstrong number.

### Dry Run (n = 153)

The number has 3 digits, so each digit is raised to power 3.

| Digit | Calculation | Power | Running sum |
|---:|---|---:|---:|
| 3 | 3 × 3 × 3 | 27 | 27 |
| 5 | 5 × 5 × 5 | 125 | 152 |
| 1 | 1 × 1 × 1 | 1 | 153 |

The sum is 153, equal to the original number, so it is an Armstrong number.

---

## Important Rules for `do-while`

1. The loop body executes at least once.
2. The condition is checked after the loop body.
3. A semicolon is required after `while (condition);`.
4. Change the loop variable inside the loop so the loop can eventually stop.
5. Use `% 10` to get the last digit of a non-negative integer.
6. Use `/ 10` with integer variables to remove the last digit.
7. Save the original number if you need to compare it after processing its digits.
8. Initialize sums and counters before using them.

## Common Beginner Mistakes

- Forgetting the semicolon after `while (condition)`.
- Forgetting to initialize `sum`, `reverse`, `count`, or `flag`.
- Changing the original number when it is needed for the final comparison.
- Using `/ 10` before extracting the last digit.
- Forgetting that `n % 10` returns the last digit.
- Treating 1 as a prime number.
- Including the number itself when adding proper divisors for a perfect-number check.
- Using integer division for an average without converting to `float`.
- Forgetting that an Armstrong number raises each digit to the power of the total number of digits.

## Quick Revision

| Concept | Important logic |
|---|---|
| Last digit | `n % 10` |
| Remove last digit | `n = n / 10` |
| Running total | `sum = sum + value` |
| Average | `(float) sum / count` |
| Divisibility | `n % i == 0` |
| Reverse a number | `reverse = reverse * 10 + digit` |
| Perfect number | Sum of proper divisors equals the number |
| Prime number | No divisor from 2 to `n - 1` |
| Flag | Records whether a condition has occurred |
| Armstrong number | Sum of each digit raised to the number of digits |

## Practice Questions

1. Find the product of the first and last digit of a number.
2. Count the number of digits in a given integer.
3. Find the sum of even digits in a number.
4. Print the digits of a number from left to right.
5. Print all perfect numbers between 1 and 1000.
6. Check whether a number is a strong number.
7. Check whether a number is an Armstrong number using a separate function.

## Learning Outcome

After completing this lab, students should be able to use `do-while` loops for repeated input, digit extraction, running totals, prime and perfect number checks, palindrome reversal, and Armstrong-number calculations.
