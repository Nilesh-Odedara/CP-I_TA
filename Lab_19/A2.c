#include <stdio.h>

int main(void)
{
    int number, count = 1;
    int even = 0, odd = 0;

    do
    {
        printf("Enter number %d: ", count);
        scanf("%d", &number);

        if (number % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }

        count++;
    } while (count <= 10);

    printf("Even numbers: %d\\n", even);
    printf("Odd numbers: %d\\n", odd);

    return 0;
}