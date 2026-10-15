#include <stdio.h>

int main()
{
    int number, choice = 1, count = 0;
    int sum = 0;
    float average;

    while (choice == 1)
    {
        printf("Enter a number: ");
        scanf("%d", &number);

        sum = sum + number;
        count++;

        printf("Do you want to enter another number? (1 = Yes, 0 = No): ");
        scanf("%d", &choice);
    }

    if (count > 0)
    {
        average = (float)sum / count;

        printf("Sum = %d\n", sum);
        printf("Average = %.2f\n", average);
    }
    else
    {
        printf("No numbers were entered.\n");
    }

    return 0;
}