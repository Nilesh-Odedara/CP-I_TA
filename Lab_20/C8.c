#include <stdio.h>

int main()
{
    int n, temp, digit, digits = 0;
    int power, j, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    temp = n;
    do
    {
        digits++;
        temp = temp / 10;
    } while (temp > 0);

    temp = n;
    do
    {
        digit = temp % 10;
        power = 1;
        j = 1;

        do
        {
            power = power * digit;
            j++;
        } while (j <= digits);

        sum = sum + power;
        temp = temp / 10;
    } while (temp > 0);

    if (sum == n)
    {
        printf("%d is an Armstrong number.\n", n);
    }
    else
    {
        printf("%d is not an Armstrong number.\n", n);
    }

    return 0;
}
