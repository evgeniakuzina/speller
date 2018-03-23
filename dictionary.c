/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

typedef struct node
{
    bool is_word;
    struct node *children[27];
}
node;

node *root = NULL;

void free_nodes(node* trav);

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    node *trav = root;
    int i = 0;
    int length_word = strlen(word);
    for (int j = 0; j < length_word+1; j++)
    {
        if (word[j] == '\0')
        {
            if (trav->is_word == true)
                return true;
            else
                return false;
        }    
        if (isupper(word[j]))
        {
            i = word[j]-65;
        }
        else if (word[j] == '\'')
        {
            i = 26;
        }
        else if (islower(word[j]))
        {
            i = word[j]-97;
        }
        
        if (trav->children[i] == NULL)
        {
            
            return false;
        }
        else
        {
            
           trav = trav->children[i];
        }
    }    
    
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
 

unsigned int n = 0;

bool load(const char *dictionary)
{
    // TODO
    root = calloc(1, sizeof(node));
    root->is_word = false;
    int i = 0;
    char dictionary_word[46];
    
    FILE* fp = fopen(dictionary, "r");
    if (fp == NULL)
    {
        return false;
    }

        while (fscanf(fp, "%s", dictionary_word) != EOF)
        {     
            node *trav = root;
            
            for (int j = 0; j < strlen(dictionary_word)+1; j++)
            { 
                if (dictionary_word[j] == '\0')
                {
                    trav->is_word = true;
                    n++;
                    break;
                }    
                else if (islower(dictionary_word[j]))
                {
                    i = dictionary_word[j]-97;
                }
                else if (dictionary_word[j] == '\'')
                {
                    i = 26;
                }
                
                if (trav->children[i] == NULL)
                {
                    node *new_node = calloc(1, sizeof(node));
                    new_node->is_word = false;
                    
                    trav->children[i] = new_node;
                    trav = new_node;
                }
                else
                {
                    trav = trav->children[i];
                }
            }
        }
    
    fclose(fp);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    if(n != 0)
    {    
        return n;
    }
    else
    {
        return 0;
    }
        
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    node* trav = root;
    if (trav)
    {
        if (root != NULL)
        {
           free_nodes(root);
        }
        return true;
    }
    
    return false;
    
}

void free_nodes(node* trav)
{
    for (int i = 0; i < 27; i++)
    {
        if (trav->children[i])
        {
            free_nodes(trav->children[i]);
        }
    }
    
    free(trav);
    return;
}
