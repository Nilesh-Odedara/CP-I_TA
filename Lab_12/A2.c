#include <stdio.h>

void main()
{
    float basic, hra, da, gross;

    printf("Enter basic salary: ");
    scanf("%f", &basic);

    if (basic >= 30000)
    {
        hra = 0.30 * basic;
        da = 0.95 * basic;
    }
    else if (basic >= 20000)
    {
        hra = 0.25 * basic;
        da = 0.90 * basic;
    }
    else if (basic >= 10000)
    {
        hra = 0.20 * basic;
        da = 0.80 * basic;
    }
    else
    {
        hra = 0;
        da = 0;
        printf("gross salary is not calculate");
    }

    gross = basic + hra + da;

    printf("HRA: %.2f\n", hra);
    printf("DA: %.2f\n", da);
    printf("Gross Salary: %.2f\n", gross);
}