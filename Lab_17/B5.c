#include <stdio.h>

int main(void)
{
    int term = 1, count = 1;

    printf("First 50 terms of the series:\n");

    while (count <= 50)
    {
        printf("%d ", term);
        term = term + 3;
        count++;
    }

    printf("\n");

    return 0;
}