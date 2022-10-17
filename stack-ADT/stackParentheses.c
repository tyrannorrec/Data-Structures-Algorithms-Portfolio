/* ******************************************************
 *    stackParentheses.c    This is the main file for the
 *                          stackParentheses program.
 *
 *           Programmer:    Norrec Nieh
 *           Course:        CS5008 Summer 2022
 *           Date:          May 26, 2022
 *    
 *           Algorithm:     read string (user input) into var;
 *                          call balanced_parentheses to parse
 *                          string character by character;
 *                          if char is LH (open) bracket, then 
 *                          PUSH onto stack; if char is closed
 *                          bracket, then call matchChar to
 *                          get the LH bracket; POP TOS and
 *                          compare with counterpart; iterate
 *                          until brackets inconsistent or
 *                          do not match; print corresponding
 *                          invalid message; if string
 *                          successfully traversed, evaluate
 *                          stack; if stack not empty, string
 *                          invalid due to unmatched LH brackets;
 *                          if stack empty, then string valid;
 *
 * ******************************************************/

#include "stack.h"
#include "stack.c"    

/* ------------------------------------------------------
 * FUNCTION `matchChar` TAKES AS A PARAM A RH (CLOSE) BRACKET 
 * CHAR SUCH AS '(', '[', OR '{', AND RETURNS ITS LH (OPEN)
 * BRACKET COUNTERPART
 */ 

char matchChar(char closeBracket) {
    
    if (closeBracket == ')') {
        return '(';
    } // IF
    else if (closeBracket == ']') {
        return '[';
    } // ELSE IF
    else if (closeBracket == '}') {
        return '{';
    } // ELSE IF
    else {
        return ' ';
    } // ELSE

} // FUNCTION `matchChar`

/* ------------------------------------------------------
 * FUNCTION `balanced_parantheses` TAKES IN A STRING WITHOUT
 * BLANKS AND EVALUATES IT FOR BALANCED PARENTHESES. IF STR
 * IS BALANCED AND CONSISTENT, RETURN 1. IF NOT, RETURN -1.
 */

int balanced_parentheses(char string[], int strLen) {
    
    // INITIALIZE VARS TO STORE POPPED LH BRACKET AND THE RESULT OF `matchChar`
    char topOfStack, counterpart;

    // ITERATE THROUGH ALL INDICES OF THE STRING/CHAR ARRAY
    for (int i = 0; i < strLen; i++) {
        
        // IF LH (OPEN) BRACKET, PUSH ONTO STACK
        if (string[i] == '(' || string[i] == '[' || string[i] == '{') {
            push(string[i]);  
        } // IF
        
        // ELSE IF RH (CLOSE) BRACKET, GET ITS LH COUNTERPART BY CALLING `matchChar`,
        // POP TOP OF STACK, AND COMPARE. 
        else if (string[i] == ')' || string[i] == ']' || string[i] == '}') {
            counterpart = matchChar(string[i]);
            topOfStack = pop();

            // IF TOP OF STACK IS DISTINCT FROM ITS COUNTERPART, CHECK IF ONE OR TWO ERRORS
            if (topOfStack != counterpart) {

                // IF NO TOP OF STACK (STACK EMPTY), THEN THERE IS NO LH BRACKET THAT
                // MATCHES THE RH BRACKET. RETURN -1
                if (topOfStack == ' ') {
                    printf("String is NOT VALID -- there is a RH bracket" 
                           " without a corresponding LH bracket\n");
                    return -1;
                } // IF

                // ELSE, IF TOS AND COUNTERPART ARE DISTINCT BUT STACK IS NOT EMPTY, THEN
                // BRACKETS ARE INCONSISTENT FOR OTHER REASONS. RETURN -1
                else {
                    printf("String is NOT VALID -- inconsistent brackets\n");
                    return -1;
                } // ELSE
            } // IF

            // IF TOS == COUNTERPART, THEN CONTINUE, HAVING POPPED THE TOS
        } // ELSE IF

        // IF CURR VALUE NOT A RH BRACKET, THEN IGNORE AND CONTINUE
    } // FOR


    // CHECK STACK IS NOT EMPTY, THERE ARE LH (OPEN) BRACKETS NOT CLOSED
    if (stackEmpty() == 0) {
        printf("String is NOT VALID -- you have more LH brackets than RH\n");
        return -1;
    } // IF

    // IF STACK IS EMPTY AND STRING SUCCESSFULLY TRAVERSED, THEN STRING IS VALID
    printf("String is VALID\n");
    return 1;

} // FUNCTION `balanced_parentheses`

/* ------------------------------------------------------
 * MAIN
 */

int main() {

    // INITIALIZE VAR TO STORE USER INPUT
    char* stringName;
    // READ USER INPUT AND STORE IN `stringName`
    printf("This program evaluates whether a string has balanced parentheses.\n"
           "Enter a string without blanks:\n");
    scanf("%s", stringName);
    
    // FIND STRING LENGTH BY COUNTING INDICES UNTIL `\0` CHAR
    int strLen = 0;
    for (int i = 0; stringName[i] != '\0'; i++) {
        strLen++;
    } // FOR
    
    // CALL `balanced_parentheses` TO EVALUATE WHETHER STRING IS BALANCED
    int resultBool = balanced_parentheses(stringName, strLen);

    return 0;
} // MAIN
