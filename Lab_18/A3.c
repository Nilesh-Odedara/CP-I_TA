#include <stdio.h>

int main()
{
    int n, i = 2, isPrime = 1;

    printf("Enter an integer: ");
    scanf("%d", &n);

    if (n < 2)
    {
        isPrime = 0;
    }
    else
    {
        while (i < n)
        {
            if (n % i == 0)
            {
                isPrime = 0;
                break;
            }

            i++;
        }
    }

    if (isPrime == 1)
    {
        printf("%d is a prime number.\n", n);
    }
    else
    {
        printf("%d is not a prime number.\n", n);
    }

    return 0;
}