// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "mystack.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.


// A sample test of your program
// You need to add sufficient testing.
void create_stack_test(){
    stack_t* test1 = create_stack(MAX_DEPTH);
    if (test1 != NULL){
        printf("\ncreate_stack() test passed; New stack created successfully.\n");
    }
    else{
        printf("\ncreate_stack() test failed; Unable to create new stack.\n");
    }
    free(test1);
}

void stack_empty_test(){
    stack_t* test2 = create_stack(MAX_DEPTH);
    int result = stack_empty(test2);
    if (result==1){
        printf("\nstack_empty() test passed; New stack is empty.\n");
    }
    else {
        printf("\nstack_empty() test failed; New stack is not empty.\n");
    }
    free(test2);
}


void stack_full_test(){
    stack_t* test3 = create_stack(3);
    stack_enqueue(test3, 1);
    stack_enqueue(test3, 2);
    stack_enqueue(test3, 3);
    int result = stack_full(test3);
    if (result==1){
        printf("\nstack_empty() test passed; New stack is full.\n");
    }
    else {
        printf("\nstack_empty() test failed; New stack is not full.\n");
    }
 free(test3);   
}



void stack_enqueue_test() {
    stack_t* test4 = create_stack(3);
    stack_enqueue(test4,1);
    int result = test4->head->data;
    if (result == 1) {
        printf("\nstack_enqueue() test 1 passed; an item added.\n");
    }
    else{
        printf("\nstack_enqueue() test 1 failed; unable to add an item.\n");
    }
    stack_enqueue(test4,2);
    result = test4->head->data;
    if (result == 2) {
        printf("\nstack_enqueue() test 2 passed; a second item is added.\n");
    }
    else{
        printf("\nstack_enqueue() test 2 failed; unable to add a second item.\n");
    }
    stack_enqueue(test4,7);
    result = test4->head->data;
    if (result == 7) {
        printf("\nstack_enqueue() test 3 passed; a third item is added.\n");
    }
    else{
        printf("\nstack_enqueue() test 3 failed; unable to add a third item.\n");
    }
    free(test4);
}



void stack_size_test() {
    stack_t* test5 = create_stack(3);
    stack_enqueue(test5,1);
    int result = stack_size(test5);;
    if (result == 1) {
        printf("\nstack_size() test 1 passed; stack size is 1.\n");
    }
    else{
        printf("\nstack_size() test 1 failed; stack size is not 1.\n");
    }
    stack_enqueue(test5,2);
    result = stack_size(test5);
    if (result == 2) {
        printf("\nstack_size() test 2 passed; stack size is 2.\n");
    }
    else{
        printf("\nstack_size() test 2 failed; stack size is not 2.\n");
    }
    stack_enqueue(test5,7);
    result = stack_size(test5);;
    if (result == 3) {
        printf("\nstack_size() test 3 passed; stack size is 3.\n");
    }
    else{
        printf("\nstack_size() test 3 failed; stack size is not 3.\n");
    }
free(test5);
}

void stack_dequeue_test() {
    stack_t* test6 = create_stack(3);
    stack_enqueue(test6,1);
    stack_enqueue(test6,2);
    stack_enqueue(test6,7);
    if (stack_dequeue(test6)==7 && test6->head->data==2){
       printf("\nstack_dequeue() test 1 passed; head with data '7' removed.\n");
    }
    else{
        printf("\nstack_dequeue() test 1 failed; head with data '7' is not removed.\n");
    }
    if (stack_dequeue(test6)==2 && test6->head->data==1){
        printf("\nstack_dequeue() test 2 passed; head with data '2' removed.\n");
    }
    else{
        printf("\nstack_dequeue() test 2 failed; head with data '2' is not removed.\n");
    }
    if (stack_dequeue(test6)==1 && test6->head==NULL){
        printf("\nstack_dequeue() test 3 passed; head with data '1' removed.\n");
    }
    else{
        printf("\nstack_dequeue() test 3 failed; head with data '1' is not removed.\n");
    }
    free(test6);
}


void stack_empty_dequeue_test() {
    stack_t* test7 = create_stack(3);
    if (stack_dequeue(test7) ==0){
     printf("\nstack_dequeue() on empty stack test passed; method returns 0 when dequeueing an empty stack.\n");
    }
    else{
            
    printf("\nstack_dequeue() on empty stack test failed; method does not return a 0 when dequeueing an empty stack.\n");
     }
    free(test7);
    }

void stack_full_enqueue_test() {
    stack_t* test8 = create_stack(3);
    stack_enqueue(test8,1);
    stack_enqueue(test8,2);
    stack_enqueue(test8,3);
    int result = stack_enqueue(test8,4);
    
    if (result ==0){
     printf("\nstack_enqueue() on full stack passed; method returns 0 when enqueueing a full stack.\n");
    }
    else{
            
    printf("\nstack_dequeue() on full stack failed; method does not return a 0 when enqueueing a full stack.\n");
     }
free(test8); 
}

void free_stack_test() {
    stack_t* test9 = create_stack(3);
    stack_enqueue(test9,1);
    stack_enqueue(test9,2);
    stack_enqueue(test9,3);
    free(test9);
    printf("\n%lu", sizeof(test9));
    
    int* a = (int*)malloc(sizeof(int));
    free(a);
   printf("\n%lu", sizeof(*a));
    
    
    if (test9 == NULL){
        printf("\nfree_stack() test passed;\n");
    }
    else {
        printf("\nfree_stack() test failed;\n");
    }
    free(test9);
}

// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){
    // List of Unit Tests to test your data structure
    create_stack_test();
    stack_empty_test();
    stack_full_test();
    stack_enqueue_test();
    stack_size_test();
    stack_dequeue_test();
    stack_empty_dequeue_test();
    stack_full_enqueue_test();
    
    printf("\n");
    return 0;
}
