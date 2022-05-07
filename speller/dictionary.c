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

void initialize_trie(trie *n);
void free_dictionary(trie *trav);

int word_count = 0;

// // Hash table
// node *table[N];

// Trie root
trie *root;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Get length of word
    int len = strlen(word);

    // Pointer to traverse the trie tree
    trie *cursor = root;

    // Follow the links in the trie tree
    for (int i = 0; i < len; i++)
    {
        char c = word[i];
        int key = hash(&c);

        if (cursor->next_letter[key] != NULL)
        {
            cursor = cursor->next_letter[key];
        }
    }

    // Return the value of the last node
    return cursor->is_word;
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
    // Allocate space for the root node
    root = malloc(sizeof(trie));
    if (root == NULL)
    {
        free(root);
        return false;
    }
    initialize_trie(root);

    // Open dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        return false;
    }

    // Set pointer to traverse the trie tree starting at root
    trie *trav = root;

    char c;
    while (fread(&c, sizeof(c), 1, file))
    {
        if (c != '\n')
        {
            int key = hash(&c);

            if (trav->next_letter[key] == NULL)
            {
                // Allocate temporary memory for new trie
                trie *temp = malloc(sizeof(trie));
                if (temp == NULL)
                {
                    return false;
                }
                initialize_trie(temp);

                // Set and point to new trie
                trav->next_letter[key] = temp;
                trav = temp;
            }
            else
            {
                // Move down the tree to next trie
                trav = trav->next_letter[key];
            }
        }
        else
        {
            // Word inserted, go back to root node
            trav->is_word = true;
            trav = root;

            // Increment word count
            word_count++;
        }
    }

    // Close file
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
    free_dictionary(root);
    return true;
}

void free_dictionary(trie *trav)
{
    // Loop through the arrays of each node
    for (int i = 0; i < N; i++)
    {

        // Check if array points to another node
        if (trav->next_letter[i] != NULL)
        {
            free_dictionary(trav->next_letter[i]);
        }
    }

    // Free node
    free(trav);
}
