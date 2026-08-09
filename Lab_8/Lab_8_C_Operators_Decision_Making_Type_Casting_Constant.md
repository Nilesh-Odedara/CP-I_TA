# C Operators & Decision-Making Statements

## Lab – 8
### Type Casting and Constant

> **Write the following programs in C.**

---

## 1. Calculate Average of 2 Integers and Show Result in Float. (A)

### Code

```c
#include <stdio.h>

int main() {
    int a = 10;
    int b = 20;

    float average = (float)(a + b) / 2;

    printf("Average = %.2f", average);

    return 0;
}
```

### Output

```text
Average = 15.00
```

---

## 2. Demonstrate `const` Keyword. (A)

### Code

```c
#include <stdio.h>

int main() {
    const int value = 10;

    printf("Value = %d", value);

    return 0;
}
```

### Output

```text
Value = 10
```

> **Note:** A variable declared with `const` cannot be modified after initialization.

---

## 3. ASCII Value of Character Using Type Casting. (A)

### Code

```c
#include <stdio.h>

int main() {
    char ch = 'A';

    int ascii = (int)ch;

    printf("Character = %c\n", ch);
    printf("ASCII Value = %d", ascii);

    return 0;
}
```

### Output

```text
Character = A
ASCII Value = 65
```

---

## 4. Convert Float Data into Integer Data and Observe Data Loss During Conversion. (A)

### Code

```c
#include <stdio.h>

int main() {
    float value = 25.75;

    int convertedValue = (int)value;

    printf("Original float value = %.2f\n", value);
    printf("Converted integer value = %d", convertedValue);
    printf("data loss = %f", value - convertedValue);

    return 0;
}
```

### Output

```text
Original float value = 25.75
Converted integer value = 25
data loss = 0.75
```

### Observation

The decimal part `.75` is lost during conversion from `float` to `int`.

This is an example of **narrowing type casting**.

---

## 5. Convert a Character into Lowercase and Uppercase Using ASCII Code. (A)

### Code

```c
#include <stdio.h>

int main() {
    char ch = 'A';

    char lowercase;
    char uppercase;

    if (ch >= 'A' && ch <= 'Z') {
        lowercase = ch + 32;
        uppercase = ch;
    } else if (ch >= 'a' && ch <= 'z') {
        uppercase = ch - 32;
        lowercase = ch;
    } else {
        printf("Enter an alphabet character.");
        return 0;
    }

    printf("Lowercase = %c\n", lowercase);
    printf("Uppercase = %c", uppercase);

    return 0;
}
```

### Output

```text
Lowercase = a
Uppercase = A
```

### Logic

In ASCII:

- `'A'` to `'Z'` = `65` to `90`
- `'a'` to `'z'` = `97` to `122`
- Difference between uppercase and lowercase = `32`

Therefore:

```text
Lowercase = Uppercase + 32
Uppercase = Lowercase - 32
```

---

## 6. Take Product Price and Tax Percentage from User and Print Amount of Tax in Float. (B)

### Code

```c
#include <stdio.h>

int main() {
    float price, taxPercent;

    printf("Enter product price: ");
    scanf("%f", &price);

    printf("Enter tax percentage: ");
    scanf("%f", &taxPercent);

    float tax = price * taxPercent / 100;

    printf("Tax Amount = %.2f", tax);

    return 0;
}
```

### Output

```text
Enter product price: 1000
Enter tax percentage: 18
Tax Amount = 180.00
```

---
