// =================== Support Code =================
// Doubly Linked List ( DLL ).
//
//
//
// - Implement each of the functions to create a working DLL.
// - Do not change any of the function declarations
//   - (i.e. dll_t* create_dll() should not have additional arguments)
// - You should not have any 'printf' statements in your DLL functions.
//   - (You may consider using these printf statements to debug, but they should be removed from your final version)
// ==================================================
#ifndef MYDLL_H
#define MYDLL_H

// Create a node data structure to store data within
// our DLL. In our case, we will stores 'integers'
typedef struct node{
    int data;
    struct node* next;
    struct node* previous;
}node_t;

// Create a DLL data structure
// Our DLL holds a pointer to the first node in our DLL called head,
// and a pointer to the last node in our DLL called tail.
typedef struct DLL{
    int count;        // count keeps track of how many items are in the DLL.
    node_t* head;        // head points to the first node in our DLL.
    node_t * tail;          //tail points to the last node in our DLL.
}dll_t;

// Creates a DLL
// Returns a pointer to a newly created DLL.
// The DLL should be initialized with data on the heap.
// (Think about what the means in terms of memory allocation)
// The DLLs fields should also be initialized to default values.
dll_t* create_dll(){
    // Modify the body of this function as needed.
    dll_t* myDLL= NULL;
    myDLL = (dll_t*)malloc(sizeof(dll_t));
    
    myDLL->head=NULL;
    myDLL->tail=NULL;
    myDLL->count = 0;
    
    return myDLL;
}



// DLL Empty
// Check if the DLL is empty
// Returns 1 if true (The DLL is completely empty)
// Returns 0 if false (the DLL has at least one element enqueued)
int dll_empty(dll_t* l){
    if(l->count==0) {
        return 1;
    }
    return 0;
}



// push a new item to the front of the DLL ( before the first node in the list).
// Returns a -1 if the operation fails ( and if the DLL is NULL), otherwise returns 1 on success.
// (i.e. the memory allocation for a new node failed).
int dll_push_front(dll_t* l, int item){
    if (l == NULL){
        return -1;
    }
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    if (newNode == NULL){
        return -1;
    }
    newNode->data = item;
    if (l->count == 0){
        newNode->next = NULL;
        newNode->previous = NULL;

        l->head = newNode;
        l->tail = newNode;
        l->count = 1;
    }
    else {
        newNode->previous = NULL;
        newNode->next = l->head;
        l->head->previous = newNode;
        l->head = newNode;
        l->count++;
    }
    return 1;
}


// push a new item to the end of the DLL (after the last node in the list).
// Returns a -1 if the operation failsm (and if the DLL is NULL), otherwise returns 1 on success.
// (i.e. the memory allocation for a new node failed).
int dll_push_back(dll_t* l, int item){
    if (l == NULL){
        return -1;
    }
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    if (newNode == NULL){
        return -1;
    }
    newNode->data = item;
    if (l->count == 0){
        newNode->next = NULL;
        newNode->previous = NULL;
        l->head = newNode;
        l->tail = newNode;
        l->count = 1;
    }
    else {
        newNode->next = NULL;
        newNode->previous = l->tail;
        l->tail->next = newNode;
        l->tail = newNode;
        l->count++;
    }
 
    return 1;
}



// Returns the first item in the DLL and also removes it from the list.
// Returns a -1 if the operation fails (and if the DLL is NULL). Assume no negative numbers in the list.
int dll_pop_front(dll_t* t){
    if (t==NULL){
        return -1;
    }
    if (t->count == 0){
        return -1;
    }
    int rem_item = t->head->data;
    if (t->count ==1) {
        free(t->head);
        t->head = NULL;
        t->tail = NULL;
    }
    else if(t->count >1){
        node_t* temp = t->head->next;
        free(t->head);
        t->head = temp;
        t->head->previous= NULL;
    }
    t->count--;
    return rem_item;
    }
    


// Returns the last item in the DLL, and also removes it from the list.
// Returns a -1 if the operation fails (and if the DLL is NULL). Assume no negative numbers in the list.
int dll_pop_back(dll_t* t){
    if (t==NULL){
        return -1;
    }
    if (t->count == 0){
        return -1;
    }
    int rem_item = t->tail->data;
    if (t->count ==1) {
        free(t->tail);
        t->head = NULL;
        t->tail = NULL;
    }
    else if (t->count>1){
        node_t* temp = t->tail->previous;
        free(t->tail);
        t->tail = temp;
        t->tail->next = NULL;
    }
    t->count--;
    return rem_item;
}



// Inserts a new node before the node at the specified position.
// Returns a -1 if the operation fails (and if the DLL is NULL), otherwise returns 1 on success.
// (i.e. the memory allocation for a new node failed or trying to insert at a negative position or at
//  a position past the size of the DLL ). Think testcases here.
int dll_insert(dll_t* l, int pos, int item){
    if (l==NULL || pos<0){
        return -1;
    }
    if (pos==0) {dll_push_front(l, item);}
    else if (pos == l->count-1) {dll_push_back(l, item);}
    else if (pos > l->count-1) {return -1;}
    else{
        node_t* newNode = (node_t*)malloc(sizeof(node_t));
        newNode->data = item;
        node_t* iter = l->head;
        for (int i=0; i<pos; i++){
            iter = iter->next;
        }
        iter->previous->next = newNode;
        iter->previous = newNode;
        newNode->previous = iter->previous;
        newNode->next =iter;
        l->count++;
    }
    return 1;
}


        
// Returns the item at position pos starting at 0 (0 being the first item )
// Returns a -1 if the operation fails (and if the DLL is NULL). Assume no negative numbers are in the list.
// (i.e. trying to get at a negative position or at a position past the size of the DLL ).
// Think testcases here.
int dll_get(dll_t* l, int pos){
    if (l==NULL || pos<0 || pos>l->count-1){
        return -1;
    }
    node_t* iter = l->head;
    for (int i=0; i<pos; i++){
        iter = iter->next;
        }
     return iter->data;
}
   



// Removes the item at position pos starting at 0 ( 0 being the first item )
// Returns a -1 if the operation fails (and if the DLL is NULL).
// (i.e. trying to remove at a negative position or at a position past the size of the DLL ).
// Think testcases here.
int dll_remove(dll_t* l, int pos){
    if (l==NULL || pos<0 || pos>l->count-1 || count ==0){
        return -1;
    }
    if (pos==0 && l->count>=1){dll_pop_front(l);}
    else if(pos==l->count-1){dll_pop_back(l);}
    else{
        node_t* iter = l->head;
        for (int i=0; i<pos; i++){
            iter = iter->next;
        }
        int rem_item = iter->data;
        iter->previous->next=iter->next;
        iter->next->previous=iter->previous;
        free(iter);
           l->count--;
    }
    return rem_item;
}


// DLL Size
// Queries the current size of a DLL
// A DLL that has not been previously created will crash the program.
// Returns -1 if the DLL is NULL.
unsigned int dll_size(dll_t* t){
    if (t==NULL){
        return -1;
    }
    return t->count;
}

// Free DLL
// Removes a DLL and ALL of its elements from memory.
// This should be called before the proram terminates.
void free_dll(dll_t* t){
    node_t* iter = t->head;
    while (iter != NULL){
        node_t* temp= iter;
        free(iter);
        t->head = temp;
        iter = iter->next;
    }
    free(t);
}


#endif
