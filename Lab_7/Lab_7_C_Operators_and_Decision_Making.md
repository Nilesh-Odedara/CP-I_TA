# Introduction & C Operators & Decision-Making Statements

## Lab – 7
### Basic C Programs

> **Write the following programs in C.**

---

## 1. Print Hello World. (A)

### Code

```c
#include <stdio.h>

int main() {
    printf("Hello World");
    return 0;
}
```

### Output

```text
Hello World
```

---

## 2. Print Your Address (A)

### i) Using Single `printf`

### Code

```c
#include <stdio.h>

int main() {
    printf("Your Address");
    return 0;
}
```

### Output

```text
Your Address
```

> **Note:** Replace `Your Address` with your actual address.

### ii) Using Multiple `printf`

### Code

```c
#include <stdio.h>

int main() {
    printf("House No. 123\n");
    printf("Your Area\n");
    printf("Your City\n");
    printf("Gujarat, India");

    return 0;
}
```

### Output

```text
House No. 123
Your Area
Your City
Gujarat, India
```

> **Note:** Replace the sample address with your actual address.

---

## 3. Print Addition of 2 Numbers (A)

### i) Without `scanf`

### Code

```c
#include <stdio.h>

int main() {
    int a = 10;
    int b = 20;

    int sum = a + b;

    printf("Sum = %d", sum);

    return 0;
}
```

### Output

```text
Sum = 30
```

### ii) With `scanf`

### Code

```c
#include <stdio.h>

int main() {
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    int sum = a + b;

    printf("Sum = %d", sum);

    return 0;
}
```

### Output

```text
Enter two numbers: 10 20
Sum = 30
```

---

## 4. Print Average of Three Numbers (A)

### i) Without `scanf`

### Code

```c
#include <stdio.h>

int main() {
    float a = 10;
    float b = 20;
    float c = 30;

    float average = (a + b + c) / 3;

    printf("Average = %.2f", average);

    return 0;
}
```

### Output

```text
Average = 20.00
```

### ii) With `scanf`

### Code

```c
#include <stdio.h>

int main() {
    float a, b, c;

    printf("Enter three numbers: ");
    scanf("%f %f %f", &a, &b, &c);

    float average = (a + b + c) / 3;

    printf("Average = %.2f", average);

    return 0;
}
```

### Output

```text
Enter three numbers: 10 20 30
Average = 20.00
```

---

## 5. Print Area of Circle (A)

### Formula

```text
Area = π × r × r
```

where `r` is the radius.

### Code

```c
#include <stdio.h>

int main() {
    float r = 5;
    float pi = 3.14;

    float area = pi * r * r;

    printf("Area of Circle = %.2f", area);

    return 0;
}
```

### Output

```text
Area of Circle = 78.50
```

---
