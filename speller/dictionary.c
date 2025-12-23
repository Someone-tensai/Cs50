// Implements a dictionary's functionality
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

int count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int len = strlen(word);
    char word1[LENGTH + 1];
    for (int i = 0; i < len; i++)
    {
        word1[i] = word[i];
    }

    int index = hash(word1);

    node *temp = malloc(sizeof(node));
    temp = table[index];

    while (temp != NULL)
    {
        if (strcmp(word, temp->word) == 0)
        {
            return true;
        }
        else
        {
            temp = temp->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *source = fopen(dictionary, "r");
    if (!source)
    {
        fclose(source);
        printf("File not found\n");
        return 1;
    }

    char word[LENGTH + 1];
    while (fscanf(source, "%s", word))
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Error allocating memory.\n");
            return 1;
        }
        strcpy(n->word, word);
        int index = hash(n->word);

        node *h = table[index];
        if (h == NULL)
        {
            table[index] = n;
            count++;
        }
        else
        {
            n->next = table[index];
            table[index] = n;
            count++;
        }
    }

    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    node *h = NULL;
    node *temp = h;

    while (temp != NULL)
    {
        node *t = temp;
        temp = temp->next;
        free(t);
    }

    return true;
}
