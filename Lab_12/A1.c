#include <stdio.h>
void main()
{
    int a, b;
    char op;
    printf("Enter No1:");
    scanf("%d", &a);

    printf("Enter No2:");
    scanf("%d", &b);

    printf("Enter your operation:- +,-,*,/ = ");
    scanf(" %c", &op);
    if (op == '+')
    {
        printf("a+b= %d", a + b);
    }
    else if (op == '-')
    {
        printf("a-b=%d", a - b);
    }
    else if (op == '*')
    {
        printf("a*b=%d", a * b);
    }
    else if (op == '/')
    {
        printf("a/b=%d", a / b);
    }
}