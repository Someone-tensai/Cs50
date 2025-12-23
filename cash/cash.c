#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int count = 0;
    int cash = -1;
    while (cash < 0)
    {
        cash = get_int("Enter the change in cents\t");
    }
    while (cash != 0)
    {
        if (cash == 1)
        {
            cash = cash - 1;
            count++;
        }

        else if (cash > 1 && cash < 5)
        {
            cash = cash - 1;
            count++;
        }

        else if (cash >= 5 && cash < 10)
        {
            cash = cash - 5;
            count++;
        }

        else if (cash >= 10 && cash < 25)
        {
            cash = cash - 10;
            count++;
        }

        else if (cash >= 25)
        {
            cash = cash - 25;
            count++;
        }
    }
    printf("%d\n", count);
}
