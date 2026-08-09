# General Reasoning and Problem Solving

## Lab – 2
### Daily Logic & Thought Process

> **No Code Required**

### Questions

1. **You have two numbers. Explain how to swap them without using a third variable.** *(A)*

   - Store the sum of the two numbers in the first variable.
   - Subtract the second number from the first to get the original first number.
   - Subtract the new second value from the first to get the original second number.
   - The two numbers are now swapped.

2. **How can you count how many times a digit (say 7) appears in a number?** *(A)*

   - Extract the last digit using the remainder when divided by `10`.
   - Compare the extracted digit with `7`.
   - If they are equal, increase the count.
   - Remove the last digit by dividing the number by `10`.
   - Repeat until the number becomes `0`.

3. **How would you check whether the input character is a vowel or consonant?** *(A)*

   - Check whether the character is `a`, `e`, `i`, `o`, or `u`.
   - If it matches any of these vowels, it is a **vowel**.
   - Otherwise, if it is an alphabet, it is a **consonant**.

4. **You are given 3 different numbers. How would you sort them in ascending order?** *(A)*

   - Compare the first number with the second and third numbers.
   - Place the smallest number first.
   - Compare the remaining two numbers.
   - Place the smaller one before the larger one.
   - The three numbers are now in ascending order.

5. **You are given a sentence. How do you count the number of words in it?** *(A)*

   - Traverse the sentence from beginning to end.
   - A word is identified by a sequence of characters separated by spaces.
   - Count each transition from a space to a non-space character.
   - Ignore extra spaces at the beginning, end, or between words.

6. **How can you check if a number is already in a list?** *(B)*

   - Traverse each element of the list.
   - Compare each element with the given number.
   - If a matching element is found, the number is already in the list.
   - If the entire list is checked without finding a match, the number is not present.

7. **If a string contains spaces and punctuation, how would you count only the letters?** *(C)*

   - Traverse each character of the string.
   - Check whether the character is an alphabetic letter.
   - If it is a letter, increase the count.
   - Ignore spaces, numbers, punctuation, and other characters.
   - The final count gives the total number of letters.
