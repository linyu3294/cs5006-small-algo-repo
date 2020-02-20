// ==================================================
// - Sections I.
// - The first section implements the queue which will then be used in BFS to traverse the graph.
// - In the second section, graph will be using Linked List.
// ==================================================//

#define QSIZE 100
typedef struct queue {
    int items[QSIZE];
    int head;
    int tail;
}queue_t;


queue_t* createQueue() {
    queue_t* newQueue = (queue_t*)malloc(sizeof(queue_t));
    newQueue->head = -1;
    newQueue->tail = -1;
    return newQueue;
}


int isEmpty(struct queue* q) {
    if(q->tail == -1)
        return 1;
    else
        return 0;
}

void enqueue(struct queue* q, int value){
    if(q->tail == QSIZE-1)
        printf("\nNO MORE ROOM IN QUEUE!!");
    else {
        if(q->head == -1){
            q->head = 0;
        }
        q->tail++;
        q->items[q->tail] = value;
    }
}

int dequeue(struct queue* q){
    int item;
    if(isEmpty(q)){
//        printf("Queue is empty");
        item = -1;
    }
    else{
        item = q->items[q->head];
        q->head++;
        if(q->head > q->tail){
//            printf("Resetting queue");
            q->head = q->tail = -1;
        }
    }
    return item;
}

void printQueue(struct queue *q) {
    int i = q->head;

    if(isEmpty(q)) {
        printf("Queue is empty");
    } else {
        printf("\nQueue contains \n");
        for(i = q->head; i < q->tail + 1; i++) {
                printf("%d ", q->items[i]);
        }
    }
}

void free_queue(queue_t* q) {
    free(q);
}



// ==================================================
// - Sections II.
// - The second section implements the double linked list.
// - In the second section, graph will be using Linked List.
// ==================================================


#ifndef MYGRAPH_H
#define MYGRAPH_H


// Create a node data structure to store data within
// our graph. In our case, we will stores 'integers'
// as our data in the nodes
typedef struct node{
    int data;
    struct neighbor * connection;
}gNode;


// A structure to represent a double linked list node.
typedef struct dllNode
{
    gNode* g_node;
    struct dllNode* next;
    struct dllNode* prv;
}dllNode;
  
// A structure to represent an double linked list.
typedef struct DLL{
    int count;        // count keeps track of how many items are in the DLL.
    struct dllNode* head;        // head points to the first node in our DLL.
    struct dllNode* tail;          //tail points to the last node in our DLL.
}dll_t;
  
  
// A utility function to create a new double linked list node
dllNode* newDllNode()
{
    struct dllNode* newNode = (struct dllNode*) malloc(sizeof(struct dllNode));
    if (newNode == NULL) {return NULL;}
    newNode->g_node = NULL;
    newNode->next = NULL;
    newNode->prv  = NULL;
    return newNode;
}


// Creates a DLL
// Returns a pointer to a newly created DLL.
// The DLL should be initialized with data on the heap.
// (Think about what the means in terms of memory allocation)
// The DLLs fields should also be initialized to default values.
dll_t* newDll(){
    // Modify the body of this function as needed.
    dll_t* myDLL= NULL;
    myDLL = (dll_t*)malloc(sizeof(dll_t));
    
    myDLL->head=NULL;
    myDLL->tail=NULL;
    myDLL->count = 0;
    
    return myDLL;
}


// Returns the item at position pos starting at 0 (0 being the first item )
int dll_get_pos(dll_t* l, int item){
    int i=0;
    int count =0;
    dllNode* iter = l->head;
    for (i=0; i<l->count; i++){
       
        if (iter->g_node->data ==item)
        {break;}
        iter = iter->next;
        count++;
    }
    return count;
}


// This is a helper function that checks
// if an interger value is contained in the graph node
// within the double linked list.
int dll_check(dll_t* l, int item){
    if (l==NULL){
        return -1;
    }
    dllNode* iter = l->head;
    int i=0;
    for (i=0; i<l->count; i++){
        iter = iter->next;
        if (iter->g_node->data == item){
            return 1;
        }
    }
    return -1;
}
    


// push a new item to the front of the DLL ( before the first node in the list).
// Returns a -1 if the operation fails ( and if the DLL is NULL), otherwise returns 1 on success.
// (i.e. the memory allocation for a new node failed).
int dll_push_front(dll_t* l, gNode* new_g_node){
    if (l == NULL){
        return -1;
    }
    dllNode* newDLLNode = (dllNode*)malloc(sizeof(dllNode));
    if (newDLLNode == NULL ){
        return -1;
    }
    if (new_g_node == NULL){
        return -1;
    }

    newDLLNode->g_node= new_g_node;
    if (l->count == 0){
        newDLLNode->next = NULL;
        newDLLNode->prv = NULL;

        l->head = newDLLNode;
        l->tail = newDLLNode;
        l->count = 1;
    }
    else {
        newDLLNode->prv = NULL;
        newDLLNode->next = l->head;
        l->head->prv = newDLLNode;
        l->head = newDLLNode;
        l->count++;
    }
    return 1;
}


// Returns the first item in the DLL and also removes it from the list.
// Returns a -1 if the operation fails (and if the DLL is NULL). Assume no negative numbers in the list.
int dll_pop_front(dll_t* t){
    if (t==NULL){
        return -1;
    }
    if (t->count == 0){
        return -1;
    }
    int rem_item = t->head->g_node->data;
    if (t->count ==1) {
        free(t->head);
        t->head = NULL;
        t->tail = NULL;
    }
    else if(t->count >1){
        dllNode* temp = t->head->next;
        free(t->head);
        t->head = temp;
        t->head->prv= NULL;
    }
    t->count--;
    return rem_item;
    }
    

// Returns the last item in the DLL, and also removes it from the list.
// Returns a -1 if the operation fails (and if the DLL is NULL). Assume no negative numbers in the list.
int dll_pop_back(dll_t* t){
    if (t==NULL){
        return -1;
    }
    if (t->count == 0){
        return -1;
    }
    int rem_item = t->tail->g_node->data;
    if (t->count ==1) {
        free(t->tail);
        t->head = NULL;
        t->tail = NULL;
    }
    else if (t->count>1){
        dllNode* temp = t->tail->prv;
        free(t->tail);
        t->tail = temp;
        t->tail->next = NULL;
    }
    t->count--;
    return rem_item;
}


// Removes the item at position pos starting at 0 ( 0 being the first item )
// Returns a -1 if the operation fails (and if the DLL is NULL).
// (i.e. trying to remove at a negative position or at a position past the size of the DLL ).
// Think testcases here.
int dll_remove(dll_t* l, int pos){
    if (l==NULL || pos<0 || pos>l->count-1 || l-> count ==0){
        return -1;
    }

    int rem_item =0;
    if (pos==0 && l->count>=1){
        return (dll_pop_front(l));}
    else if(pos==l->count-1){
        return(dll_pop_back(l));}
    else{
        dllNode* iter = l->head;
        int i =0;
        for (i=0; i<pos; i++){
            iter = iter->next;
        }
        rem_item = iter->g_node->data;
        iter->prv->next=iter->next;
        iter->next->prv=iter->prv;
        free(iter);
        l->count--;
    }
    return rem_item;
}


// Free DLL
// Removes a DLL and ALL of its elements from memory.
// This should be called before the proram terminates.
void free_dll(dll_t* t){
    dllNode* iter = t->head;
    while (iter != NULL){
        dllNode* temp= iter-> next ;
        free(iter);
        t->head = temp;
        iter = t->head;
    }
    free(t);
}


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

//==================================================
// - Sections III.
//
// - This section implements the actual graph.
// ==================================================


// Create a neighbor data structure to server as the neighbor's list.
// In our case, we will stores 'integers' as our neighbors that
// corresponding to the data that the actual nodes store.
typedef struct neighbor{
    dll_t * in_nodes;
    dll_t * out_nodes;
}neighbor_t;


// Our graph keeps track of the number of nodes, the number of edges and an array
// of all the nodes in the graph.
typedef struct graph{
    int numNodes;
    int numEdges;
    dll_t* allNodes;     //an array of nodes storing all of our nodes.
}graph_t;

  
// Creates a graph
// Returns a pointer to a newly created graph.
// The graph should be initialized with data on the heap.
// The graph fields should also be initialized to default values.
graph_t* create_graph(){
    graph_t* newGraph = (graph_t*) malloc(sizeof(graph_t));
    if (newGraph ==NULL) {return NULL;}
    newGraph->allNodes = newDll();
    newGraph->numEdges = 0;
    newGraph->numNodes = 0;
    return newGraph;
}


// A Helper function for creating new nodes.
gNode* newGraphNode (graph_t* g, int item) {
    if(g == NULL) {return NULL;}
    gNode* new_g_node = (gNode*) malloc(sizeof(gNode));
    
    new_g_node->connection = (neighbor_t*) malloc(sizeof(neighbor_t));
    new_g_node->data = item;
    new_g_node->connection->in_nodes = newDll();
    new_g_node->connection->out_nodes = newDll();
    return new_g_node;
}

// Graph Empty
// Check if the graph is empty
// Returns >=0 if true (The graph is completely empty, i.e. numNodes == 0 )
// Returns -1 if false (the graph has at least one node)
int graph_empty(graph_t* g){
    if (g==NULL) {return 1;}
    if (g->numNodes <=0) {
        return 1;
    }
    return -1;
}


//Returns >=0 if the node with value is in the graph, otherwise returns -1;
int contains_node( graph_t * g, int value){
    dllNode* iter = g->allNodes->head;
    
    while(iter != NULL ){
        if (iter->g_node->data == value){
            return 1;
        }
        iter = iter->next;
    }
    return -1;
}


// Adds a new node withe the correspoding item in the graph.
// Returns a -1 if the operation fails or has duplicate node. (otherwise returns >=0 on success)
// (i.e. the memory allocation for a new node failed).
int graph_add_node(graph_t* g, int item){
    if (g==NULL){return -1;}
    if (contains_node(g, item) ==-1){
        gNode* new_g_node = newGraphNode(g, item);
        if (new_g_node == NULL){return -1;}
        dll_push_front(g->allNodes, new_g_node);
        g->numNodes = g->allNodes->count;
        return 1;
    }
    return -1;
}


// This is a helper function that fetches the node based on the value.
// It assumes that the graph already contains the node.
gNode* dll_get(dll_t* l, int pos){
    if (l==NULL || pos<0 || pos>l->count){
        return NULL;
    }
    dllNode* iter = l->head;
    int i=0;
    for (i=0; i<pos; i++){
        iter = iter->next;
        }
    if (iter== NULL){return NULL;}
    return iter->g_node;
}



//Returns >=0 if an edge from source to destination exists, -1 otherwise.
int contains_edge( graph_t * g, int source, int destintaion){
    int checkSrcToDes = 0;
    int checkDesFromSrc = 0;
    int foundSrcPos = dll_get_pos(g->allNodes, source);
    int foundDesPos = dll_get_pos(g->allNodes, destintaion);
    
    gNode* foundSrcNode = dll_get(g->allNodes, foundSrcPos);
    gNode* foundDesNode = dll_get(g->allNodes, foundDesPos);

    if (foundSrcNode == NULL ||foundDesNode == NULL){return -1;}
    
    dllNode* srcIter = foundSrcNode->connection->out_nodes->head;
    while(srcIter != NULL ){
           if (srcIter->g_node->data ==destintaion){
               checkSrcToDes=1; break;
         }
         srcIter = srcIter->next;
     }
  
    dllNode* desIter = foundDesNode->connection->in_nodes->head;
    while(desIter != NULL ){
           if (desIter->g_node->data ==source){
               checkDesFromSrc=1; break;
         }
         desIter = desIter->next;
     }
    
    if (checkSrcToDes ==1 && checkDesFromSrc ==1) {return 1;}
    return -1;
}


//Adds an edge from source to destination.
//If source or desination is not found, or the edge already exists in the graph returns -1.
//Otherwise it returns >= 0
int graph_add_edge(graph_t * g, int source, int destination){
    if (contains_node(g, source) == -1 ||
        contains_node(g, destination) == -1 ||
        contains_edge(g, source, destination) == 1){
        return -1;
    }
    
    int srcPos = dll_get_pos(g->allNodes,source);
    gNode* srcNode = dll_get(g->allNodes,srcPos);
    int desPos = dll_get_pos(g->allNodes, destination);
    gNode* desNode = dll_get(g->allNodes,desPos);
   
    dll_push_front((srcNode->connection->out_nodes), desNode);
    dll_push_front((desNode->connection->in_nodes), srcNode);
    
    g->numEdges++;
    return 1;
}


//Removes an edge from source to destination.
//If source or desination is not found in the graph returns -1.
//If no such edge exists also returns -1.
//Otherwise it returns >=0
int graph_remove_edge(graph_t * g, int source, int destination){
    if (contains_node(g, source) == -1 ||
        contains_node(g, destination) == -1 ||
        contains_edge(g, source, destination) == -1){
        return -1;
    }
    
    int srcPos = dll_get_pos(g->allNodes,source);
    gNode* srcNode = dll_get(g->allNodes,srcPos);
    
    int desPos = dll_get_pos(g->allNodes, destination);
    gNode* desNode = dll_get(g->allNodes,desPos);
    
    
    int srcOutPos = dll_get_pos(srcNode->connection->out_nodes, destination);
    int desInPos = dll_get_pos(desNode->connection->in_nodes, source);
      
    
    dll_remove((srcNode->connection->out_nodes), desInPos);
    dll_remove((desNode->connection->in_nodes), srcOutPos);
    g->numEdges--;
    return 1;
    }


// Removes the node from the graph and the corresponding edges connected
// to the node.
// Returns a -1 if the operation fails (otherwise returns >=0 on success).
// (the node to be removed doesn't exist in the graph).
int graph_remove_node(graph_t* g, int item){
    if (g == NULL) {return -1;}
    if (contains_node(g, item) == -1
        ){return -1;}
    dllNode* iter = g->allNodes->head;
        while(iter != NULL ){
            graph_remove_edge(g, item, iter->g_node->data);
            graph_remove_edge(g, iter->g_node->data, item);
            iter = iter->next;}
    int removePos = dll_get_pos(g->allNodes, item);
        dll_remove(g->allNodes, removePos);
        g->numNodes--;
        return 1;
}


// This is a helper function that determines if an item is found in the record of visted items.
// Returns 1 if an item has been visited else return -1;
int visited(char* visitedArray, int size, int item) {
    int i = 0;
    for (i=0; i<size; i++) {
        if (visitedArray[i] == item+'0'){
               return 1;
        }
    }
      return -1;
}


// Prints the the graph using BFS
// For NULL or empty graph it should print nothing.
void graph_print(graph_t * g){
    if(g->numNodes ==0){return;}
    queue_t* q = createQueue();
    
    char visits [g->numNodes];
    int u = 0;
    for (u=0; u<g->numNodes; ++u)
        {visits[u] = 'f';}
    
    dllNode* start = g->allNodes->head;
    while(start != NULL ){
        if(start->g_node->connection->in_nodes->count==0){break;}
        start = start->next;
    }
    
    char* visitPointer = visits;
    enqueue(q, start->g_node->data);
    visits [0] =start->g_node->data + '0';
    int track = 1;
//    printQueue(q);
    
    while (!isEmpty(q)) {
        int currPos = dll_get_pos(g->allNodes,q->items [q->head]);
        gNode* currNode = dll_get(g->allNodes,currPos);
        dllNode* childrenIter = currNode->connection->out_nodes->tail;
        
        while(childrenIter != NULL ){
            int nodeData = childrenIter->g_node->data;
//            printf("\ncurrent node: %d      ||     child node: %d\n", currNode->data, nodeData);
            
                if (visited(visitPointer, g->numNodes, nodeData) == -1){
                    enqueue(q, nodeData);
                    visits[track] = nodeData + '0';
                    track++;
                }
            
            childrenIter = childrenIter->prv;
            
        }
        printf("\nThe current Node of the Graph is : %d \n", dequeue(q));
    }
    free_queue(q);
}



// Returns the number of neighbors for value.
int numNeighbors( graph_t * g, int value ){
    int nodePos = dll_get_pos(g->allNodes, value);
    gNode* srcNode = dll_get(g->allNodes, nodePos);
    int neibCount = srcNode->connection->out_nodes->count;
    return neibCount;
}
    



//Returns an int array of all the neighbors of the node with data=value.
int * getNeighbors( graph_t * g, int value ){
    int neibCount = numNeighbors(g, value);
    int neigh [neibCount];
    int* neighPointer = neigh;
    
    int nodePos = dll_get_pos(g->allNodes, value);
    gNode* srcNode = dll_get(g->allNodes, nodePos);
    
    dllNode* iter = srcNode->connection->out_nodes->head;
    int i =0;
    for (i =0; i<neibCount; ++i ){
        neigh[i] = iter->g_node->data;
            iter = iter->next;
        }
    return neighPointer;
}



// Graph Size
// Returns the number of nodes in the graph
unsigned int graph_num_nodes(graph_t* g){
    if (g == NULL){return -1;}
    else {return g->numNodes;}
    return 0;
}

         
// Graph Size
// Returns the number of edges in the graph
unsigned int graph_num_edges(graph_t* g){
    if (g == NULL){return -1;}
    else {return g->numEdges;}
    return 0;
}


//------------PART 2------------
         

// This is a heler method that traverses neibghbors recursivesly.
    
int recur_find(dllNode* child, int value){
    if (child->g_node->data == value) {
           return 1;
       }
    else if (child == NULL){
        return -1;}
    else {
            if(child->g_node->connection->out_nodes->head != NULL){
                return (recur_find( child->g_node->connection->out_nodes->head, value));
            }
        
        }
    return -1;
}

         
// returns 0 if I can reach the destination from source,
// -1 otherwise ( using BFS)
int is_reachable(graph_t * g, int source, int dest){
    if (g->numNodes ==0 ||
        contains_node(g, source) == -1 ||
        contains_node(g, dest) == -1 ){
           return -1;
       }
    if (contains_edge(g, source, dest)==1){
        return 0;
    }
    dllNode* srcNode = g->allNodes->head;
    while (srcNode != NULL){
        if (srcNode->g_node->data == source){
            break;
        }
        srcNode =srcNode->next;
    }
        queue_t* q = createQueue();

        char visits [g->numNodes];
        int u = 0;
        for (u=0; u<g->numNodes; ++u)
           {visits[u] = 'f';}

        char* visitPointer = visits;
        enqueue(q, srcNode->g_node->data);
        int track = 0;
        int pin = 0;
        
        while (!isEmpty(q)) {
            int currPos = dll_get_pos(g->allNodes,q->items [q->head]);
            gNode* currNode = dll_get(g->allNodes,currPos);
            dllNode* childrenIter = currNode->connection->out_nodes->tail;
            
            while(childrenIter != NULL ){
                int nodeData = childrenIter->g_node->data;
                if (visited(visitPointer, g->numNodes, nodeData) == -1){
                    enqueue(q, nodeData);
                    visits[track] = nodeData + '0';
                    track++;
                }
                
                childrenIter = childrenIter->prv;
                
            }
            if (source != dest && dequeue(q) ==dest){return 0;}
            if (source == dest && dequeue(q) ==dest) {pin ++;}
            if (pin == 2){return 0;}
        }
        free_queue(q);

    return -1;
}

// returns 0 if there is a cycle in the graph, -1 otherwise (using BFS or DFS)
int has_cycle(graph_t * g) {
    if (g == NULL || g->numEdges <1 || g->numNodes <1){
        return -1;
    }
    dllNode* eachNode = g->allNodes->head;
    while (eachNode != NULL){
        if (is_reachable(g, eachNode->g_node->data, eachNode->g_node->data)==0){
            return 0;
        }
        eachNode=eachNode->next;
    }
    return -1;
}



// prints any path from source to destination if there exists one
// (Choose either BFS or DFS, typically DFS is much simpler)
int print_path(graph_t * g, int source, int dest) {
if (is_reachable(g, source, dest)!= 0){return -1;}

    dllNode* srcNode = g->allNodes->head;
    while (srcNode != NULL){
        if (srcNode->g_node->data == source){
            break;
        }
        srcNode =srcNode->next;
    }
        queue_t* q = createQueue();

        char visits [g->numNodes];
        int u = 0;
        for (u=0; u<g->numNodes; ++u)
           {visits[u] = 'f';}

        char* visitPointer = visits;
        enqueue(q, srcNode->g_node->data);
        int track = 0;
        int pin = 0;
        
        while (!isEmpty(q)) {
            int currPos = dll_get_pos(g->allNodes,q->items [q->head]);
            gNode* currNode = dll_get(g->allNodes,currPos);
            dllNode* childrenIter = currNode->connection->out_nodes->tail;
            
            while(childrenIter != NULL ){
                int nodeData = childrenIter->g_node->data;
                if (visited(visitPointer, g->numNodes, nodeData) == -1){
                    enqueue(q, nodeData);
                    visits[track] = nodeData + '0';
                    track++;
                }
                
                childrenIter = childrenIter->prv;
                
            }
            
          printf(" => %d ", dequeue(q));
        }
        free_queue(q);

    return -1;
}

// Free graph
// Removes a graph and ALL of its elements from memory.
// This should be called before the proram terminates.
void free_graph(graph_t* g){
    dllNode* iter = g->allNodes->head;
    while(iter != NULL){
        dllNode* tempdllNode = iter->next;
    free_dll(iter->g_node->connection->in_nodes);
        free_dll (iter->g_node->connection->out_nodes);
        free(iter->g_node->connection);
        free(iter->g_node);
        
        iter = tempdllNode;
    }
    free_dll(g->allNodes);
    free(g);
}


    
#endif
    
