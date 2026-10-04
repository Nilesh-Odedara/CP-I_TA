#include <stdio.h>

int main()
{
    int start, end, i;

    printf("Enter starting number: ");
    scanf("%d", &start);

    printf("Enter ending number: ");
    scanf("%d", &end);

    i = start;

    while (i <= end)
    {
        if (i % 2 == 0)
        {
            printf("%d ", i);
        }

        i++;
    }

    return 0;
}