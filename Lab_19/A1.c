#include <stdio.h>

int main(void)
{
    int n, i = 1, sum = 0;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n < 1)
    {
        printf("Please enter a positive integer.\\n");
        return 0;
    }

    do
    {
        sum = sum + i;
        i++;
    } while (i <= n);

    printf("Sum from 1 to %d = %d\\n", n, sum);

    return 0;
}