#include <stdio.h>

int main(void)
{
    int n, i = 1, sum = 0;

    printf("Enter the last number n: ");
    scanf("%d", &n);

    while (i <= n)
    {
        sum = sum + (i * i);
        i++;
    }

    printf("Sum of squares from 1 to %d = %d\n", n, sum);

    return 0;
}