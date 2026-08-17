#include <stdio.h>

void main()
{
    int days, week, year, input;

    printf("Enter days : ");
    scanf("%d", &input);

    year = input / 365;
    input %= 365;
    week = input / 7;
    days = input % 7;

    printf("Year = %d, Week = %d, Days = %d ", year, week, days);
}