/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// define node data type
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// create empty hashtable
const int HASHSIZE = 27;
node *hashtable[HASHSIZE] = {NULL};

// init variables
int dictionary_size = 0;


// hash function
int hash(const char initial)
{
    if (initial == 39)
    {
        return 0;
    }
    else
    {
        return tolower(initial) - 'a' + 1;
    } 
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    // get alphabetical position
    int index = hash(word[0]);
    
    // set up cursor
    node *cursor = hashtable[index];
    
    // loop through words
    while (cursor != NULL)
    {
        // if found, return true
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        
        // not found, let's keep going
        cursor = cursor->next;
    }
    
    // definitely not found
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    // open dictionary
    FILE *fp = fopen(dictionary, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", dictionary);
        return false;
    }
    
    // initialize variables
    int index;
    char word[LENGTH + 1];

    // run through all dictionary looking for new words
    while (fscanf(fp, "%s", word) != EOF)
    {
        // get alphabetical position
        index = hash(word[0]);
        
        // create and set up new word node
        node* new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fclose(fp);
            return false;
        }
        strcpy(new_node->word, word);
        
        // add new word node to the hashtable
        if (hashtable[index] == NULL)
        {
            new_node->next = NULL;
            hashtable[index] = new_node;
        }
        else
        {
            new_node->next = hashtable[index];
            hashtable[index] = new_node;
        }
        
        // increase dictionary size
        dictionary_size++;
    }
    
    // close opened files
    fclose(fp);
    
    // done
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // return size
    return dictionary_size;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    for (int i = 0; i < HASHSIZE; i++)
    {
        if (hashtable[i] != NULL)
        {
            node *cursor = hashtable[i];
            while (cursor != NULL)
            {
                node *temp = cursor;
                cursor = cursor->next;
                free(temp);
            }
        }
    }
    return true;
}
