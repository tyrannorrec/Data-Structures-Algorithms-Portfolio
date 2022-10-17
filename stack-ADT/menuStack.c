/* ******************************************************
 *    menuStack.c    This is the main file for the
 *                   menuStack program.
 *
 *    Programmer:    Norrec Nieh
 *    Course:        CS5008 Summer 2022
 *    Date:          May 24, 2022
 *    
 *    Algorithm:     print command menu; use do-while loop
 *                   to get user input and execute command
 *                   to manipulate stack; program ends
 *                   when user input is 7 (QUIT command);   
 * ******************************************************/

#include "stack.h"
#include "stack.c"

// INCLUDING `studio.h` AND `ctype.h` TO USE `isdigit` 
// BUILT-IN FUNCTION IN `readUserChoice()`
#include <stdio.h>
#include <ctype.h>

/* ------------------------------------------------------
 * FUNCTION `printMenu()` PRINTS ALL OPTIONS AVAILABLE TO USER. 
 * RETURNS NOTHING.
 */

void printMenu() {

    printf("\n-------------------------------------\n"
           "    1 -- PUSH \n"
           "    2 -- POP \n"
           "    3 -- Empty Stack? \n"
           "    4 -- Full Stack? \n"
           "    5 -- Print Stack \n"
           "    6 -- Print Top-Of-Stack \n"
           "    7 -- QUIT \n"
           "-------------------------------------\n");     

} // FUNCTION `printMenu'

/* ------------------------------------------------------
 * FUNCTION `readMenuChoice()` GETS AN INT FROM THE USER
 * AND RETURNS IT.
 */ 

int readMenuChoice() {

    // DECLARE AND INITIALIZE CHAR VAR TO STORE USER INPUT
    char userChoice;
 
    // WHILE `userChoice` IS NOT A CHAR REPRESENTING A DIGIT, 
    // OR ITS VALUE IS SMALLER THAN 1 OR GREATER THAN 7, 
    // PRINT PROMPT AND READ OPTION NUMBER INTO `userChoice`.
    //    
    do {
        printf("Enter choice (1-7): ");
        
        // SPACE BEFORE `%c` ADDED TO AVOID READING IN `\n` 
        // AS SEPARATE ENTRY
        scanf(" %c", &userChoice);
        
    } while ((isdigit(userChoice) == 0) || (userChoice - '0') < 1 
                                        || (userChoice - '0') > 7);

    // RETURN INT OF VALUE STORED IN `userChoice` (IMPLICIT CONVERSION)
    return userChoice - '0';
} // FUNCTION `readMenuChoice'

/* ------------------------------------------------------
 * MAIN
 */

int main() {
    
    // INITIALIZE INT VAR TO STORE USER CHOICE
    int userChoice;

    // ITERATE UNTIL USER SELECTS 7 TO QUIT
    do {
        // PRINT MENU TO TERMINAL
        printMenu();

        // CALL `readMenuChoice` TO GET COMMAND
        userChoice = readMenuChoice();

        // INITIALIZE VARS TO STORE INPUT CHAR, TOS CHAR, AND PSEUDO-BOOLEANS
        char input;
        char topOfStack;
        int wasSuccessful, isEmpty, isFull;
 
        switch (userChoice) {
            
            case 1: { // PUSH
                // GET USER INPUT AND STORE IN `input` VAR
                printf("Enter a character to PUSH: ");
                scanf(" %c", &input);
                // CALL `push` FUNCTION. IF FAILED, FUNCTION WILL PRINT ERROR MESSAGE
                wasSuccessful = push(input);
                // IF SUCCESSFUL, PRINT SUCCESS MESSAGE
                if (wasSuccessful == 1) {
                    printf("%c was pushed onto the stack.\n", input);
                } // IF
                break;
            } // CASE 1

            case 2: { // POP
                // CALL `pop` FUNCTION. RETURN TOP OF STACK TO `topOfStack` VAR
                topOfStack = pop();
                // IF SUCCESSFUL, PRINT SUCCESS MESSAGE. ELSE, PRINT ERROR MESSAGE
                if (topOfStack != ' ') {
                    printf("%c was popped.\n", topOfStack);
                } // IF
                else {
                    printf("Nothing to POP... stack is EMPTY.\n");
                } // ELSE
                break;
            } // CASE 2

            case 3: { // EMPTY STACK?
                // CALL `stackEmpty` FUNCTION. STORE PSEUDO-BOOL RESULT IN `isEmpty`
                isEmpty = stackEmpty();
                // EVALUATE `isEmpty` AND PRINT APPROPRIATE MESSAGE
                if (isEmpty == 1) {
                    printf("The stack is EMPTY.\n");
                } // IF
                else {
                    printf("The stack is NOT EMPTY.\n");
                } // ELSE
                break;
            } // CASE 3

            case 4: { // FULL STACK?
                // CALL `stackFull` FUNCTION. STORE PSEUDO-BOOL RESULT IN `isFull`
                isFull = stackFull();
                // EVALUATE `isFull` AND PRINT APPROPRIATE MESSAGE
                if (isFull == 1) {
                    printf("The stack is FULL.\n");
                } // IF
                else {
                    printf("The stack is NOT FULL.\n");
                } // ELSE
                break;
            } // CASE 4

            case 5: { // PRINT STACK
                // CALL `printStack` FUNCTION TO PRINT CONTENTS OF STACK. STORE
                // PSEUDO-BOOLEAN RESULT IN `wasSuccessful`
                wasSuccessful = printStack();
                break;
            } // CASE 5

            case 6: { // TOP-OF-STACK?
                // CALL `TOS` TO RETURN CHAR AT TOP OF STACK; STORE IN `topOfStack`
                topOfStack = TOS();
                // IF FAILED, FUNCTION WILL PRINT FAILURE MESSAGE
                // IF `topOfStack` IS NOT BLANK, PRINT SUCCESS MESSAGE
                if (topOfStack != ' ') {  
                	printf("%c is at the top of the stack.\n", topOfStack);
                } // IF
                break;
            } // CASE 6

            default: { // QUIT
                break;
            } // DEFAULT
        } // SWITCH

    } while (userChoice != 7);

    printf("Quitting. See you!\n");
    return 0;
} // MAIN
