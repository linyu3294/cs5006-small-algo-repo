// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "myqueue.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.


// A sample test of your program
// You need to add sufficient testing.
void create_queue_test(){
    queue_t* test1 = create_queue(7);
    
    if (test1 != NULL
        && test1->capacity== 7
        && test1->size==0
        && test1->front==0
        && test1->back==0) {
        printf("\ncreate_queue() test passed; New queue created successfully.\n");
    }
    else {
        printf("\ncreate_queue() test failed; New queue not initiated properly. Is Null or a attribute/s not assigned correctly.\n");
    }
    free_queue(test1);    
}

void queue_empty_test() {
    queue_t* test2 = create_queue(7);
    if (test2 != NULL && queue_empty(test2)==1) {
        printf("\nqueue_empty() test passed; New queue is created with empty queue.\n");
    }
    else {
        printf("\nqueue_empty() test failed; New queue is not an empty queue.\n");
          }
    free_queue(test2);
}



void queue_full_test(){
    queue_t* test3 = create_queue(3);
    queue_enqueue(test3, 1);
    queue_enqueue(test3, 2);
    queue_enqueue(test3, 3);
    int result = queue_full(test3);
    if (result==1){
        printf("\nqueue_empty() test passed; New queue is full.\n");
    }
    else {
        printf("\nqueue_empty() test failed; New queue is not full.\n");
    }
    free_queue(test3);
}



void queue_enqueue_test() {
    queue_t* test4 = create_queue(3);
    queue_enqueue(test4,1);
    int result = test4->data[test4->back-1];
    if (result == 1) {
        printf("\nqueue_enqueue() test 1 passed; an item added.\n");
    }
    else{
        printf("\nqueue_enqueue() test 1 failed; unable to add an item.\n");
    }
    queue_enqueue(test4,2);
    result = test4->data[test4->back-1];
    if (result == 2) {
        printf("\nqueue_enqueue() test 2 passed; a second item is added.\n");
    }
    else{
        printf("\nqueue_enqueue() test 2 failed; unable to add a second item.\n");
    }
    queue_enqueue(test4,7);
    result = test4->data[2];
    if (result == 7) {
        printf("\nqueue_enqueue() test 3 passed; a third item is added.\n");
    }
    else{
        printf("\nqueue_enqueue() test 3 failed; unable to add a third item.\n");
    }
    free_queue(test4);
}



void queue_size_test() {
    queue_t* test5 = create_queue(3);
    queue_enqueue(test5,1);
    int result = queue_size(test5);;
    if (result == 1) {
        printf("\nqueue_size() test 1 passed; queue size is 1.\n");
    }
    else{
        printf("\nqueue_size() test 1 failed; queue size is not 1.\n");
    }
    queue_enqueue(test5,2);
    result = queue_size(test5);
    if (result == 2) {
        printf("\nqueue_size() test 2 passed; queue size is 2.\n");
    }
    else{
        printf("\nqueue_size() test 2 failed; queue size is not 2.\n");
    }
    queue_enqueue(test5,7);
    result = queue_size(test5);;
    if (result == 3) {
        printf("\nqueue_size() test 3 passed; queue size is 3.\n");
    }
    else{
        printf("\nqueue_size() test 3 failed; queue size is not 3.\n");
    }
    free_queue(test5);
}

void queue_dequeue_test() {
    queue_t* test6 = create_queue(3);
    queue_enqueue(test6,1);
    queue_enqueue(test6,2);
    queue_enqueue(test6,7);
    if (queue_dequeue(test6)==1){
       printf("\nqueue_dequeue() test 1 passed; front with data '7' removed.\n");
    }
    else{
        printf("\nqueue_dequeue() test 1 failed; front with data '7' is not removed.\n");
    }
    if (queue_dequeue(test6)==2){
        printf("\nqueue_dequeue() test 2 passed; front with data '2' removed.\n");
    }
    else{
        printf("\nqueue_dequeue() test 2 failed; front with data '2' is not removed.\n");
    }
    if (queue_dequeue(test6)==7){
        printf("\nqueue_dequeue() test 3 passed; front with data '1' removed.\n");
    }
    else{
        printf("\nqueue_dequeue() test 3 failed; front with data '1' is not removed.\n");
    }
    free_queue(test6);
}


void queue_empty_dequeue_test() {
    queue_t* test7 = create_queue(3);
    if (queue_dequeue(test7) ==0){
     printf("\nqueue_dequeue() on empty queue test passed; method returns 0 when dequeueing an empty queue.\n");
    }
    else{
    printf("\nqueue_dequeue() on empty queue test failed; method does not return a 0 when dequeueing an empty queue.\n");
     }
    free_queue(test7);
}


void queue_full_enqueue_test() {
    queue_t* test8 = create_queue(3);
    queue_enqueue(test8,1);
    queue_enqueue(test8,2);
    queue_enqueue(test8,3);
    int result = queue_enqueue(test8,4);
    
    if (result ==0){
     printf("\nstack_enqueue() on full queue passed; method returns 0 when enqueueing a full queue.\n");
    }
    else{
    printf("\nqueue_dequeue() on full stack failed; method does not return a 0 when enqueueing a full queue.\n");
     }
    free_queue(test8);
}



// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){
    // List of Unit Tests to test your data structure
    create_queue_test();
    queue_empty_test();
    queue_full_test();
    queue_enqueue_test();
    queue_size_test();
    queue_dequeue_test();
    queue_empty_dequeue_test();
    queue_full_enqueue_test();
    
    printf("\n");
}
