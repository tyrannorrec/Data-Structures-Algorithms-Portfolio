/* ******************************************************
 *     Program:		stack.c
 *     Purpose:         Implements a singly linked list 
 *                          based stack ADT
 *                      
 *     Programmer:	Norrec Nieh
 *     Course:		CS5008, Summer 2022
 *     Date:		June 2, 2022
 *
 * ******************************************************/

#define FULLSTACK 1000
sList_t* myStackList = NULL;

int TOS();
int stackEmpty();
int stackFull();
int push(int item);
int pop();
void printStack();
int deleteStack();
int populateStack();

/* ********************************************************* */

/* -------------------------------------------------
 * FUNCTION `stackEmpty` RETURNS 1 IF THE STACK IS EMPTY
 * AND RETURNS 0 IF THE STACK IS NOT EMPTY
 */

int stackEmpty() {    

    return listEmpty(myStackList);
} // FUNCTION `stackEmpty`

/* -------------------------------------------------
 * FUNCTION `stackFull` returns 1 IF THE STACK IS FULL
 * AND RETURNS 0 IF THE STACK IS NOT FULL
 */
 
int stackFull() {

    if (listLength(myStackList) == FULLSTACK) {
        return 1;
    } // IF
    else {
        return 0;
    } // ELSE
} // FUNCTION `stackFull`

/* -------------------------------------------------
 * FUNCTION `push` PUSHES AN INT (PARAM `item`) ONTO
 * THE STACK; RETURNS 1 IF SUCCESSFUL AND RETURNS
 * -1 IF NOT SUCCESSFUL
 */ 

int push(int item) {

    if (stackFull() == 1) {
        return -1;
    } // IF

    int pushSuccess = insertFront(myStackList, item);
    return pushSuccess;
} // FUNCTION `push`

/* -------------------------------------------------
 * FUNCTION `TOS` RETURNS DATA HELD BY TOP NODE
 * IN STACK; RETURNS -1 IF STACK IS EMPTY
 */ 

int TOS() {

    if (stackEmpty() == 0) {
        return myStackList->head->data;
    } // IF
    return -1;
} // FUNCTION `TOS`

/* ------------------------------------------------
 * FUNCTION `pop` DELETES THE TOP NODE IN STACK;
 * RETURNS THE VALUE HELD IN THE NODE; IF STACK
 * IS EMPTY, PRINT ERROR MESSAGE AND RETURN -1
 */ 

int pop() {
    
    if (stackEmpty() == 0) {
        int topOfStack = TOS();
        int deleteSuccess = deleteFront(myStackList);
        return topOfStack;
    } // IF
    else {
        printf("Stack is empty ... nothing to POP \n");
    } // ELSE
    return -1;
} // FUNCTION `pop`

/* -------------------------------------------------
 * FUNCTION `printStack` PRINTS ALL VALUES IN THE STACK,
 * FROM TOP TO BOTTOM. IF STACK IS EMPTY, PRINT
 * APPROPRIATE MESSAGE.
 */ 

void printStack() {

    if (stackEmpty() == 0) {
        printList(myStackList);
    } // IF
    else {
        printf("Stack is empty ... nothing to print\n");
    } // ELSE
}// FUNCTION `printStack`

/* ------------------------------------------------
 * FUNCTION `deleteStack` DELETES ALL VALUES IN THE STACK,
 * BY CALLING `deleteList`. RETURNS 1 IF SUCCESSFUL AND
 * -1 IF NOT SUCCESSFUL.
 */ 

int deleteStack() {

    if (deleteList(myStackList)) {
        return 1;
    } // IF
    return -1;

} // FUNCTION `deleteStack`

/* ------------------------------------------------
 * FUNCTION `populateStack` CALLS `populateListFront`
 * TO GET A FILE NAME FROM THE USER, PARSE THE FILE,
 * AND PUSH EACH INT IN THE FILE ONTO THE TOP OF STACK.
 */

int populateStack() {

    int populateSuccess = populateListFront(myStackList);
    return populateSuccess;

} // FUNCTION `populateStack`

/* *********************************************************   */
//   MENU SECTION  
/* *********************************************************   */

// ---------------------------------------------------------- 
//  function PRINTSTACKMENU prints the menu choices in the STACK ADT
// ---------------------------------------------------------- 

void printStackMenu() {
    system("clear");
    printf("----------------------------------- \n");
    printf("     1 -- PUSH  \n");
    printf("     2 -- POP   \n");
    printf("     3 -- Empty Stack? \n");
    printf("     4 -- Full Stack?  \n");
    printf("     5 -- Print Stack  \n");
    printf("     6 -- Print Top-Of-Stack  \n");
    printf("     7 -- Delete Stack \n");
    printf("     8 -- Populate Stack \n");
    printf("     9 -- QUIT \n");
    printf("----------------------------------- \n");
}// function PRINTSTACKMENU

/* ********************************************************* */

// ---------------------------------------------------------- 
//  function GETUSERSTACKCHOICE gets input from user and returns integer
// ---------------------------------------------------------- 

int getUserStackChoice() {
    int tempChoice = 0;
    char tempChar = 'Z';

    printStackMenu();
    printf("Enter choice (1-9): ");
    fflush(stdin);
    scanf("%d", &tempChoice);
    tempChar = getchar();
    printf("\n");
    return tempChoice;

} // function GETUSERSTACKCHOICE

/* ********************************************************* */

// ---------------------------------------------------------- 
//  function EXECUTESTACKMENU displays menu and implements choice
// ---------------------------------------------------------- 

int executeStackMenu() {
    int tempChoice = 0;
    char myInChar = '0';
    char newtempCbar = 'X';
    char tempChar = 'Y';
    int myNum = 0;
    int tempNum = 0;
    char tempCharCh = 'Z';
    char myChar = '0';

    tempChoice = getUserStackChoice();
    
    switch (tempChoice) {

        // CASE 1:  PUSH AN ITEM
        case (1): {
            fflush(stdin);
            printf("Enter value to Push... ");
            scanf("%d", &tempNum);

            if (push(tempNum) != -1){
                 printf("New stack is now... \n");
                 printStack();
            }//IF
            break;
        }//CASE 1


        // CASE 2:  POP AN ITEM
        case (2): {
            fflush(stdin);
            if (!stackEmpty()) {
                 myNum = pop();
                 printf("Just POPPED: %d \n", myNum);
                 if (!stackEmpty()){
                       printf("Stack is now... \n");
                       printStack();
                 }//IF
            }//IF
            else {
                printf("Stack Empty ... nothing to POP. \n");
            }//ELSE
            break;
        }//CASE 2

        // CASE 3: CHECK FOR EMPTY STACK
        case (3): {
            if (!stackEmpty()) {
                printf("Stack is NOT empty. \n");
            }//IF
            else {
                printf("Stack IS EMPTY! \n");
            }//ELSE
            break;
        }//CASE 3

        // CASE 4: CHECK FOR FULL STACK
        case (4): {
            if (!stackFull()) {
                printf("Stack is NOT full. \n");
            }//IF
            else {
                printf("Stack IS FULL! \n");
            }//ELSE
            break;
        }//CASE 4

        // CASE 5: PRINT STACK WITHOUT CHANGING IT
        case (5): {
            if (!stackEmpty()){
                 printf("Current stack is now:  \n");
            }//IF
            printStack();
            break;
        }//CASE 5

        // CASE 6: RETURNS A COPY OF THE TOP-OF-STACK
        case (6): {
            fflush(stdin);
            if (!stackEmpty()){
                 tempNum = TOS();
                 printf("Current Top-Of-Stack is now: %d  \n", tempNum);
            }//IF
            else {
                 printf("Stack is empty; there is no TOP \n");
            } //ELSE
            break;
        }//CASE 6
        
        // CASE 7: DELETE STACK 
        case (7): {
            int deleteSuccess = deleteStack();
            if (deleteSuccess == 1) {
                printf("Stack successfully deleted.\n");
                myStackList = createList();
            } // IF
            else {
                printf("Error: stack unsuccessfully deleted.\n");
            } // ELSE
            break;
        } // CASE 7

        // CASE 8: POPULATE STACK
        case (8): {
            int populateSuccess = populateStack();
            if (populateSuccess == -1) {
                printf("Error populating stack.\n");
            } // IF
            else if (populateSuccess == -2) {
                printf("Returning to menu.\n");
            } // ELSE IF
            else {
                printf("Stack successfully populated.\n");
            } // ELSE
            break;
        } // CASE 8

        // CASE 9: QUIT PROGRAM
        case (9): {
            printf("Quitting now.  Bye.  \n");
            break;
        } // CASE 9

        default: {
            printf("invalid choice ... choose again \n");
        }//DEFAULT
    } //SWITCH
    fflush(stdin);
    myChar = getchar();

    return tempChoice;

} // function EXECUTESTACKMENU

/* ********************************************************* */

// -------------------------------------------------
// function SHOWSTACKADT calls `executeMenu` in a loop
// until user chooses to quit 
// -------------------------------------------------

void showStackADT(){
    int userChoice = -1;

    do {
        userChoice = executeStackMenu(); 
    } while (userChoice != 9);

} // function SHOWSTACKADT

/* ********************************************************* */

// ------------------------------------------------
// MAIN
// ------------------------------------------------
/*
int main() {
    myStackList = createList();
    showStackADT();
    deleteStack();
    return 0;
}//MAIN
*/
/* ********************************************************** */
