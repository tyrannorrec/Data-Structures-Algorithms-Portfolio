/* *******************************************************
 *         list.c    This is the implementation file for the
 *                   Singly-Linked List ADT upon which out
 *		     queue and stack programs are based.
 *
 *               1.  createNode(int inData)
 *               2.  createList()
 *               3.  listEmpty(sList_t* inList_p)
 *               4.  listLength(sList_t* inList_p)
 *               5.  printNode(Node_t* inNode_p)
 *               6.  printList(sList_t* inList_p)
 *               7.  deleteNode(Node_t* inNode_p)
 *               8.  insertFront(sList_t* inList_p, int inValue)
 *               9.  insertRear(sList_t* inList_p, int inValue)
 *               10. deleteFront(sList_t* inList_p)
 *               11. deleteRear(sList_t* inList_p)
 *               12. insert(sList_t* inList_p, int inValue, int pos)
 *               13. delete(sList_t* inList_p, int pos)
 *               14. findItem(sList_t* inList_p, int inValue)
 *               15. deleteItem(sList_t* inList_p, int inValue)
 *               16. deleteList(sList_t* inList_p)
 *               17. populateList(sList_t* inList_p)
 *               18. populateListFront(sList_t* inList_p)
 *
 *   Programmer: Norrec Nieh
 *   Course:     CS5008, Summer 2022
 *   Date:       June 8, 2022
 *
 * *******************************************************/

/* --------------------------------------------------------
 * FUNCTION `createNode` CREATES A NODE ON THE HEAP,
 * ASSIGNS `inData` TO THE NODE'S `data` ATTRIBUTE, AND
 * RETURNS THE NODE'S ADDRESS 
 */
 
Node_t* createNode(int inData) {

    // REQUEST MEMORY ON THE HEAP
    Node_t* newNode = (Node_t*) malloc(sizeof(Node_t));

    // CHECK FOR SUCCESS OF MEMORY ALLOCATION
    if (newNode == NULL) {
        return NULL;
    } // IF

    // ASSIGN `inData' TO `newNode` AND INITIALIZE `next` 
    // ATTRIBUTE TO NULL
    newNode->data = inData;
    newNode->next = NULL;

    return newNode;
} // FUNCTION `createNode`

/* --------------------------------------------------------
 * FUNCTION `createList` CREATES A LIST AND RETURNS ITS ADDRESS
 */
 
sList_t* createList() {

    // REQUEST MEMORY ON THE HEAP
    sList_t* newList = (sList_t*) malloc(sizeof(sList_t));
    
    // CHECK FOR SUCCESS OF MEMORY ALLOCATION
    if (newList == NULL) {
        return NULL;
    } // IF

    // INITIALIZE HEAD AND TAIL POINTERS TO NULL
    newList->head = NULL;
    newList->tail = NULL;
    //newList->size = 0;

    return newList;
} // FUNCTION `createList`

/* --------------------------------------------------------
 * FUNCTION `listEmpty` RETURNS 1 IF A LIST IS EMPTY
 * AND RETURNS 0 IF IT IS NOT EMPTY
 */

int listEmpty(sList_t* inList_p) {

    // CHECK WHETHER HEAD IS NULL; IF NULL, RETURN 1 (EMPTY)
    if (inList_p->head == NULL) {
        return 1;
    } // IF

    // ELSE, RETURN 0 (NOT EMPTY)
    else{
        return 0;
    } // ELSE
} // FUNCTION `listEmpty`
 
/* --------------------------------------------------------
 * FUNCTION `listLength` COUNTS THE NUMBER OF NODES/ITEMS
 * IN A LIST AND RETURNS THE COUNT
 */

int listLength(sList_t* inList_p) {

    // DECLARE TWO POINTERS TO ITERATE THROUGH LIST
    Node_t* currNode = inList_p->head;
    Node_t* nextNode;

    // IF LIST PTR IS A NULL PTR, RETURN -1 (ERROR STATUS)
    if (inList_p == NULL) {
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

} // FUNCTION `listLength`

/* --------------------------------------------------------
 * FUNCTION `printNode` PRINTS THE VALUE STORED IN THE
 * `data` ATTRIBUTE IN A NODE
 */
 
void printNode(Node_t* inNode_p) {
    printf("%d   ", inNode_p->data);
    } // FUNCTION `printNode'

/* --------------------------------------------------------
 * FUNCTION `printList` ITERATES THROUGH A LIST FROM
 * HEAD TO TAIL AND PRINTS THE VALUE STORED IN EACH NODE.
 * RETURNS 1 IF SUCCESSFUL AND 0 IF NOT SUCCESSFUL
 */ 

int printList(sList_t* inList_p) {

    // IF POINTER IS NULL, RETURN -1 (ERROR MESSAGE)
    if (inList_p == NULL) {
        return -1;
    } // IF
    
    // IF LIST IS EMPTY, PRINT APPROPRIATE MESSAGE
    if (listEmpty(inList_p) == 1) {
        printf("The list is empty -- nothing to print.");
    } // IF

    // DECLARE/INITIALIZE ITERATOR TO HEAD OF LIST
    Node_t* iter = inList_p->head;

    // WHILE `iter` HAS NOT REACHED END OF LIST, PRINT
    // VALUE IN NODE AND MOVE TO NEXT NODE
    while (iter != NULL) {
       printNode(iter);
       iter = iter->next;
    } // WHILE

    printf("\n");
    return 1;

} // FUNCTION `printList'

/* --------------------------------------------------------
 * FUNCTION `deleteNode` FREES A SINGLE NODE
 */
 
void deleteNode(Node_t* inNode_p) {

    // IF NODE IS NULL, RETURN
    if (inNode_p == NULL) {
        return;
    } // IF

    // FREE NODE
    free(inNode_p);
} // FUNCTION `deleteNode`

/* --------------------------------------------------------
 * FUNCTION `insertFront` INSERTS A NEW VALUE `inValue` AT
 * THE BEGINNING OF THE LIST; RETURNS 1 IF SUCCESSFUL AND
 * -1 IF NOT SUCCESSFUL
 */
 
int insertFront(sList_t* inList_p, int inValue) {

    // IF POINTER IS NULL, RETURN -1 (ERROR MESSAGE)
    if (inList_p == NULL) {
        return -1;
    } // IF
   
    // CREATE A NEW NODE TO STORE THE VALUE
    Node_t* newNode = createNode(inValue);

    // VERIFY THAT MALLOC SUCCEEDED
    if (newNode == NULL) {
        return -1;
    } // IF    

    // ASSIGN CURR HEAD TO NEW NODE'S `next` ATTRIBUTE
    newNode->next = inList_p->head;

    // SET NEW NODE AS HEAD OF LIST
    inList_p->head = newNode;

    // IF NEW NODE IS FIRST NODE, ALSO SET AS TAIL
    if (newNode->next == NULL) {
        inList_p->tail = newNode;
    } // IF

    return 1; 

} // FUNCTION `insertFront`

/* --------------------------------------------------------
 * FUNCTION `insertRear` INSERTS A NEW VALUE `inValue` AT
 * THE END OF THE LIST; RETURNS 1 IF SUCCESSFUL AND -1
 * IF NOT SUCCESSFUL
 */
 
int insertRear(sList_t* inList_p, int inValue) {

    // IF POINTER IS NULL, RETURN -1 (ERROR MESSAGE)
    if (inList_p == NULL) {
        return -1; 
    } // IF
  
    // IF THE LIST IS EMPTY, INSERT AT FRONT OF LIST
    if (listEmpty(inList_p)) {
        insertFront(inList_p, inValue);
        return 1;
    } // IF

    // ELSE, CREATE A NEW NODE TO STORE THE VALUE
    Node_t* newNode = createNode(inValue);

    // VERIFY THAT MALLOC SUCCEEDED
    if (newNode == NULL) {
        return -1;
    } // IF

    // ASSIGN NEW NODE TO `next` ATTRIBUTE OF CURR TAIL
    // THEN, SET THE NEW NODE AS TAIL OF LIST
    else {
        inList_p->tail->next = newNode;
        inList_p->tail = newNode;
    } // ELSE
    
    return 1;

} // FUNCTION `insertRear`

/* --------------------------------------------------------
 * FUNCTION `deleteFront` REMOVES THE FIRST NODE IN A LIST;
 * RETURNS 1 IF SUCCESSFUL AND -1 IF NOT SUCCESSFUL
 */
 
int deleteFront(sList_t* inList_p) {

    // DECLARE/INITIALIZE POINTER TO STORE ADDRESS OF
    // NODE TO BE DELETED
    Node_t* temp_p = NULL;

    // IF LIST POINTER IS NULL, RETURN -1 (ERROR STATUS)
    if (inList_p == NULL) {
        return -1;
    }

    // ELSE IF LIST IS EMPTY, PRINT APPROPRIATE MESSAGE AND 
    // RETURN -1 (ERROR STATUS)
    else if (inList_p->head == NULL) {
        printf("List is empty -- nothing to delete.\n");
        return -1;
    }

    // ELSE IF LIST HAS ONLY ONE NODE, SET HEAD AND TAIL
    // OF LIST TO NULL AND FREE THE NODE
    else if (listLength(inList_p) == 1) {
        temp_p = inList_p->head;
        inList_p->head = NULL;
        inList_p->tail = NULL;
        deleteNode(temp_p);
        return 1;
    } // ELSE IF

    // ELSE IF LIST HAS MORE THAN ONE NODE, SET HEAD TO
    // 2ND NODE AND FREE THE ORIGINAL HEAD NODE
    else {
        temp_p = inList_p->head;
        inList_p->head = temp_p->next;
        deleteNode(temp_p);
        return 1;
    } // ELSE

} // FUNCTION `deleteFront`

/* --------------------------------------------------------
 * FUNCTION `deleteRear` REMOVES THE NODE AT THE TAIL OF
 * THE LIST; RETURNS 1 IF SUCCESSFUL AND -1 IF NOT SUCCESSFUL
 */
 
int deleteRear(sList_t* inList_p) {

    // DECLARE/INITIALIZE POINTER TO STORE ADDRESS OF
    // NODE TO BE DELETED 
    Node_t* temp_p = NULL;

    // IF POINTER TO LIST IS NULL, RETURN -1 (ERROR STATUS)
    if (inList_p == NULL) {
        return -1;
    } // IF

    // ELSE IF LIST IS EMPTY, PRINT APPROPRIATE MESSAGE
    // AND RETURN -1 (ERROR STATUS)
    else if (inList_p->head == NULL) {
        printf("List is empty -- nothing to delete.\n");
        return -1;
    } // ELSE IF

    // ELSE, THE LIST HAS AT LEAST ONE NODE
    else {

        // GET LENGTH OF LIST
        int numOfNodes = listLength(inList_p);
        
        // IF LIST HAS ONE NODE, DELETE NODE AT HEAD
        // AND SET BOTH HEAD AND TAIL TO NULL
        if (numOfNodes == 1) {
            temp_p = inList_p->head;
            inList_p->head = NULL;
            deleteNode(temp_p);
            inList_p->tail = NULL;
            return 1;
        } // IF

        // ELSE IF LIST HAS TWO NODES, DELETE NODE
        // AT TAIL, SET TAIL OF LIST TO CURR HEAD
        else if (numOfNodes == 2) {
            temp_p = inList_p->head->next;
            inList_p->head->next = NULL;
            deleteNode(temp_p);
            inList_p->tail = inList_p->head;
            return 1;
        } // ELSE IF

        // ELSE IF LIST HAS MORE THAN TWO NODES,
        // ITERATE THROUGH LIST UNTIL NODE `y`
        // IS THE TAIL
        else {
            Node_t* x = inList_p->head;
            Node_t* y = x->next;
            Node_t* z = y->next;

            while (z != NULL) {
                x = y;
                y = z;
                z = z->next;
            } // WHILE

            // SET NODE BEFORE TAIL AS NEW TAIL
            // AND FREE OLD TAIL
            x->next = NULL;
            deleteNode(y);
            inList_p->tail = x;
            return 1;
        } // ELSE
    } // ELSE

} // FUNCTION `deleteRear`

/* --------------------------------------------------------
 * FUNCTION `insert` INSERTS A VALUE `inValue` AT POSITION
 * 'pos' IN LIST; RETURNS 1 IF SUCCESSFUL AND -1 IF NOT
 * SUCCESSFUL
 */
 
int insert(sList_t* inList_p, int inValue, int pos) {

    // DECLARE/INITIALIZE PSEUDO-BOOLEAN TO STORE
    // SUCCESS STATUS OF INSERT FUNCTIONS
    int insertSuccess = 0;

    // IF LIST POINTER IS NULL, RETURN -1 (ERROR MESSAGE)
    if (inList_p == NULL) {
        return -1;
    } // IF

    // ELSE IF LIST IS EMPTY OR INSERT POS IS 0 OR 1,
    // INSERT AT FRONT OF LIST AND RETURN SUCCESS STATUS
    else if (inList_p->head == NULL || pos == 0 || pos == 1) {
        insertSuccess = insertFront(inList_p, inValue);
        return insertSuccess;
    } // ELSE IF

    // ELSE, GET LENGTH OF LIST
    else {
        int lengthOfList = listLength(inList_p);
        
        // IF POS IS GREATER THAN CURR NUMBER OF NODES,
        // INSERT AT REAR OF LIST AND RETURN SUCCESS STATUS
        if (pos > lengthOfList) {
            insertSuccess = insertRear(inList_p, inValue);
            return insertSuccess;
        } // IF

        // ELSE, GENERAL CASE
        else {
            // CREATE NEW NODE TO STORE VALUE
            Node_t* newNode = createNode(inValue);
            
            // IF MALLOC FAILED, RETURN -1 (FAIL STATUS)
            if (newNode == NULL) {
                return -1;
            } // IF
            
            // DECLARE ITERATOR AND SET TO HEAD
            Node_t* currNode = inList_p->head;

            // DECLARE/INITIALIZE CURR POSITION TO 1 (HEAD)
            int currPos = 1;

            // ITERATE TO NODE BEFORE LOCATION OF NEW NODE
            // INSERTION
            while (currPos < pos - 1) {
                currNode = currNode->next;
                currPos++;
            } // WHILE

            // ASSIGN NEW NODE AS `next` OF `currNode` AND
            // ASSIGN THE ORIGINAL `next` NODE OF `currNode`
            // AS THE `next` NODE OF NEW NODE
            Node_t* nextNode = currNode->next;
            currNode->next = newNode;
            newNode->next = nextNode;
            return 1;
        } // ELSE
    } // ELSE
} // FUNCTION `insert`

/* --------------------------------------------------------
 * FUNCTION `delete` REMOVES A NODE AT POSITION `pos` OF
 * A LIST; RETURNS 1 IF SUCCESSFUL AND -1 IF NOT SUCCESSFUL
 */
 
int delete(sList_t* inList_p, int pos) {

    // IF LIST POINTER IS NULL, RETURN -1 (ERROR STATUS)
    if (inList_p == NULL) {
        return -1;
    } // IF

    // INITIATLIZE PSEUDO-BOOLEAN VAR TO STORE STATUS OF
    // NODE DELETION
    int deleteSuccess;

    // GET LENGTH OF LIST
    int numOfNodes = listLength(inList_p);
    
    // IF ONLY ONE NODE, OR IF FIRST NODE TO BE DELETED,
    // CALL `deleteFront` AND RETURN SUCCESS STATUS
    if (numOfNodes == 1 || pos == 0 || pos == 1) {
        deleteSuccess = deleteFront(inList_p);
        return deleteSuccess;
    } // IF
    
    // ELSE IF LAST NODE TO BE DELETED, CALL `deleteRear`
    // AND RETURN SUCCESS STATUS
    else if (pos >= numOfNodes) {
        deleteSuccess = deleteRear(inList_p);
        return deleteSuccess;
    } // ELSE IF
    
    // ELSE, GENERAL CASE
    else {
        // DECLARE AND INITIALIZE CURR POSITION TO HEAD
        int currPos = 1;
 
        // DECLARE ITERATOR AND SET TO HEAD
        Node_t* currNode = inList_p->head;
        
        // ITERATE UNTIL ITERATOR POINTS TO NODE BEFORE
        // NODE TO BE DELETED
        while (currPos < pos - 1) {
            currNode = currNode->next;
            currPos++;
        } // WHILE

        // ASSIGN CURR `next` NODE OF TARGET NODE TO
        // `next` POINTER OF NODE PRECEDING TARGET NODE;
        // DELETE TARGET NODE
        Node_t* targetNode = currNode->next;
        currNode->next = targetNode->next;
        deleteNode(targetNode);

        return 1;
    } // ELSE
} // FUNCTION `delete`

/* --------------------------------------------------------
 * FUNCTION `findItem` FINDS A NODE CONTAINING THE VALUE
 * `inValue` IN ITS `data` ATTRIBUTE; RETURNS THE POSITION
 * IN LIST OF THE CORRESPONDING NODE; RETURNS 0 IF NOT IN LIST
 */ 

int findItem(sList_t* inList_p, int inValue) {
    
    // IF LIST POINTER IS NULL, RETURN -1 (ERROR STATUS)
    if (inList_p == NULL) {
        return -1;
    } // IF

    // IF LIST IS EMPTY, RETURN -1 (ERROR STATUS)
    if (listEmpty(inList_p) == 1) {
        return -1;
    } // IF

    // DECLARE AND INITIALIZE ITERATORS TO FIRST AND
    // SECOND NODES IN LIST
    Node_t* currNode = inList_p->head;
    Node_t* nextNode = currNode->next;

    // SET CURRENT POSITION TO 1
    int currPos = 1;

    // WHILE `currNode` IS NOT THE TAIL,
    while (nextNode != NULL) {

        // CHECK IF `data` ATTRIBUTE MATCHES `inValue'
        if (currNode->data == inValue) {
            // IF MATCH, RETURN POSITION OF NODE
            return currPos;
        } // IF

        // IF NOT A MATCH, CONTINUE ITERATING
        currPos++;
        currNode = nextNode;
        nextNode = nextNode->next;
    } // WHILE

    // IN THE CASE THAT `currNode` IS THE TAIL,
    // RETURN POS OF TAIL IF VALUE MATCHES `inValue`
    if (currNode->data == inValue) {
        return currPos;
    } // IF

    // ELSE, ITEM NOT IN LIST; RETURN 0
    else {
        return 0;
    } // ELSE

} // FUNCTION `findItem`
 
/* -------------------------------------------------------
 * FUNCTION `deleteItem` FINDS THE FIRST INSTANCE OF
 * A NODE CONTAINING THE VALUE `inValue` AND DELETES
 * THE NODE FROM THE LIST; RETURNS 1 IF SUCCESSFUL
 * AND -1 IF NOT SUCCESSFUL
 */
 
int deleteItem(sList_t* inList_p, int inValue) {

    // CALL `findItem` TO GET POSITION OF NODE
    // HOLDING VALUE MATCHING `inValue`
    int itemPos = findItem(inList_p, inValue);

    // IF IN LIST (NOT 0), DELETE ITEM AT POSITION
    if (itemPos > 0) {
        delete(inList_p, itemPos);
        return 1;
    } // IF

    // RETURN -1 (ERROR STATUS) IF ITEM NOT IN LIST
    return -1;
} // FUNCTION `deleteItem`

/* ------------------------------------------------------
 * FUNCTION `deleteList` TRAVERSES AND DELETES EACH NODE
 * IN THE LIST; RETURNS 1 IF SUCCESSFUL AND -1 IF NOT
 * SUCCESSFUL
 */

int deleteList(sList_t* inList_p) {

    // CREATE TWO NODE POINTERS TO ITERATE THROUGH LIST
    Node_t* targetNode = inList_p->head;
    Node_t* nextNode = NULL;

    // IF POINTER TO LIST IS NULL, RETURN -1 (ERROR MESSAGE)
    if (inList_p == NULL) {
        return -1;
    } // IF

    // IF HEAD IS NOT NULL, AND LIST IS NOT EMPTY,
    if (targetNode != NULL) {
        
        // SET `nextNode` TO NEXT OF HEAD
        nextNode = targetNode->next;

        // WHILE NOT TAIL, DELETE `targetNode` AND
        // MOVE POINTERS ONE STEP TOWARD TAIL
        while (nextNode != NULL) {
            deleteNode(targetNode);
            targetNode = nextNode;
            nextNode = nextNode->next;
        } // WHILE

        // WHEN TAIL, DELETE TAIL
        deleteNode(targetNode);
        // SET HEAD AND TAIL TO NULL
        inList_p->head = NULL;
        inList_p->tail = NULL;
    } // IF

    // FREE LIST AND RETURN 1 (SUCCESS MESSAGE)
    free(inList_p);
    return 1;

} // FUNCTION `deleteList`

/* ------------------------------------------------------
 * FUNCTION `populateList` GETS A FILE NAME FROM USER,
 * AND FOR EACH INT IN THE FILE, INSERTS THE INT TO THE
 * REAR OF THE LIST; RETURNS 1 IF SUCCESSFUL AND -1 IF NOT
 * SUCCESSFUL; RETURN -2 IF ERROR OPENING FILE
 */ 

int populateList(sList_t* inList_p) {

    // IF LIST IS NULL, RETURN -1 (GENERAL ERROR STATUS)
    if (inList_p == NULL) {
        return -1;
    } // IF

    // GET FILE NAME FROM USER
    char* fileName = (char*)malloc((sizeof(char) * 40));
    printf("Enter file name: ");
    scanf("%s", fileName);

    // OPEN FILE
    FILE* fileHandle = fopen(fileName, "r");

    // IF ERROR OPENING FILE, PRINT ERROR MESSAGE AND
    // RETURN -2 (ERROR OPENING FILE STATUS)
    if (fileHandle == NULL) {
        perror("ERROR");
        return -2;
    } // IF

    // DECLARE VAR TO STORE INTS READ IN FROM FILE
    int currInt;

    // LOOP UNTIL EOF
    while (1) {
        // READ INT
        fscanf(fileHandle, "%d", &currInt);

        // CHECK FOR EOF
        if (feof(fileHandle)) {
            break;
        } // IF

        // ELSE, INSERT INTO REAR OF LIST
        insertRear(inList_p, currInt);
    } // WHILE
    
    // CLOSE FILE
    fclose(fileHandle);
    free(fileName); 
    return 1;

} // FUNCTION `populateList`

/* ------------------------------------------------------
 * FUNCTION `populateListFront` GETS A FILE NAME FROM USER,
 * AND FOR EACH INT IN THE FILE, INSERTS THE INT TO THE
 * FRONT OF THE LIST; RETURNS 1 IF SUCCESSFUL AND -1 IF NOT
 * SUCCESSFUL; RETURN -2 IF ERROR OPENING FILE
 */ 

int populateListFront(sList_t* inList_p) {

    // IF LIST IS NULL, RETURN -1 (GENERAL ERROR STATUS)
    if (inList_p == NULL) {
        return -1;
    } // IF

    // GET FILE NAME FROM USER
    char* fileName = (char*)malloc((sizeof(char) * 40));
    printf("Enter file name: ");
    scanf("%s", fileName);

    // OPEN FILE
    FILE* fileHandle = fopen(fileName, "r");

    // IF ERROR OPENING FILE, PRINT ERROR MESSAGE AND
    // RETURN -2 (ERROR OPENING FILE STATUS)
    if (fileHandle == NULL) {
        perror("ERROR");
        return -2;
    } // IF

    // DECLARE VAR TO STORE INTS READ IN FROM FILE
    int currInt;

    // LOOP UNTIL EOF
    while (1) {
        // READ INT
        fscanf(fileHandle, "%d", &currInt);

        // CHECK FOR EOF
        if (feof(fileHandle)) {
            break;
        } // IF

        // ELSE, INSERT INTO REAR OF LIST
        insertFront(inList_p, currInt);
    } // WHILE
    
    // CLOSE FILE
    fclose(fileHandle);
    free(fileName);
    return 1;

} // FUNCTION `populateListFront`

/* ------------------------------------------------------- */
