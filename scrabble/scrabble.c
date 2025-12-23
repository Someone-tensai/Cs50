#include <cs50.h>
#include <stdio.h>
#include <string.h>

int check(string);
int main(void)
{
    string p_1 = get_string("Player 1: ");
    string p_2 = get_string("Player 2: ");
    if (strcmp(p_1, p_2) == 0)
    {
        printf("Tie!");
    }
    else
    {
        if (check(p_1) > check(p_2))
        {
            printf("Player 1 wins !");
        }
        else if (check(p_1) < check(p_2))
        {
            printf("Player 2 wins !");
        }
        else
        {
            printf("Tie!");
        }
    }
    return 0;
}
int check(string str)
{
    int count[strlen(str)], sum = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == 'D' || str[i] == 'd' || str[i] == 'g' || str[i] == 'G')
        {
            count[i] = 2;
        }
        else if (str[i] == 'B' || str[i] == 'b' || str[i] == 'C' || str[i] == 'c' || str[i] == 'M' || str[i] == 'm' ||
                 str[i] == 'P' || str[i] == 'p')
        {
            count[i] = 3;
        }
        else if (str[i] == 'Y' || str[i] == 'y' || str[i] == 'W' || str[i] == 'w' || str[i] == 'V' || str[i] == 'v' ||
                 str[i] == 'f' || str[i] == 'F' || str[i] == 'h' || str[i] == 'H')
        {
            count[i] = 4;
        }

        else if (str[i] == 'J' || str[i] == 'j' || str[i] == 'X' || str[i] == 'x')
        {
            count[i] = 8;
        }
        else if (str[i] == 'Q' || str[i] == 'q' || str[i] == 'Z' || str[i] == 'z')
        {
            count[i] = 10;
        }
        else if (str[i] == 'K' || str[i] == 'k')
        {
            count[i] = 5;
        }
        else if (str[i] == 'A' || str[i] == 'a' || str[i] == 'N' || str[i] == 'n' || str[i] == 'E' || str[i] == 'e' ||
                 str[i] == 'I' || str[i] == 'i' || str[i] == 'O' || str[i] == 'o' || str[i] == 'R' || str[i] == 'r' ||
                 str[i] == 'S' || str[i] == 's' || str[i] == 'T' || str[i] == 't' || str[i] == 'U' || str[i] == 'u' ||
                 str[i] == 'L' || str[i] == 'l')
        {
            count[i] = 1;
        }
        else
        {
            count[i] = 0;
        }
        sum = sum + count[i];
    }
    return sum;
}
