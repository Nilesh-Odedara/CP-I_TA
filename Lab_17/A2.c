#include <stdio.h>

int main(void)
{
    int number, i = 1;
    int evenCount = 0, oddCount = 0;

    while (i <= 10)
    {
        printf("Enter number %d: ", i);
        scanf("%d", &number);

        if (number % 2 == 0)
        {
            evenCount++;
        }
        else
        {
            oddCount++;
        }

        i++;
    }

    printf("Even numbers count = %d\n", evenCount);
    printf("Odd numbers count = %d\n", oddCount);

    return 0;
}