#include <stdio.h>

int main(void)
{
    int n, original, temp, digit, reverse = 0;

    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    original = n;
    temp = n;

    while (temp > 0)
    {
        digit = temp % 10;
        reverse = reverse * 10 + digit;
        temp = temp / 10;
    }

    if (original == reverse)
    {
        printf("%d is a palindrome number.\n", original);
    }
    else
    {
        printf("%d is not a palindrome number.\n", original);
    }

    return 0;
}