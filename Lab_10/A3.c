#include <stdio.h>

void main()
{
    float units, rate, bill;

    printf("Enter number of units consumed: ");
    scanf("%f", &units);

    printf("Enter rate per unit: ");
    scanf("%f", &rate);

    bill = units * rate;

    printf("Electricity Bill = %f", bill);
}