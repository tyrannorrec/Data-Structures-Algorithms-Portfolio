/* **********************************************************
 *    stack.c       This is the implementation file for the
 *                    Char Stack ADT (array implementation). 
 *
 *                  1.  int stackEmpty()
 *                  2.  int stackFull()
 *                  3.  int push(char item)
 *                  4.  char TOS()
 *                  5.  int printStack()
 *                  6.  char pop()
 *
 *    Norrec Nieh
 *    CS5008 Summer 2022
 *    5/24/22
 * **********************************************************/

#include <stdio.h>
#include <stdlib.h>

/* ----------------------------------------------------------
 * CHECK IF STACK IS EMPTY.
 * RETURN 1 IF EMPTY; RETURN 0 IF NOT EMPTY
 */

int stackEmpty() {
    
    if (TOP == -1) {
        return 1;
    } // IF
    else {
        return 0;
    } // ELSE
} // FUNCTION `stackEmpty`

/* ----------------------------------------------------------
 * CHECK IF STACK IS FULL.
 * RETURN 1 IF FULL; RETURN 0 IF NOT FULL
 */

int stackFull() {

    if (TOP == (MAXSIZE - 1)) {
        return 1;
    } // IF
    else {
        return 0;
    } // ELSE
} // FUNCTION `stackFull`

/* ----------------------------------------------------------
 * PUSH CHAR ITEM ONTO STACK. 
 * RETURN 1 IF SUCCESSFUL; RETURN -1 AND PRINT ERROR MESSAGE 
 * IF FAILED
 */

int push(char item) {
    
    if (!stackFull()) {
        TOP++;
        stackArray[TOP] = item;
        return 1;
    } // IF
    else {
        printf("Couldn't push... stack is FULL.\n");
        return -1;
    } // ELSE
} // FUNCTION `push`

/*  ----------------------------------------------------------
 * RETURN TOP OF STACK.
 * RETURN CHAR AT TOP OF STACK. IF STACK IS EMPTY, RETURN BLANK
 * AND PRINT ERROR MESSAGE
 */

char TOS() {

    if (!stackEmpty()) {
        return stackArray[TOP];
    } // IF
    else {
        printf("Stack is empty... there is no TOP.\n");
        return ' ';
    } // ELSE
} // FUNCTION `TOS`

/* ----------------------------------------------------------
 * PRINT CONTENTS OF STACK.
 * PRINT EACH CHAR VALUE IN STACK FROM TOP TO BOTTOM. RETURN
 * 1 IF SUCCESSFUL. IF STACK IS EMPTY, RETURN -1 AND PRINT
 * ERROR MESSAGE.
 */

int printStack() {
   
    int tempTop = TOP;

    if (!stackEmpty()) {
        while (tempTop != -1) {
            printf("%c    ", stackArray[tempTop]);
            tempTop--;
        } // WHILE
        printf("\n");
        return 1;
    } // IF
    else {
        printf("Nothing to print... stack is EMPTY.\n");
        return -1;
    } // ELSE

} // FUNCTION `printStack`

/* ----------------------------------------------------------
 * POP THE TOP OF STACK.
 * REMOVE THE TOP CHAR FROM THE STACK. RETURN THE CHAR.
 * IF STACK IS EMPTY, RETURN BLANK.
 */

char pop() {

    char tempVal;

    if (!stackEmpty()) {
        tempVal = stackArray[TOP];
        TOP--;
        return tempVal;
    } // IF
    else {
        // ELSE IF STACK EMPTY, PRINT ERROR STATEMENT. IMPLEMENTED
        // IN `menuStack.c` TO PREVENT STATEMENT BEING PRINTED IN
        // `stackParentheses.c`, WHERE SUCH INFO IS NOT NEEDED
        return(' ');
    } // ELSE
} // FUNCTION `pop`

/* ---------------------------------------------------------- */
