# C Operators & Decision-Making
## Statements Lab – 9

This lab focuses on basic calculations using arithmetic operators in C.

---

# 1. Basic Idea: What is an Operator?

An **operator** is a symbol that tells the computer to perform an operation.

For example:

```c
int a = 10;
int b = 5;

int sum = a + b;
```

Here, `+` is an operator. It tells the computer to add `a` and `b`.

| Operator | Meaning | Example |
|---|---|---|
| `+` | Addition | `10 + 5` → `15` |
| `-` | Subtraction | `10 - 5` → `5` |
| `*` | Multiplication | `10 * 5` → `50` |
| `/` | Division | `10 / 5` → `2` |
| `%` | Modulo / Remainder | `10 % 3` → `1` |

---

# 2. Understanding `/` and `%`

The `/` and `%` operators are especially important in Problems 4 and 5.

## Division `/`

The `/` operator gives us the **quotient**.

```text
10 / 3 = 3
```

Because 3 can fit completely into 10 three times.

## Modulo `%`

The `%` operator gives us the **remainder**.

```text
10 % 3 = 1
```

Because:

```text
10 = 3 × 3 + 1
```

So:

```text
/  → How many complete groups?
%  → What is left?
```

---

# 3. Problem 1 – Area of Triangle

## Problem

Write a C program to calculate and print the **area of a triangle**.

Take the **base** and **height** as input.

### Formula

```text
Area = (base × height) / 2
```

## Understanding the Problem

Suppose:

```text
Base = 10
Height = 5
```

Then:

```text
Area = (10 × 5) / 2
     = 25
```

So the answer is:

```text
Area = 25
```

## C Program

```c
#include <stdio.h>

int main()
{
    float base, height, area;

    printf("Enter base: ");
    scanf("%f", &base);

    printf("Enter height: ");
    scanf("%f", &height);

    area = (base * height) / 2;

    printf("Area = %.2f", area);

    return 0;
}
```

### What is happening?

```c
float base, height, area;
```

Creates variables to store the input and result.

```c
scanf("%f", &base);
```

Takes the base from the user.

```c
area = (base * height) / 2;
```

Applies the formula.

```c
printf("Area = %.2f", area);
```

Prints the result.

---

# 4. Problem 2 – Simple Interest

## Problem

Write a C program to calculate and print **Simple Interest**.

Take these as input:

- Principal amount
- Rate of interest
- Time period

### Formula

```text
Simple Interest = (Principal × Rate × Time) / 100
```

## Understanding the Problem

Suppose:

```text
Principal = 5000
Rate = 5
Time = 2
```

Then:

```text
Simple Interest = (5000 × 5 × 2) / 100
                = 500
```

## C Program

```c
#include <stdio.h>

int main()
{
    float principal, rate, time, interest;

    printf("Enter principal: ");
    scanf("%f", &principal);

    printf("Enter rate of interest: ");
    scanf("%f", &rate);

    printf("Enter time: ");
    scanf("%f", &time);

    interest = (principal * rate * time) / 100;

    printf("Simple Interest = %.2f", interest);

    return 0;
}
```

The main calculation is:

```c
interest = (principal * rate * time) / 100;
```

The parentheses make the formula clear and easy to read.

---

# 5. Problem 3 – Fahrenheit to Celsius

## Problem

Write a C program to convert a temperature from **Fahrenheit to Celsius**.

### Formula

```text
Celsius = ((Fahrenheit - 32) × 5) / 9
```

## Understanding the Problem

Suppose:

```text
Fahrenheit = 98.6
```

Then:

```text
Celsius = ((98.6 - 32) × 5) / 9
        = 37
```

Therefore:

```text
98.6°F = 37°C
```

## C Program

```c
#include <stdio.h>

int main()
{
    float fahrenheit, celsius;

    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);

    celsius = ((fahrenheit - 32) * 5) / 9;

    printf("Temperature in Celsius = %.2f", celsius);

    return 0;
}
```

### Why use `float`?

Temperature can contain decimal values such as:

```text
98.6
72.5
36.7
```

Therefore, `float` is suitable for this problem.

---

# 6. Problem 4 – Convert Seconds into HH:MM:SS

## Problem

Write a C program to convert a given number of **seconds** into:

```text
Hours : Minutes : Seconds
```

Print the result in:

```text
HH:MM:SS
```

Assume:

```text
1 hour = 3600 seconds
1 minute = 60 seconds
```

Example:

```text
10000 seconds
```

Expected output:

```text
02:46:40
```

## Understanding the Problem

We have:

```text
10000 seconds
```

We need to separate these seconds into hours, minutes, and seconds.

### Step 1 – Find Hours

There are 3600 seconds in one hour.

```text
Hours = 10000 / 3600
      = 2
```

So we have 2 complete hours.

### Step 2 – Find Remaining Seconds

We use `%` to find what is left:

```text
Remaining seconds = 10000 % 3600
                  = 2800
```

So after removing 2 hours, 2800 seconds remain.

### Step 3 – Find Minutes

There are 60 seconds in one minute.

```text
Minutes = 2800 / 60
        = 46
```

### Step 4 – Find Remaining Seconds

```text
Seconds = 2800 % 60
        = 40
```

Therefore:

```text
Hours   = 2
Minutes = 46
Seconds = 40
```

Final output:

```text
02:46:40
```

## C Program

```c
#include <stdio.h>

int main()
{
    int totalSeconds;
    int hours, minutes, seconds;

    printf("Enter total seconds: ");
    scanf("%d", &totalSeconds);

    hours = totalSeconds / 3600;
    minutes = (totalSeconds % 3600) / 60;
    seconds = totalSeconds % 60;

    printf("%02d:%02d:%02d", hours, minutes, seconds);

    return 0;
}
```

## Understanding `%02d`

```c
%02d
```

means:

- `d` → integer
- `2` → minimum width of 2 characters
- `0` → fill empty space with zero

So:

```text
2  → 02
5  → 05
46 → 46
```

Therefore:

```text
2:5:7
```

becomes:

```text
02:05:07
```

---

# 7. Problem 5 – Convert Days into Years, Weeks and Days

## Problem

Write a C program to convert a given number of **days** into:

- Years
- Weeks
- Remaining Days

Assume:

```text
1 year = 365 days
1 week = 7 days
```

For example:

```text
375 days
```

means:

```text
1 year, 1 week and 3 days
```

## Understanding the Problem

For this problem, use a **decreasing approach**.

The idea is:

```text
Total days
    ↓
Find years
    ↓
Remove the days used by years
    ↓
Find weeks
    ↓
Remove the days used by weeks
    ↓
Remaining days
```

### Step 1 – Find Years

```text
Years = 375 / 365
      = 1
```

So there is 1 complete year.

### Step 2 – Remove the Days Used by the Year

One year contains 365 days:

```text
Days used = 1 × 365
          = 365
```

Now subtract:

```text
Days = 375 - (1 × 365)
     = 10
```

So:

```text
1 year
10 days remaining
```

### Step 3 – Find Weeks

```text
Weeks = 10 / 7
      = 1
```

So there is 1 complete week.

### Step 4 – Remove the Days Used by the Week

```text
Days = 10 - (1 × 7)
     = 3
```

Therefore:

```text
1 Year, 1 Week and 3 Days
```

## C Program – Decreasing Approach

```c
#include <stdio.h>

int main()
{
    int days;
    int years, weeks;

    printf("Enter number of days: ");
    scanf("%d", &days);

    years = days / 365;
    days = days - (years * 365);

    weeks = days / 7;
    days = days - (weeks * 7);

    printf("%d Year, %d Week and %d Days", years, weeks, days);

    return 0;
}
```

## Understanding the Main Logic

First:

```c
years = days / 365;
```

Finds the number of complete years.

Then:

```c
days = days - (years * 365);
```

Removes the days already used by those years.

Next:

```c
weeks = days / 7;
```

Finds the number of complete weeks from the remaining days.

Finally:

```c
days = days - (weeks * 7);
```

Removes the days already used by those weeks.

Whatever is left is the final number of days.

---

# 8. Another Example for Problem 5

Suppose the input is:

```text
800 days
```

### Find years

```text
years = 800 / 365
      = 2
```

### Remove 2 years

```text
days = 800 - (2 × 365)
     = 70
```

### Find weeks

```text
weeks = 70 / 7
      = 10
```

### Remove 10 weeks

```text
days = 70 - (10 × 7)
     = 0
```

Output:

```text
2 Years, 10 Weeks and 0 Days
```

---

# 9. Quick Revision

| Problem | Main Concept |
|---|---|
| Area of Triangle | `*` and `/` |
| Simple Interest | `*` and `/` |
| Fahrenheit → Celsius | Arithmetic operators |
| Seconds → HH:MM:SS | `/` and `%` |
| Days → Years, Weeks, Days | `/`, `-`, and `*` |

## Remember

```text
/  → Find complete units
%  → Find the remainder
*  → Find the total amount used
-  → Remove the amount already used
```

The most important idea from the last two problems is:

```text
/ → How many complete units?
% → What is left?
- → Remove what we have already converted
```
