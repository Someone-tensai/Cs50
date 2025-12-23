#include<stdio.h>

int main()
{
    int N , sum = 0 , sum1 = 0;
    printf("Enter the size of matrix: ");
    scanf("%i" , &N);

    int mat[N][N];
    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0 ; j < N ; j++)
        {
            printf("Element: ");
            scanf("%i" , &mat[i][j]);
        }
        printf("\n");
    }

    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0 ; j < N ; j++)
        {
            if(i == j)
            {
                sum += mat[i][j];
            }
            if(i + j == N-1)
            {
                sum1 += mat[i][j];
            }

        }
    }
    printf("%i\n%i" , sum, sum1);
}

