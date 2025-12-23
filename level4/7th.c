#include <stdio.h>
int main()
{
    int i, j, row, y, x = 1;
    printf("Enter the number of rows: ");
    scanf("%d", &row);
    y = 2 * row - 1;
    for (i = row; i >= 1; i--)
    {
        for (j = 1; j <= 2 * row; j++)
        {
            if (j == x || j == y)
            {
                printf("@");
            }
            else
            {
                printf(" ");
            }
        }
        y--;
        x++;

        printf("\n");
    }
}
