# Widening, Narrowing, Implicit and Explicit Type Casting

## 1. First, Think About Containers 📦

Imagine you have two containers:

- A **small container** can hold a small amount of water.
- A **large container** can hold much more water.

If you move water from the **small container to the large container**, there is no problem.

But if you move water from the **large container to the small container**, some water may be lost.

The same idea applies to data types in programming.

---

## 2. Widening

**Widening** means converting a smaller data type into a larger data type.

For example:

```c
int a = 10;
float b = a;
```

Here, an `int` is converted into a `float`.

```text
int → float
```

Since `float` can represent a larger range of values, there is generally no problem.

### Simple Example

```c
int marks = 90;
double result = marks;

printf("%lf", result);
```

Output:

```text
90.000000
```

### Remember

> **Small type → Large type = Widening**

---

## 3. Narrowing

**Narrowing** means converting a larger data type into a smaller data type.

For example:

```c
double a = 10.75;
int b = a;
```

The decimal part may be lost.

```text
double → int
```

So:

```text
10.75 → 10
```

### Remember

> **Large type → Small type = Narrowing**

Narrowing can cause **loss of data or precision**.

---

## 4. Implicit Type Casting

**Implicit** means the conversion is done **automatically by the compiler**.

You don't have to tell the compiler to perform the conversion.

Example:

```c
int a = 10;
float b = a;
```

Here, C automatically converts `a` from `int` to `float`.

```text
int → float
     ↑
automatic conversion
```

So this is **implicit widening**.

---

## 5. Explicit Type Casting

**Explicit** means **we tell the compiler ourselves** that we want to convert a value.

We use the **cast operator**:

```c
(type)value
```

Example:

```c
float a = 10.75;
int b = (int)a;
```

Here:

```c
(int)a
```

means:

> Convert `a` to `int`.

So:

```text
10.75 → 10
```

This is **explicit narrowing**.

---

## 6. Difference Between Implicit and Explicit

| Type | Who performs conversion? | Example |
|---|---|---|
| **Implicit** | Compiler automatically | `float b = a;` |
| **Explicit** | Programmer | `int b = (int)a;` |

### Easy Way to Remember

**Implicit = I didn't tell the compiler.**

**Explicit = I explicitly told the compiler.**

---

## 7. Important Example

Consider:

```c
int a = 5;
int b = 2;

float result = a / b;
```

You might expect:

```text
2.5
```

But the result is:

```text
2.0
```

Why?

Because both `a` and `b` are `int`, so integer division happens first.

To get `2.5`, explicitly convert one value:

```c
float result = (float)a / b;
```

Now:

```text
5 / 2 = 2.5
```

---

## 8. Quick Summary

| Concept | Meaning |
|---|---|
| **Widening** | Smaller type → Larger type |
| **Narrowing** | Larger type → Smaller type |
| **Implicit** | Conversion happens automatically |
| **Explicit** | Programmer performs the conversion |

### One Line to Remember

> **Widening usually moves to a bigger type, while narrowing moves to a smaller type; either conversion can be implicit or explicit depending on how it is performed.**
