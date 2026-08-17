#include <stdio.h>

void main()
{
    float selling_price, cost_price, profit, profit_percent;

    printf("Enter cost price: ");
    scanf("%f", &cost_price);

    printf("Enter selling price: ");
    scanf("%f", &selling_price);

    profit = selling_price - cost_price;

    profit_percent = (profit / cost_price) * 100;

    printf("Profit = %f\n", profit);
    printf("Profit Percentage = %f%%", profit_percent);
}
