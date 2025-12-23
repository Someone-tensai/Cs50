#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int k = 1;
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1);

    for (int i = 1; i <= h; i++)
    {

        for (k = 1; k <= h - i; k++)
        {
            printf(" ");
        }
        for (int j = 1; j <= h; j++)
        {
            printf("#");
            if (k > h - j)
            {
                break;
            }
        }
        printf("\n");
    }
}
