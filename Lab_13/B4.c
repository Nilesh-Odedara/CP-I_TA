#include <stdio.h>
#include <math.h>
void main()
{
    float a, b, c, d, root1, root2;

    printf("Enter coefficients a, b, and c: ");
    scanf("%f %f %f", &a, &b, &c);

    d = b * b - 4 * a * c;

    if (a == 0)
    {
        printf("This is not a quadratic equation");
    }
    else if (d > 0)
    {
        root1 = (-b + sqrt(d)) / (2 * a);
        root2 = (-b - sqrt(d)) / (2 * a);
        printf("Roots are real and different.");
        printf("Root 1 = %.2f\n", root1);
        printf("Root 2 = %.2f\n", root2);
    }
    else if (d == 0)
    {
        root1 = -b / (2 * a);
        printf("Roots are real and equal.");
        printf("Root = %.2f\n", root1);
    }
    else
    {
        printf("Roots are complex and imaginary.");
    }
}