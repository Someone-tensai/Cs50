#include <stdio.h>
int main()
{
    int row, i, j, k, n;
    printf("Enter the number of rows: ");
    scanf("%d", &row);
    for (i = 0; i < row; i++)
    {
        for (j = 1; j <= row - i - 1; j++)
            printf(" ");
        n = 1;
        for (k = 0; k <= i; k++)
        {
            printf("%2d", n);
            n = n * (i - k) / (k + 1);
        }
        printf("\n");
    }
    return 0;
}
