# C Operators & Decision-Making Statements – Lab 14

## Topic: Switch Case and Conditional Operator

---

## Lab Objective

In this lab, we will learn:

- `switch-case`
- `break`
- `default`
- Grouping multiple `case` values
- Conditional operator `?:`
- Using `if` inside a `switch`
- Leap-year logic

### Important Rule

Use **`switch-case`** when one expression has several **fixed choices**.

Use the **conditional operator `?:`** when there is a simple **two-way decision**.

---

# Program 1: Print Day Name of Week Using `switch`

## Problem

Write a C program to print the day name of the week based on a number.

```text
1 → Monday
2 → Tuesday
3 → Wednesday
4 → Thursday
5 → Friday
6 → Saturday
7 → Sunday
```

## Explanation

The user enters a number from `1` to `7`.

For example:

```text
day = 3
```

The `switch` checks the value of `day`.

When it finds:

```c
case 3:
```

it prints:

```text
Wednesday
```

## Algorithm

1. Start.
2. Declare an integer variable `day`.
3. Input the day number.
4. Use `switch(day)`.
5. Print the corresponding day.
6. Use `default` for an invalid number.
7. Stop.

## C Program

```c
#include <stdio.h>

int main()
{
    int day;

    printf("Enter day number (1-7): ");
    scanf("%d", &day);

    switch (day)
    {
        case 1:
            printf("Monday");
            break;

        case 2:
            printf("Tuesday");
            break;

        case 3:
            printf("Wednesday");
            break;

        case 4:
            printf("Thursday");
            break;

        case 5:
            printf("Friday");
            break;

        case 6:
            printf("Saturday");
            break;

        case 7:
            printf("Sunday");
            break;

        default:
            printf("Invalid day number");
    }

    return 0;
}
```

## Sample Output

```text
Enter day number (1-7): 5
Friday
```

---

# Program 2: Print Number of Days in a Month Using `switch`

## Problem

Write a C program to print the number of days in a month using `switch`.

## Explanation

Months can be grouped according to their number of days.

### Months with 31 days

```text
January, March, May, July, August, October, December
```

### Months with 30 days

```text
April, June, September, November
```

### February

Normally:

```text
28 days
```

We can group cases that have the same output.

## Algorithm

1. Start.
2. Declare `month`.
3. Input the month number.
4. Use `switch(month)`.
5. Group the months having 31 days.
6. Group the months having 30 days.
7. Handle February separately.
8. Use `default` for an invalid month.
9. Stop.

## C Program

```c
#include <stdio.h>

int main()
{
    int month;

    printf("Enter month number (1-12): ");
    scanf("%d", &month);

    switch (month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            printf("31 days");
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            printf("30 days");
            break;

        case 2:
            printf("28 days");
            break;

        default:
            printf("Invalid month number");
    }

    return 0;
}
```

## Sample Output

```text
Enter month number (1-12): 4
30 days
```

## Important Concept: Grouping Cases

Consider:

```c
case 1:
case 3:
case 5:
    printf("31 days");
    break;
```

There is no `break` between `case 1`, `case 3`, and `case 5`.

This is intentional because all three cases need the same output.

It means:

```text
If month is 1 OR 3 OR 5
        ↓
Print 31 days
```

---

# Program 3: Addition, Subtraction, Multiplication and Division Using `switch`

## Problem

Perform Addition, Subtraction, Multiplication and Division of two numbers according to the user's choice using `switch`.

## Menu

```text
1. Addition
2. Subtraction
3. Multiplication
4. Division
```

## Explanation

The user first selects an operation.

For example:

```text
choice = 1
```

means Addition.

We use:

```c
switch (choice)
```

to select the required operation.

For division, we must also check that the second number is not zero.

## Algorithm

1. Start.
2. Declare two numbers `a` and `b`.
3. Declare `choice`.
4. Display the menu.
5. Input the user's choice.
6. Input two numbers.
7. Use `switch(choice)`.
8. Perform the selected operation.
9. Before division, check `b != 0`.
10. Use `default` for an invalid choice.
11. Stop.

## C Program

```c
#include <stdio.h>

int main()
{
    float a, b, result;
    int choice;

    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter two numbers: ");
    scanf("%f %f", &a, &b);

    switch (choice)
    {
        case 1:
            result = a + b;
            printf("Addition = %.2f", result);
            break;

        case 2:
            result = a - b;
            printf("Subtraction = %.2f", result);
            break;

        case 3:
            result = a * b;
            printf("Multiplication = %.2f", result);
            break;

        case 4:
            if (b != 0)
            {
                result = a / b;
                printf("Division = %.2f", result);
            }
            else
            {
                printf("Division by zero is not allowed.");
            }
            break;

        default:
            printf("Invalid choice");
    }

    return 0;
}
```

## Sample Output

```text
1. Addition
2. Subtraction
3. Multiplication
4. Division
Enter your choice: 1
Enter two numbers: 20 10
Addition = 30.00
```

## Important Point

Here:

```text
switch → selects the operation
if     → checks whether division by zero is possible
```

So `switch` and `if` can be used together.

---

# Program 4: Multiply the Largest of the First Two Numbers by the Third Number Using `switch`

## Problem

Read 3 numbers. Find the largest number among the **first two numbers**, then multiply that number by the third number using `switch`.

## Example

Suppose:

```text
First number  = 10
Second number = 20
Third number  = 5
```

First compare only:

```text
10 and 20
```

The largest is:

```text
20
```

Then:

```text
20 × 5 = 100
```

## Important Logic

The question says:

> Find the largest number from the first two numbers.

It does **not** ask us to find the largest among all three numbers.

Therefore:

```text
Step 1 → Compare first and second numbers
Step 2 → Select the larger one
Step 3 → Multiply it by the third number
```

### Important Switch Concept

Do not write:

```c
case a > b:
```

This is incorrect.

A normal `case` contains a fixed value.

Therefore, first use `if` to decide which of the first two numbers is larger.

Then store that decision as:

```text
choice = 1
```

or:

```text
choice = 2
```

Finally, use `switch(choice)`.

## Algorithm

1. Start.
2. Declare `a`, `b`, and `c`.
3. Input the three numbers.
4. Compare `a` and `b`.
5. If `a >= b`, set `choice = 1`.
6. Otherwise set `choice = 2`.
7. Use `switch(choice)`.
8. If `choice` is `1`, calculate `a * c`.
9. If `choice` is `2`, calculate `b * c`.
10. Print the result.
11. Stop.

## C Program

```c
#include <stdio.h>

int main()
{
    float a, b, c, result;
    int choice;

    printf("Enter three numbers: ");
    scanf("%f %f %f", &a, &b, &c);

    if (a >= b)
    {
        choice = 1;
    }
    else
    {
        choice = 2;
    }

    switch (choice)
    {
        case 1:
            result = a * c;
            printf("Largest of first two numbers = %.2f\n", a);
            printf("Result = %.2f", result);
            break;

        case 2:
            result = b * c;
            printf("Largest of first two numbers = %.2f\n", b);
            printf("Result = %.2f", result);
            break;
    }

    return 0;
}
```

## Sample Output

```text
Enter three numbers: 15 25 4
Largest of first two numbers = 25.00
Result = 100.00
```

---

# Program 5: Check Whether a Character Is an Alphabet Using Conditional Operator

## Problem

Write a C program to check whether an entered character is an alphabet or not using the conditional operator.

## What Is the Conditional Operator?

The conditional operator is also called the **ternary operator**.

Its syntax is:

```c
condition ? true_expression : false_expression;
```

It has three parts:

```text
condition
   ?
true expression
   :
false expression
```

### Simple Example

```c
max = (a > b) ? a : b;
```

This means:

```text
If a > b
    max = a
Otherwise
    max = b
```

---

## Alphabet Condition

An alphabet can be:

```text
A to Z
```

or:

```text
a to z
```

Therefore, the condition is:

```c
(ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')
```

If the condition is true:

```text
Alphabet
```

Otherwise:

```text
Not an alphabet
```

## Algorithm

1. Start.
2. Declare a character variable `ch`.
3. Input a character.
4. Check whether it is between `A` and `Z` OR between `a` and `z`.
5. If true, print `Alphabet`.
6. Otherwise, print `Not an alphabet`.
7. Stop.

## C Program

```c
#include <stdio.h>

int main()
{
    char ch;

    printf("Enter a character: ");
    scanf(" %c", &ch);

    (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')
        ? printf("Alphabet")
        : printf("Not an alphabet");

    return 0;
}
```

## Sample Output 1

```text
Enter a character: G
Alphabet
```

## Sample Output 2

```text
Enter a character: 7
Not an alphabet
```

## Important Point

The conditional operator is useful when there are **two possible results**.

Think:

```text
condition ? YES : NO
```

---

# Program 6: Print Number of Days in a Month Considering Leap Year Using `switch`

## Problem

Write a C program to print the number of days in a month considering the leap year.

The user enters:

- Month number
- Year

For example:

```text
Month = 2
Year = 2024
```

2024 is a leap year, so February has:

```text
29 days
```

---

## What Is a Leap Year?

A year is a leap year when:

```text
It is divisible by 400
```

OR

```text
It is divisible by 4 AND not divisible by 100
```

In C:

```c
(year % 400 == 0) ||
(year % 4 == 0 && year % 100 != 0)
```

### Examples

```text
2024 → Leap year
2000 → Leap year
1900 → Not a leap year
2023 → Not a leap year
```

---

## Why Do We Need `if` Inside `case 2`?

`switch` is used to identify the month.

For example:

```c
case 2:
```

means February.

But February can have:

```text
28 days
```

or:

```text
29 days
```

depending on the year.

Therefore, inside `case 2`, we use `if-else` to check whether the year is a leap year.

This is an important example of:

> **`switch` + `if-else`**

## Algorithm

1. Start.
2. Declare `month` and `year`.
3. Input month and year.
4. Use `switch(month)`.
5. Group the months having 31 days.
6. Group the months having 30 days.
7. For February, check the leap year condition.
8. If it is a leap year, print `29 days`.
9. Otherwise, print `28 days`.
10. Use `default` for an invalid month.
11. Stop.

## C Program

```c
#include <stdio.h>

int main()
{
    int month, year;

    printf("Enter month number (1-12): ");
    scanf("%d", &month);

    printf("Enter year: ");
    scanf("%d", &year);

    switch (month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            printf("31 days");
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            printf("30 days");
            break;

        case 2:
            if ((year % 400 == 0) ||
                (year % 4 == 0 && year % 100 != 0))
            {
                printf("29 days");
            }
            else
            {
                printf("28 days");
            }
            break;

        default:
            printf("Invalid month number");
    }

    return 0;
}
```

## Sample Output 1

```text
Enter month number (1-12): 2
Enter year: 2024
29 days
```

## Sample Output 2

```text
Enter month number (1-12): 2
Enter year: 2023
28 days
```

## Sample Output 3

```text
Enter month number (1-12): 4
Enter year: 2024
30 days
```

---

# Common Mistakes in Lab 14

## Mistake 1: Forgetting `break`

Wrong:

```c
case 1:
    printf("Monday");

case 2:
    printf("Tuesday");
```

If you do not intentionally want fall-through, use:

```c
case 1:
    printf("Monday");
    break;
```

---

## Mistake 2: Missing Colon

Wrong:

```c
case 1
```

Correct:

```c
case 1:
```

---

## Mistake 3: Writing a Condition After `case`

Wrong:

```c
case day == 1:
```

Correct:

```c
case 1:
```

Remember:

> `case` is for a fixed value, not a normal condition.

---

## Mistake 4: Trying to Use Ranges in `case`

Wrong:

```c
case marks >= 70:
```

Use `if-else-if` for ranges.

---

## Mistake 5: Forgetting `default`

For menu-based programs, it is good practice to handle invalid choices:

```c
default:
    printf("Invalid choice");
```

---

## Mistake 6: Using Double Quotes for Characters

Wrong:

```c
case "A":
```

Correct:

```c
case 'A':
```

Remember:

```text
'A' → character
"A" → string
```

---

## Mistake 7: Wrong Conditional Operator Syntax

Wrong:

```c
condition ? true_part
```

Correct:

```c
condition ? true_part : false_part;
```

Both `?` and `:` are required.

---

## Mistake 8: Using `=` Instead of `==`

Wrong:

```c
if (year % 4 = 0)
```

Correct:

```c
if (year % 4 == 0)
```

Remember:

```text
=  → assignment
== → comparison
```

---

## Mistake 9: Incorrect Leap-Year Logic

Do not use only:

```c
year % 4 == 0
```

because `1900` is divisible by 4 but is **not** a leap year.

Correct:

```c
(year % 400 == 0) ||
(year % 4 == 0 && year % 100 != 0)
```

---

# Quick Revision

| Topic | Main Idea |
|---|---|
| `switch` | Select one option from fixed choices |
| `case` | One fixed choice/value |
| `break` | Exit the switch |
| `default` | Runs when no case matches |
| Grouped cases | Multiple values can share one block |
| `?:` | Short form for a simple two-way decision |
| `if` inside `switch` | Useful when a case needs an additional condition |
| `%` | Gives remainder; useful for leap-year checking |

---

# `if-else` vs `switch-case` vs Conditional Operator

| Statement | Best Used For | Example |
|---|---|---|
| `if` | One condition | `if (age >= 18)` |
| `if-else` | Two choices | Pass / Fail |
| `if-else-if` | Multiple conditions or ranges | Marks classification |
| `switch-case` | Multiple fixed choices | Day number / menu |
| `?:` | Simple two-way decision | Alphabet / Not Alphabet |

---

# Golden Rules

> **Use `switch-case` for fixed choices.**

> **Use `if-else-if` for ranges and complex conditions.**

> **`case` takes a fixed value, not a normal condition.**

> **Put `:` after every `case` and `default`.**

> **Use `break` to stop normal fall-through.**

> **Grouped cases can intentionally share one block of code.**

> **The conditional operator `?:` is useful for a simple two-way decision.**

> **For leap years: divisible by 400 OR divisible by 4 but not by 100.**

---

# Lab 14 Program List

1. Print day name of week using `switch`.
2. Print number of days in a month using `switch`.
3. Perform Addition, Subtraction, Multiplication and Division using `switch`.
4. Read 3 numbers and multiply the largest of the first two numbers by the third number using `switch`.
5. Check whether a character is an alphabet using the conditional operator.
6. Print the number of days in a month considering leap year using `switch`.
