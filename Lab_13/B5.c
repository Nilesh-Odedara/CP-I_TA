#include <stdio.h>

void main()
{
    int a, b, c;

    printf("Enter 3 sides of triangle: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a + b > c && a + c > b && b + c > a)
    {
        // Check for Equilateral
        if (a == b && b == c)
        {
            printf("Triangle is Equilateral.");
        }
        else if (a == b || b == c || a == c)
        {
            printf("Triangle is Isosceles.\n");
        }
        else
        {
            printf("Triangle is Scalene.\n");
        }

        if (a * a == b * b + c * c || b * b == a * a + c * c || c * c == a * a + b * b)
        {
            printf("Triangle is also Right Angled.");
        }
    }
    else
    {
        printf("Not a valid triangle.");
    }
}