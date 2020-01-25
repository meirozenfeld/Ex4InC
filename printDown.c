#include "trie2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// void print(struct node *root)
// {
//     if(root==NULL)return;
//     for (int i = 0; i < 26; i++)
//     {
//         struct node* head1=getNode();
//         print(head1);
//         printf("%c",root->letter);
//     }
// }
// void fr(struct node *root)
// {
//     struct node *pr=root;
//       if(pr==NULL)
//     {
//     for (int i = 0; i < 26; i++)
//         {
//             fr(pr->children[i]);
//             free(root);
//         }
//     }

// }
int main()
{
    struct node2 *head1 = getNode2();
    char c;
    // int i = 0;
    int size = 0;
    char *str;
    while ((c = getc(stdin))!=EOF) // while not the end of text
    {
        if(size==0)
        {
            str = (char *)malloc(sizeof(char));// initial allocation to str
        }
        else
        {
            str = realloc(str,(size+1)*sizeof(char));// realloc by str size +1
        }
        if (c >= 'A' && c <= 'Z')
        { 
            c = c + 32; //uppercase to lowercase
        } 
        if (c >= CASE && c <= CASE + NUM_LETTERS)
        {
            size++;
            str[size-1] = c;
            str[size] = '\0';
            
        }
        if (c == ' ' || c == '.' || c == ',' || c == '\n'||c=='\t') // end of word
        {
            size=0; // init size
            // printf("%s\n",str);

            insert2(head1, str); // insert to trie tree
            // if(str!=NULL)free(str); 
        }
        // if(c=='\n')break; // for manual check
    }
    // printf("firs leter: %c\n",head1->letter);
    char *ansStr1   = (char *)malloc(sizeof(char));
    reverseFre(ansStr1,head1,0);
    return 0;
}
