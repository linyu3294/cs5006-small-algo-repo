// =================== Support Code =================
// Queue
//
//
//
// - Implement each of the functions to create a working circular queue.
// - Do not change any of the function declarations
//   - (i.e. queue_t* create_queue(unsigned int _capacity) should not have additional arguments)
// - You should not have any 'printf' statements in your queue functions.
//   - (You may consider using these printf statements to debug, but they should be removed from your final version)
// ==================================================
#ifndef MYQUEUE_H
#define MYQUEUE_H

// The main data structure for the queue
struct queue{
    unsigned int back;        // The next free position in the queue
                                  // (i.e. the end or tail of the line)
    unsigned int front;        // Current 'head' of the queue
                                  // (i.e. the front or head of the line)
    unsigned int size;        // How many total elements we currently have enqueued.
    unsigned int capacity;  // Maximum number of items the queue can hold
    int* data;                   // The 'integer' data our queue holds
};
// Creates a global definition of 'queue_t' so we
// do not have to retype 'struct queue' everywhere.
typedef struct queue queue_t;

// Create a queue
// Returns a pointer to a newly created queue.
// The queue should be initialized with data on
// the heap.
// If you weren't able to allocate memory, return NULL.
queue_t* create_queue(unsigned int _capacity){
    queue_t* myQueue = NULL;
    myQueue = (queue_t*)malloc(sizeof(queue_t));
    if(myQueue == NULL) {
         return NULL;
     }
    myQueue->capacity =_capacity;
    myQueue-> front = 0;
    myQueue-> back = 0;
    myQueue->size = 0;
    myQueue->data = (int*)calloc(myQueue->capacity, sizeof(int));
    
    return myQueue;
}

// Queue Empty
// Check if the queue is empty
// Returns 1 if true (The queue is completely empty)
// Returns 0 if false (the queue has at least one element enqueued)
// Returns -1 if the queue is NULL
int queue_empty(queue_t* q){
    if (q == NULL) {
        return -1;
    }
    if (q->size==0){
        return 1;
    }
    return 0;
}

// Queue Full
// Check if the queue is Full
// Returns 1 if true (The queue is completely full)
// Returns 0 if false (the queue has more space available to enqueue items)
// Returns -1 if the queue is NULL.
int queue_full(queue_t* q){
    if (q == NULL){
        return -1;
    }
    if (q->size==q->capacity) {
        return 1;
    }
    else{
        return 0;
    }
}

// Enqueue a new item
// i.e. push a new item into our data structure
// Returns a 0 if the operation fails
// Returns a 1 if the operation suceeds
// Returns -1 if the queue is NULL.
// 0 Not allowed as item entry.
// (i.e. if the queue is full that is an error).

// Note: you should have two return statements in this function.
int queue_enqueue(queue_t* q, int item){
    if (q==NULL){
        return -1;
    }
    if (queue_full(q) ==1){
        return 0;
    }
    q->data[ (q->back)] = item;
    q->back = (q->back+1)% (q->capacity);
    q->size++;
    return 1;
}

// Dequeue an item
// Returns the item at the front of the queue and
// removes an item from the queue.
// Removing from an empty queue should do nothing
// Returns 0 for an empty stack;
// Returns -1 if the queue is NULL. Assumption there is not going to be negative numbers in the queue
int queue_dequeue(queue_t *q){
    if (q ==NULL){
        return -1;
    }
    if (queue_empty(q)){
        return 0;
    }
    int item = q->data[q->front];
    q->front = (q->front+1)% (q->capacity);
    q->size--;
    return item;
}


// Queue Size
// Queries the current size of a queue
// Returns -1 if the queue is NULL.
unsigned int queue_size(queue_t* q){
    if (q ==NULL) {
        return -1;
    }
    return (q->size);
    }


// Free queue
// Removes a queue and all of its elements from memory.
// This should be called before the proram terminates.
void free_queue(queue_t* q){
    free(q->data);
    free(q);
}


#endif
