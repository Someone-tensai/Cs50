#include <stdio.h>

int main()
{
    int M , N , temp , k=0;
    printf("Enter the no of rows in matrix: ");
    scanf("%i", &M);

    printf("Enter the no of columns in matrix: ");
    scanf("%i", &N);

    int size = M * N;

    int arr[M][N] , one[size];
    printf("\nEnter the elements of the matrix\n");

    for( int i = 0  ; i < M ; i++)
    {
        for( int j = 0 ; j < N ; j++)
        {
            printf("Element of row %d: " , i+1);
            scanf("%i" , &arr[i][j] );
        }
        printf("\n");
    }

    //To find the second largest element


    //Changing 2D to 1D
    for(int i = 0 ; i < M ; i++)
    {
        for(int j = 0 ; j < N ; j++)
        {
            one[k] = arr[i][j];
            k++;
        }

    }

    //Sorting the 1D array
    for(int i = 0 ; i < size ; i++)
    {
        for(int j = i ; j < size ; j++)
        {
            if(one[i] < one[j])
            {
                temp = one[i];
                one[i] = one[j];
                one[j] = temp;
            }
        }

    }
    printf("\nSecond largest element in matrix is: %i" , one[1]);

}
