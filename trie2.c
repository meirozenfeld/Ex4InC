


#include "trie2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node2* getNode2() // create new node
{
    	 struct node2* n = (struct node2*)malloc(sizeof(struct node2));
         n->letter='\0';
         n->count=0;
         for (int i = 0; i < NUM_LETTERS; i++)
         {
            n->children[i]=NULL;
         }
         return n;
}
void insert2(node2 *root, char *word)
{
    node2 *pr=root;
    while(*word)
    {
        // printf("%c\n", *word);
        if(pr->children[*word-CASE]==NULL) // if letter not insert to this place yet
        {
            pr->children[*word-CASE]=getNode2();
            pr->letter=*word;
        }
        pr=pr->children[*word-CASE];
        word++; // promotion letter
    }
    pr->count++;
    // printf("%ld\n",pr->count);
}
void reverseFre(char *ansStr1,node2 *root,int level1)
{   
    if(root==NULL){
        return;
    }
    if(level1!=0)
    {
        ansStr1=realloc(ansStr1,(level1+1)*sizeof(char)); // realloc by ansStr size +1
    }

   
    
    if(root->count>0) // end of word
    {   
        ansStr1[level1]='\0';
        printf("%s\t",ansStr1);
        printf("%lu\n",root->count);

    }
    for(int i=NUM_LETTERS-1; i>=0;i--)
    {
        if(root->children[i]) // if not null
        {
        ansStr1[level1]=CASE+i;
        level1++;
        reverseFre(ansStr1,root->children[i],level1); // recurcive call
        level1--;
        }
    }
}