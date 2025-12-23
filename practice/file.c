#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char str[20];
    printf("Enter the string: ");
    scanf("%s", str);

    FILE *fp;
    fp = fopen("file.txt ", "w");

    if (fp == NULL)
    {
        printf("Couldn't open file\n");
        return 1;
    }
    int length;
    length = strlen(str);
    fprintf(fp, "%s" , str);
    fclose(fp);

    fp = fopen("/workspaces/151622439/practice/file.txt ", "r");
    if (fp == NULL)
    {
        printf("Couldn't open file\n");
        return 1;
    }
    char a[length];
    int i = 0;

    FILE *l;
    l = fopen("lower.txt", "w");
    if (l == NULL)
    {
        printf("Couldn't open file l\n");
        return 1;
    }

    FILE *u;
    u = fopen("upper.txt", "w");
    if (u == NULL)
    {
        printf("Couldn't open file u\n");
        return 1;
    }

    while (fscanf(fp, "%c", &a[i]) != EOF)
    {
        if(!isalpha(a[i]))
        {
            continue;
        }
        if (isupper(a[i]))
        {
            fprintf(u, "%c", a[i]);
        }
        else
        {

            fprintf(l, "%c", a[i]);
        }
        i++;
    }
}
