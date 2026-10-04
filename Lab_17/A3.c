#include <stdio.h>

int main(void)
{
    int i = 101;

    printf("Required numbers are:\n");

    while (i < 200)
    {
        if (i % 7 == 0 && i % 5 != 0)
        {
            printf("%d ", i);
        }

        i++;
    }

    printf("\n");

    return 0;
}