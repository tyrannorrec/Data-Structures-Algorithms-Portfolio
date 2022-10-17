/* ******************************************************
 *     Program:		linearQueue.c
 *     Purpose:         Implements an array-based 
 *                          linear queue ADT
 *                      
 *     Programmer:	Norrec Nieh
 *     Course:		CS5008, Summer 2022
 *     Date:		June 17, 2022
 *
 * ******************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 4

int enqueue(int item);
int dequeue();
int getFront();
int getRear();
int queueEmpty();
int queueFull();
void printQueue();
int populateQueue();
void deleteQueue();

int REAR = -1;
int FRONT = -1;
int queueArray[MAXSIZE];

// -------------------------------------------------------
// Function `enqueue` adds an int to the rear of the queue.
// Returns 1 if successful, and -1 if unsuccessful.
// -------------------------------------------------------

int enqueue(int item) {

    // If queue is empty
    if (queueEmpty()) {
        FRONT = 0;
        REAR = 0;
        queueArray[REAR] = item;
        return 1;
    } // IF

    // If queue is not empty and not full
    if (!queueFull()) {
        REAR++;
        queueArray[REAR] = item;
        return 1;
    } // IF

    // Else, queue is full. Return error code
    return -1;
} // Function `enqueue`

// -------------------------------------------------------
// Function `dequeue` removes the int at the front of the
// queue and returns it. Returns -1 if unsuccessful.
// -------------------------------------------------------

int dequeue() {

    // If queue is not empty, get frontOfQueue,
    // increment Front, and return frontOfQueue.
    if (!queueEmpty()) {
        int frontOfQueue = queueArray[FRONT];
        FRONT++;
        return frontOfQueue;
    } // IF

    // Else, queue is empty. Return error code
    printf("Queue is empty ... nothing to dequeue.\n");
    return -1;
} // Function `dequeue`

// -------------------------------------------------------
// Function `getFront` returns the item at the front of
// the queue. 
// -------------------------------------------------------

int getFront() {

    return queueArray[FRONT];
} // Function `getFront`

// -------------------------------------------------------
// Function `getRear` returns the item at the rear of
// the queue.
// -------------------------------------------------------

int getRear() {

    return queueArray[REAR];
} // Function `getRear`

// -------------------------------------------------------
// Function `queueEmpty` returns 1 if the queue is empty,
// and 0 if the queue is not empty.
// -------------------------------------------------------

int queueEmpty() {

    // Initial case: no item has been added to queue
    if (FRONT == -1 && REAR == -1) {
        return 1;
    } // IF

    // General case: queue is empty
    if (FRONT > REAR) {
        return 1;
    } // IF

    // Else, queue is not empty
    return 0;
} // Function `queueEmpty`

// -------------------------------------------------------
// Function `queueFull` returns 1 if the queue is full,
// and 0 if the queue is not full. 
// -------------------------------------------------------

int queueFull() {

    // If Rear at last index, queue is full.
    if (REAR == MAXSIZE - 1) {
        return 1;
    } // IF

    // Else, queue is not full.
    return 0;
} // Function `queueFull`

// -------------------------------------------------------
// Function `printQueue` prints all items in queue from
// front to rear. If empty, the function prints a
// corresponding message.
// -------------------------------------------------------

void printQueue() {

    int currFront = FRONT;
    // If queue is not empty,
    if (!queueEmpty()) {
        // While iterator does not surpass Rear, print value.
        while (currFront <= REAR) {
            printf("%d  ", queueArray[currFront]);
            currFront++;
        } // WHILE
    printf("\n");
    } // IF

    // Else, print error message.
    else {
        printf("The queue is empty. Nothing to print.\n");
    } // ELSE


} // Function `printQueue`

// -------------------------------------------------------
// Function `populateQueue` reads in a file of integers 
// and populates the queue with those integers. Returns
// 1 if successful, and -1 if an error was encountered.
// -------------------------------------------------------

int populateQueue() {

    char fileName[30];
    int currInt = 0;
    int enqueueStatus = 0;
    int failedEnqueues = 0;    

    // Get file name from user
    printf("Enter file name: \n");
    scanf("%s", fileName);

    // Open file
    FILE* fileHandle = fopen(fileName, "r");

    // If error opening file, print error message and return -1
    if (fileHandle == NULL) {
        perror("ERROR");
        return -1;
    } // IF

    // Initialize position
    rewind(fileHandle);

    printf("\nAdding items to queue...\n");

    // Iterate so long as not end of file
    while(1) {
        // Read in next int 
        fscanf(fileHandle, "%d", &currInt);
   
        // Check for end of file
        if (feof(fileHandle)) {
            break;
        } // IF

        // Else, enqueue current int
        enqueueStatus = enqueue(currInt);

        // If enqueue failed because queue is full,
        // increment fail counter.
        if (enqueueStatus == -1) {
            failedEnqueues++;
        } // IF
    } // WHILE

    // Print info message if any enqueues failed.
    if (failedEnqueues > 0) {
    	printf("The queue is full. %d items were not able to be added.\n\n", failedEnqueues); 
    } // IF

    fclose(fileHandle);
    return 1;
} // Function `populateQueue`

// -------------------------------------------------------
// Function `deleteQueue` resets the Front and Rear to -1.
// -------------------------------------------------------

void deleteQueue() {

    FRONT = -1;
    REAR = -1;
} // Function `deleteQueue`

/* ********************************************************* */

// ---------------------------------------------------------- 
//  Function `printMenu` prints the menu choices in the queue ADT.
// ---------------------------------------------------------- 

void printMenu() {
    system("clear");
    printf("----------------------------------- \n");
    printf("     1 -- Enqueue \n");
    printf("     2 -- Dequeue   \n");
    printf("     3 -- Empty Queue? \n");
    printf("     4 -- Full Queue?  \n");
    printf("     5 -- Print Queue\n");
    printf("     6 -- Print Front-Of-Queue\n");
    printf("     7 -- Print Rear-Of-Queue \n");
    printf("     8 -- Populate Queue \n");
    printf("     9 -- Delete Queue \n");
    printf("    10 -- QUIT \n");
    printf("----------------------------------- \n");
} // Function `printMenu`

/* ********************************************************* */

// ---------------------------------------------------------- 
//  Function `GetUserChoice` gets input from user and returns integer.
// ---------------------------------------------------------- 

int getUserChoice() {
    int tempChoice = 0;

    printMenu();
    printf("Enter choice (1-10): ");
    fflush(stdin);
    scanf("%d", &tempChoice);
    printf("\n");
    return tempChoice;
} // Function `GetUserChoice`

// ---------------------------------------------------------- 
//  Function `executeMenu` displays menu and implements choice.
// ---------------------------------------------------------- 

int executeMenu() {
    int tempChoice = 0;
    int myNum = 0;
    int tempNum = 0;
    char myChar = '0';

    tempChoice = getUserChoice();
    
    switch (tempChoice) {

        // CASE 1: Enqueue
        case (1): {
            if (!queueFull()){
                 printf("Enter value to Enqueue: ");
                 scanf("%d", &tempNum);

                 if (enqueue(tempNum) != -1){
                      printf("Queue is now... \n");
                      printQueue();
                 }//IF
            }//IF
            else {
                printf("Queue is full ... cannot Enqueue. \n");
            }//ELSE
            break;
        }//CASE 1

        // CASE 2: Dequeue
        case (2): {
            myNum = dequeue();
            if (myNum != -1){
                  printf("Just Dequeued: %d \n", myNum);
                  if (!queueEmpty())
                       printf("Queue is now... \n");
                  printQueue();
            }//IF
            break;
        }//CASE 2

        // CASE 3: Check for empty Queue
        case (3): {
            if (!queueEmpty()) {
                printf("Queue is not empty. \n");
            }//IF
            else {
                printf("Queue is empty. \n");
            }//ELSE
            break;
        }//CASE 3

        // CASE 4: Check for full Queue 
        case (4): {
            if (!queueFull()) {
                printf("Queue is not full. \n");
            }//IF
            else {
                printf("Queue is full. \n");
            }//ELSE
            break;
        }//CASE 4

        // CASE 5: Print Queue
        case (5): {
            if (!queueEmpty()){
                 printf("Current queue is now:  \n");
            }//IF
            printQueue();
            break;
        }//CASE 5

        // CASE 6: Return copy of Front-of-Queue
        case (6): {
            if (!queueEmpty()){
                 tempNum = getFront();
           printf("Current Front-of-Queue is now: %d  \n", tempNum);
            }//IF
            else {
                 printf("Queue is empty; there is no Front. \n");
            } //ELSE
            break;
        }//CASE 6


        // CASE 7: Return copy of Rear-of-Queue
        case (7): {
            if (!queueEmpty()){
                 tempNum = getRear();
            printf("Current Rear-of-Queue is now: %d  \n", tempNum);
            }//IF
            else {
                 printf("Queue is empty; there is no Rear. \n");
            } //ELSE
            break;
        }//CASE 7

        // CASE 8: Populate Queue -- reads external file of ints
        case (8):   {
            int populateStatus = populateQueue();
            if (populateStatus == 1) {
                printf("Queue is now: \n");
                printQueue();
            } // IF
            else {
                printf("Returning to menu. \n");
            } // ELSE
            break;
        }//CASE 8

        // CASE 9: Delete Queue
        case (9): {
            deleteQueue();
            printf("Queue has been safely deleted. \n");
            break;
        }//CASE 9

        // CASE 10: Quit program
        case (10): {
            printf("Quitting now. Bye.  \n");
            break;
        }//CASE 10

        default: {
            printf("Invalid choice ... choose again \n");
        }//DEFAULT
    } //SWITCH
   
    myChar = getchar();
    myChar = getchar();
    return tempChoice;

} // Function `executeMenu`

// -----------------------------------------------------------
// Function `showQueueADT` is a driver function for `executeMenu`
// -----------------------------------------------------------

void showQueueADT(){
    int userChoice = -1;

    do {
        userChoice = executeMenu(); 
    } while (userChoice != 10);

} // Function `ShowQueueADT`

// -----------------------------------------------------------
// MAIN
// -----------------------------------------------------------

int main() {
    showQueueADT();
    return 0;
}// MAIN

/* ********************************************************** */
