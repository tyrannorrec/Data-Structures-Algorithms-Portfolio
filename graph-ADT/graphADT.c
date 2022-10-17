/* **************************************************************
 *      Implementation File:  graphADT.c
 * 
 *      Programmer:   Norrec Nieh
 *      Course:       CS5008, Summer 2022
 *      Date:         July 26, 2022
 * **************************************************************/

/* --------------------------------------------------------------
 * `createVertexNode()` creates a new node to represent a vertex
 *   in a graph. Returns the new node.
 * ------------------------------------------------------------ */
vertexNode_t* createVertexNode(int inData) {

    vertexNode_t* newVertexNode = (vertexNode_t*) malloc(sizeof(edgeNode_t));
    
    if (newVertexNode == NULL) {
        return NULL;
    } // IF

    newVertexNode->data = inData;
    newVertexNode->visited = 0;
    newVertexNode->expanded = 0;
    newVertexNode->numEdges = 0;
    newVertexNode->edges = NULL;
    return newVertexNode;

} // FUNCTION `createVertexNode()`

/* --------------------------------------------------------------
 * `createEdgeNode()` creates a new node to represent a neighbor
 *   of an extant vertex node. Returns the new node.
 * ------------------------------------------------------------ */
edgeNode_t* createEdgeNode(int inParentData, int inData, int inCost) {

    edgeNode_t* newEdgeNode = (edgeNode_t*) malloc(sizeof(edgeNode_t));

    if (newEdgeNode == NULL) {
        return NULL;
    } // IF

    newEdgeNode->parentData = inParentData;
    newEdgeNode->data = inData;
    newEdgeNode->edgeCost = inCost;
    newEdgeNode->next = NULL;
    return newEdgeNode;    

} // FUNCTION `createEdglist_t* makeList() {

/* --------------------------------------------------------------
 * `createEdgeList()` creates a new list to represent the edges
 *   of an extant vertex node. Returns the new list pointer.
 * ------------------------------------------------------------ */
edgeList_t* createEdgeList() {

    edgeList_t* newEdgeList = (edgeList_t*) malloc(sizeof(edgeList_t));
    
    if (newEdgeList == NULL) {
        return NULL;
    } // IF

    newEdgeList->head = NULL;
    newEdgeList->tail = NULL;
    return newEdgeList;

} // FUNCTION `createEdgeList()`

/* --------------------------------------------------------------
 * `printVertexNode()` prints the contents of a given vertex node.
 * ------------------------------------------------------------ */
void printVertexNode(vertexNode_t* inVertexNode) {

    printf("* * * * PRINTING VERTEX: %d * * * *\n"
           "Data:       %d\n"
           "Visited:    %d\n"
           "Expanded:   %d\n"
           "Edge Count: %d\n",
           inVertexNode->data,
	   inVertexNode->data, inVertexNode->visited,
           inVertexNode->expanded, inVertexNode->numEdges);

} // FUNCTION `printVertexNode()`
 
/* --------------------------------------------------------------
 * `printEdgeNode()` prints the contents of a given edge node.
 * ------------------------------------------------------------ */
void printEdgeNode(edgeNode_t* inEdgeNode) {

    printf("\t\t----- Graph Edge Node: -----\n"
           "\t\tParent:    %d\n"
           "\t\tData:      %d\n"
           "\t\tEdge Cost: %d\n",
           inEdgeNode->parentData, inEdgeNode->data, 
	   inEdgeNode->edgeCost);

} // FUNCTION `printEdgeNode()`

/* --------------------------------------------------------------
 * `printEdgeList()` prints every edge that a given vertex has.
 * ------------------------------------------------------------ */
void printEdgeList(edgeList_t* inEdgeList) {

    edgeNode_t* iterator = inEdgeList->head;
    printf("\t\t* * * * NEIGHBOR LIST * * * *\n");
    while (iterator != NULL) {
	printf("\n");
        printEdgeNode(iterator);
        iterator = iterator->next;
    } // WHILE

} // FUNCTION `printEdgeList()`

/* --------------------------------------------------------------
 * `printGraph()` prints every edge list in the adjacency list
 *   representation of the graph in numerical order of vertices.
 * ------------------------------------------------------------ */
void printGraph() {

    printf("= + = + = + = + = + = + = + = + = + = + = + = + =\n"
           "= + = + = +       ENTIRE GRAPH        + = + = + =\n"
           "= + = + = + = + = + = + = + = + = + = + = + = + =\n\n");
    for (int i = 1; i <= NUM_VERTICES; i++) {
        vertexNode_t* currentVertex = graphArray[i];
        printVertexNode(currentVertex);
        printEdgeList(currentVertex->edges);
        printf("\n");
    } // FOR

} // FUNCTION `printGraph()`

/* --------------------------------------------------------------
 * `initializeGraph()` takes in the number of vertices to be
 *   placed in the graph, creates that number of vertex nodes
 *   and adds them to the graphArray from index 1 to index
 *   NUM_VERTICES.
 * ------------------------------------------------------------ */
void initializeGraph() {

    for (int i = 1; i <= NUM_VERTICES; i++) {
        graphArray[i] = createVertexNode(i);
        graphArray[i]->edges = createEdgeList();
    } // FOR

} // FUNCTION `initializeGraph()`

/* --------------------------------------------------------------
 * `edgeListEmpty()` returns 1 if the list is empty and 0 if not.
 * ------------------------------------------------------------ */
int edgeListEmpty(edgeList_t* inEdgeList) {

    if (inEdgeList->head == NULL) {
        return 1;
    } // IF

    else{
        return 0;
    } // ELSE

} // FUNCTION `edgeListEmpty`

/* --------------------------------------------------------------
 * `edgeListLength()` returns the number of edges in the list.
 * ------------------------------------------------------------ */
int edgeListLength(edgeList_t* inEdgeList) {

    // DECLARE TWO POINTERS TO ITERATE THROUGH LIST
    edgeNode_t* currNode = inEdgeList->head;
    edgeNode_t* nextNode;

    // IF LIST PTR IS A NULL PTR, RETURN -1 (ERROR STATUS)
    if (inEdgeList == NULL) {
        return -1;
    } // IF

    // IF HEAD IS NULL AND LIST IS EMPTY, RETURN 0
    if (currNode == NULL) {
        return 0;
    } // IF

    // ELSE, HEAD IS NOT NULL
    else {

        // SET NEXT TO NEXT NODE
        nextNode = currNode->next;    

        // IF NODE 2 IS NULL, HEAD IS THE ONLY NODE; RETURN 1
        if (nextNode == NULL) {
            return 1;
        } // IF

        currNode = nextNode;
        nextNode = nextNode->next;

        // DECLARE AND INITIALIZE COUNTER TO 2, SINCE 
        // `currNode` IS CURRENTLY POINTING TO NODE 2
        int counter = 2;

        // ITERATE UNTIL TAIL NODE
        while (nextNode != NULL) {
            counter++;
            nextNode = nextNode->next;
        } // WHILE

        return counter;
    } // ELSE

} // FUNCTION `edgeListLength()`

/* --------------------------------------------------------------
 * `insertFrontEdge()` inserts the edge node at the front of the list.
 *   Returns 1 if successful and -1 if unsuccessful.
 * ------------------------------------------------------------ */
int insertFrontEdge(edgeList_t* inEdgeList, edgeNode_t* inEdgeNode) {

    if (inEdgeList == NULL) {
        return -1;
    } // IF
   
    // ASSIGN CURR HEAD TO EDGE NODE'S `next` ATTRIBUTE
    inEdgeNode->next = inEdgeList->head;

    // SET EDGE NODE AS HEAD OF LIST
    inEdgeList->head = inEdgeNode;

    // IF EDGE NODE IS FIRST NODE, ALSO SET AS TAIL
    if (inEdgeNode->next == NULL) {
        inEdgeList->tail = inEdgeNode;
    } // IF

    return 1; 

} // FUNCTION `insertFrontEdge()`

/* --------------------------------------------------------------
 * `insertRearEdge()` inserts the edge node at the rear of the list.
 *   Returns 1 if successful and -1 if unsuccessful.
 * ------------------------------------------------------------ */
int insertRearEdge(edgeList_t* inEdgeList, edgeNode_t* inEdgeNode) {

    if (inEdgeList == NULL) {
        return -1; 
    } // IF
  
    // IF THE LIST IS EMPTY, INSERT AT FRONT OF LIST
    if (edgeListEmpty(inEdgeList)) {
        insertFrontEdge(inEdgeList, inEdgeNode);
        return 1;
    } // IF

    // ELSE, ASSIGN NEW NODE TO `next` ATTRIBUTE OF CURR TAIL
    // THEN, SET THE NEW NODE AS TAIL OF LIST
    else {
        inEdgeList->tail->next = inEdgeNode;
        inEdgeList->tail = inEdgeNode;
    } // ELSE
    
    return 1;

} // FUNCTION `insertRearEdge()`

/* --------------------------------------------------------------
 * `deleteVertexNode()` deletes the vertex node and frees its memory.
 *   Returns 1 if successful and -1 if unsuccessful.
 * ------------------------------------------------------------ */
int deleteVertexNode(vertexNode_t* inVertexNode) {

    if (inVertexNode == NULL) {
        return -1;
    } // IF

    free(inVertexNode);
    inVertexNode = NULL;
    return 1;

} // FUNCTION `deleteVertexNode()`

/* --------------------------------------------------------------
 * `deleteEdgeNode()` deletes the edge node and frees its memory.
 *   Returns 1 if successful and -1 if unsuccessful.
 * ------------------------------------------------------------ */
int deleteEdgeNode(edgeNode_t* inEdgeNode) {

    if (inEdgeNode == NULL) {
        return -1;
    } // IF

    free(inEdgeNode);
    inEdgeNode = NULL;
    return 1;

} // FUNCTION `deleteEdgeNode`

/* --------------------------------------------------------------
 * `deleteFrontEdge()` deletes the edge node at the front of the list.
 *   Returns 1 if successful and -1 if unsuccessful.
 * ------------------------------------------------------------ */
int deleteFrontEdge(edgeList_t* inEdgeList) {

    edgeNode_t* temp = NULL;

    if (inEdgeList == NULL) {
        return -1;
    }

    else if (inEdgeList->head == NULL) {
        printf("Edge list is empty -- nothing to delete.\n");
        return -1;
    }

    // ELSE IF LIST HAS ONLY ONE NODE, SET HEAD AND TAIL
    // OF LIST TO NULL AND FREE THE NODE
    else if (edgeListLength(inEdgeList) == 1) {
        temp = inEdgeList->head;
        inEdgeList->head = NULL;
        inEdgeList->tail = NULL;
        deleteEdgeNode(temp);
        return 1;
    } // ELSE IF

    // ELSE IF LIST HAS MORE THAN ONE NODE, SET HEAD TO
    // 2ND NODE AND FREE THE ORIGINAL HEAD NODE
    else {
        temp = inEdgeList->head;
        inEdgeList->head = temp->next;
        deleteEdgeNode(temp);
        return 1;
    } // ELSE

} // FUNCTION `deleteFrontEdge()`

/* --------------------------------------------------------------
 * `deleteRearEdge()` deletes the edge node at the rear of the list.
 *   Returns 1 if successful and -1 if unsuccessful.
 * ------------------------------------------------------------ */
int deleteRearEdge(edgeList_t* inEdgeList) {

    edgeNode_t* temp = NULL;

    if (inEdgeList == NULL) {
        return -1;
    } // IF

    else if (inEdgeList->head == NULL) {
        printf("Edge list is empty -- nothing to delete.\n");
        return -1;
    } // ELSE IF

    // ELSE, THE LIST HAS AT LEAST ONE NODE
    else {

        // GET LENGTH OF LIST
        int numOfNodes = edgeListLength(inEdgeList);
        
        // IF LIST HAS ONE NODE, DELETE NODE AT HEAD
        // AND SET BOTH HEAD AND TAIL TO NULL
        if (numOfNodes == 1) {
            temp = inEdgeList->head;
            inEdgeList->head = NULL;
            deleteEdgeNode(temp);
            inEdgeList->tail = NULL;
            return 1;
        } // IF

        // ELSE IF LIST HAS TWO NODES, DELETE NODE
        // AT TAIL, SET TAIL OF LIST TO CURR HEAD
        else if (numOfNodes == 2) {
            temp = inEdgeList->head->next;
            inEdgeList->head->next = NULL;
            deleteEdgeNode(temp);
            inEdgeList->tail = inEdgeList->head;
            return 1;
        } // ELSE IF

        // ELSE IF LIST HAS MORE THAN TWO NODES,
        // ITERATE THROUGH LIST UNTIL NODE `y`
        // IS THE TAIL
        else {
            edgeNode_t* x = inEdgeList->head;
            edgeNode_t* y = x->next;
            edgeNode_t* z = y->next;

            while (z != NULL) {
                x = y;
                y = z;
                z = z->next;
            } // WHILE

            // SET NODE BEFORE TAIL AS NEW TAIL
            // AND FREE OLD TAIL
            x->next = NULL;
            deleteEdgeNode(y);
            inEdgeList->tail = x;
            return 1;
        } // ELSE
    } // ELSE

} // FUNCTION `deleteRearEdge()`

/* --------------------------------------------------------------
 * `deleteEdgeList()` deletes and frees all nodes in a list.
 *   Returns 1 if successful and -1 if unsuccessful.
 * ------------------------------------------------------------ */
int deleteEdgeList(edgeList_t* inEdgeList) {

    // CREATE TWO NODE POINTERS TO ITERATE THROUGH LIST
    edgeNode_t* targetNode = inEdgeList->head;
    edgeNode_t* nextNode = NULL;

    // IF POINTER TO LIST IS NULL, RETURN -1 (ERROR MESSAGE)
    if (inEdgeList == NULL) {
        return -1;
    } // IF

    // IF HEAD IS NOT NULL, AND LIST IS NOT EMPTY,
    if (targetNode != NULL) {
        
        // SET `nextNode` TO NEXT OF HEAD
        nextNode = targetNode->next;

        // WHILE NOT TAIL, DELETE `targetNode` AND
        // MOVE POINTERS ONE STEP TOWARD TAIL
        while (nextNode != NULL) {
            deleteEdgeNode(targetNode);
            targetNode = nextNode;
            nextNode = nextNode->next;
        } // WHILE

        // WHEN TAIL, DELETE TAIL
        deleteEdgeNode(targetNode);
        // SET HEAD AND TAIL TO NULL
        inEdgeList->head = NULL;
        inEdgeList->tail = NULL;
    } // IF

    // FREE LIST AND RETURN 1 (SUCCESS MESSAGE)
    free(inEdgeList);
    return 1;

} // FUNCTION `deleteList()`

/* --------------------------------------------------------------
 * `deleteGraphArray()` frees all vertex nodes in the array and
 *   all edges in every edge list. 
 *   Returns 1 if successful and -1 if unsuccessful.
 * ------------------------------------------------------------ */
void deleteGraphArray() {

    for (int i = 1; i <= NUM_VERTICES; i++) {
        deleteEdgeList(graphArray[i]->edges);
        graphArray[i]->edges = NULL;
        deleteVertexNode(graphArray[i]);
        graphArray[i] = NULL;
    } // FOR

} // FUNCTION `deleteGraphArray()`

/* --------------------------------------------------------------
 * `markAsVisited()` sets the vertex attribute `visited` to 1.
 * ------------------------------------------------------------ */
void markAsVisited(int vertex) {

    graphArray[vertex]->visited = 1;

} // FUNCTION `markAsVisited()`

/* --------------------------------------------------------------
 * `isVisited()` returns 1 if the vertex has been visited during
 *   a BFS or DFS traversal; returns 0 if not visited.
 * ------------------------------------------------------------ */
int isVisited(int vertex) {

    if (graphArray[vertex]->visited == 1) {
        return 1;
    } // IF

    return 0;

} // FUNCTION `isVisited()`

/* --------------------------------------------------------------
 * `markAsExpanded()` sets the vertex attribute `expanded` to 1.
 * ------------------------------------------------------------ */
void markAsExpanded(int vertex) {

    graphArray[vertex]->expanded = 1;

} // FUNCTION `markAsExpanded()` 

/* --------------------------------------------------------------
 * `isExpanded()` returns 1 if the vertex has been expanded during
 *   a BFS or DFS traversal; returns 0 if not expanded.
 * ------------------------------------------------------------ */
int isExpanded(int vertex) {

    if (graphArray[vertex]->expanded == 1) {
        return 1;
    } // IF

    return 0;

} // FUNCTION `isExpanded()`

/* --------------------------------------------------------------
 * `resetFlags()` resets the attributes `visited` and `expanded` 
 *   of all vertices in the graphArray to 0.
 * ------------------------------------------------------------ */
void resetFlags() {

    for(int i = 1; i <= NUM_VERTICES; i++) {
        graphArray[i]->visited = 0;
        graphArray[i]->expanded = 0;
    } // FOR

} // FUNCTION `resetFlags()`

/* --------------------------------------------------------------
 * `graphBFS()` traverses the graphArray by way of Breadth-First
 *   Search in order to print its contents. Flags are reset at
 *   the end of the traversal.
 * ------------------------------------------------------------ */
void graphBFS(int startVertex) {

    int currVertex = startVertex;
    int neighbor;
    
    // INITIALIZE QUEUE, SINCE MAIN IN `queue.c` WAS COMMENTED OUT
    myQueueList = createList();
    
    printf("Breadth First Traversal:");

    // ENQUEUE AND VISIT START VERTEX
    enqueue(currVertex);
    graphArray[currVertex]->visited = 1;

    // WHILE QUEUE IS NOT EMPTY
    while (queueEmpty() < 1) {

        currVertex = getFront();
        
	// SET ITERATOR TO HEAD OF CURR VERTEX'S EDGE LIST
        edgeNode_t* iterator = graphArray[currVertex]->edges->head;
    
        // FOR EVERY EDGE NODE IN EDGE LIST
        while (iterator != NULL) {

	    // GET NEIGHBOR VERTEX
            neighbor = iterator->data;

	    // IF THAT VERTEX NOT ALREADY VISITED, ENQUEUE AND SET TO VISITED
            if (graphArray[neighbor]->visited == 0) {
                enqueue(neighbor);
                graphArray[neighbor]->visited = 1;
	    } // IF
            
            // MOVE ITERATOR TO NEXT EDGE NODE
	    iterator = iterator->next;
	} // WHILE

        graphArray[currVertex]->expanded = 1;
        printf("  %d", currVertex);
        dequeue();

    } // WHILE

    printf("\n");
    deleteQueue();
    resetFlags();

} // FUNCTION `graphBFS()`

/* --------------------------------------------------------------
 * `graphDFS()` traverses the graphArray by way of Depth-First
 *   Search in order to print its contents. Flags are reset at
 *   the end of the traversal.
 * ------------------------------------------------------------ */
void graphDFS(int startVertex) {

    int currVertex = startVertex;
    int neighbor;
    
    // INITIALIZE STACK, SINCE MAIN IN `stack.c` WAS COMMENTED OUT
    myStackList = createList();

    printf("Depth First Traversal:");

    // PUSH AND VISIT START VERTEX
    push(currVertex);
    graphArray[currVertex]->visited = 1;

    // WHILE STACK IS NOT EMPTY
    while (stackEmpty() < 1) {

        printf("  %d", currVertex);
        pop();
        
	// SET ITERATOR TO HEAD OF CURR VERTEX'S EDGE LIST
        edgeNode_t* iterator = graphArray[currVertex]->edges->head;
    
        // FOR EVERY EDGE NODE IN EDGE LIST
        while (iterator != NULL) {

	    // GET NEIGHBOR VERTEX
            neighbor = iterator->data;

	    // IF THAT VERTEX NOT ALREADY VISITED, PUSH AND SET TO VISITED
            if (graphArray[neighbor]->visited == 0) {
                push(neighbor);
                graphArray[neighbor]->visited = 1;
	    } // IF
            
            // MOVE ITERATOR TO NEXT EDGE NODE
	    iterator = iterator->next;
	} // WHILE

        graphArray[currVertex]->expanded = 1;
        currVertex = TOS();

    } // WHILE

    printf("\n");
    deleteStack();
    resetFlags();

} // FUNCTION `graphDFS()`

/* --------------------------------------------------------------
 * `parseGraphLine()` parses the string passed in as argument and
 *   returns an edge node with the data derived from the string.
 * ------------------------------------------------------------ */
edgeNode_t* parseGraphLine(char inLine[300]) {

    int tempParent = 0;
    int tempData = 0;
    int tempCost = 0;

    sscanf(inLine, " %d %d %d ", &tempParent, &tempData, &tempCost);
    edgeNode_t* currEdge = createEdgeNode(tempParent, tempData, tempCost);

    return currEdge;
} // FUNCTION `parseGraphLine()`

/* --------------------------------------------------------------
 * `populateGraph()` reads a specifically encoded txt file that
 *   represents a graph's adjacency list, and populates the
 *   graphArray based on the data gathered. Returns 1 if
 *   successful and -1 if unsuccessful. 
 * ------------------------------------------------------------ */
int populateGraph() {

    // GET FILE NAME FROM USER
    char* fileName = (char*) malloc((sizeof(char) * 40));
    printf("Enter file name: ");
    scanf("%s", fileName);

    // OPEN FILE
    FILE* fileHandle = fopen(fileName, "r");

    // IF ERROR OPENING FILE, PRINT ERROR MESSAGE AND
    // RETURN -1 (ERROR OPENING FILE STATUS)
    if (fileHandle == NULL) {
        perror("ERROR");
        return -1;
    } // IF

    // DECLARE VARS FOR LOOP
    char tempStr[300];
    int vertexIndex;

    // GET FIRST LINE FOR NUM OF VERTICES AND INITIALIZE GRAPH
    fgets(tempStr, 300, fileHandle);
    tempStr[strlen(tempStr)] = '\0';
    int tempVertices;
    sscanf(tempStr, " %d ", &tempVertices);
    NUM_VERTICES = tempVertices;
    initializeGraph();

    // LOOP UNTIL EOF
    while (!feof(fileHandle)) {
        
        fgets(tempStr, 300, fileHandle);
        tempStr[strlen(tempStr)] = '\0';

        if (strlen(tempStr) >= 5) {
            edgeNode_t* currEdge = parseGraphLine(tempStr);
            if (currEdge != NULL) {
		vertexIndex = currEdge->parentData;
		insertRearEdge(graphArray[vertexIndex]->edges, currEdge);
		(graphArray[vertexIndex]->numEdges)++;
            } // IF
            else {
                printf("Error reading file.\n");
                return -1;
            } // ELSE
        } // IF
    } // WHILE

    // CLOSE FILE
    fclose(fileHandle);
    free(fileName); 
    return 1;

} // FUNCTION `populateList`

/* ********************************************************************* */
