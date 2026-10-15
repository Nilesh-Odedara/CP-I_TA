#include <stdio.h>

int main()
{
    int n, temp, digit, i;
    int frequency[10] = {0};

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n == 0)
    {
        frequency[0] = 1;
    }
    else
    {
        temp = n;
        while (temp > 0)
        {
            digit = temp % 10;
            frequency[digit]++;
            temp = temp / 10;
        }
    }

    printf("Digit frequencies:\n");
    for (i = 0; i <= 9; i++)
    {
        if (frequency[i] > 0)
        {
            printf("%d appears %d time(s)\n", i, frequency[i]);
        }
    }

    return 0;
}
