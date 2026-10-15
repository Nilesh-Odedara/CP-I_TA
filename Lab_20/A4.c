#include <stdio.h>

int main()
{
    int n, temp, digit;

    printf("Enter a number: ");
    scanf("%d", &n);

    temp = n;

    do
    {
        digit = temp % 10;
        printf("%d ", digit);
        temp = temp / 10;
    } while (temp > 0);

    printf("\n");

    return 0;
}
