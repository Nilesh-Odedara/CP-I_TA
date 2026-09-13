#include <stdio.h>

void main()
{
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    (number >= 0) ? printf("Number is positive") : printf("Number is negative");
}