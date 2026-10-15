#include <stdio.h>

int main()
{
    int n, temp, first, last;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    temp = n;
    last = n % 10;

    do
    {
        first = temp % 10;
        temp = temp / 10;
    } while (temp > 0);

    printf("First digit = %d\n", first);
    printf("Last digit = %d\n", last);
    printf("Sum of first and last digit = %d\n", first + last);

    return 0;
}
