# C Programming – Decision-Making Statements

## `if`, `if-else`, Nested `if`, and `if-else-if` Ladder

---

# 1. Introduction

In C programming, a program sometimes needs to **make a decision**.

For example:

- If marks are greater than 70, print `Distinction`.
- If a number is even, print `Even`.
- If the password is correct, allow access.
- If age is 18 or more, allow voting.

For these situations, we use **decision-making statements**.

The most commonly used decision-making statements are:

1. `if`
2. `if-else`
3. Nested `if`
4. `if-else-if` ladder

---

# 2. The `if` Statement

## What is `if`?

The `if` statement is used when we want to execute some code **only when a condition is true**.

### Real-Life Example

Think about this:

> If it is raining, take an umbrella.

If it is raining → take an umbrella.

If it is not raining → do nothing.

This is similar to an `if` statement.

---

## Syntax

```c
if (condition)
{
    // statements
}
```

### Example

```c
if (marks >= 35)
{
    printf("Pass");
}
```

The program checks:

```text
Is marks >= 35?
```

If the answer is **TRUE**, `Pass` is printed.

If the answer is **FALSE**, the program skips the block.

---

## Example Program

```c
#include <stdio.h>

int main()
{
    int marks;

    printf("Enter marks: ");
    scanf("%d", &marks);

    if (marks >= 35)
    {
        printf("Pass\n");
    }

    return 0;
}
```

### Sample Output

```text
Enter marks: 60
Pass
```

For:

```text
Enter marks: 20
```

there is no `Pass` message because the condition is false.

---

# 3. How an `if` Statement Works

Consider:

```c
if (age >= 18)
{
    printf("Eligible");
}
```

The execution is:

```text
             Start
               |
               v
       Is age >= 18?
          /       \
       YES         NO
        |           |
        v           |
  Print Eligible    |
        |           |
        +-----+-----+
              |
              v
             End
```

The important point is:

> An `if` statement executes its block only when its condition is true.

---

# 4. Conditions in `if`

An `if` statement must have a **condition**.

### Correct

```c
if (age >= 18)
{
    printf("Eligible");
}
```

### Common operators used in conditions

| Operator | Meaning | Example |
|---|---|---|
| `>` | Greater than | `a > b` |
| `<` | Less than | `a < b` |
| `>=` | Greater than or equal to | `a >= 10` |
| `<=` | Less than or equal to | `a <= 10` |
| `==` | Equal to | `a == 10` |
| `!=` | Not equal to | `a != 10` |

---

# 5. Important: `=` vs `==`

This is one of the most common mistakes made by beginners.

## `=` means Assignment

```c
a = 10;
```

This means:

> Store 10 in `a`.

## `==` means Comparison

```c
a == 10
```

This means:

> Is `a` equal to 10?

### Correct

```c
if (a == 10)
{
    printf("a is 10");
}
```

### Common Mistake

```c
if (a = 10)
{
    printf("a is 10");
}
```

This is **not a proper equality comparison**. It assigns `10` to `a` instead of asking whether `a` is equal to `10`.

> **Remember:** `=` → assign, `==` → compare.

---

# 6. `if-else` Statement

## What is `if-else`?

Use `if-else` when there are **two possible paths**.

For example:

> If marks are 35 or more → Pass  
> Otherwise → Fail

### Syntax

```c
if (condition)
{
    // true block
}
else
{
    // false block
}
```

---

## Example

```c
if (marks >= 35)
{
    printf("Pass");
}
else
{
    printf("Fail");
}
```

If the condition is true, the `if` block runs.

If the condition is false, the `else` block runs.

---

# 7. `if-else` Flow

```text
             Start
               |
               v
       Is marks >= 35?
          /       \
       YES         NO
        |           |
        v           v
     Print Pass  Print Fail
        |           |
        +-----+-----+
              |
              v
             End
```

Only **one** of the two blocks executes.

---

# 8. Example Program – Even or Odd

```c
#include <stdio.h>

int main()
{
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (number % 2 == 0)
    {
        printf("Even number\n");
    }
    else
    {
        printf("Odd number\n");
    }

    return 0;
}
```

### Why `%`?

The modulus operator `%` gives the remainder.

For example:

```text
10 % 2 = 0
11 % 2 = 1
```

Therefore:

```c
number % 2 == 0
```

means the number is even.

---

# 9. Nested `if`

## What is Nested `if`?

An `if` statement written **inside another `if` statement** is called a **nested `if`**.

In simple words:

> One decision is made inside another decision.

### Syntax

```c
if (condition1)
{
    if (condition2)
    {
        // statements
    }
}
```

---

# 10. Real-Life Example of Nested `if`

Suppose a college has this rule:

> If a student has passed the exam, then check attendance.  
> If attendance is 75% or more, the student is eligible.

There are two decisions:

1. Did the student pass?
2. Is attendance at least 75%?

So we can use nested `if`.

---

## Example

```c
if (marks >= 35)
{
    if (attendance >= 75)
    {
        printf("Eligible");
    }
}
```

The second condition is checked **only if the first condition is true**.

---

# 11. Nested `if` Program

```c
#include <stdio.h>

int main()
{
    int marks, attendance;

    printf("Enter marks: ");
    scanf("%d", &marks);

    printf("Enter attendance percentage: ");
    scanf("%d", &attendance);

    if (marks >= 35)
    {
        if (attendance >= 75)
        {
            printf("Student is eligible.\n");
        }
    }

    return 0;
}
```

---

# 12. Nested `if-else`

Nested decisions can also contain `else`.

```c
if (marks >= 35)
{
    if (attendance >= 75)
    {
        printf("Eligible");
    }
    else
    {
        printf("Not eligible due to attendance");
    }
}
else
{
    printf("Not eligible because of marks");
}
```

Here, there are decisions inside decisions.

---

# 13. `if-else-if` Ladder

## What is an `if-else-if` Ladder?

When there are **multiple conditions**, we can use an `if-else-if` ladder.

### Syntax

```c
if (condition1)
{
    // statement
}
else if (condition2)
{
    // statement
}
else if (condition3)
{
    // statement
}
else
{
    // default statement
}
```

The program checks conditions **from top to bottom**.

---

# 14. Example – Student Class

Suppose:

```text
Percentage > 70   → Distinction
61 to 70          → First Class
46 to 60          → Second Class
36 to 45          → Pass Class
Below 35          → Fail
```

We can write:

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

---

# 15. Very Important Rule: First True Condition Wins

This is the most important concept when teaching an `if-else-if` ladder.

Consider:

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
```

Suppose:

```text
percentage = 80
```

The program checks:

```text
80 > 70       → TRUE
```

So it prints:

```text
Distinction
```

It does **not** check the remaining conditions.

Therefore:

> In an `if-else-if` ladder, once one condition becomes true, its block executes and the remaining conditions are skipped.

---

# 16. Why Condition Order Matters

This is extremely important when conditions overlap.

Suppose the salary slabs are:

```text
Basic >= 10000
Basic >= 20000
Basic >= 30000
```

A salary of `35000` satisfies **all three**:

```text
35000 >= 10000 → TRUE
35000 >= 20000 → TRUE
35000 >= 30000 → TRUE
```

If we write this:

```c
if (basic >= 10000)
{
    printf("20%% HRA");
}
else if (basic >= 20000)
{
    printf("25%% HRA");
}
else if (basic >= 30000)
{
    printf("30%% HRA");
}
```

For `35000`, the first condition is true:

```text
35000 >= 10000
```

So the program stops checking and uses the `10000` slab.

That is **wrong**.

---

# 17. Correct Order for Overlapping Conditions

Write the highest condition first:

```c
if (basic >= 30000)
{
    printf("30%% HRA");
}
else if (basic >= 20000)
{
    printf("25%% HRA");
}
else if (basic >= 10000)
{
    printf("20%% HRA");
}
```

Now for:

```text
basic = 35000
```

the first condition is:

```text
35000 >= 30000 → TRUE
```

So the correct `30000` slab is selected.

### Golden Rule

> When using overlapping `>=` or `>` conditions, check the **highest/specific range first**.

---

# 18. Same Rule for Marks

Suppose:

```text
> 70   → Distinction
>= 61  → First Class
>= 46  → Second Class
>= 36  → Pass Class
else   → Fail
```

Correct:

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

### Why?

For `80`:

```text
80 > 70  → TRUE
```

Therefore, `Distinction` is selected.

If we put:

```c
if (percentage >= 36)
```

first, then `80 >= 36` would also be true, and the student could incorrectly be classified as Pass Class.

---

# 19. `else` Does Not Have a Condition

This is a very common beginner mistake.

### Correct

```c
if (marks >= 35)
{
    printf("Pass");
}
else
{
    printf("Fail");
}
```

### Incorrect

```c
if (marks >= 35)
{
    printf("Pass");
}
else (marks < 35)
{
    printf("Fail");
}
```

`else` means:

> If the previous `if` condition was false.

Therefore, **do not write a condition after `else`**.

If you need another condition, use:

```c
else if (condition)
```

---

# 20. `if` Must Have a Condition

Another common mistake is writing:

```c
if
{
    printf("Hello");
}
```

This is invalid C syntax.

An `if` must contain a condition:

```c
if (condition)
{
    printf("Hello");
}
```

For example:

```c
if (age >= 18)
{
    printf("Adult");
}
```

---

# 21. Semicolon After `if` – Very Important

One of the most dangerous beginner mistakes is putting a semicolon immediately after `if`.

### Wrong

```c
if (marks >= 35);
{
    printf("Pass");
}
```

The semicolon:

```c
;
```

ends the `if` statement.

The block:

```c
{
    printf("Pass");
}
```

is then treated as a separate block and can execute regardless of the condition.

### Correct

```c
if (marks >= 35)
{
    printf("Pass");
}
```

### Remember

Do **not** write:

```c
if (condition);
```

Write:

```c
if (condition)
```

---

# 22. Semicolon After `else`

The same idea applies to `else`.

### Wrong

```c
if (marks >= 35)
{
    printf("Pass");
}
else;
{
    printf("Fail");
}
```

The semicolon after `else` is incorrect and can cause unexpected behavior.

### Correct

```c
if (marks >= 35)
{
    printf("Pass");
}
else
{
    printf("Fail");
}
```

---

# 23. Extra Semicolon After `if` Can Produce Unexpected Output

Consider:

```c
int number = 10;

if (number > 20);
{
    printf("Number is greater than 20");
}
```

The condition:

```text
10 > 20
```

is false.

But because of the semicolon:

```c
if (number > 20);
```

the `if` has already ended.

The following block is independent:

```c
{
    printf("Number is greater than 20");
}
```

So the message can still be printed.

### Lesson

Be careful with:

```c
if (condition);
```

---

# 24. Do Not Put a Semicolon Between `else if`

### Wrong

```c
if (marks >= 70)
{
    printf("Distinction");
};
else if (marks >= 60)
{
    printf("First Class");
}
```

The semicolon after the `if` block can break the connection between `if` and `else`.

### Correct

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

---

# 25. Braces `{ }` – Common Beginner Mistake

Braces define a block of statements.

### Good Practice

Always use braces:

```c
if (marks >= 35)
{
    printf("Pass");
}
```

Although C allows a single statement without braces:

```c
if (marks >= 35)
    printf("Pass");
```

beginners are strongly advised to use braces.

### Why?

Consider:

```c
if (marks >= 35)
    printf("Pass");
    printf("Student passed the exam");
```

A beginner may think both `printf` statements belong to the `if`.

But only the first statement belongs to the `if`.

The second statement executes regardless of the condition.

### Better

```c
if (marks >= 35)
{
    printf("Pass");
    printf("Student passed the exam");
}
```

---

# 26. Indentation Mistake

Indentation does not change how C executes the program, but poor indentation makes mistakes difficult to find.

### Difficult to Understand

```c
if (marks >= 35)
printf("Pass");
printf("Good");
```

### Easy to Understand

```c
if (marks >= 35)
{
    printf("Pass");
    printf("Good");
}
```

Use proper indentation to make the program readable.

---

# 27. Missing Closing Brace

### Wrong

```c
if (marks >= 35)
{
    printf("Pass");

else
{
    printf("Fail");
}
```

The `if` block is not closed.

### Correct

```c
if (marks >= 35)
{
    printf("Pass");
}
else
{
    printf("Fail");
}
```

Always match:

```text
{  with  }
```

---

# 28. Wrong Use of `=` Instead of `==`

### Wrong

```c
if (number = 5)
{
    printf("Number is 5");
}
```

### Correct

```c
if (number == 5)
{
    printf("Number is 5");
}
```

Remember:

```text
=   → Assignment
==  → Comparison
```

---

# 29. Wrong Use of `&&` and `||`

These two operators are very important.

## `&&` – AND

Both conditions must be true.

```c
if (marks >= 35 && attendance >= 75)
{
    printf("Eligible");
}
```

Meaning:

```text
marks >= 35
AND
attendance >= 75
```

## `||` – OR

At least one condition must be true.

```c
if (day == 6 || day == 7)
{
    printf("Weekend");
}
```

Meaning:

```text
day is 6
OR
day is 7
```

---

# 30. Common Range Mistake

Suppose we want to check whether marks are between 35 and 50.

### Wrong

Beginners may write:

```c
if (35 <= marks <= 50)
```

This is **not the correct way** to write a range in C.

### Correct

```c
if (marks >= 35 && marks <= 50)
{
    printf("Marks are between 35 and 50");
}
```

Use two comparisons connected by `&&`.

---

# 31. Character Comparison Mistake

For characters, use single quotes:

### Correct

```c
if (ch == 'A')
{
    printf("Character is A");
}
```

### Wrong

```c
if (ch == "A")
{
    printf("Character is A");
}
```

In C:

```text
'A'   → character
"A"   → string
```

---

# 32. Comparing Characters with Numbers

When checking characters, use character constants:

### Good

```c
if (ch >= 'A' && ch <= 'Z')
{
    printf("Uppercase");
}
```

### Good

```c
if (ch >= '0' && ch <= '9')
{
    printf("Digit");
}
```

This is clearer and safer for beginners than using numeric character codes directly.

---

# 33. Dangling `else` Problem in Nested `if`

Consider:

```c
if (a > 0)
{
    if (b > 0)
    {
        printf("Both positive");
    }
    else
    {
        printf("b is not positive");
    }
}
```

The `else` belongs to the **nearest unmatched `if`**.

This is called the **dangling `else`** concept.

Using braces makes the intended relationship clear.

---

# 34. Empty `if` Block

Avoid writing an empty `if` block accidentally.

### Problem

```c
if (marks >= 35)
{
}
else
{
    printf("Fail");
}
```

This may be syntactically valid, but it often indicates that something is missing from the program.

---

# 35. Forgetting `else`

Sometimes students write:

```c
if (marks >= 35)
{
    printf("Pass");
}
printf("Fail");
```

This does **not** mean "otherwise fail".

`Fail` will be printed every time.

### Correct

```c
if (marks >= 35)
{
    printf("Pass");
}
else
{
    printf("Fail");
}
```

---

# 36. Too Many Independent `if` Statements

Compare these two programs.

### Multiple Independent `if`

```c
if (marks >= 70)
{
    printf("Distinction");
}

if (marks >= 60)
{
    printf("First Class");
}

if (marks >= 35)
{
    printf("Pass");
}
```

For `80`, **all three conditions are true**, so all three messages can be printed.

### `if-else-if` Ladder

```c
if (marks >= 70)
{
    printf("Distinction");
}
else if (marks >= 60)
{
    printf("First Class");
}
else if (marks >= 35)
{
    printf("Pass");
}
```

For `80`, only:

```text
Distinction
```

is printed.

### Lesson

Use an `if-else-if` ladder when you want **one result from multiple mutually exclusive choices**.

---

# 37. Forgetting the Final `else`

A final `else` is optional.

### Valid

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

But if you want a default result for all remaining cases, add:

```c
else
{
    printf("Other Class");
}
```

---

# 38. Difference Between `if`, `if-else`, Nested `if`, and Ladder

| Statement | Use |
|---|---|
| `if` | One decision |
| `if-else` | Two possible choices |
| Nested `if` | A decision inside another decision |
| `if-else-if` ladder | Multiple conditions/choices |

### Simple Way to Remember

```text
if
↓
One condition

if-else
↓
Two choices

Nested if
↓
Decision inside a decision

if-else-if
↓
Many choices
```

---

# 39. Quick Comparison with Examples

## `if`

```c
if (age >= 18)
{
    printf("Adult");
}
```

**Use:** Do something only when a condition is true.

---

## `if-else`

```c
if (age >= 18)
{
    printf("Adult");
}
else
{
    printf("Minor");
}
```

**Use:** Choose between two possibilities.

---

## Nested `if`

```c
if (age >= 18)
{
    if (citizen == 1)
    {
        printf("Eligible");
    }
}
```

**Use:** One condition depends on another condition.

---

## `if-else-if` Ladder

```c
if (marks >= 70)
{
    printf("Distinction");
}
else if (marks >= 60)
{
    printf("First Class");
}
else if (marks >= 35)
{
    printf("Pass");
}
else
{
    printf("Fail");
}
```

**Use:** Choose one result from multiple conditions.

---

# 40. Common Mistakes – Quick Checklist

Before running your C program, check these:

- [ ] Did I write a condition inside every `if`?
- [ ] Did I avoid writing a condition after `else`?
- [ ] Did I use `else if` for another condition?
- [ ] Did I use `==` for comparison instead of `=`?
- [ ] Did I avoid `if (condition);`?
- [ ] Did I avoid `else;`?
- [ ] Did I use `{ }` correctly?
- [ ] Did I close every `{` with `}`?
- [ ] Did I use `&&` when both conditions are required?
- [ ] Did I use `||` when either condition is sufficient?
- [ ] Did I write ranges correctly using `&&`?
- [ ] Did I use single quotes for characters?
- [ ] Did I put higher ranges before lower ranges when conditions overlap?
- [ ] Did I use `else` when a default case is required?
- [ ] Did I use an `if-else-if` ladder instead of separate `if` statements when only one result should be selected?
- [ ] Did I indent my code properly?

---

# 41. Most Important Rules for Students

### Rule 1 – `if` needs a condition

```c
if (condition)
{
}
```

Not:

```c
if
{
}
```

---

### Rule 2 – `else` has no condition

Correct:

```c
else
{
}
```

Not:

```c
else (condition)
{
}
```

If you need a condition, use:

```c
else if (condition)
{
}
```

---

### Rule 3 – Never put `;` immediately after `if`

Wrong:

```c
if (condition);
```

Correct:

```c
if (condition)
{
}
```

---

### Rule 4 – `=` and `==` are different

```text
=   → Assign
==  → Compare
```

---

### Rule 5 – First true condition wins

For:

```c
if (condition1)
{
}
else if (condition2)
{
}
else if (condition3)
{
}
```

C checks from top to bottom.

As soon as a condition is true, the corresponding block executes and the remaining conditions are skipped.

---

### Rule 6 – Check higher ranges first

For:

```text
>= 30000
>= 20000
>= 10000
```

write:

```c
if (basic >= 30000)
```

first.

Similarly, for:

```text
> 70
>= 61
>= 46
>= 36
```

write:

```c
if (percentage > 70)
```

first.

---

### Rule 7 – Use braces

Prefer:

```c
if (condition)
{
    statement;
}
```

This reduces mistakes and makes your program easier to read.

---

# 42. Final Revision

```text
                    Decision Making
                          |
          +---------------+---------------+
          |               |               |
          v               v               v
         if            if-else         Multiple
                                          |
                                +---------+---------+
                                |                   |
                                v                   v
                           Nested if          if-else-if
```

### Remember These Four Questions

**1. Only one condition?**

Use:

```c
if
```

**2. Two choices?**

Use:

```c
if-else
```

**3. One decision inside another?**

Use:

```c
nested if
```

**4. Many choices?**

Use:

```c
if-else-if ladder
```

And the most important ladder rule:

> **The first true condition wins.**

Therefore, when conditions overlap:

> **Check the highest/specific condition first, then move toward the lower/general conditions.**
