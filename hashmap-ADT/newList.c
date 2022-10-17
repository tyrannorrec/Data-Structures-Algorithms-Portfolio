/* *******************************************************
 *       	        MIDTERM PROGRAM
 *
 *       newList.c    Implementation file for the List ADT,
 *                    with each node containing a kvpair_t
 *                    whose value is a customerRec obj
 *
 *       Programmer: Norrec Nieh
 *       Course:     CS5008, Summer 2022
 *       Date:       July 4, 2022
 *
 * *******************************************************/

/* --------------------------------------------------------
 * FUNCTION `getString` GETS A STRING FROM THE USER AS INPUT.
 * AND RETURNS IT. NOTE: CALLS MALLOC
 */

char* getString(int length) {

    char* tempString = (char*)malloc(sizeof(char)*length);

    fflush(stdin);
    printf("Enter string: ");
    scanf("%s", tempString);

    return tempString;
} // FUNCTION `getString`

/* --------------------------------------------------------
 * FUNCTION `getCustomer` READS A CUSTOMER DATA INTO A
 * NEW `customerRec` OBJ. RETURNS THE `customerRec` OBJ.
 * NOTE: CALLS MALLOC
 */

customerRec* getCustomer() {

    customerRec* newCustomerRec = (customerRec*)malloc(sizeof(customerRec));

    printf("Last Name -- ");
    newCustomerRec->lname = getString(20);
    printf("First Name -- ");
    newCustomerRec->fname = getString(20);
    printf("Social Security Number -- ");
    newCustomerRec->ssNum = getString(13);
    printf("Employee Number -- Enter: ");
    scanf("%d", &(newCustomerRec->empNum));
    printf("Salary -- Enter: ");
    scanf("%d", &(newCustomerRec->salary));

    return newCustomerRec;
} // FUNCTION `getCustomer`

/* --------------------------------------------------------
 * FUNCTION `parseLine` PARSES A STRING INTO A
 * NEW `customerRec` OBJ. RETURNS THE `customerRec` OBJ.
 */

customerRec* parseLine(char inStr[300]) {
  
    char temp_lname[13] = "            \0";
    char temp_fname[13] = "            \0";
    int temp_salary = 0;
    int temp_empNum = 0;
    char temp_ssNum[13] = "            \0";

    customerRec* currCustomer = (customerRec*)malloc(sizeof(customerRec));
    sscanf(inStr, " %s %s %d %d %s ", temp_lname, temp_fname, &temp_salary,
				      &temp_empNum, temp_ssNum);

    int lname_len = strlen(temp_lname);
    int fname_len = strlen(temp_fname);
    int ssNum_len = strlen(temp_ssNum);

    currCustomer->lname = (char*)malloc((lname_len + 1) * sizeof(char));
    currCustomer->fname = (char*)malloc((fname_len + 1) * sizeof(char));
    currCustomer->ssNum = (char*)malloc((ssNum_len + 1) * sizeof(char));

    strcpy(currCustomer->lname, temp_lname);
    strcpy(currCustomer->fname, temp_fname);
    strcpy(currCustomer->ssNum, temp_ssNum);
    currCustomer->salary = temp_salary;
    currCustomer->empNum = temp_empNum;

    return currCustomer;
} // FUNCTION `parseLine`

/* --------------------------------------------------------
 * FUNCTION `getKVpair` CREATES A NEW `kvpair_t` OBJ,
 * AND INSERTS A `customerRec` OBJ INTO THE `value` ATTRIBUTE
 * OF `kvpair_t`. EXTRACTS `empNum` AND ASSIGNS TO 'key'.
 * RETURNS `kvpair_t` OBJ. NOTE: CALLS MALLOC.
 */

kvpair_t* getKVpair(customerRec* inCust) {

    kvpair_t* newKVpair = (kvpair_t*)malloc(sizeof(kvpair_t));
    
    newKVpair->key = inCust->empNum;
    newKVpair->value = inCust;

    return newKVpair;
} // FUNCTION `getKVpair`

/* --------------------------------------------------------
 * FUNCTION 'printCustomerRec` PRINTS THE CONTENTS OF A
 * `customerRec` OBJ
 */

void printCustomerRec(customerRec* inCust) {

    printf("\t\t----- Customer Record -----\n");
    printf("\t\tName:             %s, %s \n", inCust->lname, inCust->fname);
    printf("\t\tEmployee Number:  %d \n", inCust->empNum);
    printf("\t\tSocial Sec Num:   %s \n", inCust->ssNum);
    printf("\t\tSalary:           %d \n\n", inCust->salary);

} // FUNCTION `printCustomerRec'

/* --------------------------------------------------------
 * FUNCTION `printKVpair` PRINTS THE CONTENTS OF A `kvpair_t` OBJ
 */

void printKVpair(kvpair_t* inPair) {

    printf("\t----- Key-Value Pair -----\n");
    printf("\tKEY:   %d \n", inPair->key);
    printf("\tVALUE: Customer Record as follows:\n");
    printCustomerRec(inPair->value);

} // FUNCTION `printKVpair`

/* --------------------------------------------------------
 * FUNCTION `makeNode` CREATES A NODE ON THE HEAP,
 * ASSIGNS `inPair` TO THE NODE'S `data` ATTRIBUTE, AND
 * RETURNS THE NODE'S ADDRESS
 */
 
node_t* makeNode(kvpair_t* inPair) {

    node_t* newNode = (node_t*)malloc(sizeof(node_t));

    if (newNode == NULL) {
        return NULL;
    } // IF

    newNode->data = inPair;
    newNode->next = NULL;

    return newNode;
} // FUNCTION `createNode`

/* --------------------------------------------------------
 * FUNCTION `makeList` CREATES A LIST AND RETURNS ITS ADDRESS
 */
 
list_t* makeList() {

    list_t* newList = (list_t*)malloc(sizeof(list_t));
    
    if (newList == NULL) {
        return NULL;
    } // IF

    newList->head = NULL;
    newList->tail = NULL;

    return newList;
} // FUNCTION `createList`

/* --------------------------------------------------------
 * FUNCTION `listEmpty` RETURNS 1 IF A LIST IS EMPTY
 * AND RETURNS 0 IF IT IS NOT EMPTY
 */

int listEmpty(list_t* inList) {

    if (inList->head == NULL) {
        return 1;
    } // IF

    else{
        return 0;
    } // ELSE
} // FUNCTION `listEmpty`
 
/* --------------------------------------------------------
 * FUNCTION `listLength` COUNTS THE NUMBER OF NODES/ITEMS
 * IN A LIST AND RETURNS THE COUNT
 */

int listLength(list_t* inList) {

    // DECLARE TWO POINTERS TO ITERATE THROUGH LIST
    node_t* currNode = inList->head;
    node_t* nextNode;

    // IF LIST PTR IS A NULL PTR, RETURN -1 (ERROR STATUS)
    if (inList == NULL) {
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
 * FUNCTION `printNode` PRINTS THE `kvpair_t` STORED IN THE
 * `data` ATTRIBUTE IN A NODE
 */
 
void printNode(node_t* inNode) {

    if (inNode == NULL) {
        return;
    } // IF

    printf("----- NODE -----\n");
    printf("DATA:  Key-Value pair as follows:\n");
    printKVpair(inNode->data);
    } // FUNCTION `printNode'

/* --------------------------------------------------------
 * FUNCTION `printList` ITERATES THROUGH A LIST FROM
 * HEAD TO TAIL AND PRINTS THE `kvpair_t` STORED IN EACH NODE.
 * RETURNS 1 IF SUCCESSFUL AND 0 IF NOT SUCCESSFUL
 */ 

void printList(list_t* inList) {

    // IF POINTER IS NULL, RETURN -1 (ERROR MESSAGE)
    if (inList == NULL) {
        return;
    } // IF
    
    // IF LIST IS EMPTY, PRINT APPROPRIATE MESSAGE
    if (listEmpty(inList) == 1) {
        printf("The list is empty -- nothing to print.");
    } // IF

    // DECLARE/INITIALIZE ITERATOR TO HEAD OF LIST
    node_t* iter = inList->head;

    // WHILE `iter` HAS NOT REACHED END OF LIST, PRINT
    // VALUE IN NODE AND MOVE TO NEXT NODE
    while (iter != NULL) {
       printNode(iter);
       iter = iter->next;
    } // WHILE

    printf("\n");

} // FUNCTION `printList'

/* --------------------------------------------------------
 * FUNCTION `insertFront` INSERTS A NEW 'kvpair_t' OBJ AT
 * THE BEGINNING OF THE LIST; RETURNS 1 IF SUCCESSFUL AND
 * -1 IF NOT SUCCESSFUL
 */
 
int insertFront(list_t* inList, kvpair_t* inKVpair) {

    // IF POINTER IS NULL, RETURN -1 (ERROR MESSAGE)
    if (inList == NULL) {
        return -1;
    } // IF
   
    // CREATE A NEW NODE TO STORE THE VALUE
    node_t* newNode = makeNode(inKVpair);

    // VERIFY THAT MALLOC SUCCEEDED
    if (newNode == NULL) {
        return -1;
    } // IF    

    // ASSIGN CURR HEAD TO NEW NODE'S `next` ATTRIBUTE
    newNode->next = inList->head;

    // SET NEW NODE AS HEAD OF LIST
    inList->head = newNode;

    // IF NEW NODE IS FIRST NODE, ALSO SET AS TAIL
    if (newNode->next == NULL) {
        inList->tail = newNode;
    } // IF

    return 1; 

} // FUNCTION `insertFront`

/* --------------------------------------------------------
 * FUNCTION `insertRear` INSERTS A NEW `kvpair_t` OBJ AT
 * THE END OF THE LIST; RETURNS 1 IF SUCCESSFUL AND -1
 * IF NOT SUCCESSFUL
 */
 
int insertRear(list_t* inList, kvpair_t* inKVpair) {

    // IF POINTER IS NULL, RETURN -1 (ERROR MESSAGE)
    if (inList == NULL) {
        return -1; 
    } // IF
  
    // IF THE LIST IS EMPTY, INSERT AT FRONT OF LIST
    if (listEmpty(inList)) {
        insertFront(inList, inKVpair);
        return 1;
    } // IF

    // ELSE, CREATE A NEW NODE TO STORE THE VALUE
    node_t* newNode = makeNode(inKVpair);

    // VERIFY THAT MALLOC SUCCEEDED
    if (newNode == NULL) {
        return -1;
    } // IF

    // ASSIGN NEW NODE TO `next` ATTRIBUTE OF CURR TAIL
    // THEN, SET THE NEW NODE AS TAIL OF LIST
    else {
        inList->tail->next = newNode;
        inList->tail = newNode;
    } // ELSE
    
    return 1;

} // FUNCTION `insertRear`

/* --------------------------------------------------------
 * FUNCTION `deleteCustomerRecord` FREES A `customerRec`
 * OBJ. RETURNS 1 IF SUCCESSFUL; RETURNS -1 IF NOT SUCCESSFUL
 */

int deleteCustomerRecord(customerRec* inRec) {

    // IF `customerRec` OBJ IS NULL, RETURN
    if (inRec == NULL) {
        return -1;
    } // IF

    free(inRec->lname);
    free(inRec->fname);
    free(inRec->ssNum);
    inRec->lname = NULL;
    inRec->fname = NULL;
    inRec->ssNum = NULL;
    free(inRec);
    return 1;
} // FUNCTION `deleteCustomerRec`

/* --------------------------------------------------------
 * FUNCTION `deleteKVpair` FREES A `kvpair_t` OBJ. RETURNS 1
 * IF SUCCESSFUL; RETURNS -1 IF NOT SUCCESSFUL
 */

int deleteKVpair(kvpair_t* inKVpair) {

    // IF `kvpair_t` OBJ IS NULL, RETURN
    if (inKVpair == NULL) {
        return -1; 
    } // IF

    deleteCustomerRecord(inKVpair->value);
    inKVpair->value = NULL;
    free(inKVpair);
    return 1;
} // FUNCTION `deleteKVpair`

/* --------------------------------------------------------
 * FUNCTION `deleteNode` FREES A SINGLE NODE. RETURNS 1
 * IF SUCCESSFUL; RETURNS -1 IF NOT SUCCESSFUL
 */
 
int deleteNode(node_t* inNode) {

    // IF NODE IS NULL, RETURN
    if (inNode == NULL) {
        return -1;
    } // IF

    deleteKVpair(inNode->data);
    inNode->next = NULL;
    free(inNode);
    return 1;
} // FUNCTION `deleteNode`

/* --------------------------------------------------------
 * FUNCTION `deleteFront` REMOVES THE FIRST NODE IN A LIST;
 * RETURNS 1 IF SUCCESSFUL AND -1 IF NOT SUCCESSFUL
 */
 
int deleteFront(list_t* inList) {

    // DECLARE/INITIALIZE POINTER TO STORE ADDRESS OF
    // NODE TO BE DELETED
    node_t* temp = NULL;

    // IF LIST POINTER IS NULL, RETURN -1 (ERROR STATUS)
    if (inList == NULL) {
        return -1;
    }

    // ELSE IF LIST IS EMPTY, PRINT APPROPRIATE MESSAGE AND 
    // RETURN -1 (ERROR STATUS)
    else if (inList->head == NULL) {
        printf("List is empty -- nothing to delete.\n");
        return -1;
    }

    // ELSE IF LIST HAS ONLY ONE NODE, SET HEAD AND TAIL
    // OF LIST TO NULL AND FREE THE NODE
    else if (listLength(inList) == 1) {
        temp = inList->head;
        inList->head = NULL;
        inList->tail = NULL;
        deleteNode(temp);
        return 1;
    } // ELSE IF

    // ELSE IF LIST HAS MORE THAN ONE NODE, SET HEAD TO
    // 2ND NODE AND FREE THE ORIGINAL HEAD NODE
    else {
        temp = inList->head;
        inList->head = temp->next;
        deleteNode(temp);
        return 1;
    } // ELSE

} // FUNCTION `deleteFront`

/* --------------------------------------------------------
 * FUNCTION `deleteRear` REMOVES THE NODE AT THE TAIL OF
 * THE LIST; RETURNS 1 IF SUCCESSFUL AND -1 IF NOT SUCCESSFUL
 */
 
int deleteRear(list_t* inList) {

    // DECLARE/INITIALIZE POINTER TO STORE ADDRESS OF
    // NODE TO BE DELETED 
    node_t* temp = NULL;

    // IF POINTER TO LIST IS NULL, RETURN -1 (ERROR STATUS)
    if (inList == NULL) {
        return -1;
    } // IF

    // ELSE IF LIST IS EMPTY, PRINT APPROPRIATE MESSAGE
    // AND RETURN -1 (ERROR STATUS)
    else if (inList->head == NULL) {
        printf("List is empty -- nothing to delete.\n");
        return -1;
    } // ELSE IF

    // ELSE, THE LIST HAS AT LEAST ONE NODE
    else {

        // GET LENGTH OF LIST
        int numOfNodes = listLength(inList);
        
        // IF LIST HAS ONE NODE, DELETE NODE AT HEAD
        // AND SET BOTH HEAD AND TAIL TO NULL
        if (numOfNodes == 1) {
            temp = inList->head;
            inList->head = NULL;
            deleteNode(temp);
            inList->tail = NULL;
            return 1;
        } // IF

        // ELSE IF LIST HAS TWO NODES, DELETE NODE
        // AT TAIL, SET TAIL OF LIST TO CURR HEAD
        else if (numOfNodes == 2) {
            temp = inList->head->next;
            inList->head->next = NULL;
            deleteNode(temp);
            inList->tail = inList->head;
            return 1;
        } // ELSE IF

        // ELSE IF LIST HAS MORE THAN TWO NODES,
        // ITERATE THROUGH LIST UNTIL NODE `y`
        // IS THE TAIL
        else {
            node_t* x = inList->head;
            node_t* y = x->next;
            node_t* z = y->next;

            while (z != NULL) {
                x = y;
                y = z;
                z = z->next;
            } // WHILE

            // SET NODE BEFORE TAIL AS NEW TAIL
            // AND FREE OLD TAIL
            x->next = NULL;
            deleteNode(y);
            inList->tail = x;
            return 1;
        } // ELSE
    } // ELSE

} // FUNCTION `deleteRear`

/* ------------------------------------------------------
 * FUNCTION `deleteList` TRAVERSES AND DELETES EACH NODE
 * IN THE LIST; RETURNS 1 IF SUCCESSFUL AND -1 IF NOT
 * SUCCESSFUL
 */

int deleteList(list_t* inList) {

    // CREATE TWO NODE POINTERS TO ITERATE THROUGH LIST
    node_t* targetNode = inList->head;
    node_t* nextNode = NULL;

    // IF POINTER TO LIST IS NULL, RETURN -1 (ERROR MESSAGE)
    if (inList == NULL) {
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
        inList->head = NULL;
        inList->tail = NULL;
    } // IF

    // FREE LIST AND RETURN 1 (SUCCESS MESSAGE)
    free(inList);
    return 1;

} // FUNCTION `deleteList`

/* --------------------------------------------------------
 * FUNCTION `insert` CREATES A NEW NODE AND INSERTS A `kvpair_t` 
 * OBJ AT 'position' IN LIST; RETURNS 1 IF SUCCESSFUL AND 
 * -1 IF NOT SUCCESSFUL
 */
 
int insert(list_t* inList, int position, kvpair_t* inKVpair) {

    // DECLARE/INITIALIZE PSEUDO-BOOLEAN TO STORE
    // SUCCESS STATUS OF INSERT FUNCTIONS
    int insertSuccess = 0;

    // IF LIST POINTER IS NULL, RETURN -1 (ERROR MESSAGE)
    if (inList == NULL) {
        return -1;
    } // IF

    // ELSE IF LIST IS EMPTY OR INSERT POS IS 0 OR 1,
    // INSERT AT FRONT OF LIST AND RETURN SUCCESS STATUS
    else if (inList->head == NULL || position == 0 || position == 1) {
        insertSuccess = insertFront(inList, inKVpair);
        return insertSuccess;
    } // ELSE IF

    // ELSE, GET LENGTH OF LIST
    else {
        int lengthOfList = listLength(inList);
        
        // IF POS IS GREATER THAN CURR NUMBER OF NODES,
        // INSERT AT REAR OF LIST AND RETURN SUCCESS STATUS
        if (position > lengthOfList) {
            insertSuccess = insertRear(inList, inKVpair);
            return insertSuccess;
        } // IF

        // ELSE, GENERAL CASE
        else {
            // CREATE NEW NODE TO STORE VALUE
            node_t* newNode = makeNode(inKVpair);
            
            // IF MALLOC FAILED, RETURN -1 (FAIL STATUS)
            if (newNode == NULL) {
                return -1;
            } // IF
            
            // DECLARE ITERATOR AND SET TO HEAD
            node_t* currNode = inList->head;

            // DECLARE/INITIALIZE CURR POSITION TO 1 (HEAD)
            int currPos = 1;

            // ITERATE TO NODE BEFORE LOCATION OF NEW NODE
            // INSERTION
            while (currPos < position - 1) {
                currNode = currNode->next;
                currPos++;
            } // WHILE

            // ASSIGN NEW NODE AS `next` OF `currNode` AND
            // ASSIGN THE ORIGINAL `next` NODE OF `currNode`
            // AS THE `next` NODE OF NEW NODE
            node_t* nextNode = currNode->next;
            currNode->next = newNode;
            newNode->next = nextNode;
            return 1;
        } // ELSE
    } // ELSE
} // FUNCTION `insert`

/* --------------------------------------------------------
 * FUNCTION `delete` REMOVES A NODE AT `position` OF
 * A LIST; RETURNS 1 IF SUCCESSFUL AND -1 IF NOT SUCCESSFUL
 */
 
int delete(list_t* inList, int position) {

    // IF LIST POINTER IS NULL, RETURN -1 (ERROR STATUS)
    if (inList == NULL) {
        return -1;
    } // IF

    // INITIATLIZE PSEUDO-BOOLEAN VAR TO STORE STATUS OF
    // NODE DELETION
    int deleteSuccess;

    // GET LENGTH OF LIST
    int numOfNodes = listLength(inList);
    
    // IF ONLY ONE NODE, OR IF FIRST NODE TO BE DELETED,
    // CALL `deleteFront` AND RETURN SUCCESS STATUS
    if (numOfNodes == 1 || position == 0 || position == 1) {
        deleteSuccess = deleteFront(inList);
        return deleteSuccess;
    } // IF
    
    // ELSE IF LAST NODE TO BE DELETED, CALL `deleteRear`
    // AND RETURN SUCCESS STATUS
    else if (position >= numOfNodes) {
        deleteSuccess = deleteRear(inList);
        return deleteSuccess;
    } // ELSE IF
    
    // ELSE, GENERAL CASE
    else {
        // DECLARE AND INITIALIZE CURR POSITION TO HEAD
        int currPos = 1;
 
        // DECLARE ITERATOR AND SET TO HEAD
        node_t* currNode = inList->head;
        
        // ITERATE UNTIL ITERATOR POINTS TO NODE BEFORE
        // NODE TO BE DELETED
        while (currPos < position - 1) {
            currNode = currNode->next;
            currPos++;
        } // WHILE

        // ASSIGN CURR `next` NODE OF TARGET NODE TO
        // `next` POINTER OF NODE PRECEDING TARGET NODE;
        // DELETE TARGET NODE
        node_t* targetNode = currNode->next;
        currNode->next = targetNode->next;
        deleteNode(targetNode);

        return 1;
    } // ELSE
} // FUNCTION `delete`

/* --------------------------------------------------------
 * FUNCTION `findItem` FINDS A NODE CONTAINING A `kvpair_t` OBJ
 * WHOSE KEY IS EQUIVALENT TO `item`; RETURNS THE POSITION
 * IN LIST OF THE CORRESPONDING NODE; RETURNS 0 IF NOT IN LIST
 */ 

int findItem(list_t* inList, int item) {
    
    // IF LIST POINTER IS NULL, RETURN -1 (ERROR STATUS)
    if (inList == NULL) {
        return -1;
    } // IF

    // IF LIST IS EMPTY, RETURN -1 (ERROR STATUS)
    if (listEmpty(inList) == 1) {
        return -1;
    } // IF

    // DECLARE AND INITIALIZE ITERATORS TO FIRST AND
    // SECOND NODES IN LIST
    node_t* currNode = inList->head;
    node_t* nextNode = currNode->next;

    // SET CURRENT POSITION TO 1
    int currPos = 1;

    // WHILE `currNode` IS NOT THE TAIL,
    while (nextNode != NULL) {

        // CHECK IF `key` ATTRIBUTE MATCHES `inValue'
        if (currNode->data->key == item) {
            // IF MATCH, RETURN POSITION OF NODE
            return currPos;
        } // IF

        // IF NOT A MATCH, CONTINUE ITERATING
        currPos++;
        currNode = nextNode;
        nextNode = nextNode->next;
    } // WHILE

    // IN THE CASE THAT `currNode` IS THE TAIL,
    // RETURN POS OF TAIL IF KEY MATCHES `inValue`
    if (currNode->data->key == item) {
        return currPos;
    } // IF

    // ELSE, ITEM NOT IN LIST; RETURN 0
    else {
        return 0;
    } // ELSE

} // FUNCTION `findItem`
 
/* -------------------------------------------------------
 * FUNCTION `deleteItem` FINDS THE FIRST INSTANCE OF
 * A NODE CONTAINING THE KEY VALUE `item` AND DELETES
 * THE NODE FROM THE LIST; RETURNS 1 IF SUCCESSFUL
 * AND -1 IF NOT SUCCESSFUL
 */
 
int deleteItem(list_t* inList, int item) {

    // CALL `findItem` TO GET POSITION OF NODE
    // HOLDING VALUE MATCHING `inValue`
    int itemPos = findItem(inList, item);

    // IF IN LIST (NOT 0), DELETE ITEM AT POSITION
    if (itemPos > 0) {
        delete(inList, itemPos);
        return 1;
    } // IF

    // RETURN -1 (ERROR STATUS) IF ITEM NOT IN LIST
    return -1;
} // FUNCTION `deleteItem`

/* ------------------------------------------------------
 * FUNCTION `populateList` GETS A FILE NAME FROM USER,
 * AND FOR EACH CUSTOMER RECORD IN THE FILE, CREATES A
 * `customerRec` OBJ AND ADDS IT TO THE REAR OF THE LIST; 
 * RETURNS 1 IF SUCCESSFUL AND -1 IF NOT SUCCESSFUL; 
 * RETURN -2 IF ERROR OPENING FILE
 */ 

int populateList(list_t* inList) {

    // IF LIST IS NULL, RETURN -1 (GENERAL ERROR STATUS)
    if (inList == NULL) {
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

    // DECLARE VARS FOR LOOP
    char tempStr[300];

    // LOOP UNTIL EOF
    while (!feof(fileHandle)) {
        
        fgets(tempStr, 300, fileHandle);
        tempStr[strlen(tempStr)] = '\0';

        if (strlen(tempStr) > 50) {
            customerRec* currCustomer = parseLine(tempStr);
            if (currCustomer != NULL) {
                kvpair_t* newKVpair = getKVpair(currCustomer);
                insertRear(inList, newKVpair);
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

/* ------------------------------------------------------- */
