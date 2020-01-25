#ifndef _trie2_h_
#define _trie_h_
#define NUM_LETTERS ((int)26)
#define CASE ((int)'a')
typedef struct node2
{
char letter;
long unsigned int count;
struct node2* children[NUM_LETTERS];
} node2;
struct node2* getNode2();
void insert2(node2* root, char * word);
void reverseFre(char *ansStr1,node2 *root,int level1);
#endif