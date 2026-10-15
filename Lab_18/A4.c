#include <stdio.h>

int main(void)
{
    int number, digit;

    printf("Enter a positive integer: ");
    scanf("%d", &number);

    if (number == 0)
    {
        printf("0");
    }
    else
    {
        while (number > 0)
        {
            digit = number % 10;
            printf("%d ", digit);
            number = number / 10;
        }
    }

    printf("\n");

    return 0;
}