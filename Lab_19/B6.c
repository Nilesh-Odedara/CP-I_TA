#include <stdio.h>

int main(void)
{
    int n, i = 1, sum = 0;

    printf("Enter the value of N: ");
    scanf("%d", &n);

    if (n < 1)
    {
        printf("Please enter a positive integer.\\n");
        return 0;
    }

    do
    {
        sum = sum + (i * i);
        i++;
    } while (i <= n);

    printf("Sum of squares from 1 to %d = %d\\n", n, sum);

    return 0;
}