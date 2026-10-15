#include <stdio.h>

int main(void)
{
    int n, i = 2, flag = 0;

    printf("Enter an integer: ");
    scanf("%d", &n);

    if (n < 2)
    {
        flag = 1;
    }
    else
    {
        while (i < n)
        {
            if (n % i == 0)
            {
                flag = 1;
                break;
            }

            i++;
        }
    }

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