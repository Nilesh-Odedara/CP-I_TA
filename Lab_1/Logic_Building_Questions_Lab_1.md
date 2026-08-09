# Logic Building Questions

## Lab – 1
### Math Logic, Decision Making and Conditions

> **No Code Required**

### Questions

1. **How to check whether a number is odd or even?** *(A)*

   - If the number is divisible by `2`, it is **even**.
   - Otherwise, it is **odd**.

2. **How will you find the largest of three numbers?** *(A)*

   - Compare the first number with the other two numbers.
   - If it is greater than or equal to both, it is the largest.
   - Otherwise, compare the second and third numbers to find the largest.

3. **How would you find the sum of the digits of any number?** *(A)*

   - Extract the last digit using the remainder when divided by `10`.
   - Add the extracted digit to the sum.
   - Remove the last digit by dividing the number by `10`.
   - Repeat until the number becomes `0`.

4. **How would you check if a number is a palindrome or not?** *(A)*

   - Store the original number.
   - Reverse the number by extracting its digits one by one.
   - Compare the reversed number with the original number.
   - If both are equal, the number is a **palindrome**; otherwise, it is **not a palindrome**.

5. **How would you determine if a year is a leap year?** *(A)*

   - If the year is not divisible by `4`, it is a **common year**.
   - If it is divisible by `4` but not by `100`, it is a **leap year**.
   - If it is divisible by `100`, it must also be divisible by `400` to be a **leap year**.
   - Therefore, a year is a leap year if:
     - It is divisible by `400`, **or**
     - It is divisible by `4` but not by `100`.

6. **How would you find factorial of the given number?** *(A)*

   - Start with a result of `1`.
   - Multiply the result by every integer from `1` to the given number.
   - The final result is the **factorial**.

7. **How would you check if a number is a prime or not?** *(A)*

   - A prime number is greater than `1` and has exactly two factors: `1` and itself.
   - Check whether the number is divisible by any integer from `2` up to its square root.
   - If it is divisible by any of them, it is **not prime**.
   - Otherwise, it is **prime**.

8. **What logic would you use to print only even numbers between 1 and 100?** *(B)*

   - Start from `1` and check each number up to `100`.
   - If a number is divisible by `2`, print it.
   - Alternatively, start from `2` and increase the number by `2` each time.
   - This prints: `2, 4, 6, ..., 100`.

9. **What logic would you use to print Fibonacci series up to N terms?** *(C)*

   - Start with the first two terms: `0` and `1`.
   - Print the current term.
   - Calculate the next term by adding the previous two terms.
   - Move to the next two terms.
   - Repeat until `N` terms have been printed.

### Fibonacci Example

For `N = 7`:

```text
0 1 1 2 3 5 8
```
