#include <stdio.h>

void main()
{
    float m1, m2, m3, m4, m5, total, percentage;

    printf("Enter marks for 5 subjects (out of 100):\n");
    scanf("%f %f %f %f %f", &m1, &m2, &m3, &m4, &m5);

    total = m1 + m2 + m3 + m4 + m5;
    percentage = total / 5;

    printf("Percentage: %.2f%%\n", percentage);

    if (percentage < 35)
    {
        printf("Class: Fail");
    }
    else if (percentage >= 36 && percentage <= 45)
    {
        printf("Class: Pass Class");
    }
    else if (percentage >= 46 && percentage <= 60)
    {
        printf("Class: Second Class");
    }
    else if (percentage >= 61 && percentage <= 70)
    {
        printf("Class: First Class");
    }
    else if (percentage > 70)
    {
        printf("Class: Distinction");
    }
}