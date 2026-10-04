#include <stdio.h>

int main(void)
{
    int n, i = 1, sum = 0;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    while (i <= n)
    {
        sum = sum + i;
        i++;
    }

    printf("Sum of numbers from 1 to %d = %d\n", n, sum);

    return 0;
}