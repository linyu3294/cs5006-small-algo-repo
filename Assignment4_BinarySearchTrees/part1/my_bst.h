// =================== Support Code =================
// Binary Search Tree ( BST ).
//
//
//
// - Implement each of the functions to create a working BST.
// - Do not change any of the function declarations
//   - (i.e. bst_t* create_bst() should not have additional arguments)
// - You should not have any 'printf' statements in your BST functions.
//   - (You may consider using these printf statements to debug, but they should be removed from your final version)
// ==================================================
#ifndef MYBST_H
#define MYBST_H

// Create a node data structure to store data within
// our BST. In our case, we will stores 'integers'
typedef struct node{
    int data;
    struct node* rightChild;
    struct node* leftChild;
}node_t;


// Create a BST data structure
// Our BST holds a pointer to the root node in our BST called root.
typedef struct BST{
    int count;        // count keeps track of how many items are in the BST.
    node_t* root;        // root points to the root node in our BST.
}bst_t;



// Creates a BST
// Returns a pointer to a newly created BST.
// The BST should be initialized with data on the heap.
// The BST fields should also be initialized to default values.
bst_t* create_bst(){
    // Modify the body of this function as needed.
    bst_t* myBST = (bst_t*) malloc (sizeof (bst_t));
    myBST->count = 0;
    myBST->root = NULL;
    return myBST;
}


// BST Empty
// Check if the BST is empty
// Returns 1 if true (The BST is completely empty)
// Returns 0 if false (the BST has at least one element enqueued)
int bst_empty(bst_t* t){
    if (t->count ==0) {
        return 1;
    }
    return 0;
}


// Helper function - helps to verify that next Left Node exists
// IF Left does not exist/ == NULL then return 0.
// IF Left does exist returns 1;
int hasLeft (node_t* t) {
    if (t->leftChild == NULL) {
        return 0;
    }
    return 1;
}


// Helper function - helps to verify that next Right Node exists
// IF Right does not exist/ == NULL then return -1.
// IF Right does exist returns 1;
int hasRight (node_t* t) {
    if (t->rightChild == NULL) {
        return 0;
    }
    return 1;
}


// This is a helper that recurrsively searches for an element.
// It is used in the find method.
// Returns 1 if value is found in the tree, 0 otherwise.
int findHelper (node_t* n, int item) {
    if (item < n->data) {
        if (n->leftChild ==NULL){
            return 0;
        }
        else {
            int num = findHelper(n->leftChild,  item);
            return num;
        }
    }
    else if (item > n->data){
        if (n->rightChild ==NULL){
            return 0;
        }
        else{
            int num =findHelper(n->rightChild, item);
            return num;
        }
    }
    else {return 1;}
}


// Returns 1 if value is found in the tree, 0 otherwise.
// For NULL tree it exists the program.
// It should run in O(log(n)) time.
int find(bst_t * t, int value){
    if (t ==NULL) {return -1;}
    if (t->root == NULL) {return 0;}
    else {int a = findHelper(t->root, value);
        return a;}
  return 0;
}


// Helper function - reccursively adds the new node
// to the correct place based on value comparision
// with the data stored in the current reccursive iteration.
// Returns 1 if succeeds and returns 0 if fails;
int addChild (node_t* n, int item) {
    
    // Attempt to check and add to left side of node_t n.
    if (hasLeft(n) == 0 && item < n->data){
  
        node_t* newLeftNode = (node_t*) malloc(sizeof(node_t));
        if (n == NULL || newLeftNode == NULL) {
            return -1;
        }
        newLeftNode -> leftChild = NULL;
        newLeftNode -> rightChild = NULL;
        newLeftNode -> data =item;
        n->leftChild = newLeftNode;
        return 1;
    }
    else if (hasLeft(n) == 1 && item < n->data){
        addChild(n->leftChild, item);
    }
    
    
     // Attempt to check and add to right side of node_t n.
    if (hasRight(n) == 0 && item > n->data){

        node_t* newRightNode = (node_t*) malloc (sizeof(node_t));
        if (n == NULL || newRightNode == NULL) {
            return -1;
        }
        newRightNode -> leftChild = NULL;
        newRightNode -> rightChild = NULL;
        newRightNode->data = item;
        n->rightChild = newRightNode;
        return 1;
    }
    else if (hasRight(n) == 1 && item > n->data) {
        addChild(n->rightChild, item);
    }
    
    // All fails, return -1.
    return -1;
}



// Adds a new node containng item in the correct place of the BST.
// If the data is less then the current node we go right, otherwise we go left.
// Same as described in the README.md file.
// Returns a -1 if the operation fails (otherwise returns 0 on success).
// (i.e. the memory allocation for a new node failed).
// It should run in O(log(n)) time.
int bst_add(bst_t* t, int item){
    if (find(t,item)==1){return -1;}
    if (t == NULL){
        return -1;
    }
    
    if (bst_empty(t) == 1) {
        node_t* newNode = (node_t*) malloc (sizeof(node_t));
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;
        newNode->data = item;
        t->root = newNode;
        t->count++;
        return 1;
    }
    else {
        t->count++;
        return (addChild(t->root, item));
    }
    return 0;
}


// This is a helper function for printing in the ascending order.
void bst_print_ascd_helper (node_t* start) {
    if (start==NULL){
        return;
    }
    bst_print_ascd_helper(start->leftChild);
    printf("%d\n", start->data);
    bst_print_ascd_helper(start->rightChild);
}


// This is a helper function for printing in the decending order.
void bst_print_descd_helper (node_t* start) {
    if (start==NULL){
        return;
    }
    bst_print_descd_helper(start->rightChild);
    printf("%d\n", start->data);
    bst_print_descd_helper(start->leftChild);
}


// Prints the tree in ascending order if order = 0, otherwise prints in descending order.
// For NULL tree it should print nothing.
// It should run in O(n) time.
void bst_print(bst_t*t, int order){
    if (t == NULL) {return;}
    if (t->root == NULL) {return;}
    else {
        if (order ==0){
            bst_print_ascd_helper (t->root);
        }
        if (order ==1){
            bst_print_descd_helper (t->root);
        }
    }
}


// Helper for sum function.
// Recursively traverses the tree and helps to add up all nodes
int sum_helper(node_t* start) {
    if (start == NULL){
        return 0;
    }
    return start->data + sum_helper(start->leftChild) + sum_helper(start ->rightChild);
}


// Returns the sum of all the nodes in the tree.
// exits the program for a NULL tree.
// It should run in O(n) time.
int sum(bst_t *t){
    if (t == NULL) {
        return -1;
    }
    return sum_helper(t->root);
}


// BST Size
// Queries the current size of the BST
// A BST that has not been previously created will crash the program.
// (i.e. A NULL BST cannot return the size)
unsigned int bst_size(bst_t* t){
    if (t==NULL) {return -1;}
    else {return t->count;}
}



// This is a helper function that traverses the tree.
// And free up each node recursively.
void free_helper (node_t* n) {
    if (n==NULL) {return;}
    free_helper(n->leftChild);
    free_helper(n->rightChild);
    free(n);
}


// Free BST
// Removes a BST and ALL of its elements from memory.
// This should be called before the proram terminates.
void free_bst(bst_t* t){
    if (t==NULL){return;}
    if (t->root==NULL){free(t); return;}
    else{
        free_helper(t->root);
    }
    if(t!=NULL){
        free(t);
        return;
    }
}



#endif
