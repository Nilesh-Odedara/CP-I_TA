#include <stdio.h>

void main()
{
    float price, taxPercent;

    printf("Enter product price: ");
    scanf("%f", &price);

    printf("Enter tax percentage: ");
    scanf("%f", &taxPercent);

    float tax = price * taxPercent / 100;

    printf("Tax Amount = %.2f", tax);
}