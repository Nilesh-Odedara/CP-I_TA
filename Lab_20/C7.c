#include <stdio.h>

int main()
{
    int n, original, temp, digit, reverse = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    original = n;
    temp = n;

    do
    {
        digit = temp % 10;
        reverse = reverse * 10 + digit;
        temp = temp / 10;
    } while (temp > 0);

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
