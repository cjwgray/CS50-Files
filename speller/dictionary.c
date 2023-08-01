/*Site: choaimeloo.GitHub Gist*/



// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

unsigned int word_count;



// Returns true if word is in dictionary, else false
bool check(const char *word)
{
   //Create copies of works for hash

    int a = strlen(word);
    char wordCopy[LENGTH +1];
    for (int i = 0; i < a; i++)
    {
        wordCopy[i] = tolower(word[i]);
    }
    wordCopy[a] = '\0';

    int h = hash(wordCopy);
    node *cursor =table[h];

    {
        while (cursor != NULL)
            if (strcasecmp(word, cursor->word) == 0)
        {
           return true;
        }

        else
        {
            cursor = cursor->next;
        }

    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned long sumHash = 0;
    for (int i = 0; i < strlen(word); i ++)
    {

        sumHash += toupper(word[0]) - 'A';

    }
    return sumHash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // This code will Open the Dictionary
    FILE *file = fopen(dictionary, "r");

    //return NULL
    if (file == NULL)
    {
        printf("Unable to open dictionary %s\n", dictionary);
        return false;
    }


    char word[LENGTH + 1];


    while (fscanf(file, "%s", word) != EOF)
    {

        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            unload();
            return false;
        }
        //This will copy the word into node
        strcpy(n->word, word);

        int h = hash(n->word);
        node *x = table[h];

        if (x == NULL)
        {
          table[h] = n;
          word_count++;
        }
        else
        {
          n->next = table[h];
          table[h] = n;
          word_count++;
        }
    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{

    return word_count;

}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    //This will unload the dictionary from memory

    node *y = NULL;
    node *cursor = y;

    //This will set the cursor in a temporary state
    while (cursor != NULL)
    {
        node *tmp = cursor;
        cursor = cursor->next;
        free(tmp);
    }
    return true;
}
