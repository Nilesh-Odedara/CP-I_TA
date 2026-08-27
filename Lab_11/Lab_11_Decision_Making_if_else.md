# C Operators & Decision-Making Statements

## Lab – 11
### Decision Making: `if`, `else`

> **Write the following programs in C.**

---

# 1. Swap Two Numbers

## Explanation

Swapping means **exchanging the values** of two variables.

```text
Before:
a = 10
b = 20

After:
a = 20
b = 10
```

We can do this:

1. Using a temporary variable
2. Without using a temporary variable

## i) Using a Temporary Variable

### Algorithm

1. Start
2. Read `a` and `b`
3. Store `a` in `temp`
4. Store `b` in `a`
5. Store `temp` in `b`
6. Print the swapped values
7. Stop

### Code

```c
#include <stdio.h>

int main() {
    int a, b, temp;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    temp = a;
    a = b;
    b = temp;

    printf("After swapping:\n");
    printf("a = %d\n", a);
    printf("b = %d", b);

    return 0;
}
```

### Output

```text
Enter two numbers: 10 20
After swapping:
a = 20
b = 10
```

## ii) Without Using a Temporary Variable

### Explanation

We use addition and subtraction:

```text
a = a + b
b = a - b
a = a - b
```

### Algorithm

1. Start
2. Read `a` and `b`
3. Add `a` and `b` and store the result in `a`
4. Find the original value of `a` and store it in `b`
5. Find the original value of `b` and store it in `a`
6. Print the swapped values
7. Stop

### Code

```c
#include <stdio.h>

int main() {
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    a = a + b;
    b = a - b;
    a = a - b;

    printf("After swapping:\n");
    printf("a = %d\n", a);
    printf("b = %d", b);

    return 0;
}
```

### Output

```text
Enter two numbers: 10 20
After swapping:
a = 20
b = 10
```

---

# 2. Check Whether a Number Is Positive or Negative

## Explanation

A number can be:

```text
Greater than 0 → Positive
Less than 0    → Negative
Equal to 0     → Zero
```

We use `if`, `else if`, and `else` to check these conditions.

## Algorithm

1. Start
2. Read a number `num`
3. If `num > 0`, print `Positive Number`
4. Else if `num < 0`, print `Negative Number`
5. Otherwise, print `Zero`
6. Stop

## Code

```c
#include <stdio.h>

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num > 0) {
        printf("Positive Number");
    } else if (num < 0) {
        printf("Negative Number");
    } else {
        printf("Zero");
    }

    return 0;
}
```

## Output

```text
Enter a number: -10
Negative Number
```

---

# 3. Check Whether the Given Number Is Odd or Even

## Explanation

We use the modulo operator `%` to find the remainder.

```text
10 % 2 = 0 → Even
7 % 2 = 1  → Odd
```

If the remainder is `0`, the number is even. Otherwise, it is odd.

## Algorithm

1. Start
2. Read a number `num`
3. If `num % 2 == 0`, print `Even Number`
4. Otherwise, print `Odd Number`
5. Stop

## Code

```c
#include <stdio.h>

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num % 2 == 0) {
        printf("Even Number");
    } else {
        printf("Odd Number");
    }

    return 0;
}
```

## Output

```text
Enter a number: 7
Odd Number
```

---

# 4. Find the Largest Number from Given Three Numbers

## Explanation

Suppose we have:

```text
a, b, c
```

First, check whether `a` is greater than both `b` and `c`.

If not, check whether `b` is greater than `c`.

Otherwise, `c` is the largest.

The operator:

```c
&&
```

means **AND**.

```c
a > b && a > c
```

means that `a` must be greater than both `b` and `c`.

## Algorithm

1. Start
2. Read `a`, `b`, and `c`
3. If `a > b` and `a > c`, print `a`
4. Else if `b > c`, print `b`
5. Otherwise, print `c`
6. Stop

## Code

```c
#include <stdio.h>

int main() {
    int a, b, c;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a > b && a > c) {
        printf("%d is the largest number", a);
    } else if (b > c) {
        printf("%d is the largest number", b);
    } else {
        printf("%d is the largest number", c);
    }

    return 0;
}
```

## Output

```text
Enter three numbers: 10 50 30
50 is the largest number
```

---

# 5. Check Whether a Character Is Vowel or Consonant (Using Single `if` Only)

## Explanation

The vowels are:

```text
a, e, i, o, u
```

Their uppercase forms are:

```text
A, E, I, O, U
```

If the character matches any vowel, we print `Vowel`. Otherwise, we print `Consonant`.

The operator:

```c
||
```

means **OR**.

For example:

```c
ch == 'a' || ch == 'e'
```

means that `ch` can be `a` OR `e`.

Only one `if` statement is used.

## Algorithm

1. Start
2. Read character `ch`
3. If `ch` is a vowel, print `Vowel`
4. Otherwise, print `Consonant`
5. Stop

## Code

```c
#include <stdio.h>

int main() {
    char ch;

    printf("Enter a character: ");
    scanf(" %c", &ch);

    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
        ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
        printf("Vowel");
    } else {
        printf("Consonant");
    }

    return 0;
}
```

## Output

```text
Enter a character: A
Vowel
```

---

# Quick Revision

```c
if (condition) {
    // Executes when condition is true
} else {
    // Executes when condition is false
}
```

| Operator | Meaning | Example |
|---|---|---|
| `>` | Greater than | `a > b` |
| `<` | Less than | `a < b` |
| `==` | Equal to | `a == b` |
| `%` | Remainder | `a % 2` |
| `&&` | Logical AND | `a > b && a > c` |
| `||` | Logical OR | `ch == 'a' || ch == 'e'` |
