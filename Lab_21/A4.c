#include <stdio.h>

int main()
{
    int x, y, i, result = 1;

    printf("Enter the base (x): ");
    scanf("%d", &x);

    printf("Enter the exponent (y): ");
    scanf("%d", &y);

    for (i = 1; i <= y; i++)
    {
        result = result * x;
    }

    printf("%d raised to the power %d = %d\n", x, y, result);

    return 0;
}
