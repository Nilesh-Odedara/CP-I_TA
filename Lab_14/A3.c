#include <stdio.h>

void main()
{
    float num1, num2, result;
    int choice;

    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);

    printf("Choose operation:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        result = num1 + num2;
        printf("Result = %.2f\n", result);
        break;
    case 2:
        result = num1 - num2;
        printf("Result = %.2f\n", result);
        break;
    case 3:
        result = num1 * num2;
        printf("Result = %.2f\n", result);
        break;
    case 4:
        if (num2 != 0)
        {
            result = num1 / num2;
            printf("Result = %.2f\n", result);
        }
        else
        {
            printf("Division by zero is not allowed.\n");
        }
        break;
    default:
        printf("Invalid choice.\n");
    }
}