#include <stdio.h>

int main()
{
    int n, i = 2, flag = 0;

    printf("Enter an integer: ");
    scanf("%d", &n);

    if (n < 2)
    {
        printf("%d is not a prime number.\n", n);
        return 0;
    }

    if (n == 2)
    {
        printf("%d is a prime number.\n", n);
        return 0;
    }

    do
    {
        if (n % i == 0)
        {
            flag = 1;
            break;
        }

        i++;
    } while (i < n);

    if (flag == 0)
    {
        printf("%d is a prime number.\n", n);
    }
    else
    {
        printf("%d is not a prime number.\n", n);
    }

    return 0;
}
