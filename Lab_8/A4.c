#include <stdio.h>

void main()
{
    float value = 25.75;

    int convertedValue = (int)value;

    printf("Original float value = %.2f\n", value);
    printf("Converted integer value = %d", convertedValue);
    printf("data loss = %f", value - convertedValue);
}