#include <stdio.h>

int main()
 {

    float x,y,out;
    char op;

    printf("enter your desired operator from +,-,*,/ \n");
   op =getchar();

    printf("enter 2 numbers \n");
    scanf("%f %f",&x,&y);


if(op=='+')
    {
        out=x+y;
    }
     else if(op=='-')
     {
         out=x-y;
     }
     else if(op=='*')
       {
           out=x*y;
       }
     else if(op=='/')
{
    out=x/y;
}
    else
 {
     printf("invalid input");
     return 1;
 }

    printf("your desired result is: %f",out);
    return 0;

}
