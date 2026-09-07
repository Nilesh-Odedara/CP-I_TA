#include <stdio.h>

void main()
{
    char ch;
    printf("Enter a character: ");
    scanf(" %c", &ch);

    ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) ? printf("It is an alphabet.\n") : printf("It is not an alphabet.\n");
}