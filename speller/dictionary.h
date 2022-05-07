// Declares a dictionary's functionality

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45

// Represet a trie
typedef struct trie
{
    bool is_word;
    struct trie *next_letter[N];
}
trie;

// Prototypes
bool check(const char *word);
unsigned int hash(const char *word);
void initialize_trie(trie *n);
bool load(const char *dictionary);
unsigned int size(void);
bool unload(void);

#endif // DICTIONARY_H
