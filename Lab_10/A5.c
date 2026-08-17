#include <stdio.h>

void main()
{
    float distance, mileage, price_per_liter, total_cost;

    printf("Enter distance in km: ");
    scanf("%f", &distance);

    printf("Enter mileage (km per liter): ");
    scanf("%f", &mileage);

    printf("Enter fuel price per liter: ");
    scanf("%f", &price_per_liter);

    total_cost = (distance / mileage) * price_per_liter;

    printf("Total Cost of Fuel = %f", total_cost);
}