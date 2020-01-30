// clang dfs.c -o dfs
// ./dfs
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
  struct TreeNode* left;
  struct TreeNode* right;
  char data;
}TreeNode_t;


// Helper function - helps to verify that next Left Node exists
// IF Left does not exist/ == NULL then return -1.
// IF Left does exist returns 1.

int hasLeft (TreeNode_t* node) {
    if (node->left == NULL) {
        return -1;
    }
    else { return 1;}
    return 0;
}


// Helper function - helps to verify that next Right Node exists
// IF Right does not exist/ == NULL then return -1.
// IF Right does exist returns 1.
int hasRight (TreeNode_t* node) {
    if (node->right == NULL) {
        return -1;
    }
    else { return 1;}
    return 0;
}



// Depth-First Tree Traversal
// Make sure to print out each node you visit, and only print it out once!
// **Hint** Think recursively
void dfs(TreeNode_t* start){
    // TODO: Hmm, how can I look through both branches of the node?
    //       Hmm, when do I stop?

    //Check that starting node is not null and print data stored.
    if (start == NULL) {
        printf("\nYour starting node is NULL\n");
    }
    else {printf("\nCurrent Node data is %c\n" , start->data);}
    
    
    int leftExist = hasLeft(start);
    int rightExist = hasRight(start);
    // Recursive Strategy
 
    if (leftExist == 1){
        dfs(start->left);
    }
    if (rightExist == 1){
        dfs(start ->right);
    }
        
}


int main(){

  // Manually create a tree for this lab
  TreeNode_t* start = malloc(sizeof(TreeNode_t));
  TreeNode_t* a= malloc(sizeof(TreeNode_t));
  TreeNode_t* b= malloc(sizeof(TreeNode_t));
  TreeNode_t* c= malloc(sizeof(TreeNode_t));
  TreeNode_t* d= malloc(sizeof(TreeNode_t));
  TreeNode_t* e= malloc(sizeof(TreeNode_t));
  TreeNode_t* f= malloc(sizeof(TreeNode_t));
  TreeNode_t* g= malloc(sizeof(TreeNode_t));
  TreeNode_t* h= malloc(sizeof(TreeNode_t));

  // The root of our tree
  // The root also has two 'branches' a and b.
  start->data = 's';
  start->left = a;
  start->right = b;
  
  a->data = 'a';
  a->left = c;
  a->right = d;
  
  b->data = 'b';
  b->left = e;
  b->right = f;
  
  c->data = 'c';
  c->left = g;
  c->right = h;

  // All of the 'leaves' in our tree
  d->data = 'd';
  d->left = NULL;
  d->right = NULL;
  
  e->data = 'e';
  e->left = NULL;
  e->right = NULL;

  f->data = 'f';
  f->left = NULL;
  f->right = NULL;
  
  g->data='g';
  g->left = NULL;
  g->right = NULL;

  h->data = 'h';
  h->left = NULL;
  h->right = NULL;
  
  // Perform the dfs
  dfs(start);
  
  // Perform the dfs at a different spot)
  
  free(start);
  free(a);
  free(b);
  free(c);
  free(d);
  free(e);
  free(f);
  free(g);
  free(h);
  
  return 0;
}
