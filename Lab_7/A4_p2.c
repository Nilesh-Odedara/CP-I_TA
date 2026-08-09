#include <stdio.h>

void main()
{
    float a, b, c;

    printf("Enter three numbers: ");
    scanf("%f %f %f", &a, &b, &c);

    float average = (a + b + c) / 3;

    printf("Average = %.2f", average);
}