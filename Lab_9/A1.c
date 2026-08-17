#include <stdio.h>

void main()
{
    int h, b, area;

    printf("Enter height and base of triangle : ");
    scanf("%d %d", &h, &b);

    area = ((h * b) / 2);

    printf("Area of Triangle = %d", area);
}