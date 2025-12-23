#include<stdio.h>

struct campus {

    char name[50];
    char address[30];
    char established_year[10];
    int no_of_students;

}cam[4];

typedef struct campus camp;

void check(camp cam[]);
int main()
{

    int i , j;

    for(i = 0 ; i < 4 ; i++)
    {
        printf("Enter name: ");
        scanf("%s" , cam[i].name);

        printf("Enter address: ");
        scanf("%s" , cam[i].address);

        printf("Enter established year: ");
        scanf("%s" , cam[i].established_year);

        printf("Enter no of students:  ");
        scanf("%i" , &cam[i].no_of_students);
    }

    check(cam);
}

void check(camp t[])
{
    printf("Campuses with more than 1000 students: \n");
    for(int i = 0 ; i < 4 ; i++)
    {
        if(t[i].no_of_students > 1000)
        {
            printf("%s\n", t[i].name);
        }
    }
}
