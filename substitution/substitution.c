#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage : ./substitution key\n");
        return 1;
    }
    int c = 0;
    string s = argv[1];
    int len = strlen(s);
    for (int i = 0; s[i]; i++)
    {

        if (isalpha(s[i]) == 0)
        {
            printf("Usage : ./substituion key\n");
            return 1;
        }
        for (int j = i + 1; j < len; j++)
        {
            if (s[i] == s[j])
            {
                return 1;
            }
        }
        c++;
    }
    if (c != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    string p_text = get_string("Plaintext: ");
    printf("ciphertext: ");
    int l = strlen(p_text);
    int n = 0;
    char p[l];

    for (int i = 0; i < l; i++)
    {
        if (isalpha(p_text[i]))
        {
            if (islower(p_text[i]))
            {
                n = 1;
            }
            if (isupper(p_text[i]))
            {
                n = 2;
            }
            p[i] = toupper(p_text[i]);
            p[i] = s[p[i] - 65];
            if (n == 1)
            {
                p[i] = tolower(p[i]);
                n = 0;
            }
            else if (n == 2)
            {
                p[i] = toupper(p[i]);
                n = 0;
            }
            printf("%c", p[i]);
        }

        else
        {
            printf("%c", p_text[i]);
        }
    }
    printf("\n");
}
