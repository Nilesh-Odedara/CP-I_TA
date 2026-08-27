#include <stdio.h>

void main()
{
    int number, lastDigit;

    printf("Enter an integer number: ");
    scanf("%d", &number);

    lastDigit = number % 10;

    if (lastDigit % 2 == 0)
    {
        printf("The last digit (%d) is Even.\n", lastDigit);
    }
    else
    {
        printf("The last digit (%d) is Odd.\n", lastDigit);
    }
}