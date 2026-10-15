#include <stdio.h>

int main()
{
    int n, i = 1, sum = 0;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    do
    {
        if (n % i == 0)
        {
            sum = sum + i;
        }

        i++;
    } while (i <= n / 2);

    if (sum == n && n != 1)
    {
        printf("%d is a perfect number.\n", n);
    }
    else
    {
        printf("%d is not a perfect number.\n", n);
    }

    return 0;
}
