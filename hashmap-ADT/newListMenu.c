/* ******************************************************************
 *                          MIDTERM PROGRAM    
 *
 *      Program:        listMenu.c
 *      Purpose:        contains the menu code and main driver of
 *			    updated linked list ADT.
 *
 *	Programmer:     Norrec Nieh
 *      Course:         CS5008, Summer 2022
 *      Date:           July 4, 2022
 *
 * ***************************************************************** */
#include "newList.h"
#include "newList.c"


list_t* myList = NULL;

// ---------------------------------------------------------- 
//  function PRINTMENU prints the menu choices for LINKED LIST ADT
// ---------------------------------------------------------- 

void printMenu() {
    system("clear");
    printf("----------------------------------- \n");
    printf("     1 -- INSERT FRONT \n");
    printf("     2 -- INSERT REAR \n");
    printf("     3 -- INSERT at Position \n");
    printf("     4 -- DELETE FRONT \n");
    printf("     5 -- DELETE REAR  \n");
    printf("     6 -- DELETE at Position \n");
    printf("     7 -- LIST LENGTH \n");
    printf("     8 -- EMPTY LIST? \n");
    printf("     9 -- FIND ITEM \n");
    printf("    10 -- FIND & DELETE ITEM \n");
    printf("    11 -- PRINT LIST \n");
    printf("    12 -- POPULATE LIST \n");
    printf("    13 -- DELETE LIST \n");
    printf("    14 -- QUIT \n");
    printf("----------------------------------- \n");
}// function PRINTMENU

/* ********************************************************* */

// ---------------------------------------------------------- 
//  function GETUSERCHOICE gets input from user and returns integer
// ---------------------------------------------------------- 

int getUserChoice() {
    int tempChoice = 0;

    printMenu();
    printf("Enter choice (1-14): ");
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

int executeMenu() {
    int tempChoice = 0;
    int myNum = 0;
    int tempNum = 0;
    char myChar = '0';
    customerRec*  myCR;
    kvpair_t*     myKV;

    tempChoice = getUserChoice();
    int statusNum = 0;
    int userPosition = 0;

    
    switch (tempChoice) {

        // -------------------------------------------------------------------------
        // CASE 1:  INSERT FRONT
        case (1): {
            // GET CUSTOMERREC;  GET KVPAIR
            myCR = getCustomer();
            myKV = getKVpair(myCR);

            statusNum = insertFront(myList, myKV);
            if (statusNum != -1){
                 printf("\nList is now... \n\n");
                 printList(myList);
            }//IF
            break;
        }//CASE 1

        // -------------------------------------------------------------------------

        // CASE 2:  INSERT REAR
        case (2): {

            // GET CUSTOMERREC;  GET KVPAIR
            myCR = getCustomer();
            myKV = getKVpair(myCR);
            tempNum = myKV->key;

            statusNum = insertRear(myList, myKV);
            if (statusNum != -1){
                  printf("Node with KEY %d inserted at REAR.\n", tempNum);
                  if (!listEmpty(myList))
                       printf("\nList is now... \n\n");
                  printList(myList);
            }//IF
            break;
        }//CASE 2  INSERT REAR

        // -------------------------------------------------------------------------
        
        // CASE 3:  INSERT AT INDICATED POSITION 
        case (3): {
            printf("Enter data to insert in list: \n");
            // GET CUSTOMERREC;  GET KVPAIR
            myCR = getCustomer();
            myKV = getKVpair(myCR);
            tempNum = myKV->key;

            printf("Enter position to insert: ");
            fflush(stdin);
            scanf("%d",&userPosition);


            statusNum = insert(myList, userPosition, myKV);
            if (statusNum != -1){
                  printf("Node with KEY %d inserted at position %d.\n",tempNum, userPosition);
                  if (!listEmpty(myList))
                       printf("List is now... \n\n");
                  printList(myList);
            }//IF
            break;
        }//CASE 3  INSERT at indicated position

        // -------------------------------------------------------------------------

        //CASE 4  DELETE FRONT 
        case (4): {
             statusNum = deleteFront(myList);
             if (statusNum != -1) {
                   printf("Deleted node at FRONT of list. \n");
                   if (!listEmpty(myList)){
                       printf("\nList is now... \n\n");
                       printList(myList);
                   }//IF
             }//IF
             break;
         }//CASE 4 delete front
        // -------------------------------------------------------------------------

         //CASE 5 DELETE REAR
         case (5): {
               statusNum = deleteRear(myList);
               if (statusNum != -1) {
                     printf("Deleted node at REAR of list. \n");
                     if (!listEmpty(myList))
                         printf("\nList is now... \n\n");
                     printList(myList);
               }//IF
               break;
         }//CASE 5 delete rear

        // -------------------------------------------------------------------------
        
        // CASE 6:  DELETE AT INDICATED POSITION 
        case (6): {
            printf("Enter position to delete: ");
            fflush(stdin);
            scanf("%d", &userPosition);
            statusNum = delete (myList, userPosition);
            if (statusNum != -1){
                  printf("Node at position %d has been deleted.\n", userPosition);
                  if (!listEmpty(myList))
                       printf("\nList is now... \n\n");
                  printList(myList);
            }//IF
            break;
        }//CASE 6  DELETE at indicated position

        // -------------------------------------------------------------------------

        // CASE 7: LIST LENGTH
        case (7): {
            tempNum = listLength(myList);
            if (tempNum > 0) {
                printf("List has %d nodes. \n", tempNum);
            }//IF
            else {
                printf("List is empty! \n");
            }//ELSE
            break;
        }//CASE 7

        // -------------------------------------------------------------------------

        // CASE 8: LIST EMPTY?
        case (8): {
            if (listEmpty(myList) < 1) {
                printf("List is NOT empty. \n");
            }//IF
            else {
                printf("List is empty! \n");
            }//ELSE
            break;
        }//CASE 8

        // -------------------------------------------------------------------------
        
        // CASE 9:  FIND POSITION OF KEY
        case (9): {
            printf("Enter KEY to find in List: ");
            fflush(stdin);
            scanf("%d", &tempNum);
            userPosition = findItem(myList, tempNum);
            if (userPosition > 0){
                  printf("KEY %d found at position %d.\n",tempNum, userPosition);
                 
		  node_t* iter = myList->head;
		  for (int i = 1; i < userPosition; i++) {
		      iter = iter->next;
		  } // FOR
		  printNode(iter);
            }//IF
            else {
                printf("KEY not found in List. \n");
            }
            break;
        }//CASE 9  FIND position


        // -------------------------------------------------------------------------

        // CASE 10:  FIND AND DELETE CUSTOMER REC VIA KEY
        case (10): {
            printf("Enter KEY to find and delete in List: ");
            fflush(stdin);
            scanf("%d", &tempNum);
            statusNum = deleteItem(myList, tempNum);
            
            if (statusNum > 0){
                  printf("KEY %d was deleted.\n",tempNum);
                  if (!listEmpty(myList))
                       printf("\nList is now... \n\n");
                  printList(myList);
            }//IF
            else {
                  printf("KEY not in List. Could not be deleted. \n");
            }
            break;
         }// CASE 10

        // -------------------------------------------------------------------------
        
        // CASE 11: PRINT LIST WITHOUT CHANGING IT
        case (11): {
            if (listEmpty(myList) == 1){
                printf("List is empty... nothing to print. \n");
            }//IF
            else {
                printf("\nList is now... \n\n");
                printList(myList);
            }//ELSE
            break;
        }//CASE  11

        // -------------------------------------------------------------------------

        // CASE 12: POPULATE LIST BY READING DATA FROM A FILE
        case (12): {
            int status = populateList(myList);
            if (status == 1) {
                printf("\nList populated! \n");
            } // IF
            break;
        }//CASE  12

        // -------------------------------------------------------------------------
        
        // CASE 13: DELETE LIST AND FREE MEMORY
        case (13): {
            deleteList(myList);
            printf("List deleted. \n");
            myList = makeList();
            break;
        }//CASE  13

        // -------------------------------------------------------------------------

        // CASE 14 QUIT program
        case (14): {
            printf("Quitting now. Bye.  \n");
            break;
        }//CASE 14

        // -------------------------------------------------------------------------

        default: {
            printf("Invalid choice... choose again. \n");
        }//DEFAULT
    } //SWITCH

    fflush(stdin);
    myChar = getchar();
    myChar = getchar();
    fflush(stdout);
    return tempChoice;

} // function EXECUTE MENU

/* ********************************************************** */

void showListADT(){

    int userChoice = -1;

    do {
        userChoice = executeMenu(); 
    } while (userChoice != 14);

} // function SHOWLISTADT

/****************************************************************/

int main() {

    myList = makeList();

    showListADT();

    deleteList(myList);
    return 0;
} //MAIN
