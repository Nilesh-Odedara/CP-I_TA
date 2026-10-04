#include <stdio.h>

int main(void)
{
    int number, i = 1;

    printf("Enter a number: ");
    scanf("%d", &number);

    while (i <= 10)
    {
        printf("%d x %d = %d\n", number, i, number * i);
        i++;
    }

    return 0;
}