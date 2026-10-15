# C Loops Lab – 22
## Topic: Nested `for` Loop and Pattern Printing

In this lab, we will use **nested `for` loops** to print number and star patterns.

## What Is a Nested `for` Loop?

A nested loop means writing one loop inside another loop.

```c
for (i = 1; i <= rows; i++)
{
    for (j = 1; j <= i; j++)
    {
        printf("*");
    }

    printf("\n");
}
```

- The **outer loop** controls the rows.
- The **inner loop** controls how many symbols or numbers are printed in each row.
- `printf("\n");` moves the cursor to the next line after one row is complete.

For example, if the outer loop runs 5 times and the inner loop prints 1, 2, 3, 4, and 5 stars respectively, the pattern becomes a triangle.

---

# Program 1: Print the Following Patterns (A)

The first question contains five patterns. Each pattern is shown as a separate program so that students can understand the logic of each one.

## Pattern 1: Increasing Star Triangle

### Pattern

```text
*
**
***
****
*****
```

### Algorithm
1. Start.
2. Use the outer loop to select rows 1 through 5.
3. For each row, print stars from 1 up to the row number.
4. Move to the next line after each row.
5. Stop.

### C Program

```c
#include <stdio.h>

int main()
{
    int i, j;

    for (i = 1; i <= 5; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}
```

### Sample Output

```text
*
**
***
****
*****
```

### Why do we write this?

- `i` represents the current row. It starts at 1 because the first row must contain one star.
- `i <= 5` makes five rows.
- `j` counts how many stars are printed in the current row.
- `j = 1` starts each row's star count from the beginning.
- `j <= i` is the key condition: row 1 prints 1 star, row 2 prints 2 stars, and so on.
- `printf("*");` prints a star without moving to a new line, allowing stars in the same row to stay together.
- `printf("\n");` runs after the inner loop finishes, so the next row begins on a new line.

### Dry Run

| Outer loop `i` | Inner loop values of `j` | Stars printed |
|---:|---|---|
| 1 | 1 | `*` |
| 2 | 1, 2 | `**` |
| 3 | 1, 2, 3 | `***` |
| 4 | 1, 2, 3, 4 | `****` |
| 5 | 1, 2, 3, 4, 5 | `*****` |

---

## Pattern 2: Increasing Number Triangle

### Pattern

```text
1
12
123
1234
12345
```

### Algorithm
1. Start.
2. Use the outer loop for rows 1 through 5.
3. In each row, print numbers from 1 to the row number.
4. Move to the next line after each row.
5. Stop.

### C Program

```c
#include <stdio.h>

int main()
{
    int i, j;

    for (i = 1; i <= 5; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("%d", j);
        }

        printf("\n");
    }

    return 0;
}
```

### Sample Output

```text
1
12
123
1234
12345
```

### Why do we write this?

- `i` decides the row number and therefore the number of digits in that row.
- `j` is printed as the number, so each row begins at 1 and increases by 1.
- `j <= i` ensures the last number printed in a row equals that row's number.
- `%d` is used because `j` is an integer.
- No spaces are printed between digits because the required pattern is `123`, not `1 2 3`.

### Dry Run

| `i` | Values printed by `j` | Row |
|---:|---|---|
| 1 | 1 | `1` |
| 2 | 1, 2 | `12` |
| 3 | 1, 2, 3 | `123` |
| 4 | 1, 2, 3, 4 | `1234` |
| 5 | 1, 2, 3, 4, 5 | `12345` |

---

## Pattern 3: Decreasing Number Triangle Starting from 5

### Pattern

```text
5
54
543
5432
54321
```

### Algorithm
1. Start.
2. Use the outer loop for rows 1 through 5.
3. For each row, start `j` at 5 and decrease it until it reaches `6 - i`.
4. Print each value of `j` without spaces.
5. Move to the next line after each row.
6. Stop.

### C Program

```c
#include <stdio.h>

int main()
{
    int i, j;

    for (i = 1; i <= 5; i++)
    {
        for (j = 5; j >= 6 - i; j--)
        {
            printf("%d", j);
        }

        printf("\n");
    }

    return 0;
}
```

### Sample Output

```text
5
54
543
5432
54321
```

### Why do we write this?

- `i` counts the rows from 1 to 5.
- `j = 5` makes every row begin with 5.
- `j--` decreases the printed number by 1 each time, giving 5, 4, 3, 2, 1.
- `j >= 6 - i` changes the stopping point for each row:
  - When `i = 1`, `j >= 5`, so only 5 is printed.
  - When `i = 2`, `j >= 4`, so 5 and 4 are printed.
  - When `i = 5`, `j >= 1`, so all numbers from 5 down to 1 are printed.
- `printf("\n");` ends the current row.

### Dry Run

| `i` | Condition's lower limit `6 - i` | Values printed |
|---:|---:|---|
| 1 | 5 | `5` |
| 2 | 4 | `54` |
| 3 | 3 | `543` |
| 4 | 2 | `5432` |
| 5 | 1 | `54321` |

---

## Pattern 4: Decreasing Star Triangle

### Pattern

```text
*****
****
***
**
*
```

### Algorithm
1. Start.
2. Use the outer loop for rows 1 through 5.
3. For each row, print stars while `j` goes from 1 to `6 - i`.
4. Move to the next line.
5. Stop.

### C Program

```c
#include <stdio.h>

int main()
{
    int i, j;

    for (i = 1; i <= 5; i++)
    {
        for (j = 1; j <= 6 - i; j++)
        {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}
```

### Sample Output

```text
*****
****
***
**
*
```

### Why do we write this?

- `i` counts the rows.
- The first row should have 5 stars, so the inner loop's limit starts at `6 - 1 = 5`.
- As `i` increases, `6 - i` becomes smaller: 5, 4, 3, 2, 1.
- `j` counts the stars in the current row.
- `printf("*");` keeps stars on the same line; the newline is printed only after the inner loop ends.

### Dry Run

| `i` | Inner loop condition | Number of stars |
|---:|---|---:|
| 1 | `j <= 5` | 5 |
| 2 | `j <= 4` | 4 |
| 3 | `j <= 3` | 3 |
| 4 | `j <= 2` | 2 |
| 5 | `j <= 1` | 1 |

---

## Pattern 5: Decreasing Number Triangle

### Pattern

```text
12345
1234
123
12
1
```

### Algorithm
1. Start.
2. Use the outer loop for rows 1 through 5.
3. For each row, print numbers from 1 through `6 - i`.
4. Move to the next line.
5. Stop.

### C Program

```c
#include <stdio.h>

int main()
{
    int i, j;

    for (i = 1; i <= 5; i++)
    {
        for (j = 1; j <= 6 - i; j++)
        {
            printf("%d", j);
        }

        printf("\n");
    }

    return 0;
}
```

### Sample Output

```text
12345
1234
123
12
1
```

### Why do we write this?

- `i` represents the row number.
- `j` starts at 1 in every row because every row begins with 1.
- `j <= 6 - i` reduces the number of printed digits in each new row: 5, 4, 3, 2, and 1.
- `printf("%d", j);` prints the current number without a space or newline.
- The newline after the inner loop makes each group of numbers appear on its own row.

### Dry Run

| `i` | Values of `j` | Row |
|---:|---|---|
| 1 | 1, 2, 3, 4, 5 | `12345` |
| 2 | 1, 2, 3, 4 | `1234` |
| 3 | 1, 2, 3 | `123` |
| 4 | 1, 2 | `12` |
| 5 | 1 | `1` |

---

# Program 2: Print the Following Patterns (B)

This question contains two patterns.

## Pattern 6: Alternating 1 and 0

### Pattern

```text
1
0 1
0 1 0
1 0 1 0
1 0 1 0 1
```

### Algorithm
1. Start.
2. Use the outer loop for rows 1 through 5.
3. For each row, use the inner loop to print as many values as the row number.
4. For rows 1 to 3, start with 1 on the first row and 0 on the next two rows; for rows 4 and 5, start with 1.
5. Alternate 0 and 1 across each row.
6. Move to the next line after each row.
7. Stop.

### C Program

```c
#include <stdio.h>

int main()
{
    int i, j, value;

    for (i = 1; i <= 5; i++)
    {
        if (i == 1 || i >= 4)
        {
            value = 1;
        }
        else
        {
            value = 0;
        }

        for (j = 1; j <= i; j++)
        {
            printf("%d", value);

            if (j < i)
            {
                printf(" ");
            }

            value = 1 - value;
        }

        printf("\n");
    }

    return 0;
}
```

### Sample Output

```text
1
0 1
0 1 0
1 0 1 0
1 0 1 0 1
```

### Why do we write this?

- `i` identifies the current row, and `j` counts the values printed in that row.
- `j <= i` makes each row contain as many values as its row number.
- `value` stores the digit to print next.
- The `if` condition sets the starting value according to the required pattern: row 1 starts with 1, rows 2 and 3 start with 0, and rows 4 and 5 start with 1.
- `value = 1 - value` switches 1 to 0 and 0 to 1:
  - If `value` is 1, then `1 - 1 = 0`.
  - If `value` is 0, then `1 - 0 = 1`.
- `if (j < i)` prints a space only between values, not after the last value in the row.
- The newline after the inner loop moves to the next row.

### Dry Run

| Row `i` | Starting `value` | Values printed |
|---:|---:|---|
| 1 | 1 | `1` |
| 2 | 0 | `0 1` |
| 3 | 0 | `0 1 0` |
| 4 | 1 | `1 0 1 0` |
| 5 | 1 | `1 0 1 0 1` |

---

## Pattern 7: Continuous Number Triangle

### Pattern

```text
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
```

### Algorithm
1. Start.
2. Set `number = 1`.
3. Use the outer loop for rows 1 through 5.
4. In each row, print `i` numbers using the inner loop.
5. Increase `number` after each printed value.
6. Move to the next line after each row.
7. Stop.

### C Program

```c
#include <stdio.h>

int main()
{
    int i, j, number = 1;

    for (i = 1; i <= 5; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("%d", number);

            if (j < i)
            {
                printf(" ");
            }

            number++;
        }

        printf("\n");
    }

    return 0;
}
```

### Sample Output

```text
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
```

### Why do we write this?

- `i` controls the row number.
- `j` controls how many numbers are printed in the current row.
- `j <= i` prints 1 number in row 1, 2 in row 2, and so on.
- `number = 1` is used because the sequence must begin at 1.
- `number` is separate from `j` because `j` resets to 1 for every row, but the printed sequence must continue from one row to the next.
- `number++` runs after each number is printed, so the next printed value is one greater.
- `if (j < i)` adds spaces only between numbers in the same row.
- `printf("\n");` starts a new row without resetting `number`.

### Dry Run

| Row `i` | Values printed | `number` after row |
|---:|---|---:|
| 1 | `1` | 2 |
| 2 | `2 3` | 4 |
| 3 | `4 5 6` | 7 |
| 4 | `7 8 9 10` | 11 |
| 5 | `11 12 13 14 15` | 16 |

---

## Common Beginner Mistakes

- Putting `printf("\n");` inside the inner loop. This prints every star or number on a separate line.
- Using `j <= 5` for every row when the number of items should change with `i`.
- Forgetting to reset a row-specific counter such as `j` by declaring it in the `for` loop or initializing it in the loop header.
- Using `j++` when a decreasing pattern requires `j--`.
- Confusing the row counter (`i`) with the item counter (`j`).
- Resetting `number` to 1 inside the outer loop in the continuous number pattern.
- Forgetting spaces between numbers in patterns where spaces are shown.
- Updating `value` before printing it, which changes the first digit of each row.

## Quick Revision

| Pattern type | Main idea |
|---|---|
| Increasing stars | `j <= i` |
| Increasing numbers | Print `j` while `j <= i` |
| Descending numbers from 5 | Start `j = 5`, then use `j--` |
| Decreasing stars | `j <= 6 - i` |
| Decreasing number rows | Print `j` while `j <= 6 - i` |
| Alternating 0 and 1 | Switch value after each print |
| Continuous number triangle | Keep `number` outside both loops and increment it |

## Practice Questions

1. Print a right-angled triangle of 1s, with row lengths from 1 to 5.
2. Print the pattern `1`, `22`, `333`, `4444`, `55555`.
3. Print an inverted triangle of numbers from 5 down to 1.
4. Print a triangle in which each row alternates between `A` and `B`.
5. Print continuous numbers in a triangle with 6 rows.
6. Modify the patterns to read the number of rows from the user.

## Learning Outcome

After completing this lab, students should understand how an outer loop controls rows, how an inner loop controls the items in each row, how loop limits create increasing and decreasing patterns, and how variables can preserve or alternate values across iterations.
