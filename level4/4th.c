#include <stdio.h>
#include <math.h>
int main()
{
    int num, r, rem, out = 0, i, temp, sum = 0 , t;
    printf("Enter an octal number (using digit 0 - 7) :");
    scanf("%d", &num);
    i = 0;
    temp = num;
    while (num != 0)
    {
        r = num % 10;
        sum+= r* pow(8 , i);
        i++;
        num=num/10;
    }
    t= sum;

    i = 1;
    while(sum != 0)
    {
        rem = sum % 2;
        if(rem == 1)
        {
            out+=i;
        }

        i*=10;
        sum = sum/2;

    }
    printf("The Octal Number : %d\n", temp);
    printf("The equivalent Binary Number : %d\n", out);
    return 0;
}
