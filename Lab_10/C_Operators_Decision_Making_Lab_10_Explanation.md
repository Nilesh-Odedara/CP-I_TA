# C Operators & Decision-Making
## Statements Lab – 10

This lab continues our practice with **arithmetic operators** in C.

In this lab, we will use:

```text
+  Addition
-  Subtraction
*  Multiplication
/  Division
%  Remainder
```

We will also learn how to calculate **percentages** in real-life problems.

---

# 1. Problem – Perimeter of a Rectangle

## Problem

Write a C program to calculate the **perimeter of a rectangle**.

Take the **length** and **width** from the user.

### Formula

```text
Perimeter = 2 × (Length + Width)
```

## Understanding the Problem

Imagine you have a rectangular garden.

To put a fence around the garden, you need to know the total distance around it.

That total distance is called the **perimeter**.

For example:

```text
Length = 10
Width = 5
```

Then:

```text
Perimeter = 2 × (10 + 5)
          = 2 × 15
          = 30
```

So the perimeter is:

```text
30
```

## C Program

```c
#include <stdio.h>

int main()
{
    float length, width, perimeter;

    printf("Enter length: ");
    scanf("%f", &length);

    printf("Enter width: ");
    scanf("%f", &width);

    perimeter = 2 * (length + width);

    printf("Perimeter = %.2f", perimeter);

    return 0;
}
```

---

# 2. Problem – Calculate BMI

## Problem

Write a C program to calculate **BMI (Body Mass Index)** by taking weight and height from the user.

### Formula

```text
BMI = weight / (height × height)
```

For this problem, use:

```text
Weight → kilograms (kg)
Height → meters (m)
```

## Understanding the Problem

BMI is a value calculated using a person's **weight and height**.

For example:

```text
Weight = 60 kg
Height = 1.7 m
```

Apply the formula:

```text
BMI = 60 / (1.7 × 1.7)
    = 60 / 2.89
    ≈ 20.76
```

So:

```text
BMI ≈ 20.76
```

## C Program

```c
#include <stdio.h>

int main()
{
    float weight, height, bmi;

    printf("Enter weight in kg: ");
    scanf("%f", &weight);

    printf("Enter height in meters: ");
    scanf("%f", &height);

    bmi = weight / (height * height);

    printf("BMI = %.2f", bmi);

    return 0;
}
```

### Important

If the height is given in **centimeters**, convert it to meters first.

For example:

```text
170 cm = 1.70 m
```

---

# 3. Problem – Electricity Bill

## Problem

Write a C program to calculate the **electricity bill** based on:

- Number of units consumed
- Rate per unit

### Formula

```text
Electricity Bill = Units Consumed × Rate
```

## Understanding the Problem

Suppose you used:

```text
Units = 250
Rate = ₹6 per unit
```

Then:

```text
Bill = 250 × 6
     = ₹1500
```

So the electricity bill is:

```text
₹1500
```

## C Program

```c
#include <stdio.h>

int main()
{
    float units, rate, bill;

    printf("Enter units consumed: ");
    scanf("%f", &units);

    printf("Enter rate per unit: ");
    scanf("%f", &rate);

    bill = units * rate;

    printf("Electricity Bill = %.2f", bill);

    return 0;
}
```

### Important

This problem uses a **simple rate for every unit**.

For example:

```text
250 units × ₹6 = ₹1500
```

It does not use different rates for different unit ranges.

---

# 4. Problem – Calculate Total Salary After Bonus

## Problem

Write a C program to calculate the **total salary after adding a bonus percentage**.

Take:

- Salary
- Bonus percentage

from the user.

### Formula

First calculate the bonus:

```text
Bonus = Salary × Bonus Percentage / 100
```

Then:

```text
Total Salary = Salary + Bonus
```

## Understanding the Problem

Suppose:

```text
Salary = ₹30,000
Bonus = 10%
```

First calculate the bonus:

```text
Bonus = 30000 × 10 / 100
      = ₹3000
```

Now add the bonus:

```text
Total Salary = 30000 + 3000
             = ₹33000
```

## C Program

```c
#include <stdio.h>

int main()
{
    float salary, bonusPercent, bonus, totalSalary;

    printf("Enter salary: ");
    scanf("%f", &salary);

    printf("Enter bonus percentage: ");
    scanf("%f", &bonusPercent);

    bonus = (salary * bonusPercent) / 100;

    totalSalary = salary + bonus;

    printf("Total Salary = %.2f", totalSalary);

    return 0;
}
```

### Important Idea

Whenever you are given a percentage, first find the actual amount:

```text
Percentage Amount = Original Value × Percentage / 100
```

Then use that amount in the final calculation.

---

# 5. Problem – Total Cost of Fuel

## Problem

Write a C program to calculate the **total cost of fuel** required for a journey.

Take:

- Distance
- Mileage
- Fuel price per liter

from the user.

### Formula

```text
Fuel Required = Distance / Mileage
```

Then:

```text
Total Cost = Fuel Required × Fuel Price
```

Or directly:

```text
Total Cost = (Distance / Mileage) × Fuel Price
```

## Understanding the Problem

Suppose:

```text
Distance = 300 km
Mileage = 15 km/liter
Fuel Price = ₹100/liter
```

First find how much fuel is needed:

```text
Fuel Required = 300 / 15
              = 20 liters
```

Now calculate the cost:

```text
Total Cost = 20 × 100
           = ₹2000
```

Therefore:

```text
Total Fuel Cost = ₹2000
```

## C Program

```c
#include <stdio.h>

int main()
{
    float distance, mileage, price, fuelRequired, totalCost;

    printf("Enter distance in km: ");
    scanf("%f", &distance);

    printf("Enter mileage in km/liter: ");
    scanf("%f", &mileage);

    printf("Enter fuel price per liter: ");
    scanf("%f", &price);

    fuelRequired = distance / mileage;
    totalCost = fuelRequired * price;

    printf("Total Fuel Cost = %.2f", totalCost);

    return 0;
}
```

### Easy Way to Understand

Think of it in two steps:

```text
Distance ÷ Mileage
        ↓
Fuel Required
        ↓
Fuel Required × Price
        ↓
Total Cost
```

---

# 6. Problem – Calculate Profit Percentage

## Problem

Write a C program to calculate the **profit percentage** by taking:

- Selling Price
- Cost Price

from the user.

### Formula

First calculate the profit:

```text
Profit = Selling Price - Cost Price
```

Then calculate profit percentage:

```text
Profit % = (Profit / Cost Price) × 100
```

Or:

```text
Profit % = ((Selling Price - Cost Price) / Cost Price) × 100
```

## Understanding the Problem

Suppose:

```text
Cost Price = ₹800
Selling Price = ₹1000
```

First find the profit:

```text
Profit = 1000 - 800
       = ₹200
```

Now calculate the percentage:

```text
Profit % = (200 / 800) × 100
         = 25%
```

Therefore:

```text
Profit = ₹200
Profit Percentage = 25%
```

## C Program

```c
#include <stdio.h>

int main()
{
    float sellingPrice, costPrice, profit, profitPercent;

    printf("Enter cost price: ");
    scanf("%f", &costPrice);

    printf("Enter selling price: ");
    scanf("%f", &sellingPrice);

    profit = sellingPrice - costPrice;

    profitPercent = (profit / costPrice) * 100;

    printf("Profit = %.2f
", profit);
    printf("Profit Percentage = %.2f%%", profitPercent);

    return 0;
}
```

### Understanding `%` in `printf`

You may notice:

```c
printf("Profit Percentage = %.2f%%", profitPercent);
```

The first `%` is used for the format specifier:

```text
%.2f
```

To actually print the `%` symbol, we use:

```text
%%
```

So:

```c
printf("%.2f%%", profitPercent);
```

can print:

```text
25.00%
```

---

# 7. Problem – Final Cost After Discount

## Problem

Write a C program to calculate the **final cost of a product after applying a discount**.

Take:

- Total cost of the product
- Discount percentage

from the user.

### Formula

First calculate the discount amount:

```text
Discount = Total Cost × Discount Percentage / 100
```

Then subtract the discount:

```text
Final Cost = Total Cost - Discount
```

## Understanding the Problem

Suppose:

```text
Total Cost = ₹2000
Discount = 10%
```

First calculate the discount amount:

```text
Discount = 2000 × 10 / 100
         = ₹200
```

Now subtract the discount:

```text
Final Cost = 2000 - 200
           = ₹1800
```

Therefore:

```text
Final Cost = ₹1800
```

## C Program

```c
#include <stdio.h>

int main()
{
    float totalCost, discountPercent, discount, finalCost;

    printf("Enter total cost: ");
    scanf("%f", &totalCost);

    printf("Enter discount percentage: ");
    scanf("%f", &discountPercent);

    discount = (totalCost * discountPercent) / 100;

    finalCost = totalCost - discount;

    printf("Discount = %.2f
", discount);
    printf("Final Cost = %.2f", finalCost);

    return 0;
}
```

---

# 8. Understanding Percentage Calculations

Problems 4, 6, and 7 use percentages.

The basic rule is:

```text
Amount = Original Value × Percentage / 100
```

For example:

```text
₹500 × 20 / 100
= ₹100
```

So 20% of ₹500 is ₹100.

Then:

### For Bonus

Add the percentage amount:

```text
Total = Salary + Bonus
```

### For Profit

Find the profit first:

```text
Profit = Selling Price - Cost Price
```

Then:

```text
Profit % = Profit / Cost Price × 100
```

### For Discount

Find the discount first:

```text
Discount = Cost × Discount % / 100
```

Then subtract it:

```text
Final Cost = Cost - Discount
```

---

# 9. Quick Revision

| Problem | Main Concept |
|---|---|
| Rectangle Perimeter | `+`, `*` |
| BMI | `*`, `/` |
| Electricity Bill | `*` |
| Salary + Bonus | Percentage and `+` |
| Fuel Cost | `/`, `*` |
| Profit % | `-`, `/`, `*` |
| Discount | Percentage and `-` |

## Important Formulas

```text
Perimeter = 2 × (Length + Width)

BMI = Weight / (Height × Height)

Electricity Bill = Units × Rate

Bonus = Salary × Bonus% / 100
Total Salary = Salary + Bonus

Fuel Required = Distance / Mileage
Fuel Cost = Fuel Required × Fuel Price

Profit = Selling Price - Cost Price
Profit% = Profit / Cost Price × 100

Discount = Total Cost × Discount% / 100
Final Cost = Total Cost - Discount
```

## One Important Rule to Remember

Whenever you see **percentage** in a problem:

```text
Percentage Amount = Original Value × Percentage / 100
```

Then decide whether you need to **add** or **subtract** that amount.
