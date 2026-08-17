#include <stdio.h>

void main()
{
    float total_cost, discount_percent, discount, final_cost;

    printf("Enter total cost: ");
    scanf("%f", &total_cost);

    printf("Enter discount percentage: ");
    scanf("%f", &discount_percent);

    discount = (total_cost * discount_percent) / 100;

    final_cost = total_cost - discount;

    printf("Discount Amount = %f\n", discount);
    printf("Final Cost = %f", final_cost);
}