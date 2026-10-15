#include <stdio.h>

int main()
{
    int a[100], n, i, count = 0;
    float sum = 0, average;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        sum = sum + a[i];
    }

    average = sum / n;

    for (i = 0; i < n; i++)
    {
        if (a[i] > average)
        {
            count++;
        }
    }

    printf("Average = %.2f\n", average);
    printf("Numbers greater than average = %d\n", count);

    return 0;
}
