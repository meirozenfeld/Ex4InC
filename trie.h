#ifndef _trie_h_
#define _trie_h_
#define NUM_LETTERS ((int)26)
#define CASE ((int)'a')
typedef struct node node;
struct node* getNode();
void insert(node* root, char * word);
void printUp(char* ansStr,node* root,int level);
void printDown(char* ansStr,node* root,int level);
void freeTrie(node *root);
#endif