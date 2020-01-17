//
//  linkedlist_draft.c
//  helloworld.c
//
//  Created by Yu Lin on 1/14/20.
//  Copyright © 2020 Yu Lin. All rights reserved.


//Reference Source : used code from http://www.zentut.com/c-tutorial/c-linked-list/


#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int year;
    int wins;
    struct node* next;
}node_t;


node_t* create_node (int year , int wins, node_t* next) {

    node_t* new_node = (node_t*) malloc(sizeof(node_t));
    if (new_node == NULL) {
        printf("Unable to create a node.");
    }
    new_node -> year = year;
    new_node -> wins = wins;
    new_node -> next = next;
    return new_node;
}


node_t* create_list () {
    node_t* node5 = create_node(2014, 71, NULL);
    node_t* node4 = create_node(2015, 78, node5);
    node_t* node3 = create_node(2016, 93, node4);
    node_t* node2 = create_node (2017, 93, node3);
    node_t* node1 = create_node(2018, 108, node2);
    
    node_t* head_address = node1;
    return head_address;
}


void print_list(node_t* node_pointer) {
    if (node_pointer == NULL){
        return;
    }
    node_t* iter = node_pointer;
    while (iter != NULL) {
        printf("\nYear %d, %d wins.", (*iter).year, (*iter).wins);
        iter = iter->next;
    }
    printf("\n");
}


void free_list(node_t* node_pointer) {
    if (node_pointer == NULL) {
           printf("Unable to create a node.");
    }
    node_t* iter = node_pointer;
       while (iter != NULL) {
           node_t* temp = iter;
           free (iter);
           iter =(*temp).next;
       }
}


int main() {
    node_t* example = create_list();
    printf("%p", example);
    print_list(example);
    free_list(example);   
}


