# C Programming Lab – 24: Arrays

## Topic: Array Operations, Searching, Sorting, and Duplicate Elements

An **array** stores multiple values of the same data type under one name. Each value is accessed using an index. In C, array indexing starts from `0`, so an array with `n` elements uses indexes from `0` to `n - 1`.

> **Note:** These programs use `int main()` and beginner-friendly logic. Enter a valid positive array size within the declared limit.

---

## Program 1: Find Maximum, Minimum, Sum, and Average of Array Elements (A)

### Problem
Read `n` numbers into an array. Find the maximum value, minimum value, sum, and average.

### Algorithm
1. Read the number of elements `n`.
2. Read `n` values into the array.
3. Set `max` and `min` to the first array element. This gives both variables a real array value to compare with.
4. Set `sum` to `0`, because no values have been added yet.
5. Visit every array element:
   - Add it to `sum`.
   - If it is greater than `max`, update `max`.
   - If it is smaller than `min`, update `min`.
6. Calculate `average = sum / n`.
7. Display the maximum, minimum, sum, and average.

### C Program
```c
#include <stdio.h>

int main()
{
    int a[100], n, i;
    int max, min, sum = 0;
    float average;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100)
    {
        printf("Please enter a size from 1 to 100.\\n");
        return 0;
    }

    printf("Enter %d numbers:\\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    max = a[0];
    min = a[0];

    for (i = 0; i < n; i++)
    {
        sum = sum + a[i];

        if (a[i] > max)
        {
            max = a[i];
        }

        if (a[i] < min)
        {
            min = a[i];
        }
    }

    average = (float)sum / n;

    printf("Maximum = %d\\n", max);
    printf("Minimum = %d\\n", min);
    printf("Sum = %d\\n", sum);
    printf("Average = %.2f\\n", average);

    return 0;
}
```

### Why does the program work?
- `a[100]` can store up to 100 integers. The size check prevents using an invalid size or going beyond the array.
- `n` stores how many values the user wants to enter. The loops use `n` so the program works for different array sizes.
- `i` is the index counter. It starts at `0` because C arrays start at index `0`, and the condition `i < n` stops at the last valid index, `n - 1`.
- `sum = 0` is the correct starting value because adding values to an empty total begins at zero.
- `max = a[0]` and `min = a[0]` are safer than starting at `0`: an array might contain only negative numbers or only positive numbers. Starting with the first actual value makes comparisons correct in either case.
- `(float)sum / n` converts `sum` to a floating-point value before division. Without this conversion, integer division could discard the decimal part.
- The second loop starts at `0` and checks each element once, so no value is skipped.

### Sample Output
```text
Enter number of elements: 5
Enter 5 numbers:
12 7 25 4 10
Maximum = 25
Minimum = 4
Sum = 58
Average = 11.60
```

### Dry Run

For the values `12, 7, 25, 4, 10`:

| Element | `sum` after addition | `max` | `min` |
|---:|---:|---:|---:|
| 12 | 12 | 12 | 12 |
| 7 | 19 | 12 | 7 |
| 25 | 44 | 25 | 7 |
| 4 | 48 | 25 | 4 |
| 10 | 58 | 25 | 4 |

Average = `58 / 5 = 11.60`.

---

## Program 2: Count People with Height Greater Than 170 and Weight Less Than 50 (A)

### Problem
Read the height and weight of five people. Count how many people have a height greater than `170` and a weight less than `50`.

### Algorithm
1. Set `count` to `0`.
2. Repeat five times:
   - Read one person's height and weight.
   - If height is greater than `170` **and** weight is less than `50`, increase `count` by one.
3. Display `count`.

### C Program
```c
#include <stdio.h>

int main()
{
    float height, weight;
    int i, count = 0;

    for (i = 1; i <= 5; i++)
    {
        printf("Enter height and weight of person %d: ", i);
        scanf("%f %f", &height, &weight);

        if (height > 170 && weight < 50)
        {
            count++;
        }
    }

    printf("Number of people matching the condition = %d\\n", count);

    return 0;
}
```

### Why does the program work?
- The problem asks for exactly five people, so the loop starts at `1` and continues while `i <= 5`. This repeats five times and also makes the displayed person numbers easy to understand.
- `height` and `weight` are `float` variables because measurements may contain decimal values, such as `172.5` or `48.7`.
- `count = 0` means no person has matched the condition yet.
- `&&` means **AND**. Both conditions must be true: the height must be strictly greater than `170`, and the weight must be strictly less than `50`.
- `count++` increases the count by one only when the current person satisfies both conditions. The program does not need an array here because each person's measurements are checked immediately and only the total count is required.

### Sample Output
```text
Enter height and weight of person 1: 172 48
Enter height and weight of person 2: 165 45
Enter height and weight of person 3: 175 52
Enter height and weight of person 4: 181 49
Enter height and weight of person 5: 170 40
Number of people matching the condition = 2
```

People 1 and 4 match. Person 5 does not match because the height is `170`, not greater than `170`.

---

## Program 3: Sort Array Elements in Ascending Order (A)

### Problem
Read `n` numbers and arrange them from smallest to largest.

### Algorithm
1. Read `n` and the array elements.
2. Use an outer loop to select each position that needs a value.
3. Use an inner loop to compare the current element with the elements after it.
4. If `a[i] > a[j]`, swap the two values.
5. Display the sorted array.

### C Program
```c
#include <stdio.h>

int main()
{
    int a[100], n, i, j, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100)
    {
        printf("Please enter a size from 1 to 100.\\n");
        return 0;
    }

    printf("Enter %d numbers:\\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("Array in ascending order: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\\n");

    return 0;
}
```

### Why does the program work?
- `i` marks the position currently being filled with the smallest available value.
- `j = i + 1` starts comparing just after position `i`. There is no need to compare an element with itself or recheck earlier positions.
- `j < n` ensures `a[j]` never accesses an index outside the array.
- If `a[i] > a[j]`, the values are in the wrong order for ascending sorting, so they are swapped.
- `temp` temporarily stores `a[i]`. Without `temp`, assigning `a[i] = a[j]` would overwrite the original value of `a[i]` before it could be moved to `a[j]`.
- The outer loop ends at `n - 2` (`i < n - 1`) because the last position will contain the correct value after all earlier positions are handled.
- This is a simple comparison-based sorting method suitable for learning. It is not the most efficient method for very large arrays.

### Sample Output
```text
Enter number of elements: 5
Enter 5 numbers:
30 10 50 20 40
Array in ascending order: 10 20 30 40 50
```

### Small Dry Run
Starting array: `30 10 50`

- Compare `30` and `10`; swap → `10 30 50`
- Compare `10` and `50`; no swap.
- Compare `30` and `50`; no swap.

Sorted array: `10 30 50`.

---

## Program 4: Count Duplicate Elements in an Array (B)

### Problem
Count how many **distinct values** occur more than once in an array. For example, in `2 4 2 5 4 2`, the duplicate values are `2` and `4`, so the answer is `2`.

> This solution counts each repeated value once, even if it occurs three or more times.

### Algorithm
1. Read `n` and the array elements.
2. Set `duplicates` to `0`.
3. For each element, check whether the same value appeared earlier in the array.
4. If it appeared earlier, skip it so that the same value is not counted more than once.
5. Otherwise, search the elements after it for a matching value.
6. If a match is found, increase `duplicates` once.
7. Display `duplicates`.

### C Program
```c
#include <stdio.h>

int main()
{
    int a[100], n, i, j, k;
    int duplicates = 0;
    int alreadyChecked, found;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100)
    {
        printf("Please enter a size from 1 to 100.\\n");
        return 0;
    }

    printf("Enter %d numbers:\\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++)
    {
        alreadyChecked = 0;

        for (k = 0; k < i; k++)
        {
            if (a[k] == a[i])
            {
                alreadyChecked = 1;
                break;
            }
        }

        if (alreadyChecked == 1)
        {
            continue;
        }

        found = 0;
        for (j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                found = 1;
                break;
            }
        }

        if (found == 1)
        {
            duplicates++;
        }
    }

    printf("Number of distinct duplicate values = %d\\n", duplicates);

    return 0;
}
```

### Why does the program work?
- `duplicates` starts at `0` because no duplicate values have been confirmed yet.
- `i` selects the value being checked.
- The `k` loop checks earlier indexes (`0` to `i - 1`). If the same value was already handled, `alreadyChecked` becomes `1`; `continue` skips it. This prevents counting a value like `2` more than once when it occurs three times.
- `found` starts at `0` for each new value because no later match has been found yet.
- The `j` loop starts at `i + 1`, looking only at later elements. If it finds an equal value, `found` becomes `1`.
- `break` stops a search as soon as one matching value is found. More matches are not needed because this program counts each distinct duplicate value only once.
- `alreadyChecked` and `found` serve different purposes: the first avoids recounting a value, while the second checks whether that value occurs again.

### Sample Output
```text
Enter number of elements: 6
Enter 6 numbers:
2 4 2 5 4 2
Number of distinct duplicate values = 2
```

The distinct duplicate values are `2` and `4`.

---

## Program 5: Find Missing Numbers in a Sequence Using an Array (C)

### Problem
Given a sequence of numbers in increasing order, find the missing numbers between the first and last values.

Example: for `1 2 4 5 7 8 10`, the missing numbers are `3 6 9`.

### Algorithm
1. Read `n` and the sequence into an array.
2. Start at the first value and check every integer up to the last value.
3. For each integer, search the array to see whether it exists.
4. If it does not exist, print it as a missing number.
5. Move to the next integer and repeat.

### C Program
```c
#include <stdio.h>

int main()
{
    int a[100], n, i, number, found;

    printf("Enter number of elements in the sequence: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100)
    {
        printf("Please enter a size from 1 to 100.\\n");
        return 0;
    }

    printf("Enter the sequence in increasing order:\\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Missing numbers: ");
    for (number = a[0]; number <= a[n - 1]; number++)
    {
        found = 0;

        for (i = 0; i < n; i++)
        {
            if (a[i] == number)
            {
                found = 1;
                break;
            }
        }

        if (found == 0)
        {
            printf("%d ", number);
        }
    }
    printf("\\n");

    return 0;
}
```

### Why does the program work?
- This solution assumes the sequence is entered in increasing order, as in the question's example. Therefore, `a[0]` is the first value and `a[n - 1]` is the last value.
- `number` represents each integer that should be checked between the first and last values, including both endpoints.
- `found = 0` means the current number has not yet been located in the array.
- The inner loop checks all array elements. When `a[i] == number`, the number exists, so `found` becomes `1` and `break` ends the search early.
- After searching, `found == 0` means the number does not appear in the sequence, so it is printed as missing.
- The outer loop uses `number++` to check consecutive integers. For the example, it checks `1, 2, 3, ... 10`; `3`, `6`, and `9` are not found in the array.
- This straightforward method is easy to understand, though it performs repeated searches and is less efficient for very large sequences.

### Sample Output
```text
Enter number of elements in the sequence: 7
Enter the sequence in increasing order:
1 2 4 5 7 8 10
Missing numbers: 3 6 9
```

### Dry Run

Input sequence: `1 2 4 5 7 8 10`

| Number checked | Present in array? | Action |
|---:|---|---|
| 1 | Yes | Skip |
| 2 | Yes | Skip |
| 3 | No | Print `3` |
| 4 | Yes | Skip |
| 5 | Yes | Skip |
| 6 | No | Print `6` |
| 7 | Yes | Skip |
| 8 | Yes | Skip |
| 9 | No | Print `9` |
| 10 | Yes | Skip |

---

## Common Mistakes in Array Programs

1. **Using an invalid index:** For an array of `n` elements, valid indexes are `0` through `n - 1`, not `1` through `n`.
2. **Writing `i <= n` in a loop:** This tries to access `a[n]`, which is outside the array. Use `i < n`.
3. **Starting maximum or minimum at `0`:** This can give incorrect results when every element is positive or every element is negative. Start both at `a[0]`.
4. **Using integer division for an average:** Use `(float)sum / n` when a decimal result is needed.
5. **Forgetting the temporary variable when swapping:** Store one value in `temp` before overwriting it.
6. **Counting every repeated occurrence instead of each distinct duplicate value:** Decide which meaning the question expects. Program 4 counts each distinct value only once.
7. **Assuming an unsorted sequence is sorted:** Program 5 expects the sequence in increasing order, as stated in its input prompt.
8. **Using `&&` incorrectly:** In Program 2, both the height and weight conditions must be true.

---

## Quick Revision

- Array indexes begin at `0`.
- Last valid index = `n - 1`.
- Sum starts at `0`.
- Maximum and minimum should start from the first array element.
- `&&` means both conditions must be true.
- Ascending order means smallest to largest.
- A swap needs a temporary variable to avoid losing a value.
- A flag such as `found` is commonly initialized to `0` and changed to `1` when a match is found.

## Practice Questions

1. Modify Program 1 to also display the index of the maximum element.
2. Modify Program 2 to count people whose height is at least `170` and weight is at most `50`.
3. Modify Program 3 to sort the array in descending order.
4. Modify Program 4 to display the duplicate values as well as their count.
5. Modify Program 5 to work when the sequence starts at a value other than `1`.
