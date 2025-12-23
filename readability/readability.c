#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
void printi(int i);

int main(void)
{
    int no_of_words = 1, no_of_letters = 0, no_of_sent = 1, I, p = 1;
    float L, S;
    string text = get_string("Text: ");
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {

        if (text[i] == ' ' || text[i] == '\n')
        {
            no_of_words += 1;
        }
        else if (text[i] == '.' || text[i] == '?')
        {
            no_of_sent += 1;
        }

        else if (isalpha(text[i]) != 0)
        {
            no_of_letters += 1;
        }
    }

    L = 100.00 * (float) no_of_letters / (float) no_of_words;
    S = 100.00 * (float) no_of_sent / (float) no_of_words;
    I = (round) ((0.0588 * L) - (0.296 * S) - 15.8);
    if (I < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (I >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", I + 1);
    }
}
