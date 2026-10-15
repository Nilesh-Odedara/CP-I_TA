#include <stdio.h>

int main()
{
    float height, weight;
    int i, count = 0;

    for (i = 1; i <= 5; i++)
    {
        printf("Enter height and weight of person %d: ", i);
        scanf("%f %f", &height, &weight);

        if (height > 170 && weight < 50)
        {
            count++;
        }
    }

    printf("Number of people matching the condition = %d\n", count);

    return 0;
}
