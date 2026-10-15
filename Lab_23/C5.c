#include <stdio.h>
#include <math.h>

int main()
{
    float a[100], sum = 0, product = 1, reciprocalSum = 0;
    float am, gm, hm;
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%f", &a[i]);
        sum = sum + a[i];
        product = product * a[i];
        reciprocalSum = reciprocalSum + (1.0 / a[i]);
    }

    am = sum / n;
    gm = pow(product, 1.0 / n);
    hm = n / reciprocalSum;

    printf("Arithmetic Mean: %.2f\n", am);
    printf("Geometric Mean: %.2f\n", gm);
    printf("Harmonic Mean: %.2f\n", hm);

    return 0;
}
