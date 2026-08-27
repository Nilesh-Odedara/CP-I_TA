# C Programming Lab – 12: Operators & Decision-Making Statements

## Topic

**Decision Making in C – Nested `if` and `if-else-if` Ladder**

---

## 1. Aim

To understand and implement **operators** and **decision-making statements** in C using:

- Arithmetic operators
- Relational operators
- Logical operators
- `if`
- `if-else`
- Nested `if`
- `if-else-if` ladder

---

## 2. Introduction

Decision-making statements allow a C program to **make a choice based on a condition**.

For example:

```c
if (marks >= 70)
{
    printf("Distinction");
}
```

Here, the program checks whether `marks >= 70` is true. If it is true, the statement inside `if` is executed.

When there are **multiple conditions**, we commonly use an **`if-else-if` ladder**:

```c
if (condition1)
{
    // statement
}
else if (condition2)
{
    // statement
}
else
{
    // statement
}
```

### Important Rule: Check Higher Ranges First

This is one of the most important concepts in this lab.

Suppose the salary conditions are:

- Basic Salary >= 10000
- Basic Salary >= 20000
- Basic Salary >= 30000

Notice that a salary of `35000` is also:

- >= 10000
- >= 20000
- >= 30000

Therefore, **the conditions overlap**.

If we write:

```c
if (basic >= 10000)
{
    // 10000 condition
}
else if (basic >= 20000)
{
    // 20000 condition
}
else if (basic >= 30000)
{
    // 30000 condition
}
```

and the salary is `35000`, the first condition `basic >= 10000` is already true. The program will execute that block and **will not check the remaining `else if` conditions**.

So, we must write the **highest condition first**:

```c
if (basic >= 30000)
{
    // 30000 condition
}
else if (basic >= 20000)
{
    // 20000 condition
}
else if (basic >= 10000)
{
    // 10000 condition
}
```

Now a salary of `35000` is correctly handled by the `>= 30000` condition.

### The Same Rule Applies to Marks

Suppose the classes are:

- Distinction: more than 70
- First Class: 61 to 70
- Second Class: 46 to 60
- Pass Class: 36 to 45
- Fail: below 35

For marks `80`, both of these are true:

```text
80 > 70
80 >= 35
```

If we check the lower condition first, the program may classify `80` incorrectly.

Therefore, when using ranges, **check the highest range first and move downward**:

```c
if (percentage > 70)
{
    // Distinction
}
else if (percentage >= 61)
{
    // First Class
}
else if (percentage >= 46)
{
    // Second Class
}
else if (percentage >= 36)
{
    // Pass Class
}
else
{
    // Fail
}
```

> **Remember:** In an `if-else-if` ladder, once a condition becomes true, the remaining conditions are skipped. Therefore, when conditions overlap, check the **highest/specific range first**.

---

# 3. Program 1 – Arithmetic Operations as per User's Choice

## Problem Statement

Perform **Addition, Subtraction, Multiplication, and Division** of two numbers according to the user's choice.

The user enters two numbers and selects an operation.

## Concept Used

- Arithmetic operators: `+`, `-`, `*`, `/`
- `if-else-if` ladder
- Relational operator `==`

## Algorithm

1. Start.
2. Declare two numbers and a choice variable.
3. Read two numbers from the user.
4. Display the operation menu.
5. Read the user's choice.
6. If the choice is `1`, perform addition.
7. Else if the choice is `2`, perform subtraction.
8. Else if the choice is `3`, perform multiplication.
9. Else if the choice is `4`, perform division.
10. Before division, check that the second number is not zero.
11. If the choice is invalid, display an error message.
12. Stop.

## C Program

```c
#include <stdio.h>

int main()
{
    float num1, num2, result;
    int choice;

    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);

    printf("\nChoose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        result = num1 + num2;
        printf("Addition = %.2f\n", result);
    }
    else if (choice == 2)
    {
        result = num1 - num2;
        printf("Subtraction = %.2f\n", result);
    }
    else if (choice == 3)
    {
        result = num1 * num2;
        printf("Multiplication = %.2f\n", result);
    }
    else if (choice == 4)
    {
        if (num2 != 0)
        {
            result = num1 / num2;
            printf("Division = %.2f\n", result);
        }
        else
        {
            printf("Division by zero is not allowed.\n");
        }
    }
    else
    {
        printf("Invalid choice.\n");
    }

    return 0;
}
```

## Explanation

The program uses an `if-else-if` ladder to compare the user's choice.

For example:

```c
if (choice == 1)
```

means: **Is the choice equal to 1?**

If yes, addition is performed.

For division, another `if` is used:

```c
if (num2 != 0)
```

This is a **nested `if`** because it is written inside another `if-else-if` block.

Division by zero is not allowed, so the program checks it before performing division.

## Sample Output

```text
Enter two numbers: 20 5

Choose an operation:
1. Addition
2. Subtraction
3. Multiplication
4. Division
Enter your choice: 4

Division = 4.00
```

---

# 4. Program 2 – Calculate Gross Salary

## Problem Statement

Enter the basic salary of an employee and calculate the gross salary according to the following conditions:

| Basic Salary | HRA | DA |
|---|---:|---:|
| `>= 30000` | 30% of Basic | 95% of Basic |
| `>= 20000` | 25% of Basic | 90% of Basic |
| `>= 10000` | 20% of Basic | 80% of Basic |

### Formula

```text
Gross Salary = Basic Salary + HRA + DA
```

## Important Concept – Why `30000` Must Come Before `10000`

This is a **critical concept**.

Consider a basic salary of `35000`.

The following conditions are all true:

```text
35000 >= 10000  → TRUE
35000 >= 20000  → TRUE
35000 >= 30000  → TRUE
```

C executes an `if-else-if` ladder **from top to bottom**.

If we write:

```c
if (basic >= 10000)
{
    // 20% HRA, 80% DA
}
else if (basic >= 20000)
{
    // 25% HRA, 90% DA
}
else if (basic >= 30000)
{
    // 30% HRA, 95% DA
}
```

For `35000`, the first condition is already true:

```c
basic >= 10000
```

Therefore, C executes that block and **skips all remaining `else if` blocks**.

The employee would incorrectly receive the `>= 10000` calculation.

### Correct Order

Always check the highest limit first:

```c
if (basic >= 30000)
{
    // 30% HRA, 95% DA
}
else if (basic >= 20000)
{
    // 25% HRA, 90% DA
}
else if (basic >= 10000)
{
    // 20% HRA, 80% DA
}
```

For `35000`:

```text
35000 >= 30000 → TRUE
```

So the program immediately uses:

```text
HRA = 30%
DA  = 95%
```

This is the correct result.

> **Golden Rule:** When using `>=` conditions with overlapping ranges, always check the **largest value first**.

## Algorithm

1. Start.
2. Declare variables for basic salary, HRA, DA, and gross salary.
3. Read the basic salary.
4. Check whether basic salary is `>= 30000`.
5. If true, calculate HRA as 30% and DA as 95%.
6. Otherwise, check whether basic salary is `>= 20000`.
7. If true, calculate HRA as 25% and DA as 90%.
8. Otherwise, check whether basic salary is `>= 10000`.
9. If true, calculate HRA as 20% and DA as 80%.
10. Calculate gross salary.
11. Display HRA, DA, and gross salary.
12. Stop.

## C Program

```c
#include <stdio.h>

int main()
{
    float basic, hra, da, gross;

    printf("Enter basic salary: ");
    scanf("%f", &basic);

    if (basic >= 30000)
    {
        hra = basic * 0.30;
        da = basic * 0.95;
    }
    else if (basic >= 20000)
    {
        hra = basic * 0.25;
        da = basic * 0.90;
    }
    else if (basic >= 10000)
    {
        hra = basic * 0.20;
        da = basic * 0.80;
    }
    else
    {
        hra = 0;
        da = 0;
        printf("Basic salary is below 10000.\n");
    }

    gross = basic + hra + da;

    printf("HRA = %.2f\n", hra);
    printf("DA = %.2f\n", da);
    printf("Gross Salary = %.2f\n", gross);

    return 0;
}
```

## Explanation

For a salary of `35000`:

```text
HRA = 35000 × 30 / 100 = 10500
DA  = 35000 × 95 / 100 = 33250

Gross Salary = 35000 + 10500 + 33250
             = 78750
```

The `>= 30000` condition must be checked first because it represents the **highest salary slab**.

## Sample Output

```text
Enter basic salary: 35000
HRA = 10500.00
DA = 33250.00
Gross Salary = 78750.00
```

---

# 5. Program 3 – Check Character Type

## Problem Statement

Enter a character and check whether it is:

- Uppercase letter
- Lowercase letter
- Digit
- Special character

## Concept Used

- Relational operators
- Logical operators
- `if-else-if` ladder
- Character comparison

## Algorithm

1. Start.
2. Declare a character variable.
3. Read a character.
4. Check whether it is between `A` and `Z`.
5. If true, print uppercase.
6. Otherwise, check whether it is between `a` and `z`.
7. If true, print lowercase.
8. Otherwise, check whether it is between `0` and `9`.
9. If true, print digit.
10. Otherwise, print special character.
11. Stop.

## C Program

```c
#include <stdio.h>

int main()
{
    char ch;

    printf("Enter a character: ");
    scanf("%c", &ch);

    if (ch >= 'A' && ch <= 'Z')
    {
        printf("Uppercase character\n");
    }
    else if (ch >= 'a' && ch <= 'z')
    {
        printf("Lowercase character\n");
    }
    else if (ch >= '0' && ch <= '9')
    {
        printf("Digit\n");
    }
    else
    {
        printf("Special character\n");
    }

    return 0;
}
```

## Explanation

The condition:

```c
ch >= 'A' && ch <= 'Z'
```

checks whether the character is in the uppercase alphabet range.

The `&&` operator means **AND**. Both conditions must be true.

Similarly:

```c
ch >= '0' && ch <= '9'
```

checks whether the character is a digit.

If none of the first three conditions are true, the character is considered a special character.

## Sample Output

```text
Enter a character: G
Uppercase character
```

Another example:

```text
Enter a character: @
Special character
```

---

# 6. Program 4 – Check Whether Last Digit is Even or Odd

## Problem Statement

Input an integer number and check whether the **last digit** of the number is even or odd.

## Concept Used

- Modulus operator `%`
- `if-else`
- Relational operator

## Important Concept – Modulus Operator

The `%` operator gives the **remainder** after division.

For example:

```text
25 % 10 = 5
48 % 10 = 8
123 % 10 = 3
```

Therefore:

```c
number % 10
```

gives the last digit of an integer.

To check whether the last digit is even:

```c
(number % 10) % 2 == 0
```

## Algorithm

1. Start.
2. Declare an integer variable.
3. Read the integer.
4. Find the last digit using `% 10`.
5. Divide the last digit by `2`.
6. If the remainder is `0`, the last digit is even.
7. Otherwise, the last digit is odd.
8. Stop.

## C Program

```c
#include <stdio.h>

int main()
{
    int number, lastDigit;

    printf("Enter an integer number: ");
    scanf("%d", &number);

    lastDigit = number % 10;

    if (lastDigit % 2 == 0)
    {
        printf("Last digit %d is even.\n", lastDigit);
    }
    else
    {
        printf("Last digit %d is odd.\n", lastDigit);
    }

    return 0;
}
```

## Explanation

Suppose the user enters:

```text
123
```

First:

```c
lastDigit = 123 % 10;
```

So:

```text
lastDigit = 3
```

Then:

```c
3 % 2 = 1
```

Since the remainder is not zero, `3` is odd.

## Sample Output

```text
Enter an integer number: 123
Last digit 3 is odd.
```

---

# 7. Program 5 – Calculate Percentage and Print Class

## Problem Statement

Read marks of five subjects. Calculate the percentage and print the class according to the following conditions:

| Percentage | Class |
|---|---|
| More than 70 | Distinction |
| 61 to 70 | First Class |
| 46 to 60 | Second Class |
| 36 to 45 | Pass Class |
| Below 35 | Fail |

> **Note:** The question specifies "Fail below 35" and "Pass Class between 36 to 45". This leaves exactly `35` unspecified. In the program below, `35` is treated as **Fail** so that every possible percentage has a defined result. If your college/lab manual requires `35` to be Pass, change the final boundary accordingly.

## Important Concept – Why Check `70+` Before `35`?

This is another **critical concept** about the `if-else-if` ladder.

Suppose the percentage is `80`.

The following conditions can be true:

```text
80 > 70       → TRUE
80 >= 61      → TRUE
80 >= 46      → TRUE
80 >= 36      → TRUE
```

If we start with a lower condition such as:

```c
if (percentage >= 36)
{
    printf("Pass Class");
}
else if (percentage > 70)
{
    printf("Distinction");
}
```

then `80 >= 36` is already true.

The program prints:

```text
Pass Class
```

and **never reaches** the Distinction condition.

That is incorrect.

### Correct Order

We should check from the **highest percentage to the lowest**:

```c
if (percentage > 70)
{
    printf("Distinction");
}
else if (percentage >= 61)
{
    printf("First Class");
}
else if (percentage >= 46)
{
    printf("Second Class");
}
else if (percentage >= 36)
{
    printf("Pass Class");
}
else
{
    printf("Fail");
}
```

For `80`:

```text
80 > 70 → TRUE
```

So the program immediately prints:

```text
Distinction
```

### Why Does This Work?

The ranges are written as descending limits:

```text
> 70
>= 61
>= 46
>= 36
else
```

Once a percentage enters a higher range, it is handled immediately.

> **Remember:** In an `if-else-if` ladder, **the first true condition wins**. Therefore, when conditions overlap, always place the **highest range first**.

## Algorithm

1. Start.
2. Declare variables for five subjects, total, and percentage.
3. Read marks of five subjects.
4. Calculate total marks.
5. Calculate percentage.
6. If percentage is greater than 70, print Distinction.
7. Else if percentage is greater than or equal to 61, print First Class.
8. Else if percentage is greater than or equal to 46, print Second Class.
9. Else if percentage is greater than or equal to 36, print Pass Class.
10. Else, print Fail.
11. Display total and percentage.
12. Stop.

## C Program

```c
#include <stdio.h>

int main()
{
    float marks1, marks2, marks3, marks4, marks5;
    float total, percentage;

    printf("Enter marks of five subjects: ");
    scanf("%f %f %f %f %f",
          &marks1, &marks2, &marks3, &marks4, &marks5);

    total = marks1 + marks2 + marks3 + marks4 + marks5;
    percentage = total / 5;

    printf("Total Marks = %.2f\n", total);
    printf("Percentage = %.2f%%\n", percentage);

    if (percentage > 70)
    {
        printf("Class = Distinction\n");
    }
    else if (percentage >= 61)
    {
        printf("Class = First Class\n");
    }
    else if (percentage >= 46)
    {
        printf("Class = Second Class\n");
    }
    else if (percentage >= 36)
    {
        printf("Class = Pass Class\n");
    }
    else
    {
        printf("Class = Fail\n");
    }

    return 0;
}
```

## Explanation

Suppose the five marks are:

```text
80 75 72 85 78
```

Total:

```text
80 + 75 + 72 + 85 + 78 = 390
```

Percentage:

```text
390 / 5 = 78%
```

Now the program checks:

```text
78 > 70 → TRUE
```

Therefore:

```text
Class = Distinction
```

The program does not check the remaining `else if` conditions because the first condition was already true.

## Sample Output

```text
Enter marks of five subjects: 80 75 72 85 78
Total Marks = 390.00
Percentage = 78.00%
Class = Distinction
```

---

# 8. Quick Revision – `if-else-if` Ladder

The most important rule from this lab is:

```text
FIRST TRUE CONDITION = BLOCK THAT WILL EXECUTE
```

For overlapping conditions, always arrange them from **highest/specific to lowest/general**.

### Wrong Order

```c
if (salary >= 10000)
{
    // 10000 slab
}
else if (salary >= 20000)
{
    // 20000 slab
}
else if (salary >= 30000)
{
    // 30000 slab
}
```

### Correct Order

```c
if (salary >= 30000)
{
    // 30000 slab
}
else if (salary >= 20000)
{
    // 20000 slab
}
else if (salary >= 10000)
{
    // 10000 slab
}
```

### Wrong Order for Percentage

```c
if (percentage >= 36)
{
    // Pass
}
else if (percentage > 70)
{
    // Distinction
}
```

### Correct Order for Percentage

```c
if (percentage > 70)
{
    // Distinction
}
else if (percentage >= 61)
{
    // First Class
}
else if (percentage >= 46)
{
    // Second Class
}
else if (percentage >= 36)
{
    // Pass
}
else
{
    // Fail
}
```

---

# 9. Key Points to Remember

1. `if` is used to execute code when a condition is true.
2. `if-else` provides two choices.
3. `if-else-if` is useful when there are multiple conditions.
4. In an `if-else-if` ladder, **only the first true condition is executed**.
5. If conditions overlap, check the **highest range first**.
6. `&&` means **AND**.
7. `==` means **equal to**.
8. `!=` means **not equal to**.
9. `%` gives the remainder.
10. `number % 10` gives the last digit of an integer.
11. Always check for division by zero before performing division.
12. Use nested `if` when one decision needs another decision inside it.

---

# 10. Lab Learning Outcome

After completing this lab, students should be able to:

- Use arithmetic, relational, and logical operators.
- Use `if`, `if-else`, and `if-else-if` statements.
- Understand nested `if`.
- Solve problems involving multiple ranges.
- Correctly arrange overlapping conditions.
- Use the modulus operator to extract the last digit.
- Implement real-world decision-making logic in C.
