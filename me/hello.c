#include<stdio.h>
#include<string.h>
 int main()
 {
    char a[30];
    printf("What's your name?\t");
    fgets(a,30,stdin);
    printf("\nhello, %s" ,a);
 }
