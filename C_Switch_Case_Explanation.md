# C Programming – `switch-case`

## 1. Introduction

`switch-case` is a **decision-making statement** in C.

It is useful when we have **one variable/expression and many fixed choices**.

For example:

```text
1 → Monday
2 → Tuesday
3 → Wednesday
4 → Thursday
5 → Friday
6 → Saturday
7 → Sunday
```

Instead of writing many `if-else-if` conditions, we can use `switch-case`.

---

## 2. Basic Syntax

```c
switch (expression)
{
    case value1:
        // statements
        break;

    case value2:
        // statements
        break;

    default:
        // statements
}
```

| Part | Meaning |
|---|---|
| `switch` | Starts the decision-making statement |
| `expression` | Value that we want to check |
| `case` | A possible fixed value |
| `break` | Stops the switch after a matching case |
| `default` | Executes when no case matches |

---

## 3. Simple Example

```c
#include <stdio.h>

int main()
{
    int choice;

    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("You selected One");
            break;

        case 2:
            printf("You selected Two");
            break;

        case 3:
            printf("You selected Three");
            break;

        default:
            printf("Invalid choice");
    }

    return 0;
}
```

If the user enters `2`, C finds `case 2` and prints:

```text
You selected Two
```

---

## 4. How `switch-case` Works

Think of it like a menu:

```text
                choice
                   |
                   v
             switch(choice)
                   |
       +-----------+-----------+
       |           |           |
       v           v           v
    case 1      case 2      case 3
       |           |           |
       v           v           v
    Action 1    Action 2    Action 3
```

If no case matches, `default` executes.

For:

```c
switch (day)
{
    case 1:
        printf("Monday");
        break;
}
```

`case 1` means:

> If the value of `day` is equal to `1`.

---

## 5. Why Do We Use `break`?

`break` tells C to **exit the switch** after executing a matching case.

```c
switch (choice)
{
    case 1:
        printf("One");
        break;

    case 2:
        printf("Two");
        break;
}
```

If `choice = 2`, C executes `case 2`, prints `Two`, and then `break` exits the switch.

### What Happens Without `break`?

```c
switch (choice)
{
    case 1:
        printf("One");

    case 2:
        printf("Two");

    case 3:
        printf("Three");
}
```

If `choice = 1`, the output can be:

```text
OneTwoThree
```

This is called **fall-through**.

### Beginner Rule

> Usually write `break` at the end of every `case`.

---

## 6. `default`

`default` is similar to the final `else` in an `if-else-if` ladder.

```c
switch (choice)
{
    case 1:
        printf("Addition");
        break;

    case 2:
        printf("Subtraction");
        break;

    default:
        printf("Invalid choice");
}
```

If the user enters `5`, there is no `case 5`, so `default` executes.

`default` is optional, but it is good practice when invalid input should be handled.

---

## 7. `switch-case` vs `if-else-if`

### `if-else-if`

```c
if (day == 1)
{
    printf("Monday");
}
else if (day == 2)
{
    printf("Tuesday");
}
```

### `switch-case`

```c
switch (day)
{
    case 1:
        printf("Monday");
        break;

    case 2:
        printf("Tuesday");
        break;
}
```

For fixed values, `switch-case` is often cleaner.

---

## 8. When Should We Use `switch-case`?

Use it when there is **one expression with several fixed possible values**.

Good examples:

```text
1 → Monday
2 → Tuesday
3 → Wednesday
```

```text
1 → Addition
2 → Subtraction
3 → Multiplication
4 → Division
```

```text
'A' → Apple
'B' → Banana
'C' → Cherry
```

### Easy Rule

> **Fixed choices → `switch-case`**

---

## 9. When Should We Use `if-else`?

Use `if-else-if` when you need ranges or complex conditions.

Example:

```c
if (marks >= 70)
{
    printf("Distinction");
}
else if (marks >= 60)
{
    printf("First Class");
}
```

`if` can handle:

```text
>
<
>=
<=
==
!=
&&
||
```

For example:

```c
if (age >= 18 && age <= 60)
```

### Easy Rule

> **Ranges/complex conditions → `if-else-if`**

---

## 10. Calculator Using `switch-case`

```c
#include <stdio.h>

int main()
{
    float a, b, result;
    char operator;

    printf("Enter first number: ");
    scanf("%f", &a);

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator);

    printf("Enter second number: ");
    scanf("%f", &b);

    switch (operator)
    {
        case '+':
            result = a + b;
            printf("Result = %.2f\n", result);
            break;

        case '-':
            result = a - b;
            printf("Result = %.2f\n", result);
            break;

        case '*':
            result = a * b;
            printf("Result = %.2f\n", result);
            break;

        case '/':
            if (b != 0)
            {
                result = a / b;
                printf("Result = %.2f\n", result);
            }
            else
            {
                printf("Division by zero is not allowed.\n");
            }
            break;

        default:
            printf("Invalid operator.\n");
    }

    return 0;
}
```

Notice:

```c
switch (operator)
```

contains a `char`, so the cases use character constants:

```c
case '+':
case '-':
case '*':
case '/':
```

---

## 11. Why Is There a Space Before `%c`?

Notice:

```c
scanf(" %c", &operator);
```

There is a space before `%c`.

This tells `scanf` to skip whitespace such as a newline left in the input buffer.

When reading a character after other input, beginners should generally use:

```c
scanf(" %c", &ch);
```

---

## 12. Can We Use Characters in `switch`?

Yes.

```c
#include <stdio.h>

int main()
{
    char grade;

    printf("Enter grade: ");
    scanf(" %c", &grade);

    switch (grade)
    {
        case 'A':
            printf("Excellent");
            break;

        case 'B':
            printf("Very Good");
            break;

        case 'C':
            printf("Good");
            break;

        default:
            printf("Invalid grade");
    }

    return 0;
}
```

Character constants use **single quotes**:

```c
'A'
'B'
'C'
```

---

## 13. Can We Use Strings in `switch`?

No.

You cannot normally write:

```c
char name[20];

switch (name)
{
    ...
}
```

C's `switch` expression must be an integral or enumeration type, not a string.

For string comparison, functions such as `strcmp()` are used.

---

## 14. `case` Values Must Be Constant

Correct:

```c
switch (number)
{
    case 1:
        printf("One");
        break;

    case 2:
        printf("Two");
        break;
}
```

Correct:

```c
switch (grade)
{
    case 'A':
        printf("Excellent");
        break;
}
```

A normal `case` label should use a constant value.

---

## 15. Duplicate `case` Values Are Not Allowed

Wrong:

```c
switch (choice)
{
    case 1:
        printf("One");
        break;

    case 1:
        printf("Another One");
        break;
}
```

Two cases cannot have the same value in one switch.

---

## 16. `case` Needs a Colon

Wrong:

```c
case 1
    printf("Monday");
```

Correct:

```c
case 1:
    printf("Monday");
```

Every `case` needs:

```text
:
```

The same applies to `default`:

```c
default:
    printf("Invalid");
```

---

## 17. `case` Does Not Take a Condition

This is a common mistake.

Wrong:

```c
case (day == 1):
```

Correct:

```c
case 1:
```

Why?

Because:

```c
switch (day)
```

already tells C which value is being checked.

Then:

```c
case 1:
```

means:

> Match the value `1`.

---

## 18. Do Not Use `>` or `<` in Normal `case` Labels

Wrong:

```c
switch (marks)
{
    case marks > 70:
        printf("Distinction");
        break;
}
```

This is not how normal `switch-case` works.

Use:

```c
if (marks > 70)
{
    printf("Distinction");
}
```

for range/relational conditions.

---

## 19. Example: Marks Classification

Suppose:

```text
70+       → Distinction
61–70     → First Class
46–60     → Second Class
36–45     → Pass Class
Below 35  → Fail
```

Do not try to use `switch` like this:

```c
switch (marks)
{
    case marks >= 70:
        printf("Distinction");
        break;
}
```

Use an `if-else-if` ladder:

```c
if (marks > 70)
{
    printf("Distinction");
}
else if (marks >= 61)
{
    printf("First Class");
}
else if (marks >= 46)
{
    printf("Second Class");
}
else if (marks >= 36)
{
    printf("Pass Class");
}
else
{
    printf("Fail");
}
```

---

## 20. Nested `if` Inside `switch`

An `if` statement can be used inside a `case`.

```c
switch (choice)
{
    case 1:
        printf("Addition");
        break;

    case 2:
        if (b != 0)
        {
            printf("Division possible");
        }
        else
        {
            printf("Cannot divide by zero");
        }
        break;

    default:
        printf("Invalid choice");
}
```

Here:

- `switch` handles the main choice.
- `if` handles an additional condition.

---

## 21. Nested `switch`

A `switch` can also be placed inside another `switch`.

```c
switch (mainChoice)
{
    case 1:

        switch (subChoice)
        {
            case 1:
                printf("Option 1");
                break;

            case 2:
                printf("Option 2");
                break;
        }

        break;

    case 2:
        printf("Main option 2");
        break;
}
```

This is called a **nested switch**.

For beginner programs, avoid unnecessary nesting.

---

## 22. `break` vs `return`

### `break`

```c
case 1:
    printf("One");
    break;
```

`break` exits the current `switch`.

### `return`

```c
case 1:
    printf("One");
    return 0;
```

`return 0` exits the `main()` function.

So:

```text
break  → exits switch
return → exits function
```

---

## 23. Complete Weekday Example

### Problem

Write a C program to print the day based on a number.

```c
#include <stdio.h>

int main()
{
    int day;

    printf("Enter day number: ");
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

### Sample Output

```text
Enter day number: 5
Friday
```

---

## 24. Common Mistakes Checklist

Before submitting a `switch-case` program, check:

- [ ] Did I write `switch (expression)`?
- [ ] Does every `case` have a colon `:`?
- [ ] Did I use a fixed value after `case`, not a condition?
- [ ] Did I write `break` where needed?
- [ ] Did I include `default` for invalid choices?
- [ ] Did I avoid duplicate case values?
- [ ] Did I avoid using strings in `switch`?
- [ ] Did I use `if-else` for ranges?
- [ ] Did I use single quotes for character cases?
- [ ] If reading a character, did I use `" %c"` where appropriate?
- [ ] Did I check division by zero where required?

---

## 25. Quick Comparison

| Feature | `if-else-if` | `switch-case` |
|---|---|---|
| Fixed values | Yes | Excellent |
| Ranges | Yes | Not directly |
| `>` / `<` | Yes | No in normal case labels |
| `>=` / `<=` | Yes | No in normal case labels |
| `&&` / `||` | Yes | Not used for normal case matching |
| Menu choices | Possible | Excellent |
| Character choices | Yes | Yes |
| String choices | With string functions | No |
| `break` required | No | Usually yes |
| `default` equivalent | `else` | `default` |

---

## 26. Final Revision

### `if`

One condition:

```c
if (condition)
{
}
```

### `if-else`

Two choices:

```c
if (condition)
{
}
else
{
}
```

### Nested `if`

A decision inside another decision:

```c
if (condition1)
{
    if (condition2)
    {
    }
}
```

### `if-else-if`

Multiple conditions and ranges:

```c
if (condition1)
{
}
else if (condition2)
{
}
else
{
}
```

### `switch-case`

One expression with multiple fixed values:

```c
switch (choice)
{
    case 1:
        // statement
        break;

    case 2:
        // statement
        break;

    default:
        // default statement
}
```

---

## 27. Golden Rules

> **`if` → condition**

> **`else` → no condition**

> **`case` → fixed value**

> **`default` → no condition**

> **`break` → exit the switch**

> **Use `if-else-if` for ranges and complex conditions.**

> **Use `switch-case` for menus and fixed choices.**

> **Do not forget the colon `:` after `case` and `default`.**

> **Do not normally forget `break` after a case.**

---

## 28. One-Line Memory Trick

```text
IF       → "Is this condition true?"
SWITCH   → "Which fixed option/value is this?"
```

That is the easiest way to decide whether to use `if-else-if` or `switch-case`.
