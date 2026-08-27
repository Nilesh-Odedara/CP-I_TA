#include <stdio.h>

void main()
{
    float units, amount, totalAmount, surcharge;

    printf("Enter electricity units consumed: ");
    scanf("%f", &units);

    if (units <= 50)
    {
        amount = units * 0.50;
    }
    else if (units <= 150)
    {
        amount = (50 * 0.50) + (units - 50) * 0.75;
    }
    else if (units <= 250)
    {
        amount = (50 * 0.50) + (100 * 0.75) + (units - 150) * 1.20;
    }
    else
    {
        amount = (50 * 0.50) + (100 * 0.75) + (100 * 1.20) + (units - 250) * 1.50;
    }

    surcharge = amount * 0.20;
    totalAmount = amount + surcharge;

    printf("Electricity Bill:\n");
    printf("Base Amount: Rs. %.2f\n", amount);
    printf("Surcharge (20%%): Rs. %.2f\n", surcharge);
    printf("Total Amount to Pay: Rs. %.2f\n", totalAmount);
}