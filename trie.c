#include "trie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    char letter;
    long unsigned int count;
    struct node *children[NUM_LETTERS];
} node;

struct node *getNode() // create new node
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->letter = '\0';
    n->count = 0;
    for (int i = 0; i < NUM_LETTERS; i++)
    {
        n->children[i] = NULL;
    }
    return n;
}
void insert(node *root, char *word)
{
    node *pr = root;
    while (*word)
    {
        // printf("%c\n", *word);
        if (pr->children[*word - CASE] == NULL) // if letter not insert to this place yet
        {
            pr->children[*word - CASE] = getNode();
            pr->letter = *word;
        }
        pr = pr->children[*word - CASE];
        word++; // promotion letter
    }
    pr->count++;
    // printf("d= %lu\n",pr->count);
}

void printUp(char *ansStr, node *root, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (root->count > 0) // end of word
    {
        ansStr[level] = '\0';
        printf("%s\t", ansStr);
        printf("%lu\n", root->count);
    }
    for (int i = 0; i < NUM_LETTERS; i++)
    {
        if (root->children[i]) // if not null
        {
            ansStr[level] = CASE + i;
            level++;
            printUp(ansStr, root->children[i], level); // recurcive call
            level--;
        }
    }
}

void printDown(char *ansStr1, node *root, int level1)
{
    if (root == NULL)
    {
        return;
    }
    if (root->count > 0 && root->letter != ' ' && root->letter != '.' && root->letter != ',' && root->letter != '\n' && root->letter != '\t') // end of word
    {
        ansStr1[level1] = '\0';
        printf("%s\t", ansStr1);
        printf("%lu\n", root->count);
    }
    for (int i = NUM_LETTERS - 1; i >= 0; i--)
    {
        if (root->children[i]) // if not null
        {
            ansStr1[level1] = CASE + i;
            level1++;
            printDown(ansStr1, root->children[i], level1); // recurcive call
            level1--;
        }
    }
}
void freeTrie(node *root)
{
    for (int i = 0; i < NUM_LETTERS; i++)
    {
        if (root->children[i]) // if not null
        {
            freeTrie(root->children[i]); //recurcive call
        }
    }
    if (root != NULL)
    {
        free(root);
    }
}