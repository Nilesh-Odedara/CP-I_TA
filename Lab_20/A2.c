#include <stdio.h>

int main()
{
    int number, sum = 0, count = 0, choice;
    float average;

    do
    {
        printf("Enter a number: ");
        scanf("%d", &number);

        sum = sum + number;
        count++;

        printf("Do you want to enter another number? (1 = Yes, 0 = No): ");
        scanf("%d", &choice);
    } while (choice == 1);

    average = (float)sum / count;

    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", average);

    return 0;
}
