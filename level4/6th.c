#include <stdio.h>
int main()
{
    int repeat = 2, i, j, n;
    printf("Enter number of rows: ");
    scanf("%d" , &n);
    while (x != 0)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j <= i; j++)
            {
                printf("* ");
            }
            printf("\n");
        }
        repeat--;
    }
    return 0;
}
