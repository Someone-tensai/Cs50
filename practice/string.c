#include<stdio.h>

#define MAX 20
int main()
{
    char string[MAX];
    int length;

    printf("Enter the string: ");
    scanf("%s", string);
    int i = 0;
   while(string[i] != '\0')
   {
    i++;
    length = i;
   }
    printf("Length of string is: %i\n" , length);
}
