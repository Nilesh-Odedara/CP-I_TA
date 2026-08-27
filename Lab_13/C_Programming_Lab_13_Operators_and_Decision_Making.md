# C Programming Lab – 13: Operators & Decision-Making Statements

## Topic

**Decision Making in C – Nested `if` and `if-else-if` Ladder**

---

# 1. Aim

To write C programs using operators and decision-making statements to solve problems involving:

- `if`
- `if-else`
- Nested `if`
- `if-else-if` ladder
- Relational operators
- Logical operators
- Arithmetic operators
- Conditional decision making

---

# 2. Introduction

Decision-making statements allow a C program to choose what to do based on a condition.

For example:

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

When a problem has several possible conditions, we can use an `if-else-if` ladder:

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
    // default statement
}
```

## Important Rule: First True Condition Wins

C checks an `if-else-if` ladder from **top to bottom**.

As soon as one condition is true:

- That block is executed.
- The remaining conditions are skipped.

Therefore, when conditions overlap, we must carefully decide the order of the conditions.

For example:

```c
if (salary >= 30000)
{
}
else if (salary >= 20000)
{
}
else if (salary >= 10000)
{
}
```

The highest limit is checked first because `35000` is also greater than `20000` and `10000`.

---

# 3. Program 1 – Print Weekday Based on Given Number

## Problem Statement

Input a number from `1` to `7` and print the corresponding weekday.

The mapping is:

| Number | Weekday |
|---:|---|
| 1 | Monday |
| 2 | Tuesday |
| 3 | Wednesday |
| 4 | Thursday |
| 5 | Friday |
| 6 | Saturday |
| 7 | Sunday |

If the user enters a number outside `1` to `7`, print `Invalid weekday number`.

## Concept Used

- `if-else-if` ladder
- Relational operator `==`

## Algorithm

1. Start.
2. Declare an integer variable `day`.
3. Read the day number.
4. If `day == 1`, print Monday.
5. Else if `day == 2`, print Tuesday.
6. Else if `day == 3`, print Wednesday.
7. Else if `day == 4`, print Thursday.
8. Else if `day == 5`, print Friday.
9. Else if `day == 6`, print Saturday.
10. Else if `day == 7`, print Sunday.
11. Otherwise, print invalid number.
12. Stop.

## C Program

```c
#include <stdio.h>

int main()
{
    int day;

    printf("Enter weekday number (1-7): ");
    scanf("%d", &day);

    if (day == 1)
    {
        printf("Monday\n");
    }
    else if (day == 2)
    {
        printf("Tuesday\n");
    }
    else if (day == 3)
    {
        printf("Wednesday\n");
    }
    else if (day == 4)
    {
        printf("Thursday\n");
    }
    else if (day == 5)
    {
        printf("Friday\n");
    }
    else if (day == 6)
    {
        printf("Saturday\n");
    }
    else if (day == 7)
    {
        printf("Sunday\n");
    }
    else
    {
        printf("Invalid weekday number\n");
    }

    return 0;
}
```

## Explanation

The program compares the user's input with each number.

For example, if the user enters:

```text
4
```

the program checks:

```text
4 == 1  → False
4 == 2  → False
4 == 3  → False
4 == 4  → True
```

So it prints:

```text
Thursday
```

## Sample Output

```text
Enter weekday number (1-7): 4
Thursday
```

---

# 4. Program 2 – Print Month Name Based on Given Number

## Problem Statement

Input a number from `1` to `12` and print the corresponding month name.

| Number | Month |
|---:|---|
| 1 | January |
| 2 | February |
| 3 | March |
| 4 | April |
| 5 | May |
| 6 | June |
| 7 | July |
| 8 | August |
| 9 | September |
| 10 | October |
| 11 | November |
| 12 | December |

If the number is outside `1` to `12`, print `Invalid month number`.

## Concept Used

- `if-else-if` ladder
- Equality operator `==`

## Algorithm

1. Start.
2. Declare an integer variable `month`.
3. Read the month number.
4. Compare the number with `1` through `12`.
5. Print the corresponding month.
6. If no number matches, print invalid month.
7. Stop.

## C Program

```c
#include <stdio.h>

int main()
{
    int month;

    printf("Enter month number (1-12): ");
    scanf("%d", &month);

    if (month == 1)
    {
        printf("January\n");
    }
    else if (month == 2)
    {
        printf("February\n");
    }
    else if (month == 3)
    {
        printf("March\n");
    }
    else if (month == 4)
    {
        printf("April\n");
    }
    else if (month == 5)
    {
        printf("May\n");
    }
    else if (month == 6)
    {
        printf("June\n");
    }
    else if (month == 7)
    {
        printf("July\n");
    }
    else if (month == 8)
    {
        printf("August\n");
    }
    else if (month == 9)
    {
        printf("September\n");
    }
    else if (month == 10)
    {
        printf("October\n");
    }
    else if (month == 11)
    {
        printf("November\n");
    }
    else if (month == 12)
    {
        printf("December\n");
    }
    else
    {
        printf("Invalid month number\n");
    }

    return 0;
}
```

## Sample Output

```text
Enter month number (1-12): 8
August
```

---

# 5. Program 3 – Calculate Electricity Bill

## Problem Statement

Input the number of electricity units consumed and calculate the electricity bill according to the following rates:

| Units | Rate |
|---|---:|
| First 50 units | Rs. 0.50/unit |
| Next 100 units | Rs. 0.75/unit |
| Next 100 units | Rs. 1.20/unit |
| Above 250 units | Rs. 1.50/unit |

An additional **20% surcharge** is added to the bill.

## Very Important Concept – Slab Calculation

This problem is different from simply checking one range.

The rates apply to **different portions of the total units**.

For example, suppose the user consumes `300` units.

The calculation is:

```text
First 50 units       → 50 × 0.50
Next 100 units       → 100 × 0.75
Next 100 units       → 100 × 1.20
Remaining 50 units   → 50 × 1.50
```

Therefore, we calculate each slab separately.

### Formula

```text
Bill = slab charges
Surcharge = Bill × 20 / 100
Total Bill = Bill + Surcharge
```

## Why Do We Check `> 250` First?

We can structure the calculation using the highest unit range first:

```c
if (units > 250)
{
    ...
}
else if (units > 150)
{
    ...
}
else if (units > 50)
{
    ...
}
else
{
    ...
}
```

This works because each branch handles the appropriate portion of the units.

For example, if units are `300`:

```text
300 > 250 → TRUE
```

So we calculate all four slabs.

If we checked:

```c
if (units > 50)
```

first, then `300 > 50` would already be true, and the program could incorrectly skip the higher slabs.

> **Remember:** When conditions overlap, check the higher/specific range first.

## Algorithm

1. Start.
2. Declare `units`, `bill`, `surcharge`, and `totalBill`.
3. Read electricity units.
4. If units are greater than 250:
   - Calculate the first 50 units at Rs. 0.50.
   - Calculate the next 100 units at Rs. 0.75.
   - Calculate the next 100 units at Rs. 1.20.
   - Calculate remaining units at Rs. 1.50.
5. Else if units are greater than 150:
   - Calculate the first 50 units at Rs. 0.50.
   - Calculate the next 100 units at Rs. 0.75.
   - Calculate remaining units at Rs. 1.20.
6. Else if units are greater than 50:
   - Calculate the first 50 units at Rs. 0.50.
   - Calculate remaining units at Rs. 0.75.
7. Else:
   - Calculate all units at Rs. 0.50.
8. Calculate 20% surcharge.
9. Add surcharge to the bill.
10. Display the bill, surcharge, and total bill.
11. Stop.

## C Program

```c
#include <stdio.h>

int main()
{
    float units, bill, surcharge, totalBill;

    printf("Enter electricity units consumed: ");
    scanf("%f", &units);

    if (units > 250)
    {
        bill = (50 * 0.50)
             + (100 * 0.75)
             + (100 * 1.20)
             + ((units - 250) * 1.50);
    }
    else if (units > 150)
    {
        bill = (50 * 0.50)
             + (100 * 0.75)
             + ((units - 150) * 1.20);
    }
    else if (units > 50)
    {
        bill = (50 * 0.50)
             + ((units - 50) * 0.75);
    }
    else if (units >= 0)
    {
        bill = units * 0.50;
    }
    else
    {
        printf("Invalid units.\n");
        return 0;
    }

    surcharge = bill * 0.20;
    totalBill = bill + surcharge;

    printf("Bill before surcharge = Rs. %.2f\n", bill);
    printf("Surcharge = Rs. %.2f\n", surcharge);
    printf("Total electricity bill = Rs. %.2f\n", totalBill);

    return 0;
}
```

## Example Calculation

Suppose:

```text
Units = 300
```

Then:

```text
First 50 units  = 50 × 0.50 = Rs. 25.00
Next 100 units  = 100 × 0.75 = Rs. 75.00
Next 100 units  = 100 × 1.20 = Rs. 120.00
Next 50 units   = 50 × 1.50 = Rs. 75.00
```

Bill:

```text
25 + 75 + 120 + 75 = Rs. 295.00
```

Surcharge:

```text
295 × 20 / 100 = Rs. 59.00
```

Total:

```text
295 + 59 = Rs. 354.00
```

## Sample Output

```text
Enter electricity units consumed: 300
Bill before surcharge = Rs. 295.00
Surcharge = Rs. 59.00
Total electricity bill = Rs. 354.00
```

---

# 6. Program 4 – Find Roots of a Quadratic Equation

## Problem Statement

Determine the roots of the quadratic equation:

```text
ax² + bx + c = 0
```

The roots are calculated using the quadratic formula.

The nature of the roots depends on the **discriminant**:

```text
D = b² - 4ac
```

### Cases

| Discriminant | Type of Roots |
|---|---|
| `D > 0` | Two distinct real roots |
| `D == 0` | Two equal real roots |
| `D < 0` | Complex roots |

genui{"learning_viz":{"type_id":"QUADRATIC_FORMULA"}}

## Important: Check `a == 0`

The equation is quadratic only when:

```text
a != 0
```

If:

```text
a = 0
```

then the equation is not quadratic. It becomes:

```text
bx + c = 0
```

So the program should check this first.

## Algorithm

1. Start.
2. Read `a`, `b`, and `c`.
3. Check whether `a == 0`.
4. If `a == 0`, check whether `b == 0`.
5. If both `a` and `b` are zero:
   - If `c` is zero, infinitely many solutions exist.
   - Otherwise, there is no solution.
6. If `a == 0` but `b != 0`, calculate the linear root.
7. Otherwise calculate:
   ```text
   D = b² - 4ac
   ```
8. If `D > 0`, calculate two distinct real roots.
9. If `D == 0`, calculate the equal real root.
10. If `D < 0`, calculate the complex roots.
11. Display the result.
12. Stop.

## C Program

```c
#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c;
    float discriminant;
    float root1, root2;
    float realPart, imaginaryPart;

    printf("Enter values of a, b and c: ");
    scanf("%f %f %f", &a, &b, &c);

    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                printf("Infinitely many solutions.\n");
            }
            else
            {
                printf("No solution.\n");
            }
        }
        else
        {
            root1 = -c / b;
            printf("This is a linear equation.\n");
            printf("Root = %.2f\n", root1);
        }

        return 0;
    }

    discriminant = (b * b) - (4 * a * c);

    if (discriminant > 0)
    {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);

        printf("Two distinct real roots:\n");
        printf("Root 1 = %.2f\n", root1);
        printf("Root 2 = %.2f\n", root2);
    }
    else if (discriminant == 0)
    {
        root1 = -b / (2 * a);

        printf("Two equal real roots:\n");
        printf("Root 1 = Root 2 = %.2f\n", root1);
    }
    else
    {
        realPart = -b / (2 * a);
        imaginaryPart = sqrt(-discriminant) / (2 * a);

        printf("Complex roots:\n");
        printf("Root 1 = %.2f + %.2fi\n",
               realPart, imaginaryPart);
        printf("Root 2 = %.2f - %.2fi\n",
               realPart, imaginaryPart);
    }

    return 0;
}
```

## Explanation

The most important calculation is:

```c
discriminant = (b * b) - (4 * a * c);
```

### If `D > 0`

There are two different real roots.

### If `D == 0`

There is one repeated real root.

### If `D < 0`

There are no real roots, but there are two complex roots.

The program uses:

```c
sqrt()
```

from:

```c
#include <math.h>
```

to calculate the square root.

## Sample Output – Two Real Roots

```text
Enter values of a, b and c: 1 -5 6
Two distinct real roots:
Root 1 = 3.00
Root 2 = 2.00
```

---

# 7. Program 5 – Classify a Triangle

## Problem Statement

Enter three sides of a triangle and determine whether the triangle is:

- Equilateral
- Isosceles
- Scalene
- Right-angled

## First Important Step – Check Whether It Is a Valid Triangle

Before classifying a triangle, the three sides must actually be able to form a triangle.

For sides `a`, `b`, and `c`:

```text
a + b > c
a + c > b
b + c > a
```

All three conditions must be true.

If they are not, the sides do not form a valid triangle.

## Triangle Types

### Equilateral

All three sides are equal:

```c
a == b && b == c
```

### Isosceles

Exactly two sides are equal.

For example:

```c
a == b
```

or:

```c
a == c
```

or:

```c
b == c
```

### Scalene

All three sides are different.

### Right-Angled

A triangle is right-angled if the square of the largest side equals the sum of the squares of the other two sides.

For example, if `c` is the largest side:

```text
a² + b² = c²
```

genui{"learning_viz":{"type_id":"PYTHAGOREAN_THEOREM"}}

## Important: Why Check Right-Angled Carefully?

A right-angled triangle can also be **isosceles**.

For example:

```text
3, 3, 4.2426...
```

is both:

```text
Isosceles
Right-angled
```

Therefore, if the question expects **one final category**, we must decide which category has priority.

In the program below, the order is:

1. Validate triangle.
2. Check right-angled.
3. Check equilateral.
4. Check isosceles.
5. Otherwise scalene.

This gives `Right-angled` priority when a triangle belongs to more than one category.

> If your college manual wants the triangle to be reported by side type only, classify it as equilateral/isosceles/scalene and treat "right-angled" as a separate property.

## Algorithm

1. Start.
2. Read three sides `a`, `b`, and `c`.
3. Check the triangle inequality conditions.
4. If invalid, print invalid triangle.
5. Find the largest side.
6. Check the Pythagorean condition using the largest side.
7. If true, print right-angled triangle.
8. Otherwise, check whether all three sides are equal.
9. If true, print equilateral.
10. Otherwise, check whether any two sides are equal.
11. If true, print isosceles.
12. Otherwise, print scalene.
13. Stop.

## C Program

```c
#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c;
    float largest, side1, side2;

    printf("Enter three sides of triangle: ");
    scanf("%f %f %f", &a, &b, &c);

    if (a <= 0 || b <= 0 || c <= 0)
    {
        printf("Invalid triangle.\n");
        return 0;
    }

    if (!(a + b > c && a + c > b && b + c > a))
    {
        printf("Invalid triangle.\n");
        return 0;
    }

    if (a >= b && a >= c)
    {
        largest = a;
        side1 = b;
        side2 = c;
    }
    else if (b >= a && b >= c)
    {
        largest = b;
        side1 = a;
        side2 = c;
    }
    else
    {
        largest = c;
        side1 = a;
        side2 = b;
    }

    if (fabs((side1 * side1) + (side2 * side2)
             - (largest * largest)) < 0.0001)
    {
        printf("Right-angled triangle\n");
    }
    else if (a == b && b == c)
    {
        printf("Equilateral triangle\n");
    }
    else if (a == b || a == c || b == c)
    {
        printf("Isosceles triangle\n");
    }
    else
    {
        printf("Scalene triangle\n");
    }

    return 0;
}
```

## Explanation

The program first validates the triangle.

For example:

```text
3, 4, 5
```

is valid because:

```text
3 + 4 > 5
3 + 5 > 4
4 + 5 > 3
```

Then the largest side is `5`.

The program checks:

```text
3² + 4² = 5²
9 + 16 = 25
```

Therefore, it is a right-angled triangle.

## Sample Output

```text
Enter three sides of triangle: 3 4 5
Right-angled triangle
```

Another example:

```text
Enter three sides of triangle: 5 5 5
Equilateral triangle
```

---

# 8. Program 6 – Find the Second Largest Number Among Three Numbers

## Problem Statement

Input three numbers and find the **second largest** number.

For example:

```text
Input: 10 25 15
```

The numbers in descending order are:

```text
25, 15, 10
```

Therefore:

```text
Second largest = 15
```

## Important Concept

The easiest way to solve this problem using decision making is to compare the numbers.

For three numbers `a`, `b`, and `c`:

- If `a` is between `b` and `c`, then `a` is the second largest.
- If `b` is between `a` and `c`, then `b` is the second largest.
- Otherwise, `c` is the second largest.

## Handling Equal Numbers

If the question means **second largest distinct number**, then duplicate values need special handling.

For example:

```text
10 20 20
```

The distinct values are:

```text
20, 10
```

So the second largest distinct number is:

```text
10
```

The program below finds the **second largest distinct number** and reports when all three values are equal.

## Algorithm

1. Start.
2. Read three numbers `a`, `b`, and `c`.
3. Check whether all three numbers are equal.
4. If all are equal, there is no second largest distinct number.
5. Otherwise:
   - Check whether `a` is greater than one number and less than the other.
   - Check whether `b` is between the other two.
   - Otherwise, `c` is the second largest.
6. Display the second largest number.
7. Stop.

## C Program

```c
#include <stdio.h>

int main()
{
    float a, b, c, secondLargest;

    printf("Enter three numbers: ");
    scanf("%f %f %f", &a, &b, &c);

    if (a == b && b == c)
    {
        printf("All three numbers are equal.\n");
        printf("There is no second largest distinct number.\n");
    }
    else if ((a > b && a < c) || (a < b && a > c))
    {
        secondLargest = a;
        printf("Second largest = %.2f\n", secondLargest);
    }
    else if ((b > a && b < c) || (b < a && b > c))
    {
        secondLargest = b;
        printf("Second largest = %.2f\n", secondLargest);
    }
    else
    {
        secondLargest = c;
        printf("Second largest = %.2f\n", secondLargest);
    }

    return 0;
}
```

## Explanation

Suppose:

```text
a = 10
b = 25
c = 15
```

Check `a`:

```text
10 is not between 25 and 15
```

Check `b`:

```text
25 is not between 10 and 15
```

Therefore, `c` must be the second largest:

```text
Second largest = 15
```

### Another Example

```text
a = 10
b = 20
c = 20
```

The program sees that:

```text
a < b
a < c
```

and `b` and `c` are equal.

The second largest **distinct** number is:

```text
10
```

For a lab question that does not require distinct values, confirm the expected duplicate-value behavior with your instructor.

---

# 9. Common Mistakes in Lab 13

## Mistake 1 – Writing `=` Instead of `==`

Wrong:

```c
if (day = 1)
```

Correct:

```c
if (day == 1)
```

Remember:

```text
=   → Assignment
==  → Comparison
```

---

## Mistake 2 – Semicolon After `if`

Wrong:

```c
if (day == 1);
{
    printf("Monday");
}
```

Correct:

```c
if (day == 1)
{
    printf("Monday");
}
```

A semicolon immediately after `if` ends the `if` statement.

---

## Mistake 3 – Writing a Condition After `else`

Wrong:

```c
else (day == 2)
{
}
```

Correct:

```c
else if (day == 2)
{
}
```

`else` itself does not have a condition.

---

## Mistake 4 – Wrong Order of Overlapping Conditions

Wrong:

```c
if (units > 50)
{
}
else if (units > 250)
{
}
```

For `300` units:

```text
300 > 50 → TRUE
```

The `> 250` condition will never be reached.

Correct:

```c
if (units > 250)
{
}
else if (units > 50)
{
}
```

---

## Mistake 5 – Forgetting the Final `else`

For a menu or range problem, invalid input should often be handled.

Example:

```c
if (month == 1)
{
    printf("January");
}
else if (month == 2)
{
    printf("February");
}
else
{
    printf("Invalid month");
}
```

Without the final `else`, invalid input may produce no message.

---

## Mistake 6 – Forgetting the Triangle Validity Check

Do not immediately classify arbitrary side lengths.

First check:

```c
a + b > c && a + c > b && b + c > a
```

Otherwise, invalid side lengths could be incorrectly classified.

---

## Mistake 7 – Forgetting `#include <math.h>`

The quadratic equation program uses:

```c
sqrt()
```

Therefore, include:

```c
#include <math.h>
```

---

## Mistake 8 – Dividing by Zero

For the quadratic equation, do not directly use:

```c
(-b + sqrt(discriminant)) / (2 * a)
```

without first checking:

```c
if (a == 0)
```

because a quadratic equation requires `a != 0`.

---

# 10. Quick Revision

## `if`

Use when there is one condition:

```c
if (condition)
{
    // statement
}
```

## `if-else`

Use when there are two choices:

```c
if (condition)
{
    // true
}
else
{
    // false
}
```

## Nested `if`

Use when one decision must be made inside another:

```c
if (condition1)
{
    if (condition2)
    {
        // statement
    }
}
```

## `if-else-if` Ladder

Use when there are multiple choices:

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
else
{
}
```

---

# 11. Most Important Rule of the Lab

Always remember:

> **The first true condition wins.**

For example:

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

For:

```text
percentage = 80
```

the first condition is true:

```text
80 > 70
```

Therefore, the program prints:

```text
Distinction
```

and skips the remaining conditions.

---

# 12. Lab Learning Outcomes

After completing Lab 13, students should be able to:

- Use `if-else-if` ladders to solve multiple-choice decision problems.
- Use nested `if` for decisions inside decisions.
- Understand how conditions are evaluated from top to bottom.
- Correctly order overlapping conditions.
- Calculate electricity bills using slab-based logic.
- Determine quadratic roots using the discriminant.
- Validate and classify triangles.
- Find the second largest value among three numbers.
- Handle invalid input and special cases.
- Identify common syntax and logical mistakes in decision-making programs.
