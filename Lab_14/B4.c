#include <stdio.h>

void main()
{
    int a, b, c, large, result;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    switch (a > b)
    {
    case 1:
        large = a;
        break;
    case 0:
        large = b;
        break;
    }

    result = large * c;
    printf("Result = %d\n", result);
}