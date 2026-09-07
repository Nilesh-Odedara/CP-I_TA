# Conditional (Ternary) Operator in C

## Complete Beginner-Friendly Explanation

---

# 1. Introduction

The **conditional operator** in C is also known as the **ternary operator**.

It is used to make a simple decision between **two possible choices**.

For example:

```text
If number is even → print Even
Otherwise → print Odd
```

Normally, we can solve this using `if-else`.

Using the conditional operator, the same decision can be written in a shorter form.

---

# 2. What Is an Operator?

Before learning the conditional operator, understand what an **operator** is.

An operator is a symbol that tells C to perform some operation.

Examples:

```c
+   Addition
-   Subtraction
*   Multiplication
/   Division
%   Remainder
>   Greater than
<   Less than
==  Equal to
&&  Logical AND
||  Logical OR
```

The conditional operator is:

```c
? :
```

It uses both `?` and `:`.

---

# 3. Why Is It Called the Ternary Operator?

The word **ternary** means **three**.

The conditional operator works with three parts:

```c
condition ? expression1 : expression2
```

The three parts are:

```text
1. condition
2. expression1
3. expression2
```

Therefore, it is called the **ternary operator**.

---

# 4. Symbol of the Conditional Operator

The conditional operator uses:

```c
? :
```

For example:

```c
age >= 18 ? printf("Adult") : printf("Minor");
```

Here:

```text
age >= 18       → condition
printf("Adult") → true expression
printf("Minor") → false expression
```

---

# 5. Basic Syntax

The general syntax is:

```c
condition ? expression1 : expression2;
```

Meaning:

```text
If condition is TRUE
        ↓
   expression1

If condition is FALSE
        ↓
   expression2
```

Another way to remember it:

```text
condition ? TRUE : FALSE
```

---

# 6. Simple Example

```c
int a = 10;

(a > 5) ? printf("Yes") : printf("No");
```

The condition is:

```c
a > 5
```

Since:

```text
10 > 5
```

is true, C executes:

```c
printf("Yes");
```

Output:

```text
Yes
```

---

# 7. What Happens When the Condition Is False?

Consider:

```c
int a = 3;

(a > 5) ? printf("Yes") : printf("No");
```

The condition:

```c
a > 5
```

is false because:

```text
3 > 5
```

is false.

Therefore, C executes:

```c
printf("No");
```

Output:

```text
No
```

---

# 8. Flow of the Conditional Operator

Think of it like this:

```text
             condition
                 |
          ┌──────┴──────┐
        TRUE           FALSE
          |               |
   expression1       expression2
```

Only **one** of the two expressions is selected.

---

# 9. Conditional Operator and `if-else`

The conditional operator is often used as a short form of a simple `if-else`.

### Using `if-else`

```c
if (a > b)
{
    printf("A is greater");
}
else
{
    printf("B is greater");
}
```

### Using conditional operator

```c
(a > b) ? printf("A is greater") : printf("B is greater");
```

Both perform the same basic decision.

---

# 10. When Should We Use It?

The conditional operator is best when:

- There are only two possible results.
- The condition is simple.
- The code remains easy to understand.

Good example:

```c
result = (a > b) ? a : b;
```

Not recommended for a very complicated decision containing many nested conditions.

For complex logic, use `if-else`.

---

# 11. Storing a Result in a Variable

The conditional operator becomes especially useful when we want to choose a value.

Example:

```c
int a = 10;
int b = 20;
int max;

max = (a > b) ? a : b;
```

If `a > b` is true:

```text
max = a
```

Otherwise:

```text
max = b
```

Since `20` is greater than `10`:

```text
max = 20
```

---

# 12. Complete Program: Find Largest of Two Numbers

```c
#include <stdio.h>

int main()
{
    int a, b, largest;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    largest = (a > b) ? a : b;

    printf("Largest = %d", largest);

    return 0;
}
```

### Sample Output

```text
Enter two numbers: 25 15
Largest = 25
```

---

# 13. Conditional Operator for Even or Odd

We can check whether a number is even or odd.

Condition:

```c
num % 2 == 0
```

If true:

```text
Even
```

Otherwise:

```text
Odd
```

Program:

```c
#include <stdio.h>

int main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    (num % 2 == 0) ? printf("Even") : printf("Odd");

    return 0;
}
```

### Sample Output

```text
Enter a number: 14
Even
```

---

# 14. Conditional Operator for Positive or Negative

```c
#include <stdio.h>

int main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    (num >= 0) ? printf("Positive") : printf("Negative");

    return 0;
}
```

### Important Note

This program considers `0` as positive because the condition is:

```c
num >= 0
```

If you need three results:

```text
Positive
Negative
Zero
```

then a normal `if-else-if` structure is clearer.

---

# 15. Check Pass or Fail

Suppose a student passes when marks are `35` or above.

```c
result = (marks >= 35) ? "Pass" : "Fail";
```

Complete example:

```c
#include <stdio.h>

int main()
{
    int marks;

    printf("Enter marks: ");
    scanf("%d", &marks);

    printf("%s", (marks >= 35) ? "Pass" : "Fail");

    return 0;
}
```

### Sample Output

```text
Enter marks: 72
Pass
```

---

# 16. Conditional Operator with Character

The conditional operator can also be used with characters.

Example:

```c
char ch;

scanf(" %c", &ch);

(ch >= 'A' && ch <= 'Z') ?
    printf("Uppercase") :
    printf("Not Uppercase");
```

Notice:

```c
'A'
```

uses **single quotes** because it is a character.

---

# 17. Check Whether Character Is an Alphabet

This is the problem from Lab 14.

An alphabet is either:

```text
A to Z
```

or:

```text
a to z
```

Condition:

```c
(ch >= 'A' && ch <= 'Z') ||
(ch >= 'a' && ch <= 'z')
```

Complete program:

```c
#include <stdio.h>

int main()
{
    char ch;

    printf("Enter a character: ");
    scanf(" %c", &ch);

    ((ch >= 'A' && ch <= 'Z') ||
     (ch >= 'a' && ch <= 'z'))
        ? printf("Alphabet")
        : printf("Not an alphabet");

    return 0;
}
```

### Sample Output

```text
Enter a character: G
Alphabet
```

---

# 18. Why Is There a Space Before `%c`?

You may see:

```c
scanf(" %c", &ch);
```

There is a space before `%c`.

This helps `scanf` ignore leftover whitespace such as:

```text
Enter
Space
Newline
Tab
```

For character input, it is good practice for beginners to use:

```c
scanf(" %c", &ch);
```

---

# 19. Conditional Operator with Arithmetic

The conditional operator can select values that are then used in calculations.

Example:

```c
int a = 10;
int b = 20;

int max = (a > b) ? a : b;

printf("%d", max);
```

Output:

```text
20
```

We can also use it directly:

```c
printf("%d", (a > b) ? a : b);
```

---

# 20. Conditional Operator with Assignment

A very common use is:

```c
variable = condition ? value1 : value2;
```

Example:

```c
int max;

max = (a > b) ? a : b;
```

Another example:

```c
int result;

result = (num % 2 == 0) ? 1 : 0;
```

Meaning:

```text
If num is even → result = 1
Otherwise       → result = 0
```

---

# 21. Conditional Operator Can Return Different Values

The two expressions do not have to be `printf()` statements.

Example:

```c
int age = 20;

int status = (age >= 18) ? 1 : 0;
```

Here:

```text
age >= 18 → true
```

Therefore:

```text
status = 1
```

---

# 22. Conditional Operator with Strings

In C, a conditional operator can select between string literals.

Example:

```c
int marks = 80;

printf("%s", (marks >= 35) ? "Pass" : "Fail");
```

Output:

```text
Pass
```

Remember:

```c
"Pass"
```

is a string, so it uses **double quotes**.

---

# 23. Nested Conditional Operator

A conditional operator can be placed inside another conditional operator.

Example:

```c
result = (marks >= 75) ? "Distinction" :
         (marks >= 35) ? "Pass" :
                         "Fail";
```

This means:

```text
marks >= 75
    ↓
Distinction

Otherwise:
marks >= 35
    ↓
Pass

Otherwise:
Fail
```

### Important Warning

Nested ternary operators can become difficult to read.

For beginners, prefer:

```c
if
else if
else
```

when there are many conditions.

---

# 24. Example: Find Largest of Three Numbers

It is possible to use nested conditional operators:

```c
largest = (a > b) ?
             ((a > c) ? a : c) :
             ((b > c) ? b : c);
```

This works, but it is harder for beginners to understand.

A clearer solution is:

```c
if (a > b && a > c)
{
    largest = a;
}
else if (b > c)
{
    largest = b;
}
else
{
    largest = c;
}
```

### Teaching Rule

> Use the conditional operator for simple decisions. Use `if-else` when the logic becomes difficult to read.

---

# 25. Conditional Operator with Logical Operators

The condition can contain logical operators.

Example:

```c
result = (age >= 18 && age <= 60) ? "Allowed" : "Not Allowed";
```

Here:

```c
&&
```

means **AND**.

Both conditions must be true.

---

# 26. Conditional Operator with OR

We can also use `||`.

Example:

```c
result = (ch == 'a' || ch == 'A') ? "A" : "Not A";
```

Meaning:

```text
If ch is 'a' OR ch is 'A'
    → print A
Otherwise
    → print Not A
```

---

# 27. Conditional Operator with Relational Operators

Common relational operators can be used in the condition:

```c
>
<
>=
<=
==
!=
```

Example:

```c
(a >= b) ? printf("A is greater or equal") :
           printf("B is greater");
```

---

# 28. Conditional Operator and `=` Are Different

Do not confuse:

```c
=
```

with:

```c
?:
```

### Assignment

```c
x = 10;
```

means:

> Store 10 in `x`.

### Conditional operator

```c
x = (a > b) ? a : b;
```

means:

> If `a > b` is true, store `a`; otherwise store `b`.

---

# 29. Conditional Operator and `==`

Remember:

```c
==
```

is used for comparison.

Example:

```c
(num % 2 == 0)
```

means:

> Is the remainder equal to zero?

Do not write:

```c
(num % 2 = 0)
```

because `=` is assignment.

---

# 30. Operator Precedence

When expressions become complicated, use parentheses.

Prefer:

```c
result = ((a > b) ? a : b);
```

For a complex condition:

```c
((a > 0 && a < 100) || a == 200)
```

Parentheses make the logic easier to understand.

### Beginner Rule

> When in doubt, use parentheses.

---

# 31. Conditional Operator vs `if-else`

| Feature | Conditional Operator | `if-else` |
|---|---|---|
| Syntax | `?:` | `if`, `else` |
| Number of main choices | Two | Two or more with `else-if` |
| Code length | Usually shorter | Usually longer |
| Best for | Simple decisions | Complex decisions |
| Readability | Good for short expressions | Better for complex logic |
| Can contain multiple statements easily? | No | Yes |

---

# 32. Conditional Operator vs `switch`

These are used for different purposes.

### Conditional operator

Good for:

```c
max = (a > b) ? a : b;
```

There are two possible results.

### `switch`

Good for:

```c
switch(day)
{
    case 1:
        printf("Monday");
        break;

    case 2:
        printf("Tuesday");
        break;
}
```

There are multiple fixed choices.

---

# 33. `if-else` vs Conditional Operator vs `switch`

| Decision Type | Recommended |
|---|---|
| One condition | `if` |
| Two simple results | Conditional operator |
| Multiple conditions/ranges | `if-else-if` |
| Multiple fixed choices | `switch-case` |

Examples:

```text
Pass / Fail
→ Conditional operator

Marks 0–34, 35–49, 50–59, etc.
→ if-else-if

Day 1–7
→ switch-case
```

---

# 34. Common Mistake: Forgetting `:`

Wrong:

```c
(a > b) ? a : b
```

If used as a statement, remember the semicolon:

```c
(a > b) ? a : b;
```

If assigning:

```c
max = (a > b) ? a : b;
```

Both `?` and `:` are required.

---

# 35. Common Mistake: Wrong Order

The correct syntax is:

```c
condition ? true_expression : false_expression;
```

Not:

```c
true_expression ? condition : false_expression;
```

---

# 36. Common Mistake: Forgetting the False Part

Wrong:

```c
(a > b) ? printf("A");
```

The conditional operator requires both results:

```c
(a > b) ? printf("A") : printf("B");
```

---

# 37. Common Mistake: Confusing `?` with `if`

Wrong idea:

```c
if ? condition
```

Correct:

```c
if (condition)
```

or:

```c
condition ? true_part : false_part;
```

---

# 38. Common Mistake: Using Too Many Conditions

This is possible:

```c
result = (a > b) ? a :
         (b > c) ? b :
         c;
```

But if the logic becomes complicated, it is better to use `if-else`.

Readable code is more important than making the code as short as possible.

---

# 39. Common Mistake: Confusing Character and String

For a character:

```c
'A'
```

For a string:

```c
"A"
```

Example:

```c
ch == 'A'
```

Correct.

```c
ch == "A"
```

Incorrect for comparing a single `char`.

---

# 40. Common Mistake: Missing Parentheses in Complex Conditions

Instead of making a complicated expression difficult to read:

```c
ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z' ? ...
```

prefer:

```c
((ch >= 'A' && ch <= 'Z') ||
 (ch >= 'a' && ch <= 'z'))
    ? printf("Alphabet")
    : printf("Not an alphabet");
```

Parentheses make the intended logic clear.

---

# 41. Common Mistake: Thinking Ternary Means "Only One Character"

The word ternary does **not** mean it works only with characters.

It means the operator has **three operands/parts**:

```text
condition
true expression
false expression
```

It can work with:

```text
integers
floating-point values
characters
strings
expressions
function calls
```

depending on the context.

---

# 42. Common Mistake: Thinking Ternary Is Always Better

Shorter code is not always better code.

For example:

```c
result = condition ? value1 : value2;
```

is excellent when the decision is simple.

But a long nested ternary expression can be confusing.

Use:

```c
if-else
```

when it makes the program easier to understand.

---

# 43. Real-Life Example

Suppose:

```text
Age >= 18 → Eligible
Age < 18  → Not Eligible
```

Using conditional operator:

```c
(age >= 18) ? printf("Eligible") : printf("Not Eligible");
```

This is a good use of the ternary operator because there are only two outcomes.

---

# 44. Example: Maximum of Two Numbers

```c
max = (a > b) ? a : b;
```

Read it as:

> If `a` is greater than `b`, maximum is `a`; otherwise maximum is `b`.

This is one of the most common examples of the conditional operator.

---

# 45. Example: Minimum of Two Numbers

```c
min = (a < b) ? a : b;
```

Read it as:

> If `a` is smaller than `b`, minimum is `a`; otherwise minimum is `b`.

---

# 46. Example: Absolute Value

For a simple integer:

```c
absolute = (num >= 0) ? num : -num;
```

Example:

```text
num = -10
```

Since `num >= 0` is false:

```text
absolute = -(-10)
absolute = 10
```

---

# 47. Example: Check Voting Eligibility

```c
(age >= 18) ? printf("Eligible to vote")
            : printf("Not eligible to vote");
```

There are exactly two outcomes.

---

# 48. Example: Check Divisibility

Check whether a number is divisible by 5:

```c
(num % 5 == 0) ? printf("Divisible by 5")
               : printf("Not divisible by 5");
```

---

# 49. Example: Check Uppercase or Lowercase

If we already know the input is an alphabet:

```c
(ch >= 'A' && ch <= 'Z')
    ? printf("Uppercase")
    : printf("Lowercase");
```

---

# 50. Example: Assign Grade for Two Choices

For a simple pass/fail decision:

```c
char *result;

result = (marks >= 35) ? "Pass" : "Fail";

printf("%s", result);
```

---

# 51. Important: Conditional Operator Does Not Replace Every `if`

Use conditional operator:

```c
max = (a > b) ? a : b;
```

when the decision is short and simple.

Use `if-else` when you need:

- Multiple statements
- Multiple conditions
- Complex calculations
- Nested logic
- Better readability

---

# 52. A Simple Mental Trick

Whenever you see:

```c
condition ? A : B
```

read it as:

```text
If condition is TRUE → A
Otherwise → B
```

For example:

```c
age >= 18 ? "Adult" : "Minor"
```

Read:

```text
If age is 18 or more → Adult
Otherwise → Minor
```

---

# 53. Step-by-Step Method to Write a Ternary Expression

Suppose the problem is:

> Check whether a number is even or odd.

### Step 1: Find the condition

```c
num % 2 == 0
```

### Step 2: Find the true result

```text
Even
```

### Step 3: Find the false result

```text
Odd
```

### Step 4: Put them together

```c
(num % 2 == 0) ? printf("Even") : printf("Odd");
```

This four-step method can be used for many beginner problems.

---

# 54. Another Step-by-Step Example

Problem:

> Find the larger of two numbers.

### Step 1: Condition

```c
a > b
```

### Step 2: True result

```c
a
```

### Step 3: False result

```c
b
```

### Step 4: Complete expression

```c
(a > b) ? a : b
```

### Step 5: Store the answer

```c
largest = (a > b) ? a : b;
```

---

# 55. Practice Questions

Try writing the conditional operator for these:

1. Check whether a number is even or odd.
2. Find the largest of two numbers.
3. Find the smallest of two numbers.
4. Check whether a person is eligible to vote.
5. Check whether a number is positive or negative.
6. Check whether a number is divisible by 10.
7. Check whether a character is an alphabet.
8. Check whether a character is uppercase or lowercase.
9. Check pass or fail using marks.
10. Find whether two numbers are equal or different.

---

# 56. Practice Answers

### 1. Even or Odd

```c
(num % 2 == 0) ? printf("Even") : printf("Odd");
```

### 2. Largest of Two

```c
largest = (a > b) ? a : b;
```

### 3. Smallest of Two

```c
smallest = (a < b) ? a : b;
```

### 4. Voting Eligibility

```c
(age >= 18) ? printf("Eligible") : printf("Not Eligible");
```

### 5. Positive or Negative

```c
(num >= 0) ? printf("Positive") : printf("Negative");
```

### 6. Divisible by 10

```c
(num % 10 == 0) ? printf("Divisible") : printf("Not Divisible");
```

### 7. Alphabet or Not

```c
((ch >= 'A' && ch <= 'Z') ||
 (ch >= 'a' && ch <= 'z'))
    ? printf("Alphabet")
    : printf("Not Alphabet");
```

### 8. Uppercase or Lowercase

```c
(ch >= 'A' && ch <= 'Z')
    ? printf("Uppercase")
    : printf("Lowercase");
```

### 9. Pass or Fail

```c
(marks >= 35) ? printf("Pass") : printf("Fail");
```

### 10. Equal or Different

```c
(a == b) ? printf("Equal") : printf("Different");
```

---

# 57. Final Summary

The **conditional operator** is:

```c
? :
```

Its syntax is:

```c
condition ? true_expression : false_expression;
```

It is called the **ternary operator** because it has three operands/parts.

### Remember

```text
Condition TRUE
     ↓
First expression

Condition FALSE
     ↓
Second expression
```

### Best use

Use it for simple two-way decisions:

```c
max = (a > b) ? a : b;
```

```c
(num % 2 == 0) ? printf("Even") : printf("Odd");
```

```c
(marks >= 35) ? printf("Pass") : printf("Fail");
```

### Avoid

Do not make complicated nested ternary expressions when `if-else` would be easier to read.

---

# Quick Revision Table

| Item | Meaning |
|---|---|
| `?` | Separates condition from true expression |
| `:` | Separates true expression from false expression |
| `?:` | Conditional/Ternary operator |
| Ternary | Three operands/parts |
| True | First expression is selected |
| False | Second expression is selected |
| `if-else` | More suitable for complex decisions |
| `switch` | More suitable for multiple fixed choices |

---

# Golden Rule

> **Conditional operator = a short and simple way to choose between two results.**

Always remember:

```c
condition ? TRUE : FALSE;
```

Think:

```text
If condition is true → first part
Otherwise            → second part
```
