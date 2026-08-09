#include <stdio.h>

void main()
{
    char chl, chu;

    printf("Enter a character in lowercase: ");
    scanf("%c", &chl);
    fflush(stdin); // need to use when working with two char variable
    printf("Enter a character in uppercase: ");
    scanf("%c", &chu);

    printf("Uppercase: %c\n", chl - 32);
    printf("Lowercase: %c\n", chu + 32);
    getch();
}