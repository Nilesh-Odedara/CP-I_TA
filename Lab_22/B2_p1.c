#include <stdio.h>

int main()
{
    int i, j, value;

    for (i = 1; i <= 5; i++)
    {
        if (i == 1 || i >= 4)
        {
            value = 1;
        }
        else
        {
            value = 0;
        }

        for (j = 1; j <= i; j++)
        {
            printf("%d ", value);
            value = 1 - value;
        }

        printf("\n");
    }

    return 0;
}
