/* *****************************************************************  
 *    Implementation File: BST.c 
 *
 *    Programmer:    Norrec Nieh
 *    Course:        CS 5008, Summer 2022
 *    Date:          July 19, 2022
 *
 * *************************************************************** */
// ORIGINALLY INCLUDED FOR TESTING
// #include "BST.h"

/* ----------------------------------------------------------------
 * `createTree()` creates and returns a pointer to an empty tree.
 * --------------------------------------------------------------- */
bstnode_t* createTree() {

    bstnode_t* tree_p = NULL;
    return tree_p;

} // FUNCTION: `createTree()`

/* ----------------------------------------------------------------
 * `createNode()` mallocs and returns a pointer to a new node with
 *     the value of `item` assigned to its `data` attribute.
 * --------------------------------------------------------------- */
bstnode_t* createNode(int item) {

    bstnode_t* node_p = (bstnode_t*) malloc(sizeof(bstnode_t));
    node_p->data = item;
    node_p->leftChild = NULL;
    node_p->rightChild = NULL;
    return node_p;

} // FUNCTION: `createNode()`

/* ----------------------------------------------------------------
 * `treeEmpty()` returns 1 if the tree is empty and 0 if not empty.
 * --------------------------------------------------------------- */
int treeEmpty(bstnode_t* inNode) {

    if (inNode == NULL) {
        return 1;
    } // IF

    return 0;

} // FUNCTION: `treeEmpty()`

/* ----------------------------------------------------------------
 * `treeSize()` determines the number of nodes currently in the tree.
 *     Updates the value of `tempSize` to the number of nodes.
 * --------------------------------------------------------------- */
void treeSize(bstnode_t* start, int* tempSize) {

    if (*tempSize < 0) {
        return;
    } // IF

    // BASE CASE
    if (start == NULL) {
        return;
    } // IF

    (*tempSize)++;
    treeSize(start->leftChild, tempSize);
    treeSize(start->rightChild, tempSize);

} // FUNCTION: `treeSize()`

/* ----------------------------------------------------------------
 * `inTree()` recursively determines whether an item is in the BST.
 *     Updates the value of `tempBooleanInTree` to 1 if true and
 *     0 if false. Assumes `tempBooleanInTree` is initialized at 0.
 * --------------------------------------------------------------- */
void inTree(bstnode_t* start, int findItem, int* tempBooleanInTree) {

    // RETURN IF ITEM ALREADY FOUND
    if (*tempBooleanInTree == 1) {
        return;
    } // IF

    // BASE CASE
    if (start == NULL) {
        return;
    } // IF

    if (start->data == findItem) {
        *tempBooleanInTree = 1;
        return;
    } //

    inTree(start->leftChild, findItem, tempBooleanInTree);
    inTree(start->rightChild, findItem, tempBooleanInTree);

} // FUNCTION: `inTree()`

/* ----------------------------------------------------------------
 * `sumTree()` returns the sum of all the values in the BST.
 * --------------------------------------------------------------- */
int sumTree(bstnode_t* inRootPtr) {

    // BASE CASE
    if (inRootPtr == NULL) {
        return 0;
    } // IF

    return (inRootPtr->data) + sumTree(inRootPtr->leftChild) 
			     + sumTree(inRootPtr->rightChild); 

} // FUNCTION: `sumTree()`

/* ----------------------------------------------------------------
 * `addNodeBST()` adds a new leaf node with the value of `item` to
 *     its proper location in the BST.
 * --------------------------------------------------------------- */
int addNodeBST(bstnode_t** inRootPtr, int item) {

    if (inRootPtr == NULL) {
        return 0;
    } // IF

    // BASE CASE
    if (*inRootPtr == NULL) {
        *inRootPtr = createNode(item);
        return 1;
    } // IF

    else if (item < (*inRootPtr)->data) {
        addNodeBST(&((*inRootPtr)->leftChild), item);
    } // ELSE IF

    // else if (item >= (*inRootPtr)->data)
    else {
        addNodeBST(&((*inRootPtr)->rightChild), item);
    } // ELSE

    return 1;
    
} // FUNCTION: `addNodeBST()`

/* ----------------------------------------------------------------
 * `searchBSTforKey()` traverses the BST from the root and finds
 *     the node with the key as its value. Updates `targetNode` to
 *     hold the address of the pointer to the target node. Assumes
 *     `targetNode` is NULL when function is called.
 * --------------------------------------------------------------- */
void searchBSTforKey(bstnode_t** inRootPtr, int key, bstnode_t** targetNode) {

    // RETURN IF KEY ALREADY FOUND
    if (*targetNode != NULL) {
        return;
    } // IF

    // BASE CASE
    if (*inRootPtr == NULL) {
        return;
    } // IF

    if ((*inRootPtr)->data == key) {
        *targetNode = *inRootPtr;
        return;
    } // IF

    searchBSTforKey(&((*inRootPtr)->leftChild), key, targetNode);
    searchBSTforKey(&((*inRootPtr)->rightChild), key, targetNode);

    return;
} // FUNCTION: `searchBSTforKey()`

/* ----------------------------------------------------------------
 * `getMinimumKey()` traverses the BST from the current node and
 *     returns the node in its subtree with the smallest value 
 * --------------------------------------------------------------- */
bstnode_t* getMinimumKey(bstnode_t* current) {

    // IF TREE IS EMPTY
    if (current == NULL) {
        return NULL;
    } // IF

    // BASE CASE
    if (current->leftChild == NULL) {
        return current;
    } // IF

    return getMinimumKey(current->leftChild);
} // FUNCTION: `getMinimumKey()`

/* ----------------------------------------------------------------
 * `printDFSpreorder()` traverses the BST via DFS and prints the
 *     values of its nodes PRE ORDER.
 * --------------------------------------------------------------- */
void printDFSpreorder(bstnode_t* start) {
    
    // BASE CASE
    if (start == NULL) {
        return;
    } // IF

    printf("%d  ", start->data);
    printDFSpreorder(start->leftChild);
    printDFSpreorder(start->rightChild);
    
} // FUNCTION: `printDFSpreorder()`

/* ----------------------------------------------------------------
 * `printDFSpostorder()` traverses the BST via DFS and prints the
 *     values of its nodes POST ORDER.
 * --------------------------------------------------------------- */
void printDFSpostorder(bstnode_t* start) {

    // BASE CASE
    if (start == NULL) {
        return;
    } // IF

    printDFSpostorder(start->leftChild);
    printDFSpostorder(start->rightChild);
    printf("%d  ", start->data);
    
} // FUNCTION: `printDFSpostorder()`

/* ----------------------------------------------------------------
 * `printDFSinorder()` traverses the BST via DFS and prints the
 *     values of its nodes IN ORDER.
 * --------------------------------------------------------------- */
void printDFSinorder(bstnode_t* start) {

    // BASE CASE
    if (start == NULL) {
        return;
    } // IF

    printDFSinorder(start->leftChild);
    printf("%d  ", start->data);
    printDFSinorder(start->rightChild);
    
} // FUNCTION: `printDFSinorder()`

/* ----------------------------------------------------------------
 * `deleteBSTfreeNode()` frees a single node in the BST.
 * --------------------------------------------------------------- */
int deleteBSTfreeNode(bstnode_t** inNode) {

    if (*inNode == NULL) {
        return 0;
    } // IF

    free(*inNode);
    return 1;

} // FUNCTION: `deleteBSTfreeNode()`

/* ----------------------------------------------------------------
 * `deleteNodeFromBST()` deletes the first node found in the BST
 *     which contains the key as its data value.
 * --------------------------------------------------------------- */
void deleteNodeFromBST(bstnode_t** inRootPtr, int key) {

    // BASE CASE
    if (*inRootPtr == NULL) {
        return;
    } // IF

    // MOVE LEFT IF KEY IS SMALLER THAN CURR NODE DATA
    if (key < (*inRootPtr)->data) {
        deleteNodeFromBST(&((*inRootPtr)->leftChild), key);
    } // IF

    // MOVE RIGHT IF KEY IS LARGER THAN CURR NODE DATA
    else if (key > (*inRootPtr)->data) {
        deleteNodeFromBST(&((*inRootPtr)->rightChild), key);
    } // ELSE IF

    // CURRENT NODE IS NODE TO BE DELETED
    else {
        
        // CASE: NODE IS LEAF OR SINGLETON 
        if ((*inRootPtr)->leftChild == NULL && (*inRootPtr)->rightChild == NULL) {
            deleteBSTfreeNode(inRootPtr);
            *inRootPtr = NULL;
        } // IF

        // CASE: NODE ONLY HAS LEFT CHILD
        else if ((*inRootPtr)->rightChild == NULL) {
            bstnode_t* temp = (*inRootPtr)->leftChild;
            deleteBSTfreeNode(inRootPtr);
            *inRootPtr = temp;
        } // ELSE IF

        // CASE: NODE ONLY HAS RIGHT CHILD
        else if ((*inRootPtr)->leftChild == NULL) {
            bstnode_t* temp = (*inRootPtr)->rightChild;
            deleteBSTfreeNode(inRootPtr);
            *inRootPtr = temp;
        } // ELSE IF

        // CASE: NODE HAS TWO CHILDREN
        else {
            bstnode_t* successor = getMinimumKey((*inRootPtr)->rightChild);
            (*inRootPtr)->data = successor->data;
            deleteNodeFromBST(&((*inRootPtr)->rightChild), successor->data);
        } // ELSE

    } // ELSE


} // FUNCTION: `deleteNodeFromBST()`

/* ----------------------------------------------------------------
 * `deleteTree()` recursively frees the BST.
 * --------------------------------------------------------------- */
void deleteTree(bstnode_t** inRootPtr) {

    // BASE CASE
    if (*inRootPtr == NULL) {
        return;
    } // IF

    deleteTree(&(*inRootPtr)->leftChild);
    deleteTree(&(*inRootPtr)->rightChild);
    deleteBSTfreeNode(inRootPtr);
    *inRootPtr = NULL;

} // FUNCTION: `deleteTree()`

/* ----------------------------------------------------------------
 * `populateTree()` reads a file of integers and adds each integer
 *     to the BST in order. Returns 1 on success, -1 on NULL tree
 *     error, and -2 on file read error.
 * --------------------------------------------------------------- */
int populateTree(bstnode_t** inRootPtr) {

    // IF TREE IS NULL, RETURN -1
    if (inRootPtr == NULL) {
        return -1;
    } // IF

    // GET FILE NAME FROM USER
    char* fileName = (char*) malloc ((sizeof(char) * 40));
    printf("Enter file name: ");
    scanf("%s", fileName);

    // OPEN FILE
    FILE* fileHandle = fopen(fileName, "r");

    // IF ERROR OPENING FILE, THROW ERROR AND RETURN -2
    if (fileHandle == NULL) {
        perror("ERROR");
        return -2;
    } // IF

    rewind(fileHandle);
    int currInt = 0;
    int addStatus = 1;

    // LOOP UNTIL EOF
    while (!feof(fileHandle)) {
        
        fscanf(fileHandle, " %d ", &currInt);
        addStatus = addNodeBST(inRootPtr, currInt);
        
        if (addStatus < 1) {
            printf("Error encountered adding %d to BST.\n", currInt);
            break;
        } // IF
    } // WHILE

    fclose(fileHandle);
    free(fileName);
    return 1;

} // FUNCTION: `populateTree()`



/* ORIGINAL TEST SUITE

int main() {

    bstnode_t* myBST = createTree();


    printf("\nTesting treeSize() function...\n");
    
    int nodeCount = 0;
    treeSize(myBST, &nodeCount);
    printf("Expected: 0 \t Actual: %d\n", nodeCount);

    addNodeBST(&myBST, 5);
    nodeCount = 0;
    treeSize(myBST, &nodeCount);
    printf("Expected: 1 \t Actual: %d\n", nodeCount);
    
    addNodeBST(&myBST, 10);
    nodeCount = 0;
    treeSize(myBST, &nodeCount);
    printf("Expected: 2 \t Actual: %d\n", nodeCount);
    
    addNodeBST(&myBST, 7);
    nodeCount = 0;
    treeSize(myBST, &nodeCount);
    printf("Expected: 3 \t Actual: %d\n", nodeCount);
    
    addNodeBST(&myBST, 3); 
    nodeCount = 0;
    treeSize(myBST, &nodeCount);
    printf("Expected: 4 \t Actual: %d\n", nodeCount);
    
    addNodeBST(&myBST, 12);
    nodeCount = 0;
    treeSize(myBST, &nodeCount);
    printf("Expected: 5 \t Actual: %d\n", nodeCount);

    printf("\nTesting traversals...\n");

    printf("PREORDER\n");
    printDFSpreorder(myBST);
    printf("\n");

    printf("POSTORDER\n");
    printDFSpostorder(myBST);
    printf("\n");

    printf("INORDER\n");
    printDFSinorder(myBST);
    printf("\n");

    printf("\nTesting sumTree() function...\n");
    int sum = sumTree(myBST);
    printf("Expected: 37 \t Actual: %d\n", sum);

    printf("\nTesting inTree() function...\n");
    int result = 0;
    inTree(myBST, 1, &result);
    printf("Is 1 in the tree? Expected: 0 \t Actual: %d\n", result);
    result = 0;
    inTree(myBST, 12, &result);
    printf("Is 12 in the tree? Expected: 1 \t Actual: %d\n", result);
    result = 0;
    inTree(myBST, 7, &result);
    printf("Is 7 in the tree? Expected: 1 \t Actual: %d\n", result);
    result = 0;
    inTree(myBST, 99, &result);
    printf("Is 99 in the tree? Expected: 0 \t Actual: %d\n", result);


    printf("\nTesting searchBSTforKey() function...\n");
    bstnode_t* targetNode = NULL;
    searchBSTforKey(&myBST, 12, &targetNode);
    if (targetNode != NULL) {
        printf("Node with key 12 found; data = %d \n", targetNode->data);
    } // IF
    else {
        printf("Node with key 12 not found; targetNode is NULL \n");
    } // ELSE

    targetNode = NULL;
    searchBSTforKey(&myBST, 7, &targetNode);
    if (targetNode != NULL) {
        printf("Node with key 7 found; data = %d \n", targetNode->data);
    } // IF
    else {
        printf("Node with key 7 not found; targetNode is NULL \n");
    } // ELSE

    targetNode = NULL;
    searchBSTforKey(&myBST, 1, &targetNode);
    if (targetNode != NULL) {
        printf("Node with key 1 found; data = %d \n", targetNode->data);
    } // IF
    else {
        printf("Node with key 1 not found; targetNode is NULL \n");
    } // ELSE

    printf("\nTesting getMinimumKey() function...\n");
    bstnode_t* resultNode = getMinimumKey(myBST);
    printf("Minimum found in BST: %d\n", resultNode->data);

    printDFSinorder(myBST);
    printf("\n");

    deleteNodeFromBST(&myBST, 7);
    printDFSinorder(myBST);
    printf("\n");

    deleteNodeFromBST(&myBST, 10);
    printDFSinorder(myBST);
    printf("\n");    

    deleteNodeFromBST(&myBST, 5);
    printDFSinorder(myBST);
    printf("\n\n");    

    deleteTree(&myBST);

    nodeCount = 0;
    treeSize(myBST, &nodeCount);
    printf("Tree deleted. Testing treeSize(). Expected: 0 \t Actual: %d\n\n", nodeCount);

    populateTree(&myBST);
    printDFSinorder(myBST);
    printf("\n");

    nodeCount = 0;
    treeSize(myBST, &nodeCount);
    printf("Tree populated. Testing treeSize(). Actual: %d\n\n", nodeCount);
    
    deleteTree(&myBST);

    return 0;
} // MAIN
*/
