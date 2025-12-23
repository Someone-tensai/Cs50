#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage : ./caesar key\n");
        return 1;
    }
    string s = argv[1];
    for (int i = 0; s[i]; i++)
    {
        if (isdigit(s[i]) == 0)
        {
            return 1;
        }
    }


    int key = atoi(argv[1]);
    if (key < 1)
    {
        printf("Usage : ./caesar key\n");
        return 1;
    }
    else
    {
        string p_text = get_string("Plaintext  : ");
        int length = strlen(p_text);
        char c_text[length];
        char n[2];
        char a[2];
        printf("ciphertext: ");
        if (key >= 26)
        {
            key = key % 26;
        }
        for (int i = 0; i < length; i++)
        {

            if (isalpha(p_text[i]) != 0)
        {
                if (islower(p_text[i]) != 0)
                {
                    n[0] = 'z';
                    a[0] = 'a';
                }
                else
                {
                    n[0] = 'Z';
                    a[0] = 'A';
                }
                if ((p_text[i] + key) > n[0])
                {
                    key = (p_text[i] + key) - n[0];
                    c_text[i] = a[0] + key - 1;
                    key = key + n[0] - (p_text[i]);
                }
                else
                {
                    c_text[i] = (p_text[i] + key);
                }
            }
            else
            {
                c_text[i] = p_text[i];
            }
            printf("%c", c_text[i]);
        }
        printf("\n");
    }
}
