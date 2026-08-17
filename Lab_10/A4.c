#include <stdio.h>

void main()
{
    float salary, bonus_percent, bonus, total_salary;

    printf("Enter salary: ");
    scanf("%f", &salary);

    printf("Enter bonus percentage: ");
    scanf("%f", &bonus_percent);

    bonus = (salary * bonus_percent) / 100;

    total_salary = salary + bonus;

    printf("Bonus = %f\n", bonus);
    printf("Total Salary = %f", total_salary);
}