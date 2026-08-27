#include <stdio.h>

void main()
{
    int a, b, c;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    if ((a > b && a < c) || (a > c && a < b))
        printf("Second largest is: %d", a);
    else if ((b > a && b < c) || (b > c && b < a))
        printf("Second largest is: %d", b);
    else
        printf("Second largest is: %d", c);
}