#include "BST.h"
#include "BST.c"



/* ******************************************************************
 *   file BSTMenu.c contains the menu code and main driver of Binary
 *      Search Tree (BST).
 ********************************************************************/


// ---------------------------------------------------------- 
//  function PRINTMENU prints the menu choices 
// ---------------------------------------------------------- 

void printMenu() {
    system("clear");
    printf("----------------------------------- \n");
    printf("     1 -- ADD NODE to BST\n");
    printf("     2 -- DELETE NODE from BST\n");
    printf("     3 -- COMPUTE SUM of BST\n");
    printf("     4 -- TREE EMPTY?\n");
    printf("     5 -- TREE SIZE\n");
    printf("     6 -- NODE in BST TREE?\n");
    printf("     7 -- PRE-ORDER TRAVERSAL and PRINT \n");
    printf("     8 -- IN-ORDER TRAVERSAL and PRINT\n");
    printf("     9 -- POST-ORDER TRAVERSAL and PRINT\n");
    printf("    10 -- POPULATE BST TREE\n");
    printf("    11 -- DELETE BST TREE\n");
    printf("    12 -- QUIT \n");
    printf("----------------------------------- \n");
}// function PRINTMENU

/* ********************************************************* */

// ---------------------------------------------------------- 
//  function GETUSERCHOICE gets input from user and returns integer
// ---------------------------------------------------------- 

int getUserChoice() {
    int tempChoice = 0;

    printMenu();
    printf("Enter choice (1-12): ");
    fflush(stdin);
    scanf("%d", &tempChoice);
    printf("\n");
    return tempChoice;

} // function GETUSERCHOICE

/* ********************************************************* */

// ---------------------------------------------------------- 
//  function EXECUTE_MENU displays menu and implements choice
//
// ---------------------------------------------------------- 

int executeMenu(bstnode_t** inRootPtr) {
    int tempChoice = 0;
    int myNum = 0;
    int tempNum = 0;
    char myChar = '0';

    tempChoice = getUserChoice();
    int statusNum = 0;
    int userPosition = 0;

    
    
    switch (tempChoice) {

        // -------------------------------------------------------------------------
        // CASE 1:  ADD NODE TO BINARY SEARCH TREE
        case (1): {
            printf("Enter value to ADD to BST TREE: ");
            fflush(stdin);
            scanf("%d", &tempNum);

            statusNum = addNodeBST(inRootPtr, tempNum);
            if (statusNum != -1){
                 printf("New BINARY SEARCH TREE is now... \n");
                 printDFSpreorder(*inRootPtr);
            }//IF
            break;
        }//CASE 1 ... ADD NODE

        // -------------------------------------------------------------------------

        // CASE 2: DELETE NODE FROM BST 
        case (2): {
            printf("Enter value to DELETE from TREE: ");
            fflush(stdin);
            scanf("%d", &tempNum);
            deleteNodeFromBST(inRootPtr, tempNum);
            if (statusNum != -1){
                  if (!treeEmpty(*inRootPtr))
                       printf("BST TREE is now... \n");
                       printDFSpreorder(*inRootPtr);
                  }//IF
                 break;
        }//CASE 2 DELETE NODE FROM BST

        // -------------------------------------------------------------------------
        
        // CASE 3:  COMPUTE SUM OF BST
        case (3): {
            int mySum = sumTree(*inRootPtr);
            printf("The SUM of the BST TREE is %d.\n", mySum);
            break;
        }//CASE 3 COMPUTE SUM OF BST

        // -------------------------------------------------------------------------

        //CASE 4 TREE EMPTY?
        case (4): {
             if (treeEmpty(*inRootPtr)){
                 printf("BST Tree IS empty.\n");
             }//IF
             else{
                 printf("BST Tree IS NOT empty.\n");
             }//ELSE
             break;
         }//CASE 4 TREE EMPTY?
        // -------------------------------------------------------------------------

         //CASE 5 TREE SIZE?
         case (5): {
               int mySize = 0;
               treeSize(*inRootPtr, &mySize);
               printf("The SIZE of the Tree is %d nodes.\n",mySize);
               break;
         }//CASE 5 TREE SIZE?

        // -------------------------------------------------------------------------
        
        // CASE 6:  NODE IN BST?
        case (6): {
            int myInTree = 0;
            printf("Enter value to NODE to check in Tree: ");
            fflush(stdin);
            scanf("%d", &tempNum);
            inTree(*inRootPtr, tempNum,&myInTree);
            if (myInTree == 1) {
                printf("Node %d IS in the BST Tree.\n", tempNum);
            }//IF
            else{
                printf("Node %d IS NOT in the BST Tree.\n", tempNum);
            }//ELSE

            break;
        }//CASE 6  NODE IN TREE?

        // -------------------------------------------------------------------------

        // CASE 7: PRE-ORDER TRAVERSAL AND PRINT
        case (7): {
            if (!treeEmpty(*inRootPtr)){
                printf("PRE-ORDER TRAVERSAL: \n");
                printDFSpreorder(*inRootPtr);
            }//IF
            else {
                printf("BST Tree is empty .. nothing to print. \n");
            }//ELSE
            break;
        }//CASE 7

        // -------------------------------------------------------------------------
        // CASE 8: IN-ORDER TRAVERSAL AND PRINT
        case (8): {
            if (!treeEmpty(*inRootPtr)){
                printf("IN-ORDER TRAVERSAL: \n");
                printDFSinorder(*inRootPtr);
            }//IF
            else {
                printf("BST Tree is empty .. nothing to print. \n");
            }//ELSE
            break;
        }//CASE 8

        // CASE 9: POST-ORDER TRAVERSAL AND PRINT
        case (9): {
            if (!treeEmpty(*inRootPtr)){
                printf("POST-ORDER TRAVERSAL: \n");
                printDFSpostorder(*inRootPtr);
            }//IF
            else {
                printf("BST Tree is empty .. nothing to print. \n");
            }//ELSE
            break;
        }//CASE 9


        // -------------------------------------------------------------------------

        // CASE 10: POPULATE TREE BY READING DATA FROM A FILE
        case (10): {
           populateTree(inRootPtr);
           break;
        }//CASE 10

        // CASE 11: DELETE TREE 
        case (11): {
           deleteTree(inRootPtr);
           break;
        }//CASE  11
        // -------------------------------------------------------------------------
        // CASE 12 QUIT program

        case (12): {
            deleteTree(inRootPtr);
            printf("Quitting now.  Bye.  \n");
            break;
        }//CASE 12

        default: {
            printf("invalid choice ... choose again \n");
        }//DEFAULT
    } //SWITCH
    fflush(stdin);
    myChar = getchar();
    myChar = getchar();
    fflush(stdout);
    return tempChoice;

} // function EXECUTE MENU

/* ********************************************************** */

void showListADT(bstnode_t** inRootPtr){

    int userChoice = -1;

    do {
        userChoice = executeMenu(inRootPtr); 
    } while (userChoice != 12);

} // function SHOWLISTADT

/****************************************************************/

int main() {
    
     bstnode_t* root = createTree();
     showListADT(&root);

     return 0;
} //MAIN
