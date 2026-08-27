#include <stdio.h>

void main()
{
    // with temp variable

    int a, b, c, d, temp;

    printf("Enter Two Numbers : ");
    scanf("%d %d", &a, &b);

    temp = a;
    a = b;
    b = temp;

    printf("Swapped values with temp => a = %d, b = %d\n\n", a, b);

    // without temp variable

    printf("Enter Two Numbers : ");
    scanf("%d %d", &c, &d);

    c += d;
    d = c - d;
    c = c - d;

    printf("Swapped without temp => c = %d, d = %d", c, d);
}