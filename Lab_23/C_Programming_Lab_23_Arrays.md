# C Programming Lab – 23
## Topic: Arrays

Write the following programs in C.

---

## 1. Read `n` Numbers and Print Them in Normal and Reverse Order (A)

### Problem
Read `n` integers into an array. First print them in the order entered, then print them from the last element to the first.

### Algorithm
1. Read the number of elements `n`.
2. Declare an array to store `n` integers.
3. Use a loop from index `0` to `n - 1` to read the elements.
4. Use another loop from index `0` to `n - 1` to print the elements in normal order.
5. Use a loop from index `n - 1` down to `0` to print the elements in reverse order.

### C Program
```c
#include <stdio.h>

int main()
{
    int a[100], n, i;

    printf("Enter number of elements (1-100): ");
    scanf("%d", &n);

    if (n < 1 || n > 100)
    {
        printf("Invalid number of elements.\\n");
        return 0;
    }

    printf("Enter %d numbers:\\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Normal order: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\\nReverse order: ");
    for (i = n - 1; i >= 0; i--)
    {
        printf("%d ", a[i]);
    }

    printf("\\n");
    return 0;
}
```

### Why Does This Program Work?
- `a[100]` stores up to 100 integers. An array keeps related values under one name, and each value is accessed using an index.
- `n` stores how many values the user wants to enter. The check prevents using an invalid size for this array.
- `i` is the loop counter and also the array index.
- The first input loop starts at `0` because C arrays use indexes beginning at `0`. It stops when `i` reaches `n - 1`, so exactly `n` values are read.
- The normal-order loop starts at `0` and increases the index.
- The reverse-order loop starts at `n - 1`, the last valid index, and decreases to `0`.
- `a[i]` means the element stored at index `i`.

### Sample Output
```text
Enter number of elements (1-100): 5
Enter 5 numbers:
10 20 30 40 50
Normal order: 10 20 30 40 50
Reverse order: 50 40 30 20 10
```

### Dry Run

For input array `[10, 20, 30, 40, 50]`:

| `i` | `a[i]` |
|---:|---:|
| 0 | 10 |
| 1 | 20 |
| 2 | 30 |
| 3 | 40 |
| 4 | 50 |

Reverse printing uses indexes `4, 3, 2, 1, 0`.

### Common Mistakes
- Using `i <= n` instead of `i < n`, which accesses one element beyond the entered values.
- Starting an array index at `1`; the first element is `a[0]`.
- Starting reverse printing at `n` instead of `n - 1`.

---

## 2. Count Positive and Negative Numbers in an Array (A)

### Problem
Read `n` integers and count how many are positive and how many are negative. Zero is neither positive nor negative, so it is not included in either count.

### Algorithm
1. Read `n` and validate that it is between `1` and `100`.
2. Read `n` integers into an array.
3. Initialize `positive` and `negative` to `0`.
4. Visit each element.
5. If it is greater than `0`, increase `positive`.
6. Otherwise, if it is less than `0`, increase `negative`.
7. Display both counts.

### C Program
```c
#include <stdio.h>

int main()
{
    int a[100], n, i;
    int positive = 0, negative = 0;

    printf("Enter number of elements (1-100): ");
    scanf("%d", &n);

    if (n < 1 || n > 100)
    {
        printf("Invalid number of elements.\\n");
        return 0;
    }

    printf("Enter %d integers:\\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            positive++;
        }
        else if (a[i] < 0)
        {
            negative++;
        }
    }

    printf("Positive numbers: %d\\n", positive);
    printf("Negative numbers: %d\\n", negative);

    return 0;
}
```

### Why Does This Program Work?
- `a[100]` stores the numbers so the program can examine them one by one.
- `positive` and `negative` are counters. Both start at `0` because no elements have been checked yet.
- `i` visits indexes from `0` through `n - 1`.
- `a[i] > 0` identifies positive values. `positive++` adds one to the count each time one is found.
- `a[i] < 0` identifies negative values. `negative++` adds one to that count.
- Zero satisfies neither condition, so it is intentionally not counted as positive or negative.

### Sample Output
```text
Enter number of elements (1-100): 6
Enter 6 integers:
12 -5 0 8 -3 -10
Positive numbers: 2
Negative numbers: 3
```

### Dry Run

| Element | Check | Positive count | Negative count |
|---:|---|---:|---:|
| 12 | Positive | 1 | 0 |
| -5 | Negative | 1 | 1 |
| 0 | Neither | 1 | 1 |
| 8 | Positive | 2 | 1 |
| -3 | Negative | 2 | 2 |
| -10 | Negative | 2 | 3 |

### Common Mistakes
- Counting zero as positive or negative.
- Writing `positive = positive + 1` outside the `if` block, which would count every element.
- Forgetting to initialize counters to `0`.

---

## 3. Count Even and Odd Numbers in an Array (A)

### Problem
Read `n` integers and count how many are even and how many are odd.

### Algorithm
1. Read and validate `n`.
2. Read `n` integers into an array.
3. Initialize `even` and `odd` to `0`.
4. Check each element using the remainder operator `%`.
5. If `a[i] % 2 == 0`, increase `even`; otherwise, increase `odd`.
6. Display the two counts.

### C Program
```c
#include <stdio.h>

int main()
{
    int a[100], n, i;
    int even = 0, odd = 0;

    printf("Enter number of elements (1-100): ");
    scanf("%d", &n);

    if (n < 1 || n > 100)
    {
        printf("Invalid number of elements.\\n");
        return 0;
    }

    printf("Enter %d integers:\\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }

    printf("Even numbers: %d\\n", even);
    printf("Odd numbers: %d\\n", odd);

    return 0;
}
```

### Why Does This Program Work?
- `even` and `odd` count the two categories. They start at `0` because no elements have been checked.
- `%` gives the remainder after division. An integer divisible by `2` has remainder `0`, so `a[i] % 2 == 0` checks whether it is even.
- If the remainder is not `0`, the integer is odd, so the `else` branch increases `odd`.
- Zero is even because `0 % 2` is `0`. Negative integers also work with this test.
- Each element is checked once, so the total of the even and odd counts equals `n`.

### Sample Output
```text
Enter number of elements (1-100): 6
Enter 6 integers:
2 7 10 13 0 -4
Even numbers: 4
Odd numbers: 2
```

### Dry Run

| Element | `element % 2` | Category | Even | Odd |
|---:|---:|---|---:|---:|
| 2 | 0 | Even | 1 | 0 |
| 7 | 1 | Odd | 1 | 1 |
| 10 | 0 | Even | 2 | 1 |
| 13 | 1 | Odd | 2 | 2 |
| 0 | 0 | Even | 3 | 2 |
| -4 | 0 | Even | 4 | 2 |

### Common Mistakes
- Using `/` instead of `%`. Division does not directly tell whether a number is even.
- Writing `a[i] % 2 = 0`; use `==` to compare values.
- Forgetting that zero is even.

---

## 4. Count Numbers Greater Than the Array Average (B)

### Problem
Read `n` numbers, calculate their average, and count how many elements are strictly greater than that average.

### Algorithm
1. Read and validate `n`.
2. Read the numbers into an array while adding them to `sum`.
3. Calculate `average = sum / n` using floating-point division.
4. Visit every element again.
5. If an element is greater than `average`, increase `count`.
6. Display the average and count.

### C Program
```c
#include <stdio.h>

int main()
{
    int a[100], n, i, count = 0;
    double sum = 0, average;

    printf("Enter number of elements (1-100): ");
    scanf("%d", &n);

    if (n < 1 || n > 100)
    {
        printf("Invalid number of elements.\\n");
        return 0;
    }

    printf("Enter %d numbers:\\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        sum = sum + a[i];
    }

    average = sum / n;

    for (i = 0; i < n; i++)
    {
        if (a[i] > average)
        {
            count++;
        }
    }

    printf("Average: %.2f\\n", average);
    printf("Numbers greater than average: %d\\n", count);

    return 0;
}
```

### Why Does This Program Work?
- `a[100]` stores all the input values because the program needs them again after calculating the average.
- `sum` starts at `0` because no numbers have been added yet. It is a `double` so the sum and average can support decimal values.
- During input, `sum = sum + a[i]` adds the current element to the running total.
- `average = sum / n` divides the total by the number of elements. Since `sum` is a `double`, the division keeps any fractional part.
- A second loop is needed because the average is not known until all numbers have been read.
- `a[i] > average` uses `>` because the task asks for numbers *greater than* the average; values equal to the average are not counted.
- `count` starts at `0` because no element has yet been found to be greater than the average.

### Sample Output
```text
Enter number of elements (1-100): 5
Enter 5 numbers:
10 20 30 40 50
Average: 30.00
Numbers greater than average: 2
```

### Dry Run

Input: `10, 20, 30, 40, 50`

- Sum = `10 + 20 + 30 + 40 + 50 = 150`
- Average = `150 / 5 = 30`

| Element | Is it greater than 30? | Count |
|---:|---|---:|
| 10 | No | 0 |
| 20 | No | 0 |
| 30 | No (equal) | 0 |
| 40 | Yes | 1 |
| 50 | Yes | 2 |

### Common Mistakes
- Trying to count greater-than-average values before all values have been read and the average is known.
- Using integer division for the average, which can discard the fractional part.
- Using `>=` when the question says strictly greater than.
- Forgetting to reset or initialize `count` to `0`.

---

## 5. Calculate Arithmetic, Geometric, and Harmonic Means (C)

### Problem
Read `n` array elements and calculate:
- **Arithmetic mean (AM):** sum of all values divided by `n`.
- **Geometric mean (GM):** the `n`th root of the product of all values.
- **Harmonic mean (HM):** `n` divided by the sum of the reciprocals of the values.

### Important Conditions
- `n` must be at least `1`.
- The geometric mean in this program is calculated for **positive values only**.
- The harmonic mean also requires **non-zero values**; this program uses positive values for all three means to keep the conditions simple and clear.
- If any value is zero or negative, the program reports that the input is invalid for this version and does not calculate the means.
- The program uses `math.h` functions `pow()` and `sqrt()`; compile with the math library when required, for example: `gcc program.c -o program -lm`.

### Algorithm
1. Read and validate `n`.
2. Read `n` positive numbers into an array.
3. While reading, calculate:
   - `sum` by adding each value.
   - `product` by multiplying each value.
   - `reciprocalSum` by adding `1.0 / value`.
4. If any value is not positive, stop with an explanatory message.
5. Calculate arithmetic mean as `sum / n`.
6. Calculate geometric mean as `pow(product, 1.0 / n)`.
7. Calculate harmonic mean as `n / reciprocalSum`.
8. Display all three means.

### C Program
```c
#include <stdio.h>
#include <math.h>

int main()
{
    double a[100], sum = 0, product = 1, reciprocalSum = 0;
    double arithmeticMean, geometricMean, harmonicMean;
    int n, i;

    printf("Enter number of elements (1-100): ");
    scanf("%d", &n);

    if (n < 1 || n > 100)
    {
        printf("Invalid number of elements.\\n");
        return 0;
    }

    printf("Enter %d positive numbers:\\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%lf", &a[i]);

        if (a[i] <= 0)
        {
            printf("Invalid input. Enter positive numbers only.\\n");
            return 0;
        }

        sum = sum + a[i];
        product = product * a[i];
        reciprocalSum = reciprocalSum + (1.0 / a[i]);
    }

    arithmeticMean = sum / n;
    geometricMean = pow(product, 1.0 / n);
    harmonicMean = n / reciprocalSum;

    printf("Arithmetic Mean: %.2f\\n", arithmeticMean);
    printf("Geometric Mean: %.2f\\n", geometricMean);
    printf("Harmonic Mean: %.2f\\n", harmonicMean);

    return 0;
}
```

### Why Does This Program Work?
- `a[100]` stores the values. The array is useful because the problem specifically asks for an array, although the means can also be accumulated as the input is read.
- `double` is used because means and input values may contain decimal fractions.
- `sum` starts at `0` because addition has a neutral starting value of zero.
- `product` starts at `1` because multiplying by `1` leaves the first value unchanged. Starting at `0` would make the product remain zero.
- `reciprocalSum` starts at `0` because no reciprocals have been added yet.
- `a[i]` is read with `%lf` because it is a `double`.
- The `a[i] <= 0` check prevents zero or negative values in this beginner-friendly version. Zero would make `1.0 / a[i]` invalid, and this version restricts values to positive numbers for a straightforward geometric-mean calculation.
- `sum = sum + a[i]` builds the total needed for the arithmetic mean.
- `product = product * a[i]` builds the product needed for the geometric mean.
- `reciprocalSum = reciprocalSum + (1.0 / a[i])` adds each reciprocal. `1.0` is used rather than `1` to make the division floating-point.
- `pow(product, 1.0 / n)` calculates the `n`th root of the product, because raising a positive number to the power `1/n` gives its `n`th root.
- `n / reciprocalSum` calculates the harmonic mean from the number of elements and the sum of reciprocals.

### Sample Output
```text
Enter number of elements (1-100): 3
Enter 3 positive numbers:
1 2 4
Arithmetic Mean: 2.33
Geometric Mean: 2.00
Harmonic Mean: 1.71
```

### Dry Run

Input values: `1, 2, 4`

| Value | Running sum | Running product | Reciprocal added | Reciprocal sum |
|---:|---:|---:|---:|---:|
| 1 | 1 | 1 | 1.0000 | 1.0000 |
| 2 | 3 | 2 | 0.5000 | 1.5000 |
| 4 | 7 | 8 | 0.2500 | 1.7500 |

- Arithmetic mean = `7 / 3 = 2.33`
- Geometric mean = cube root of `8` = `2.00`
- Harmonic mean = `3 / 1.75 = 1.71`

### Common Mistakes
- Starting `product` at `0` instead of `1`.
- Using `%f` in `scanf` for a `double`; use `%lf`.
- Dividing by zero when calculating a reciprocal.
- Calculating `product / n` instead of the `n`th root of the product for geometric mean.
- Calculating the harmonic mean as `sum / n`; that is the arithmetic mean, not the harmonic mean.
- Forgetting `#include <math.h>` when using `pow()`.

---

## Quick Revision

| Concept | Key idea |
|---|---|
| Array | Stores multiple values of the same type under one name |
| First array element | `a[0]` |
| Last of `n` elements | `a[n - 1]` |
| Array traversal | Usually `for (i = 0; i < n; i++)` |
| Reverse traversal | `for (i = n - 1; i >= 0; i--)` |
| Even check | `a[i] % 2 == 0` |
| Positive check | `a[i] > 0` |
| Arithmetic mean | `sum / n` |
| Geometric mean | `pow(product, 1.0 / n)` for positive values |
| Harmonic mean | `n / sum_of_reciprocals` |

## Practice Questions
1. Modify Program 1 to print only the elements at even indexes.
2. Count how many zeros are present in an array.
3. Find the largest and smallest values in an array.
4. Count how many elements are equal to the average.
5. Modify Program 5 to print all three means to four decimal places.
