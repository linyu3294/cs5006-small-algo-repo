// Modify this file
// compile with: gcc linkedlist.c -o linkedlist

#include <stdio.h>
#include <stdlib.h> // contains the functions free/malloc

// Create your node_t type here


// Write your functions here
// There should be 1.) create_list 2.) print_list 3.) free_list
// You may create as many helper functions as you like.


//Reference Source : used code from http://www.zentut.com/c-tutorial/c-linked-list/


typedef struct node {
    int data;
    struct node* next;
}node_t;



node_t create_node (int data , node_t* next) {
    node_t* new_node = (node_t*) malloc(sizeof(node_t));
    if (new_node == null) {
        printf("Unable to create a node.")
    }
    new_node -> data = data;
    new_node -> next = next;
    return new_node;
}

void created_list () {
}

void print_list () {
    while
}

void free_list () {
}

void main(void) {

    node_head = create_node(5, &node_tail);
    node_tail = create_node (7, null);

    printf("Hello, World!\n");

}
