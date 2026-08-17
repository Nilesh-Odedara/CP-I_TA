#include <stdio.h>

void main()
{
    float weight, height, bmi;

    printf("Enter weight in kg: ");
    scanf("%f", &weight);

    printf("Enter height in meters: ");
    scanf("%f", &height);
    bmi = weight / (height * height);

    printf("BMI = %f", bmi);
}