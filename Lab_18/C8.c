#include <stdio.h>

int main(void)
{
    int n, original, temp, digit;
    int digits = 0, sum = 0, power, i;

    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    original = n;
    temp = n;

    /* Count the digits. */
    if (temp == 0)
    {
        digits = 1;
    }
    else
    {
        while (temp > 0)
        {
            digits++;
            temp = temp / 10;
        }
    }

    /* Calculate the sum of each digit raised to 'digits'. */
    temp = n;

    while (temp > 0)
    {
        digit = temp % 10;
        power = 1;
        i = 1;

        while (i <= digits)
        {
            power = power * digit;
            i++;
        }

        sum = sum + power;
        temp = temp / 10;
    }

    if (sum == original)
    {
        printf("%d is an Armstrong number.\n", original);
    }
    else
    {
        printf("%d is not an Armstrong number.\n", original);
    }

    return 0;
}