#include<stdio.h>

int sum(int);

int main()
{
    int n , result;
    printf("Enter the number of terms: ");
    scanf("%i" , &n);

    result  = sum(n);

    printf("\nSum of %i even numbers divisible by 5 is: %i\n" , n, result);

    return 0;
}

int sum(int n)
{
    int size =  10 * n , sum = 0;
    for(int i = 0 ; i <=  size ; i+=2)
    {
        if(i % 5 == 0)
        {
            sum += i;
        }
    }
    return sum;
}
