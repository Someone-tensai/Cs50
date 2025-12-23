#include<stdio.h>
#include<math.h>

int checkarm(int);

int main()
{
    int p , q;

    printf("Enter lower limit: ");
    scanf("%i" , &p);

    printf("Enter upper limit: ");
    scanf("%i" , &q);

    for(int i = p ; i < q ; i++)
    {
        if(checkarm(i) == 1)
        {
            printf("%i " , i );
        }
    }

}

int checkarm(int n)
{
    int temp = n, sum = 0 , digits = 0 , rem;
    while(n > 0)
    {
        digits += 1;
        n =n/10;
    }
    n = temp;
    while(n > 0)
    {
        rem = n % 10;
        sum += pow(rem , digits);
        n = n/10;
    }

    if(sum == temp)
    {
        return 1;
    }
    return 0;
}
