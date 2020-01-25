#include "trie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int arc, char *arv[])
{
    struct node *head = getNode();
    char c; // every char in th text
    int size = 0;
    int maxSize = 0; // max size of word
    char *str;
    while ((c = getc(stdin)) != EOF) // while not the end of text
    {
     
 if (c != ' '  && c != '\n' && c != '\t'&&c != '\0') 
 {
        if (c >= 'A' && c <= 'Z')
        {
            c = c + 32; //uppercase to lowercase
        }
       
        if (c >= CASE && c <= CASE + NUM_LETTERS)
        {
        if (size == 0)
        {
            str = (char *)malloc(sizeof(char)); // initial allocation to str
        }
        else
        {
            str = realloc(str, (size + 1) * sizeof(char)); // realloc by str size +1
        }
            size++;
            str[size - 1] = c;
            str[size] = '\0';
        }
 }
        if (c == ' '  || c == '\n' || c == '\t'||c == '\0') // end of word
        {
            if (size > maxSize)
            {
                maxSize = size; // save the maxSize of word
            }
            insert(head, str); // insert to trie tree
            // printf(" the word is %s\n", str);
            if (str != NULL)
            {
            free(str); // delete word memory after insert
            }
                        // str[size-1] = '\0';

            size = 0;      // init word size
        }
        // if(c=='\n')break; // for manual check
    }
    // printf("%d",maxSize );
    char ansStr[maxSize];
    if (arc == 1)
    {
        printUp(ansStr, head, 0);
    }
    else
    {
        if (strcmp(arv[1], "r") == 0)
        {
            printDown(ansStr, head, 0);
        }
    }
    freeTrie(head);
    return 0;
}
