#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int r, r1, count = 0, sum = 0, sum1 = 0, c = 0, i = 0, length;
    long int num;
    long int a = get_long("Enter the credit card number");
    num = a;
    while (num > 0)
    {
        num = num / 10;
        count += 1;
    }
    length = count / 2;
    int h[length];
    while (a > 0)
    {
        r = a % 10;
        c++;
        if (c % 2 != 0)
        {
            h[i] = 2 * r;
            i++;
        }
        else
        {
            sum1 = sum1 + r;
        }
    }
    for (i = 0; i < count / 2; i++)
    {
        r1 = h[i] % 10;
        sum = sum + r1;
    }
    printf("%d", sum + sum1);
    return 0;
}
