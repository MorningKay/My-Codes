// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

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

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int l = strlen(word);
    char lower_word[l + 1];
    lower_word[l] = '\0';
    for (int i = 0; i < l; i++)
    {
        lower_word[i] = tolower(word[i]);
    }
    printf("lower_word: %s\n", lower_word);
    int index = hash(word);
    node *p = table[index];
    while (p != NULL)
    {
        int pl = strlen(p->word);
        char p_lower_word[pl + 1];
        p_lower_word[pl] = '\0';
        for (int i = 0; i < pl; i++)
        {
            p_lower_word[i] = tolower(p->word[i]);
        }
        printf("p_lower_word: %s\n", p_lower_word);
        if (strcmp(lower_word, p_lower_word) == 0)
        {
            return true;
        }
        p = p->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        sum += toupper(word[i]);
    }
    return sum % 26;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        return false;
    }
    char word[LENGTH + 1];
    while (fscanf(source, "%s", word) != EOF)
    {
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            return false;
        }
        strcpy(new_node->word, word);
        int index = hash(word);
        new_node->next = table[index];
        table[index] = new_node;
    }
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    int numbers = 0;
    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            node *p = table[i];
            while (p->next != NULL)
            {
                numbers += 1;
                p = p->next;
            }
            numbers += 1;
        }
    }
    return numbers;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            node *p = table[i];
            node *q;
            while (p->next != NULL)
            {
                q = p;
                p = p->next;
                free(q);
            }
            free(p);
        }
        free(table[i]);
    }
    return true;
}
