#include <stdio.h>

int main(void)
{
    int term = 1, count = 1;

    do
    {
        printf("%d ", term);
        term = term + 3;
        count++;
    } while (count <= 50);

    printf("\\n");

    return 0;
}