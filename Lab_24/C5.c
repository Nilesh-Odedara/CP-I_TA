#include <stdio.h>

int main()
{
    int a[100], n, i, number;

    printf("Enter number of elements in the sequence: ");
    scanf("%d", &n);

    printf("Enter the sequence in increasing order:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Missing numbers: ");
    for (i = 0; i < n - 1; i++)
    {
        for (number = a[i] + 1; number < a[i + 1]; number++)
        {
            printf("%d ", number);
        }
    }
    printf("\n");

    return 0;
}
