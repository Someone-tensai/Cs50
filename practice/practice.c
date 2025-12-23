#include <stdio.h>

int main()
{
    int x , y , temp, result;
    printf("Enter first number: ");
    scanf("%d" , &x);
    printf("Enter second number: ");
    scanf("%d" , &y);

    if(x < y)
    {
        temp = x;
    }
    else
    {
        temp = y;
    }

    for(int i = 1 ; i <= temp ; i++)
    {
        if(x % i == 0  && y % i == 0 )
        {
            result = i;
        }

    }
    printf("HCF of numbers %d and %d is %d\n" , x , y , result);
    return 0;
}
