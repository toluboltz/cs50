// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "dictionary.h"

// // Represents a node in a hash table
// typedef struct node
// {
//     char word[LENGTH + 1];
//     struct node *next;
// }
// node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 27;

// Represet a trie
typedef struct trie
{
    bool is_word;
    struct trie *next_letter[N];
}
trie;

// // Hash table
// node *table[N];

// Trie root
trie *root;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    if (strcmp(word, "'") == 0)
    {
        return 26;
    }
    return toupper(word[0]) - 'A';
}

// Initializes the fields of a trie to NULL
void initialize_trie(trie *n)
{
    n->is_word = false;
    for (int i = 0; i < 27; i++)
    {
        n->next_letter[i] = NULL;
    }
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    root = malloc(sizeof(trie));
    if (root == NULL)
    {
        return false;
    }
    initialize(root);
    
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
