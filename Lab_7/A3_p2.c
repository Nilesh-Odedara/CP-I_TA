#include <stdio.h>

void main()
{
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    int sum = a + b;

    printf("Sum = %d", sum);
}