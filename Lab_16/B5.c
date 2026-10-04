#include <stdio.h>
#include <math.h>

int main()
{
    int i = 0;

    while (i <= 9)
    {
        printf("%d	%.3f\n", i, sqrt(i));
        i++;
    }

    return 0;
}