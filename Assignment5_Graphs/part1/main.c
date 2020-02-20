// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "my_graph.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.

// ====================================================
// ================== Program Entry ===================
// ====================================================

void create_graph_test(){
    graph_t* graph_test1 = create_graph();
    if (graph_test1 != NULL &&
        graph_test1->allNodes !=NULL &&
        graph_test1->numNodes ==0 &&
        graph_test1->numEdges ==0)
    {printf("\ncreate_graph_test is successful. able to create a new graph.\n");}
    else{printf ("\ncreate_graph_test failed. not able to create a new graph.\n");}
    free_graph(graph_test1);
}


void graph_empty_test() {
    graph_t* graph_test2 = create_graph();
    int result1 = graph_empty(graph_test2);
    graph_add_node(graph_test2, 4);
    int result2 = graph_empty(graph_test2);
    
    if (result1 == 1 && result2 ==-1)
    {printf("\ngraph_empty test is successful. able to verify that a graph is empty when newly isntantiated and that it is not empty when a node is added to the graph.\n");
    }
    else{printf("\ngraph_empty test failed. unable to verify that a graph is empty when newly isntantiated and that it is not empty when a node is added to the graph.\n");}
    free_graph(graph_test2);
    
}


void create_single_node_test(){
    graph_t* graph_test3 = create_graph();
    gNode* new_g_node = newGraphNode(graph_test3, 3);
    
    if (new_g_node->connection->in_nodes !=        NULL &&
        new_g_node->connection->out_nodes != NULL &&
        new_g_node->data == 3
        )
    {printf ("\ncreate_single_node_test is successful. able to add a single node to a graph.\n");}
    else
    {printf ("\ncreate_single_node_test failed. not able to add a single node to a graph.\n");}
    free_graph(graph_test3);
}


void contains_node_test() {
    graph_t* graph_test4 = create_graph();
    graph_add_node(graph_test4, 3);
    graph_add_node(graph_test4, 5);
    if (contains_node(graph_test4, 3) ==1
        &&
        contains_node(graph_test4, 5) ==1
        &&
        contains_node(graph_test4, 9) ==-1
        )
    {printf("\ncontains_node_test is successful. able to verify that a graph contains the correct items.\n");}
    else {printf("\ncontains_node_test failed. not able to verify that a graph contains the correct items.\n");}
    free_graph(graph_test4);
}


void add_single_node_test(){
    graph_t* graph_test5 = create_graph();
    graph_add_node(graph_test5, 3);

    if (
        graph_test5->allNodes->count ==1 &&
        graph_test5->numNodes ==1 &&
        contains_node(graph_test5, 3) ==1
        )
    {printf ("\nadd_single_node_test is successful. able to add a single node to a graph.\n");}
    else
    {printf ("\nadd_single_node_test failed. not able to add a single node to a graph.\n");}
    free_graph(graph_test5);
}



void add_two_nodes_test(){
    graph_t* graph_test6 = create_graph();
    int result1 = graph_add_node(graph_test6, 3);
    int result2 = graph_add_node(graph_test6, 5);

    if (result1 ==1 && result2 ==1 &&
        graph_test6->allNodes->count ==2 &&
        graph_test6->numNodes ==2 &&
        contains_node(graph_test6, 3) ==1 &&
        contains_node(graph_test6, 5) ==1
    )
    {printf ("\nadd_two_nodes_test is successful. able to add two nodes to a graph.\n");}
    else
    {printf ("\nadd_two_nodes_test failed. not able to add two nodes to a graph.\n");}
    free_graph(graph_test6);
}


void add_duplicate_nodes_test(){
    graph_t* graph_test7 = create_graph();
    int result1 = graph_add_node(graph_test7, 3);
    int result2 = graph_add_node(graph_test7, 3);

    if (result1 ==1 && result2==-1 &&
        graph_test7->allNodes->count ==1 &&
        graph_test7->numNodes ==1 &&
        contains_node(graph_test7, 3) ==1 &&
        contains_node(graph_test7, 5) == -1
    )
        
    {printf ("\nadd_duplicate_nodes is successful. able to verify that duplicate nodes are not added to graph.\n");}
    else
    {printf ("\nadd_two_nodes_test failed. not able to verify that duplicate nodes are not added to graph.\n");}
    free_graph(graph_test7);
}


void contains_edge_test(){
    graph_t* graph_test8 = create_graph();
    graph_add_node(graph_test8, 3);
    graph_add_node(graph_test8, 7);

    graph_add_edge(graph_test8, 3, 7);
    if (contains_edge(graph_test8, 3, 7) == 1){
        printf("\ncontains_edge_test is succesful. able to verify that an edge exists.\n");
    }
    else {
        printf("\ncontains_edge_test failed. not able to verify that an edge exists.\n");
    }
    free_graph(graph_test8);
}


void add_edges_test(){
    graph_t* graph_test9 = create_graph();
    graph_add_node(graph_test9, 4);
    graph_add_node(graph_test9, 6);
    graph_add_node(graph_test9, 9);
    
    int result1 = graph_add_edge(graph_test9, 4, 6);
    int result2 = graph_add_edge(graph_test9, 6, 9);
    
    if (result1 ==1 && result2 ==1 &&
        contains_edge(graph_test9, 4, 6)==1
        &&
        contains_edge(graph_test9, 6, 9)==1
        &&
        graph_test9->numEdges ==2
        ){
    printf("\nadd_edges_test is succesful. able to add two edges.\n");
    }
    else {
    printf("\nadd_edges_test failed. not able to add two edges.\n");
    }
    free_graph(graph_test9);
}
    

void add_edge_with_no_src_test(){
    graph_t* graph_test10 = create_graph();
    graph_add_node(graph_test10, 4);
    graph_add_node(graph_test10, 6);

    int result = graph_add_edge(graph_test10, 3, 6);

    if (result == -1 &&
        contains_edge(graph_test10, 4, 6)== -1
      &&
        contains_edge(graph_test10, 3, 6)== -1
      &&
      graph_test10->numEdges ==0
      ){
    printf("\nadd_edge_with_no_src_test is succesful. able to verify that adding a edge with invalid source is not allowed.\n");
    }
    else {
    printf("\nadd_edge_with_no_src_test failed. not able to verify that adding a edge with invalid source is not allowed.\n");
    }
    free_graph(graph_test10);
}


void add_edge_with_no_des_test(){
    graph_t* graph_test11 = create_graph();
    graph_add_node(graph_test11, 4);
    graph_add_node(graph_test11, 6);

    int result = graph_add_edge(graph_test11, 4, 7);

    if (result ==-1 &&
        contains_edge(graph_test11, 4, 6)== -1
        &&
        contains_edge(graph_test11, 4, 6)== -1
        &&
      graph_test11->numEdges ==0
      ){
    printf("\nadd_edge_with_no_des_test is succesful. able to verify that adding a edge with invalid destination is not allowed.\n");
    }
    else {
    printf("\nadd_edge_with_no_des_test failed. not able to verify that adding a edge with invalid destination is not allowed.\n");
    }
    free_graph(graph_test11);
}


void remove_edges_test(){
    graph_t* graph_test12 = create_graph();
    graph_add_node(graph_test12, 4);
    graph_add_node(graph_test12, 6);
    graph_add_node(graph_test12, 9);

    graph_add_edge(graph_test12, 4, 6);
    graph_add_edge(graph_test12, 6, 9);
    
    int result1 = graph_remove_edge(graph_test12, 4, 6);
    int result2 = graph_remove_edge(graph_test12, 6, 9);
    
    if (result1 ==1 && result2 ==1 &&
        graph_test12->numEdges == 0
        && graph_test12->allNodes->head->g_node->connection->in_nodes->count ==0
        && graph_test12->allNodes->tail->g_node->connection->out_nodes->count ==0
        )
    {printf("\nremove_edges_test is succesful. able to remove edges.d.\n");
    }
    else {
    printf("\nremove_edges_test failed. not able remove edges.\n");
    }
    free_graph(graph_test12);
}


void remove_edge_with_no_des_test(){
    graph_t* graph_test13 = create_graph();
    graph_add_node(graph_test13, 4);
    graph_add_node(graph_test13, 6);
    graph_add_node(graph_test13, 9);

    graph_add_edge(graph_test13, 4, 6);
    graph_add_edge(graph_test13, 6, 9);
    
    int result1 = graph_remove_edge(graph_test13, 4, 6);
    int result2 = graph_remove_edge(graph_test13, 6, 10);
    
  
    if (result1 ==1 && result2 == -1 &&
        graph_test13->numEdges == 1
        && graph_test13->allNodes->head->next->g_node->connection->out_nodes->head->g_node->data ==9
        &&
        graph_test13->allNodes->head->g_node->connection->in_nodes->head->g_node->data == 6
        &&  graph_test13->allNodes->head->next->g_node->connection->in_nodes->head == NULL
        
        &&
        graph_test13->allNodes->tail->g_node->connection->out_nodes->head == NULL
        )
    {printf("\nremove_edge_with_no_des_test is succesful. able to confirm that removing edge with no destination is not allowed.\n");
    }
    else {
    printf("\nremove_edge_with_no_des_test failed. not able to confirm that removing edge with no destination is not allowed.\n");
    }
    free_graph(graph_test13);
}


void remove_edge_with_no_src_test(){
    graph_t* graph_test14 = create_graph();
    graph_add_node(graph_test14, 4);
    graph_add_node(graph_test14, 6);
    graph_add_node(graph_test14, 9);

    graph_add_edge(graph_test14, 4, 6);
    graph_add_edge(graph_test14, 6, 9);
    
    int result1 = graph_remove_edge(graph_test14, 2, 6);
    int result2 = graph_remove_edge(graph_test14, 6, 9);
    
    if (result1 == -1 && result2 == 1 &&
        graph_test14->numEdges == 1
        && graph_test14->allNodes->head->g_node->connection->in_nodes->head == NULL
        && graph_test14->allNodes->head->next->g_node->connection->out_nodes->head == NULL
        &&
        graph_test14->allNodes->head->next->g_node->connection->in_nodes->head->g_node->data== 4
        &&
        graph_test14->allNodes->tail->g_node->connection->out_nodes->head->g_node->data == 6
        )
    {printf("\nremove_edge_with_no_src_test is succesful. able to confirm that removing edge with no source is not allowed.\n");
    }
    else {
    printf("\nremove_edge_with_no_src_test failed. able to confirm that removing edge with no source is not allowed.\n");
    }
    free_graph(graph_test14);
}


void remove_single_node_test() {
    graph_t* graph_test15 = create_graph();
    graph_add_node(graph_test15, 3);
    graph_add_node(graph_test15, 5);
    graph_add_node(graph_test15, 8);
    
    graph_add_edge(graph_test15, 3, 5);
    graph_add_edge(graph_test15, 5, 8);

    int result1 = graph_remove_node(graph_test15, 3);
    
    if (result1 ==1 &&
        graph_test15->allNodes->count == 2
        &&
        graph_test15->numNodes == 2
        &&
        graph_test15->numEdges == 1
        &&
    graph_test15->allNodes->head->g_node->connection->in_nodes->head->g_node->data == 5
        &&

        graph_test15->allNodes->tail->g_node->data == 5
        &&
    graph_test15->allNodes->tail->g_node->connection->out_nodes->head->g_node->data ==8
    )
    {printf ("\nremove_single_node_test is succesful. able to remove a node and its edges if any exists.\n");}
    else
    {printf ("\nremove_single_node_test failed. not able to remove a node and its edges if any exists.\n");}
    free_graph(graph_test15);
}



void remove_two_nodes_test() {
    graph_t* graph_test16 = create_graph();
    graph_add_node(graph_test16, 3);
    graph_add_node(graph_test16, 5);
    graph_add_node(graph_test16, 8);
    
    graph_add_edge(graph_test16, 3, 5);
    graph_add_edge(graph_test16, 5, 8);

    int result1  = graph_remove_node(graph_test16, 3);
    int result2 = graph_remove_node(graph_test16, 5);
    
    if (result1 == 1 && result2 ==1 &&
        graph_test16->allNodes->count == 1
        &&
        graph_test16->numNodes == 1
        &&
        graph_test16->numEdges == 0
        &&
    graph_test16->allNodes->head->g_node->connection->in_nodes->head == NULL
        &&
    graph_test16->allNodes->tail->g_node->connection->out_nodes->head == NULL
        &&
        graph_test16->allNodes->head->g_node->data ==8
        &&
        graph_test16->allNodes->tail->g_node->data ==8
    )
    {printf ("\nremove_two_nodes_test is succesful. able to remove a node and its edges if any exists.\n");}
    else
    {printf ("\nremove_two_nodes_test failed. not able to remove a node and its edges if any exists.\n");}
    free_graph(graph_test16);
}



void remove_nonexisting_node_test() {
    graph_t* graph_test17 = create_graph();
    graph_add_node(graph_test17, 3);
    graph_add_node(graph_test17, 5);
    graph_add_node(graph_test17, 8);
    
    graph_add_edge(graph_test17, 3, 5);
    graph_add_edge(graph_test17, 5, 8);

    int result = graph_remove_node(graph_test17, 2);
    
    if (result == -1 &&
        graph_test17->allNodes->count == 3
        &&
        graph_test17->numNodes == 3
        &&
        graph_test17->numEdges == 2
    )
    {printf ("\nremove_nonexisting_node_test is succesful. able to verify that removing a nonexisting node is not allowed.\n");}
    else
    {printf ("\nremove_nonexisting_node_test failed. not able to verify that removing a nonexisting node is not allowed.\n");}
    free_graph(graph_test17);
}



void numNeighbors_test() {
    graph_t* graph_test18 = create_graph();
    graph_add_node(graph_test18, 3);
    graph_add_node(graph_test18, 5);
    graph_add_node(graph_test18, 8);
    graph_add_node(graph_test18, 2);
    
    graph_add_edge(graph_test18, 2, 8);
    graph_add_edge(graph_test18, 2, 3);
    graph_add_edge(graph_test18, 2, 5);
    graph_add_edge(graph_test18, 5, 2);
    graph_add_edge(graph_test18, 8, 2);

    int result1 = numNeighbors(graph_test18, 2);
    int result2 = numNeighbors(graph_test18, 5);
    int result3 = numNeighbors(graph_test18, 3);
    int result4 = numNeighbors(graph_test18, 8);
    
    if (result1 == 3 &&
        result2 == 1 &&
        result3 == 0 &&
        result4 == 1
    )
    {printf ("\nnumNeighbors_test is successful. able to get the correct number of neighbors.\n");}
    else
    {printf ("\nnnumNeighbors_test failed. not able to get the correct number of neighbors.\n");}
    free_graph(graph_test18);
}



void getNeighbors_test() {
    graph_t* graph_test19 = create_graph();
    graph_add_node(graph_test19, 3);
    graph_add_node(graph_test19, 5);
    graph_add_node(graph_test19, 8);
    graph_add_node(graph_test19, 2);
    
    graph_add_edge(graph_test19, 2, 8);
    graph_add_edge(graph_test19, 2, 3);
    graph_add_edge(graph_test19, 2, 5);
    graph_add_edge(graph_test19, 5, 2);
    graph_add_edge(graph_test19, 8, 2);

    int* testNeighArray = getNeighbors(graph_test19, 2);
    int i =0;
    int size = numNeighbors(graph_test19, 2);

    printf("\nNeighbour elements are: ");
    for(i = 0; i < size; i++)
    {
        printf("%d, ", testNeighArray[i]);
    }
    
    if (
        testNeighArray[0] == 5 &&
        testNeighArray[1] == 3 &&
        testNeighArray[2] == 8
    )
    {printf ("\ngetNeighbors_test is successful. able to get the correct neighbors of a node.\n");}
    else
    {printf ("\ngetNeighbors_test failed. not able to get the correct neighbors of a node.\n");}
    free_graph(graph_test19);
}


void graph_print_test() {
    graph_t* graph_test20 = create_graph();
    graph_add_node(graph_test20, 1);
    graph_add_node(graph_test20, 2);
    graph_add_node(graph_test20, 3);
    graph_add_node(graph_test20, 4);
    graph_add_node(graph_test20, 5);
    graph_add_node(graph_test20, 6);

    graph_add_edge(graph_test20, 1, 2);
    graph_add_edge(graph_test20, 1, 3);
    graph_add_edge(graph_test20, 3, 4);
    graph_add_edge(graph_test20, 3, 5);
    graph_add_edge(graph_test20, 4, 6);
    graph_add_edge(graph_test20, 3, 6);
    graph_add_edge(graph_test20, 5, 6);
    graph_add_edge(graph_test20, 2, 6);
   

    graph_print(graph_test20);
    {printf ("\nIf graph elements printed above conform to data in the test case, then graph_print_test passed, else failed.\n");}
  
    free_graph(graph_test20);
}


void is_reachable_test() {
    graph_t* graph_test21 = create_graph();
    graph_add_node(graph_test21, 1);
    graph_add_node(graph_test21, 2);
    graph_add_node(graph_test21, 3);
    graph_add_node(graph_test21, 4);
    graph_add_node(graph_test21, 5);
    graph_add_node(graph_test21, 6);

    graph_add_edge(graph_test21, 1, 1);
    graph_add_edge(graph_test21, 1, 2);
    graph_add_edge(graph_test21, 4, 6);
    graph_add_edge(graph_test21, 2, 3);
    graph_add_edge(graph_test21, 1, 3);
    graph_add_edge(graph_test21, 3, 4);
    graph_add_edge(graph_test21, 1, 0);
    
    int result1 = is_reachable(graph_test21, 1, 5);
    int result2 = is_reachable(graph_test21, 1, 6);
    int result3 = is_reachable(graph_test21, 1, 4);
    if (result1 == -1
        &&
        result2 ==0
        &&
        result3 ==0
        ){
        printf("\nis_reachable_test is successful. able to confirm reachability.\n");
    }
    else {printf("\nis_reachable_test failed. not able to confirm reachability.\n");
     }
    free(graph_test21);
}

void has_cycle_test() {
    graph_t* graph_test22 = create_graph();
    graph_add_node(graph_test22, 1);
    graph_add_node(graph_test22, 2);
    graph_add_node(graph_test22, 3);
    graph_add_node(graph_test22, 4);
    graph_add_node(graph_test22, 5);
    graph_add_node(graph_test22, 6);

    graph_add_edge(graph_test22, 2, 5);
    graph_add_edge(graph_test22, 1, 2);
    graph_add_edge(graph_test22, 2, 6);
    graph_add_edge(graph_test22, 2, 3);
    graph_add_edge(graph_test22, 3, 5);
    graph_add_edge(graph_test22, 5, 1);
    graph_add_edge(graph_test22, 3, 4);
    graph_add_edge(graph_test22, 4, 6);
    graph_add_edge(graph_test22, 5, 0);
////
    int result1 = has_cycle(graph_test22);
    int result2 = is_reachable(graph_test22, 1, 1);
    int result3 = is_reachable(graph_test22, 6, 6);
    
    if (result1 == 0 && result2 ==0 && result3 == -1){
        printf("\nhas_cycle_test is successful. able to confirm that has_cycle is working correctly.");
    }
    else {printf("\nhas_cycle_test failed. not able to confirm that has_cycle is working correctly.");
     }
    free(graph_test22);
}


void print_path_test() {
    graph_t* graph_test23 = create_graph();
    graph_add_node(graph_test23, 1);
    graph_add_node(graph_test23, 2);
    graph_add_node(graph_test23, 3);
    graph_add_node(graph_test23, 4);
    graph_add_node(graph_test23, 5);
    graph_add_node(graph_test23, 6);

    graph_add_edge(graph_test23, 2, 5);
    graph_add_edge(graph_test23, 1, 2);
    graph_add_edge(graph_test23, 2, 6);
    graph_add_edge(graph_test23, 2, 3);
    graph_add_edge(graph_test23, 3, 5);
    graph_add_edge(graph_test23, 5, 1);
    graph_add_edge(graph_test23, 3, 4);
    graph_add_edge(graph_test23, 4, 6);
    graph_add_edge(graph_test23, 5, 0);

//    print_path(graph_test23,3,3);
//    print_path(graph_test23,1,1);
    print_path(graph_test23,1,5);
    
    
    printf("\nIf graph elements printed above conform to data in the test case, then print_path passed, else failed.\n");
    
    free(graph_test23);
}


int main(){
    create_graph_test();
    graph_empty_test();
    create_single_node_test();
    contains_node_test();
    
    add_single_node_test();
    add_two_nodes_test();
    add_duplicate_nodes_test();
    
    contains_edge_test();
    
    add_edges_test();
    add_edge_with_no_src_test();
    add_edge_with_no_des_test();
    
    remove_edges_test();
    remove_edge_with_no_src_test();
    remove_edge_with_no_des_test();
    
    remove_single_node_test();
    remove_two_nodes_test();
    remove_nonexisting_node_test();

    numNeighbors_test();
    getNeighbors_test();
    graph_print_test();
    is_reachable_test();
    has_cycle_test();
    
    print_path_test();
    
    printf("\n");
}
