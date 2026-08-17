#include <stdio.h>

void main()
{
    int sec = 0, min = 0, hour = 0, input;

    printf("Enter Seconds : ");
    scanf("%d", &input);

    hour = input / 3600;
    input = input % 3600;
    min = input / 60;
    sec = input % 60;
    printf("%d : %d : %d", hour, min, sec);
}