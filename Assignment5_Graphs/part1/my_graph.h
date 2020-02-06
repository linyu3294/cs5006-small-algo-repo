// =================== Support Code =================
// Graph.
//
//
//
// - Implement each of the functions to create a working graph.
// - Do not change any of the function declarations
//   - (i.e. graph_t* create_graph() should not have additional arguments)
// - You should not have any 'printf' statements in your graph functions. 
//   - (You may consider using these printf statements to debug, but they should be removed from your final version)
// ==================================================
#ifndef MYGRAPH_H
#define MYGRAPH_H

// Create a neighbor data structure to server as the neighbor's list.
// In our case, we will stores 'integers' as our neighbors that 
// corresponding to the data that the actual nodes store.
typedef struct neighbor{
	int data;
	struct neighbor * next;
}neighbor_t;

// Create a node data structure to store data within
// our graph. In our case, we will stores 'integers'
// as our data in the nodes
typedef struct node{
	int data;
	struct node *next;
	struct neighbor * neighbor;
}node_t;

// Create a graph data structure
// Our graph keeps track of the number of nodes, the number of edges and an array
// of all the nodes in the graph, and the maximum number of nodes we store in our graph.
typedef struct graph{
	int numNodes;		
        int numEdges;
	node_t* nodes;	 //an array of nodes storing all of our nodes.
}graph_t;

// Creates a graph
// Returns a pointer to a newly created graph.
// The graph should be initialized with data on the heap.
// The graph fields should also be initialized to default values.
graph_t* create_graph(){
	// Modify the body of this function as needed.
	graph_t* myGraph= NULL;	

	return myGraph;
}

// Graph Empty
// Check if the graph is empty
// Returns 0 if true (The graph is completely empty, i.e. numNodes == 0 )
// Returns -1 if false (the graph has at least one node)
int graph_empty(graph_t* g){
	return -1;
}

// Adds a new node withe the correspoding item in the graph.
// Returns a -1 if the operation fails (otherwise returns 0 on success).
// (i.e. the memory allocation for a new node failed).
// Duplicates nodes should not be added. For a duplicate node returns 0.
int graph_add_node(graph_t* g, int item){
	return -1; 
}

// Removes the node from the graph and the corresponding edges connected 
// to the node.
// Returns a -1 if the operation fails (otherwise returns 0 on success).
// (the node to be removed doesn't exist in the graph).
int graph_remove_node(graph_t* g, int item){
	return -1; 
}

//Adds an edge from source to destination. 
//If source or desination is not found in the graph returns -1.
//Otherwise it returns 0 ( even for trying to add a duplicate edge )
int graph_add_edge(graph_t * g, int source, int destination){
	return -1;
}

//Removes an edge from source to destination. 
//If source or desination is not found in the graph returns -1.
//If no such edge exists also returns -1.
//Otherwise it returns 0
int graph_remove_edge(graph_t * g, int source, int destination){
	return -1;
}
//Returns 0 if the node with value is in the graph, otherwise returns -1;
int contains_node( graph_t * g, int value){
   	return -1;
}

//Returns 0 if an edge from source to destination exists, -1 otherwise.
int contains_edge( graph_t * g, int source, int destintaion){
	return -1;
}
//Returns an int array of all the neighbors of the node with data=value.
int * getNeighbors( graph_t * g, int value ){
	return NULL;
}

// Returns the number of neighbors for value.
int numNeighbors( graph_t * g, int value ){
	return 0;
}
	
// Prints the the graph using BFS
// For NULL or empty graph it should print nothing. 
void graph_print(graph_t * g){
	
}

// Graph Size
// Returns the number of nodes in the graph
unsigned int graph_num_nodes(graph_t* g){
	return 0;
}

// Graph Size
// Returns the number of edges in the graph
unsigned int graph_num_edges(graph_t* g){
	return 0;
}

// Free graph
// Removes a graph and ALL of its elements from memory.
// This should be called before the proram terminates.
void free_graph(graph_t* g){

}



#endif
