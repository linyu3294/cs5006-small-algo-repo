//Yu Lin
//Course CS5006
//Date 01/13/2020

//Reference Source : used code from http://www.zentut.com/c-tutorial/c-linked-list/


#include "library.h"

#include <stdio.h>

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


void iterate_linked_list () {
    while
}

void main(void) {

    node_head = create_node(5, &node_tail);
    node_tail = create_node (7, null);

    printf("Hello, World!\n");

}
