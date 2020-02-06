// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "my_bst.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.

// ====================================================
// ================== Program Entry ===================
// ====================================================

void bst_size_test(){
    bst_t* test1 = create_bst();
    bst_add(test1, 4);
    bst_add(test1, 3);
    bst_add(test1, 1);
    
    if (test1->count ==3){
        printf("\nbst_size_test passed. validated a bst object has the correct size.\n");
    }else {
         printf("\nbst_size_test failed. unable to validate a bst object has the correct size.\n");
    }
    free_bst(test1);
    
}


void bst_size0_test(){
    bst_t* test2 = create_bst();
    if (test2->count ==0){
        printf("\nbst_size0_test passed. validated a newly created bst object has the size 0.\n");
    }else {
         printf("\nbst_size0_test failed. unable to validate a newly created bst object has the size 0.\n");
    }
    free_bst(test2);
}


void bst_empty_test(){
    bst_t* test3 = create_bst();
    if (test3->count ==0 && bst_empty(test3)==1){
        printf("\nbst_empty_test passed. validated an empty bst object.\n");
    }else {
         printf("\nbst_empty_test failed. unable to validate an empty bst object.\n");
    }
    free_bst(test3);
}


void bst_not_empty_test(){
    bst_t* test4 = create_bst();
    bst_add(test4, 4);
    bst_add(test4, 3);
    bst_add(test4, 1);
    if (test4->count ==3 && bst_empty(test4)==0){
        printf("\nbst_not_empty_test passed. validated an loaded bst object is not empty.\n");
    }else {
        printf("\nbst_empty_test failed. unable to validate loaded bst object is not empty.\n");
    }
    free_bst(test4);
 }


void bst_print_ascend(){
    bst_t* test5 = create_bst();
    bst_add(test5, 3);
    bst_add(test5, 12);
    bst_add(test5, 58);
    bst_add(test5, 2);
    bst_add(test5, 4);
    bst_add(test5, 43);
    bst_add(test5, 39);
    bst_add(test5, 28);
    bst_add(test5, 42);
    bst_add(test5, 11);
    bst_add(test5, 13);
    bst_add(test5, 15);
    bst_print(test5, 0);
    printf("\nbst_print_ascend test passed if the results is displayed in ascending order and no number is missing. else failed.\n");
    free_bst(test5);
}
 

void bst_print_descend(){
    bst_t* test6 = create_bst();
    bst_add(test6, 3);
    bst_add(test6, 12);
    bst_add(test6, 58);
    bst_add(test6, 2);
    bst_add(test6, 4);
    bst_add(test6, 43);
    bst_add(test6, 39);
    bst_add(test6, 28);
    bst_add(test6, 42);
    bst_add(test6, 11);
    bst_add(test6, 13);
    bst_add(test6, 15);
    bst_print(test6, 1);
    printf("\nbst_print_descend test passed if the results is displayed in descending order and no number is missing. else failed.\n");
    free_bst(test6);
    }


void find_root_test(){
    bst_t* test7 = create_bst();
    bst_add(test7, 3);
    bst_add(test7, 12);
    bst_add(test7, 58);
    bst_add(test7, 1);
    bst_add(test7, 4);
    if (find(test7, 3)==1) {
        printf("\nfind_root_test test passed. able to find the root of a bst object.\n");
    }
    else{
        printf("\nfind_root_test test failed. unable to find the root of a bst object.\n");
    }
    free_bst(test7);
}


void find_largest_test(){
    bst_t* test8 = create_bst();
    bst_add(test8, 3);
    bst_add(test8, 12);
    bst_add(test8, 58);
    bst_add(test8, 1);
    bst_add(test8, 4);
    if (find(test8, 58)==1) {
        printf("\nfind_largest_test test passed. able to find the largest number of a bst object.\n");
    }
    else{
        printf("\nfind_largest_test test failed. unable to find the largest number of a bst object.\n");
    }
    free_bst(test8);
}


void find_middle_test(){
    bst_t* test9 = create_bst();
    bst_add(test9, 3);
    bst_add(test9, 12);
    bst_add(test9, 58);
    bst_add(test9, 1);
    bst_add(test9, 4);
    if (find(test9, 12)==1) {
       printf("\nfind_middle_test test passed. able to find a number neither smallest nor largest of a bst object.\n");
    }
    else{
       printf("\nfind_middle_test test failed. unable to find a number neither smallest nor largest of a bst object.\n");
    }
    free_bst(test9);
}


void find_in_null_tree_test(){
    bst_t* test10 = NULL;
    if (find(test10, 12)==-1) {
       printf("\nfind_in_null_tree_test test passed.able to validated that attempting to find a number in a null tree returns -1.\n");
    }
    else{
       printf("\nfind_in_null_tree_test test failed. unable to validated that attempting to find a number in a null tree returns -1.\n");
    }
}


void find_absent_number_test(){
    bst_t* test11 = create_bst();
    bst_add(test11, 3);
    bst_add(test11, 12);
    bst_add(test11, 58);
    bst_add(test11, 1);
    bst_add(test11, 4);
    if (find(test11, 14)==0) {
       printf("\nfind_absent_number_test passed. attempting to find an absent number returns a 0.\n");
    }
    else{
       printf("\nfind_absent_number_test failed. attempting to find an absent number does not return 0.\n");
    }
    free_bst(test11);
}


void find_smallest_test(){
    bst_t* test12 = create_bst();
    bst_add(test12, 3);
    bst_add(test12, 12);
    bst_add(test12, 58);
    bst_add(test12, 1);
    bst_add(test12, 4);
    if (find(test12, 1)==1) {
        printf("\nfind_smallest_test test passed. able to find the smallest number of a bst object.\n");
    }
    else{
        printf("\nfind_smallest_test test failed. unable to find the smallest number of a bst object.\n");
    }
    free_bst(test12);
}


void sum_test(){
    bst_t* test13 = create_bst();
    bst_add(test13, 3);
    bst_add(test13, 12);
    bst_add(test13, 58);
    bst_add(test13, 1);
    bst_add(test13, 4);
    if (sum(test13)==78) {
        printf("\nsum_test test passed. adding up all the nodes in the tree produces the correct outcome.\n");
    }
    else{
        printf("\nsum_test test failed. adding up all the nodes in the tree does not produce the correct outcome.\n");
    }
    free_bst(test13);
}


void bst_add_root(){
    bst_t* test14 = create_bst();
    bst_add(test14, 3);
    if (test14->root->data==3) {
        printf("\nbst_add_root test test passed. Aale to add a single leaf.\n");
    }
    else{
        printf("\nbst_add_root test test failed. not able to add a single leaf.\n");
    }
    free_bst(test14);
}


void bst_add_test(){
    bst_t* test15 = create_bst();
    bst_add(test15, 3);
    bst_add(test15, 2);
    bst_add(test15, 4);
    bst_add(test15, 43);
    bst_add(test15, 39);
    bst_add(test15, 28);
    if (
        test15->root->data==3 &&
        test15->root->leftChild->data == 2 &&
        test15->root->rightChild->data ==4 &&
        test15->root->rightChild->rightChild->data ==43 &&
        test15->root->rightChild->rightChild->leftChild->data ==39 &&
        test15->root->rightChild->rightChild->leftChild->leftChild->data==28
        )
    {
        printf("\nbst_add test test passed. able to add multiple leafs in the correct positions.\n");
    }
    else{
        printf("\nbst_add test test failed. not able to add multiple leafs in the correct positions.\n");
    }
    free_bst(test15);
}

void bst_add_duplicate() {
    bst_t* test16 = create_bst();
    bst_add(test16, 3);
    bst_add(test16, 2);
    bst_add(test16, 2);
    bst_add(test16, 4);
    bst_add(test16, 4);
    bst_add(test16, 43);
    printf("%d", test16->count);
    if (test16->count == 4){
        printf("\nbst_add_duplicate test passed. able to omitt duplicate items when adding them to bst.");
    }
    else { printf("\nbst_add_duplicate test failed. unable to omitt duplicate items when adding them to bst.");
        
    }
    free_bst(test16);
}

int main(){
    bst_size_test();
    bst_empty_test();
    bst_size0_test();
    bst_print_ascend();
    bst_print_descend();
    find_root_test();
    find_largest_test();
    find_middle_test();
    find_smallest_test();
    find_root_test();
    sum_test();
    bst_add_root();
    bst_add_test();
    bst_add_duplicate();
}
