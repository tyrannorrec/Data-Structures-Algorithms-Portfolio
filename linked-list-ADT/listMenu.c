/* *******************************************************
 *     listMenu.c    This is the menu implementation file 
 *                   for the Singly-Linked List ADT
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
 *   Algorithm:  print command menu; use do-while loop
 *               to get user input and execute command
 *               to manipulate singly-linked list; program
 *               ends when user input is 14 (QUIT command); 
 *
 * *******************************************************/

#include "list.h"
#include "list.c"

// INCLUDING `stdio.h` AND `ctype.h` TO USE 'isdigit'
// BUILT-IN FUNCTION IN `readUserChoice`
#include <stdio.h>
#include <ctype.h>

/* --------------------------------------------------------
 * FUNCTION `printMenu` PRINTS ALL OPTIONS AVAILABLE TO USER.
 * RETURNS NOTHING
 */

void printMenu() {

    printf("------------------------------------\n"
           "    1 -- INSERT FRONT\n"
           "    2 -- INSERT REAR\n"
           "    3 -- INSERT at Position\n"
           "    4 -- DELETE FRONT\n"
           "    5 -- DELETE REAR\n"
           "    6 -- DELETE at Position\n"
           "    7 -- LIST LENGTH\n"
           "    8 -- EMPTY LIST?\n"
           "    9 -- FIND ITEM\n"
           "   10 -- FIND & DELETE ITEM\n"
           "   11 -- PRINT LIST\n"
           "   12 -- POPULATE LIST\n"
           "   13 -- DELETE LIST\n" 
           "   14 -- QUIT\n"
           "------------------------------------\n");

} // FUNCTION `printMenu`

/* -------------------------------------------------------
 * FUNCTION `readMenuChoice` GETS AN INT FROM THE USER
 * AND RETURNS IT
 */ 

int readMenuChoice() {

    // DECLARE AND INITIALIZE CHAR VAR TO STORE USER INPUT
    int userChoice;

    // WHILE `userChoice` VALUE IS SMALLER THAN 1 OR GREATER THAN 14,
    // PRINT PROMPT AND READ OPTION NUMBER INTO `userChoice`
    do {
        printf("Enter choice (1-14): ");

        // SPACE BEFORE `%d` ADDED TO AVOID READING IN `\n`
        // AS SEPARATE ENTITY
        scanf(" %d", &userChoice);

    } while (userChoice < 1 || userChoice > 14);

    // RETURN VALUE STORED IN `userChoice`
    return userChoice;
} // FUNCTION `readMenuChoice`

/* ------------------------------------------------------
 * MAIN
 */ 

int main() {

    // CREATE LIST
    sList_t* myList = createList();
    
    // DECLARE AND INITIALIZE VAR TO STORE USER INPUT
    int userInput = 0;
    
    // DO WHILE USER UNPUT IS NOT 14 (QUIT)
    do {
        // PRINT MENU
        printMenu();
        
        // GET USER INPUT
        userInput = readMenuChoice();

        // DECLARE VARS FOR USE IN SWITCH CASES
        int inValue, insertSuccess, deleteSuccess;

        switch (userInput) {

            case 1: { // INSERT FRONT
                // GET VALUE TO INSERT
                printf("Enter the value to insert at front of list:  ");
                scanf("%d", &inValue);
                // CALL `insertFront`; RETURN SUCCESS BOOL
                insertSuccess = insertFront(myList, inValue);
                // PRINT APPROPRIATE STATEMENTS IF SUCCESSFUL / NOT SUCCESSFUL      
                if (insertSuccess == 1) {
                    printf("%d successfully inserted at front of list.\n", inValue);
                    printf("List is now:    ");
                    printList(myList);
                } // IF
                else {
                    printf("Insertion failed.\n");
                } // ELSE
                break;
            } // CASE 1: INSERT FRONT

            case 2: { // INSERT REAR
                // GET VALUE TO INSERT
                printf("Enter the value to insert at rear of list:  ");
                scanf("%d", &inValue);
                // CALL `insertRear`; RETURN SUCCESS BOOL
                insertSuccess = insertRear(myList, inValue);  
                // PRINT APPROPRIATE STATEMENTS IF SUCCESSFUL / NOT SUCCESSFUL      
                if (insertSuccess == 1) {      
                    printf("%d successfully inserted at rear of list.\n", inValue); 
                    printf("List is now:    ");
                    printList(myList);
                } // IF
                else {
                    printf("Insertion failed.\n");
                } // ELSE
                break;
            } // CASE 2: INSERT REAR

            case 3: { // INSERT AT POSITION
                // INITIALIZE VAR TO STORE POSITION
                int inPos;
                // GET VALUE AND POSITION TO INSERT
                printf("Enter the value to insert:  ");
                scanf("%d", &inValue);
                printf("Enter the position to insert:  ");
                scanf("%d", &inPos);
                // CALL `insert`; RETURN SUCCESS BOOL
                insertSuccess = insert(myList, inValue, inPos);  
                // PRINT APPROPRIATE STATEMENTS IF SUCCESSFUL / NOT SUCCESSFUL       
                if (insertSuccess == 1) {
                    printf("%d successfully inserted at position %d.\n", inValue, inPos);
                    printf("List is now:    ");
                    printList(myList);
                } // IF
                else {
                    printf("Insertion failed.\n");
                } // ELSE
                break;
             } // CASE 3: INSERT AT POSITION

            case 4: { // DELETE FRONT
               // CALL `deleteFront`; RETURN SUCCESS BOOL
               deleteSuccess = deleteFront(myList);
               // PRINT APPROPRIATE STATEMENTS IF SUCCESSFUL / NOT SUCCESSFUL
               if (deleteSuccess == 1) {
                   printf("Item at front successfully deleted.\n");
                   if (listEmpty(myList) == 0) {
                       printf("List is now:    ");
                   } // IF
                   printList(myList);
               } // IF
               break;
            } // CASE 4: DELETE FRONT

            case 5: { // DELETE REAR
               // CALL `deleteRear`; RETURN SUCCESS BOOL
               deleteSuccess = deleteRear(myList);
               // PRINT APPROPRIATE STATEMENTS IF SUCCESSFUL / NOT SUCCESSFUL
               if (deleteSuccess == 1) {
                   printf("Item at rear successfully deleted.\n");
                   if (listEmpty(myList) == 0) {
                       printf("List is now:    ");
                   } // IF
                   printList(myList);
               } // IF
               break;
            } // CASE 5: DELETE REAR

            case 6: { // DELETE AT POSITION
               // DECLARE VAR TO STORE POSITION
               int inPos;
               // GET POSITION OF VALUE TO DELETE
               printf("Enter the position of the value to delete:  ");
               scanf("%d", &inPos);
               // CALL `delete`; RETURN SUCCESS BOOL
               deleteSuccess = delete(myList, inPos);
               // PRINT APPROPRIATE STATEMENTS IF SUCCESSFUL / NOT SUCCESSFUL
               if (deleteSuccess == 1) {
                   int posDeleted = inPos;
                   int itemsLeft = listLength(myList);
                   if (inPos > itemsLeft) {
                       posDeleted = itemsLeft + 1; 
                   } // IF
		   if (inPos < 1) {
                       posDeleted = 1;
                   } // IF
                   printf("Item at position %d successfully deleted.\n", posDeleted);
                   if (listEmpty(myList) == 0) {
                       printf("List is now:    ");
                   } // IF
                   printList(myList);
               } // IF
               break;
            } // CASE 6: DELETE AT POSITION

            case 7: { // LIST LENGTH
                // GET NUM OF NODES IN LIST
                int numOfNodes = listLength(myList);
                // IF NOT ERROR CODE, PRINT NUM OF NODES. ELSE, PRINT ERROR MESSAGE
                if (numOfNodes > -1) {
                    printf("There are %d items in the list.\n", numOfNodes);
                } // IF
                else {
                    printf("Could not get list length.\n");
                } // ELSE
                break;
            } // CASE 7: LIST LENGTH
             
            case 8: { // EMPTY LIST?
                // CALL `listEmpty` TO FIND OUT IF LIST IS EMPTY
                int listIsEmpty = listEmpty(myList);
                // PRINT APPROPRIATE STATEMENTS IS LIST IS EMPTY OR IS NOT EMPTY
                if (listIsEmpty == 1) {
                    printf("The list is empty.\n");
                } // IF
                else {
                    printf("The list is not empty.\n");
                } // ELSE
                break;
            } // CASE 8: EMPTY LIST?
    
            case 9: { // FIND ITEM
                // GET VALUE FROM USER
                printf("Enter the value to find:  ");
                scanf("%d", &inValue);
                // CALL `findItem` TO GET POS OF VALUE IN LIST
                int itemPos = findItem(myList, inValue);
                // IF NOT ERROR, PRINT RESULT. ELSE, PRINT ERROR MESSAGE
                if (itemPos > 0) {                
                    printf("The item %d was found at position %d.\n", inValue, itemPos);
                } // IF
                else {
                    if (listEmpty(myList) == 1) {
                        printf("Item not found -- the list is empty.\n");
                    } // IF
                    else {
                        printf("The item was not found in the list.\n");
                    } // ELSE
                } // ELSE
                break;
            } // CASE 9: FIND ITEM

            case 10: { // FIND & DELETE ITEM 
                // GET VALUE FROM USER TO FIND AND DELETE
                printf("Enter the value to find and delete:  ");
                scanf("%d", &inValue);
                // CALL `deleteItem`; RETURN SUCCESS BOOL
                deleteSuccess = deleteItem(myList, inValue);
                // PRINT APPROPRIATE STATEMENTS IF SUCCESSFUL / NOT SUCCESSFUL
                if (deleteSuccess == 1) {
                    printf("The item %d was deleted.\n", inValue);
                    if (listEmpty(myList) == 0) {
                        printf("List is now:    ");
                    } // IF
                    printList(myList);
                } // IF
                else {
                    printf("The list is empty. Nothing to delete.\n");
                } // ELSE
                break;
            } // CASE 10: FIND & DELETE ITEM     

            case 11: { // PRINT LIST
                // CALL `printList` TO PRINT LIST
                if (listEmpty(myList) == 0) {
                    printf("List is now:    ");
                } // IF
                printList(myList);
                break;
            } // CASE 11: PRINT LIST

            case 12: { // POPULATE LIST
                // CALL `populateList`
                int populateSuccess = populateList(myList);

                // IF RETURNED -1, GENERAL ERROR; PRINT ERROR STATEMENT
                if (populateSuccess == -1) {
                    printf("Error. List not populated.\n");
                } // IF
                // ELSE IF RETURNED -2, SPECIFIC FILE INPUT ERROR
                else if (populateSuccess == -2) {
                    printf("Returning to menu.\n");
                } // ELSE IF
                // ELSE, POPULATE SUCCESS; PRINT LIST
                else { 
                    printf("List is now:    ");
                    printList(myList);
                } // ELSE
               break;
            } // CASE 12: POPULATE LIST

            case 13: { // DELETE LIST
                // CALL `deleteList'
                deleteList(myList);
                // RE-CREATE LIST UNDER SAME POINTER NAME
                myList = createList();
                // PRINT SUCCESS MESSAGE
                printf("List deleted.\n");
                break;
            } // CASE 13: DELETE LIST

            default: // CASE 14: QUIT
                break;

        } // SWITCH
    } while (userInput != 14);

    // FREE LIST
    deleteList(myList);

    // PRINT QUIT MESSAGE
    printf("Quitting... See you!\n\n");

    return 0;

} // MAIN

/* -----------------------------------------------------*/
