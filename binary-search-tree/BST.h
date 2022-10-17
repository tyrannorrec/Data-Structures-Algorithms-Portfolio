#include <stdio.h>
#include <stdlib.h>

/* **************************************************************
*      Header File:  BST.h
*
*                     CREATE NODE, CREATE LIST, ADD
*                     PRINT PREORDER, POSTORDER, INORDER
*                     SUMTREE, TREEEMPTY, TREESIZE
*                     INTREE
*                     DELETENODE, SEARCHKEYSETPARENT
*                     DELETENODEFROMBST, DELETETREE
*                     POPULATETREE
*                     MENU Code
*
* **************************************************************/


//----------------------------------
typedef struct bstnode {
                int      data;
         struct bstnode* leftChild;
         struct bstnode* rightChild;
} bstnode_t;
//----------------------------------

/* **************************************************** */
bstnode_t* createTree();
bstnode_t* createNode(int item);
int treeEmpty(bstnode_t* inNode);
void treeSize(bstnode_t* start, int* tempSize);
void inTree(bstnode_t* start, int findItem, int* tempBooleanInTree);
int sumTree(bstnode_t* inRootPtr);
int addNodeBST(bstnode_t** inRootPtr, int item) ;
void searchBSTforKey(bstnode_t** inRootPtr, int key, bstnode_t** targetNode);
bstnode_t* getMinimumKey(bstnode_t* current);
void printDFSpreorder(bstnode_t* start);
void printDFSpostorder(bstnode_t* start);
void printDFSpostorderOTHER(bstnode_t* start);
void printDFSinorder(bstnode_t* start);
int deleteBSTfreeNode(bstnode_t** inNode);
void deleteNodeFromBST(bstnode_t** inrootPtr, int key);
void deleteTree(bstnode_t** inRootPtr);
int populateTree(bstnode_t** inRootPtr);
