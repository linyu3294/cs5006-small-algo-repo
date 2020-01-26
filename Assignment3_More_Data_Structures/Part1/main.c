// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "my_dll.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.

void create_dll_test(){
    dll_t* test1 = create_dll();
    if (test1 != NULL) {
        printf("\ncreate_dll() test passed; created a dll_t successfully.\n");
    }
    else {
        printf("\ncreate_dll() test failed; unable to created a dll_t.\n");
    }
    free_dll(test1);
}


void dll_size_test(){
    dll_t* test2 = create_dll();
    if (dll_size(test2) == 0){
        printf("\ndll_size() test 1 passed; Created a dll_t with size 0.\n");
    }
    else {
        printf("\ndll_size() test 1  failed; unable to create a dll_t with size 0.\n");
    }

    dll_push_front(test2, 1);
    if (dll_size(test2) == 1){
        printf("\ndll_size() test 2 passed; Created a dll_t with size 1.\n");
    }
    else {
        printf("\ndll_size() test 2 failed; unable to create a dll_t with size 1.\n");
    }
    
    dll_push_front(test2, 2);
    if (dll_size(test2) == 2){
        printf("\ndll_size() test 3 passed; Created a dll_t with size 2.\n");
    }
    else {
        printf("\ndll_size() test 3 failed; unable to create a dll_t with size 2.\n");
    }
    free_dll(test2);
}



void dll_empty_test(){
    dll_t* test3 = create_dll();
    if (dll_empty(test3)){
        printf("\ndll_empty() test 1 passed; a newly initiated dll_t is indeed empty.\n");
    }
    else {
        printf("\ndll_size() test 1  failed; a newly initiated dll_t is not empty.");
    }
    dll_push_front(test3, 1);
    dll_push_front(test3, 2);
    dll_pop_front(test3);
    dll_pop_front(test3);
   
    if (dll_empty(test3)){
        printf("\ndll_empty() test 2 passed; After pushing 2 nodes and popping two nodes, the dll indeed has count of 0.\n");
    }
    else {
          printf("\ndll_empty() test 2 failed; After pushing 2 nodes and popping two nodes, the dll does not have count of 0.\n");    }
    free_dll(test3);
}



void dll_push_front_test(){
    dll_t* test4 = create_dll();
    dll_push_front(test4, 3);
    if (test4->head->data == 3 &&
        test4->tail->data == 3 &&
        test4->head->next == NULL &&
        test4->head->previous == NULL &&
        test4->tail->next ==NULL &&
        test4->tail->previous == NULL
        ){
        printf("\ndll_push_front() test 1 passed; able to create a dll with one node as head and tail that point to null in both directions.\n");
    }
    else{
        printf("\ndll_push_front() test 1 failed; not able to create a dll with one node as head and tail that point to null in both directions.\n");
        }
    dll_push_front(test4, 5);
    if (test4->head->data == 5 &&
        test4->tail->data == 3 &&
        test4->head->next->data == 3  &&
        test4->head->previous == NULL &&
        test4->tail->next ==NULL &&
        test4->tail->previous->data == 5
        ){
            printf("\ndll_push_front() test 2 passed; able to create a dll with two nodes and verified correct data and neighbours for both.\n");
        }
    else{
            printf("\ndll_push_front() test 2 failed; not able to properly create a dll with two nodes becuase of incorrect data or incorrect neighbours, or both.\n");
    }
    free_dll(test4);
}



void dll_push_back_test(){
    dll_t* test5 = create_dll();
    dll_push_back(test5, 3);
    if (test5->head->data == 3 &&
        test5->tail->data == 3 &&
        test5->head->next == NULL &&
        test5->head->previous == NULL &&
        test5->tail->next ==NULL &&
        test5->tail->previous == NULL
        ){
        printf("\ndll_push_back() test 1 passed; able to create a dll with one node as head and tail that point to null in both directions.\n");
    }
    else{
        printf("\ndll_push_back() test 1 failed; not able to create a dll with one node as head and tail that point to null in both directions.\n");
        }
    dll_push_back(test5, 5);
    if (test5->tail->data == 5 &&
        test5->head->data == 3 &&
        test5->tail->previous->data == 3  &&
        test5->tail->next == NULL &&
        test5->head->previous ==NULL &&
        test5->head->next->data == 5
        ){
            printf("\ndll_push_back() test 2 passed; able to create a dll with two nodes and verified correct data and neighbours for both.\n");
        }
    else{
            printf("\ndll_push_back() test 2 failed; not able to properly create a dll with two nodes becuase of incorrect data or incorrect neighbours, or both.\n");
    }
    free_dll(test5);
}



void dll_pop_front_test(){
    dll_t* test6 = create_dll();
    dll_push_front(test6, 3);
    dll_push_front(test6, 5);
    int result = dll_pop_front(test6);
    if (test6->head->data == 3 &&
        test6->tail->data == 3 &&
        test6->head->next == NULL &&
        test6->head->previous == NULL &&
        test6->tail->next ==NULL &&
        test6->tail->previous == NULL &&
        result == 5
        ){
        printf("\ndll_pop_front() test 1 passed; able to verify removing a head node from a two-node dll.\n");
    }
    else{
        printf("\ndll_pop_front() test 1 failed; not able to verify removing a head node from a two-node dll.\n");
        }
    dll_pop_front(test6);
    if (test6->head==NULL &&
        test6->tail==NULL){
        printf("\ndll_pop_front() test 2 passed; able to verify removing the only node by pop front method.\n");
        }
    else{
        printf("\ndll_pop_front() test 2 failed; not able to verify removing the only node by pop front method.\n");
    }
    free_dll(test6);
}



void dll_pop_back_test(){
    dll_t* test7 = create_dll();
    dll_push_back(test7, 3);
    dll_push_back(test7, 5);
    int result = dll_pop_back(test7);
    if (test7->tail->data == 3 &&
        test7->head->data == 3 &&
        test7->head->next == NULL &&
        test7->head->previous == NULL &&
        test7->tail->next ==NULL &&
        test7->tail->previous == NULL &&
        result == 5
        ){
        printf("\ndll_pop_back() test 1 passed; able to verify removing a tail node from a two-node dll.\n");
       }
       else{
           printf("\ndll_pop_back() test 1 failed; not able to verify removing a tail node from a two-node dll.\n");
           }
       dll_pop_back(test7);
       if (test7->head==NULL &&
           test7->tail==NULL){
           printf("\ndll_pop_back() test 2 passed; able to verify removing the only node by pop back method.\n");
           }
       else{
           printf("\ndll_pop_back() test 2 failed; not able to verify removing the only node by pop back method.\n");
       }
    free_dll(test7);
}


void dll_get_middle_test(){
    dll_t* test8 = create_dll();
    dll_push_front(test8, 3);
    dll_push_front(test8, 5);
    dll_push_front(test8, 9);
    if (dll_get(test8, 1)==5){
        printf("\ndll_get() test 1 passed; able to retrieve an item between head and tail.\n");
    }
    else{
        printf("\ndll_get() test 1 failed; not able to retrieve an item between head and tail.\n");
    }
    free_dll(test8);
}


void dll_get_only_one_node_test(){
    dll_t* test9 = create_dll();
    dll_push_front(test9, 3);
    if (dll_get(test9, 0)==3){
        printf("\ndll_get() test 2 passed; able to retrieve an item when there is only one node in dll.\n");
    }
    else{
        printf("\ndll_get() test 2 failed; not able to retrieve the only node in dll.\n");
    }
    free_dll(test9);
}


void dll_get_pos_zero_test(){
    dll_t* test10 = create_dll();
    dll_push_front(test10, 3);
    dll_push_front(test10, 6);
    dll_push_front(test10, 8);
    dll_push_front(test10, 10);
    if (dll_get(test10, 0)==10){
        printf("\ndll_get() test 3 passed; able to retrieve an item at pos 0 in dll.\n");
    }
    else{
        printf("\ndll_get() test 3 failed; not able to retrieve an item at pos 0 in dll.\n");
    }
    free_dll(test10);
}


void dll_get_end_pos_test(){
    dll_t* test11 = create_dll();
    dll_push_front(test11, 3);
    dll_push_front(test11, 6);
    dll_push_front(test11, 8);
    dll_push_front(test11, 10);
    if (dll_get(test11, 3)==3){
        printf("\ndll_get() test 4 passed; able to retrieve an item at tail pos in dll.\n");
    }
    else{
        printf("\ndll_get() test 4 failed; not able to retrieve an item at tail pos in dll.\n");
    }
    free_dll(test11);
}



void dll_get_overcount_test(){
 dll_t* test12 = create_dll();
 dll_push_front(test12, 3);
 dll_push_front(test12, 6);
 dll_push_front(test12, 8);
 dll_push_front(test12, 10);
 if (dll_get(test12, 4)==-1){
     printf("\ndll_get() test 5 passed; returned -1 when retrieving a position past the size of the DLL .\n");
 }
 else{
     printf("\ndll_get() test 5 failed; -1 not returned when retrieving a position past the size of the DLL .\n");
 }
 free_dll(test12);
}


void dll_get_neg_pos_test(){
    dll_t* test13 = create_dll();
    dll_push_front(test13, 3);
    if (dll_get(test13, -1)==-1){
        printf("\ndll_get() test 6 passed; returned -1 when retrieving an item at a negative postion.\n");
    }
    else{
        printf("\ndll_get() test 6 failed; -1 not returned when retrieving an item at a negative position.\n");
    }
    free_dll(test13);
}



void null_dll_get_test(){
    dll_t* test14 = NULL;
    if (dll_get(test14, 0)==-1){
        printf("\ndll_get() test 7 passed; returned -1 when retrieving an item from a null dll.\n");
    }
    else{
        printf("\ndll_get() test 7 failed; -1 not returned when retrieving an item from a null dll.\n");
    }
}



void dll_insert_middle_test(){
    dll_t* test15 = create_dll();
    dll_push_front(test15, 7);
    dll_push_front(test15, 5);
    dll_push_front(test15, 2);
    int result = dll_insert(test15, 1, 3);
    if (test15->head->next->data == 3 && result ==1){
        printf("\ndll_insert() test 1 passed; able to insert an item in the middle of the dll.\n");
    }
    else{
        printf("\ndll_insert() test 1 failed; not able to insert an item in the middle of the dll.\n");
    }
    free_dll(test15);
}



void dll_insert_0_pos_test(){
    dll_t* test16 = create_dll();
    dll_push_front(test16, 7);
    int result = dll_insert(test16, 0, 3);
    if (test16->head->data == 3 && result ==1){
        printf("\ndll_insert() test 2 passed; able to insert an item in the 0 pos of the dll.\n");
    }
    else{
        printf("\ndll_insert() test 2 failed; not able to insert an item in the 0 pos of the dll.\n");
    }
    free_dll(test16);
}



void dll_insert_0_pos_empty_test(){
    dll_t* test17 = create_dll();
    int result = dll_insert(test17, 0, 3);
    printf("%d", test17->head->data == 3);
    if (test17->head->data == 3 && result ==1){
        printf("\ndll_insert() test 3 passed; able to insert an item in the 0 pos of an empty dll.\n");
    }
    else{
        printf("\ndll_insert() test 3 failed; not able to insert an item in the 0 pos of an empty dll.\n");
    }
    free_dll(test17);
}

void dll_insert_end_pos_test(){
    dll_t* test18 = create_dll();
    dll_push_front(test18, 3);
    dll_push_front(test18, 1);
    dll_push_front(test18, 6);
    dll_push_front(test18, 8);
    dll_push_front(test18, 5);
    dll_push_front(test18, 2);
    dll_push_front(test18, 1);
    int result = dll_insert(test18, 6, 9);
    if (test18->tail->data == 9 && result ==1){
        printf("\ndll_insert() test 4 passed; able to insert an item at the end pos of a loaded dll.\n");
    }
    else{
        printf("\ndll_insert() test 4 failed; not able to insert an item at the end pos of a loaded dll.\n");
    }
    free_dll(test18);
}

void dll_insert_end_pos_empty_test(){
    dll_t* test19 = create_dll();
    int result = dll_insert(test19, 0, 3);
    if (test19->head->data == 3 && result ==1){
        printf("\ndll_insert() test 5 passed; able to insert an item in the end pos of an empty dll.\n");
    }
    else{
        printf("\ndll_insert() test 5 failed; not able to insert an item in the end pos of an empty dll.\n");
    }
    free_dll(test19);
}

void dll_insert_negative_test(){
    dll_t* test20 = create_dll();
    dll_push_front(test20,  1);
    if (dll_insert(test20, -1, 3) == -1){
        printf("\ndll_insert() test 6 passed; inserting at a negative pos returns -1.\n");
    }
    else{
        printf("\ndll_insert() test 6 failed; inserting at a negative pos does not return -1.\n");
    }
    free_dll(test20);
}

void dll_insert_overcount_test(){
    dll_t* test21 = create_dll();
    dll_push_front(test21, 8);
    dll_push_front(test21, 4);
    dll_push_front(test21, 5);
    dll_push_front(test21, 6);
       if ( dll_insert(test21, 4, 3) == -1){
        printf("\ndll_insert() test 7 passed; inserting at a pos greater than the size of dll will return -1 .\n");
    }
    else{
        printf("\ndll_insert() test 7 failed; inserting at a pos greater than the size of dll does not return -1 .\n");
    }
    free_dll(test21);
}

void dll_insert_null_test(){
    dll_t* test22 = NULL;
       if ( dll_insert(test22, 0, 3) == -1){
        printf("\ndll_insert() test 8 passed; inserting an item to a null dll will return -1 .\n");
    }
    else{
        printf("\ndll_insert() test 8 failed; inserting an item to a null dll does not return -1 .\n");
    }
}


void dll_remove_middle_test(){
    dll_t* test23 = create_dll();
    dll_push_front(test23, 3);
    dll_push_front(test23, 4);
    dll_push_front(test23, 5);
    dll_push_front(test23, 2);
    int result = dll_remove(test23, 2);
    if (test23->head->data == 2 &&
        test23->head->next->data ==5 &&
        test23->head->next->next->data ==3 && result == 1){
        printf("\ndll_remove() test 1 passed; able to remove an item in the middle of the dll.\n");
    }
    else{
        printf("\ndll_remove() test 1 failed; not able to remove an item in the middle of the dll.\n");
    }
    free_dll(test23);
}


void dll_remove_0_pos_test(){
    dll_t* test24 = create_dll();
    dll_push_front(test24, 3);
    dll_push_front(test24, 4);
    dll_push_front(test24, 5);
    dll_push_front(test24, 2);
    int result = dll_remove(test24, 0);
    if (test24->head->data == 5 && result == 1){
        printf("\ndll_remove() test 2 passed; able to remove an item at the 0 pos of the dll.\n");
    }
    else{
        printf("\ndll_remove() test 2 failed; not able to remove an item at the 0 pos of the dll.\n");
    }
    free_dll(test24);
}

void dll_remove_0_pos_1node_test(){
    dll_t* test25 = create_dll();
    dll_push_front(test25, 3);
     printf("%d", test25->count);
    int result = dll_remove(test25, 0);
    
    if (test25->head ==NULL){printf("ert");}
//        &&
    if (  result ==1) {printf("ded");}
//          &&
    printf("%d", test25->count);
       if( dll_empty(test25)){
        printf("\ndll_remove() test 3 passed; able to remove an item at the 0 pos of a single node dll.\n");
    }
    else{
        printf("\ndll_remove() test 3 failed; not able to remove an item at the 0 pos of a single node dll.\n");
    }
    free_dll(test25);
}

void dll_remove_end_pos_test(){
    dll_t* test26 = create_dll();
    dll_push_front(test26, 6);
    dll_push_front(test26, 4);
    dll_push_front(test26, 5);
    dll_push_front(test26, 2);
    int result =dll_remove(test26, 3);
    if (test26->tail->data == 4 && result == 1){
        printf("\ndll_remove() test 4 passed; able to remove an item at the end pos of the dll.\n");
    }
    else{
        printf("\ndll_remove() test 4 failed; not able to remove an item at the end pos of the dll.\n");
    }
    free_dll(test26);
}


void dll_remove_negative_test(){
    dll_t* test27 = create_dll();
    dll_push_front(test27, 6);
    dll_push_front(test27, 8);
    dll_push_front(test27, 4);
    dll_push_front(test27, 2);
   
    if ( dll_remove(test27,-1) == -1){
        printf("\ndll_remove() test 5 passed; removing an item at a negative position returns -1.\n");
    }
    else{
        printf("\ndll_remove() test 5 failed; able to remove an item at the end pos of the dll.\n");
    }
    free_dll(test27);
}


void dll_remove_overcount_test(){
    dll_t* test27 = create_dll();
    dll_push_front(test27, 6);
    dll_push_front(test27, 8);
    dll_push_front(test27, 4);
    dll_push_front(test27, 2);

    if (dll_remove(test27,4) == -1){
        printf("\ndll_remove() test 6 passed; removing an item at a position larger than dll size will return -1.\n");
    }
    else{
        printf("\ndll_remove() test 6 failed; removing an item at a position larger than dll size will return -1.\n");
    }
    free_dll(test27);
    }


void dll_remove_null_test(){
    dll_t* test28 = NULL;
    if (dll_remove(test28,0) == -1){
        printf("\ndll_remove() test 7 passed; removing an item from a null dll reutrns -1.\n");
    }
    else{
        printf("\ndll_remove() test 7 failed; removing an item at an item from a null dll does not return -1.\n");
    }
}



// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){
    create_dll_test();
    dll_size_test();
    dll_empty_test();
    dll_push_front_test();
    dll_push_back_test();
    dll_pop_front_test();
    dll_pop_back_test();
    
    dll_get_middle_test();
    dll_get_only_one_node_test();
    dll_get_pos_zero_test();
    dll_get_end_pos_test();
    dll_get_overcount_test();
    dll_get_neg_pos_test();
    null_dll_get_test();
    
    dll_insert_middle_test();
    dll_insert_0_pos_test();
    dll_insert_0_pos_empty_test();
    dll_insert_end_pos_test();
    dll_insert_end_pos_empty_test();
    dll_insert_negative_test();
    dll_insert_overcount_test();
    dll_insert_null_test();
    
    dll_remove_middle_test();
    dll_remove_0_pos_test();
    dll_remove_0_pos_1node_test();
    dll_remove_end_pos_test();
    dll_remove_negative_test();
    dll_remove_overcount_test();
    dll_remove_null_test();
}
