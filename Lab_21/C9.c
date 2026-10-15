#include <stdio.h>

int main()
{
    int i;

    printf("ASCII characters and their values:\n");
    for (i = 32; i <= 126; i++)
    {
        printf("ASCII value %d = character '%c'\n", i, i);
    }

    return 0;
}
