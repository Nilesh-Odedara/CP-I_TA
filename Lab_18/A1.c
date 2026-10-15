#include <stdio.h>

int main()
{
    int number, temp, firstDigit, lastDigit, sum;

    printf("Enter a positive integer: ");
    scanf("%d", &number);

    temp = number;
    lastDigit = number % 10;

    while (temp >= 10)
    {
        temp = temp / 10;
    }

    firstDigit = temp;
    sum = firstDigit + lastDigit;

    printf("First digit = %d\n", firstDigit);
    printf("Last digit = %d\n", lastDigit);
    printf("Sum of first and last digit = %d\n", sum);

    return 0;
}