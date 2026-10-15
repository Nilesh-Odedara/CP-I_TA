#include <stdio.h>

int main()
{
    int i, n;

    printf("Numbers from 1 to 10:\n");
    for (i = 1; i <= 10; i++)
    {
        printf("%d ", i);
    }

    printf("\nEnter the value of n: ");
    scanf("%d", &n);

    printf("Numbers from 1 to %d:\n", n);
    for (i = 1; i <= n; i++)
    {
        printf("%d ", i);
    }

    printf("\n");

    return 0;
}
