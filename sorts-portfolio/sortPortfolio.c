/*  ***************************************************************** *
 *     Program:		sortPortfolio.c
 *     Purpose:         implements a menu to access five sorts:
 *                          bubble sort, selection sort, insertion
 *                          sort, merge sort, and quick sort; also
 *                          includes menu option to compare time
 *                          taken to run each sort;
 *
 *     Programmer:	Norrec Nieh
 *     Course:		CS5008, Summer 2022
 *     Date:		June 20, 2022
 *  ***************************************************************** */
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

char* fileName;

void printBuffer (int buffer[], int size);

/*  ***************************************************************** */
//     DECLARES CONSTANTS FOR compareSorts  

int SIZE = 30000;
int* numbers;
int* testArr;

/*  ***************************************************************** *
 *     FUNCTION swap(int* a, int* b) SWAPS THE CONTENTS OF a AND b
 *  ***************************************************************** */

void swap(int* a, int* b) {

    int temp = *a;
    *a = *b;
    *b = temp;

} // function SWAP

/*  ***************************************************************** *
 *     FUNCTION insertionSort(int arr[], int size) SORTS CONTENTS   
 *     OF INTEGER ARRAY arr IN ASCENDING ORDER USING INSERTION SORT
 *  ***************************************************************** */

void insertionSort(int arr[], int size) {

    // INITIALIZE COUNTERS    
    int i = 0, j;

    // FOR EVERY INDEX IN BUFFER
    while (i < size) {

        // IF PREV VAL > CURR VAL, SWAP CURR WITH PREV;
	// DECREMENT COUNTER FOR CURR AND KEEP SWAPPING WITH PREV UNTIL
	// CURR VAL >= PREV VAL
        j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            swap(&arr[j], &arr[j - 1]);
            j--;
        } // WHILE

        // INCREMENT `i`
        i++;
    } // WHILE

} // function INSERTIONSORT

/*  ***************************************************************** *
 *     FUNCTION selectionSort(int arr[], int size) SORTS CONTENTS   
 *     OF INTEGER ARRAY arr IN ASCENDING ORDER USING SELECTION SORT
 *  ***************************************************************** */

void selectionSort(int arr[], int size) {

    // DECLARE VAR TO TRACK INDEX OF MIN
    int indexOfMin;

    // FOR EVERY INDEX `i`
    for (int i = 0; i < size - 1; i++) {

        // INITIALIZE MIN INDEX TO `i`
        indexOfMin = i;
        
        // ITERATE THROUGH REST OF BUFFER TO FIND MIN
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[indexOfMin]) {
                indexOfMin = j;
            } // IF
        } // FOR
    
        // SWAP VALUE OF `i` WITH MIN VALUE
        swap(&arr[i], &arr[indexOfMin]);
    } // FOR

} // function SELECTIONSORT

/*  ***************************************************************** *
 *     FUNCTION bubbleSort(int arr[], int size) SORTS CONTENTS
 *       OF INTEGER ARRAY arr IN ASCENDING ORDER USING BUBBLE SORT
 *  ***************************************************************** */

void bubbleSort(int arr[], int size) {

    // DECLARE PSEUDO-BOOLEAN TO TRACK SWAPPED STATUS
    int swapped;

    do { // ITERATE UNTIL NO SWAP HAS OCCURED IN A GO-THROUGH
        swapped = 0;

        // FOR EVERY INDEX, CHECK IF PREV VALUE IS LARGER THAN CURR VALUE
        // IF TRUE, SWAP THE VALUES AND RAISE SWAPPED FLAG
        for (int i = 1; i < size; i++) {
            if (arr[i - 1] > arr[i]) {
                swap(&arr[i - 1], &arr[i]);
                swapped = 1;
            } // IF
        } // FOR
     } while (swapped == 1);

} // function BUBBLESORT

/*  ***************************************************************** *
 *     FUNCTION merge(int arr[], int left, int mid, int right)
 *       MERGES TWO HALVES OF AN ARRAY AND RETURNS IT IN SORTED ORDER 
 *  ***************************************************************** */

void merge(int arr[], int left, int mid, int right) {
    
    // CREATE TEMP ARR TO HOLD SORTED ELEMENTS
    int tempLen = right - left + 1;
    int temp[tempLen];

    // DECLARE AND INITIALIZE COUNTERS FOR LEFT HALF (i), RIGHT HALF (j),
    // AND TEMP ARRAY (k)
    int i = left;
    int j = mid + 1;
    int k = 0;  

    // COMPARE ELEMENTS IN FIRST AND SECOND HALF, COPYING THE SMALLER
    // ELEMENT TO temp EVERY ITERATION UNTIL ONE HALF IS OUT OF ELEMENTS
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;      
        } // IF
        else {
            temp[k] = arr[j];
            j++;
        } // ELSE
        k++;
    } // WHILE

    // IF THERE ARE ELEMENTS LEFT IN FIRST HALF, ADD TO temp
    while (i <= mid) {
        temp[k] = arr[i];
        k++;
        i++;
    } // WHILE

    // IF THERE ARE ELEMENTS LEFT IN SECOND HALF, ADD TO temp
    while (j <= right) {
        temp[k] = arr[j];
        k++;
        j++;
    } // WHILE

    // COPY ALL ELEMENTS IN temp BACK INTO arr IN ORDER
    for (k = 0, i = left; k < tempLen; k++, i++) {
        arr[i] = temp[k];
    } // FOR
}

/*  ***************************************************************** *
 *     FUNCTION mergeSort(int arr[], int left, int right) SORTS CONTENTS
 *       OF INTEGER ARRAY arr IN ASCENDING ORDER USING MERGE SORT
 *  ***************************************************************** */

void mergeSort(int arr[], int left, int right) {

    // IF NOT BASE CASE
    if (left < right) {

        // SET MID TO MIDPOINT OF arr
        int mid = (left + right) / 2;
        
        // CALL mergeSort RECURSIVELY ON FIRST AND SECOND HALF
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // SORT ELEMENTS BETWEEN LEFT AND RIGHT INDICES
        merge(arr, left, mid, right);
    } // IF

} // function MERGESORT

/*  ***************************************************************** *
 *     FUNCTION partition(int arr[], int low, int high) DIVIDES
 *     INTEGER ARRAY arr INTO TWO PARTITIONS; RETURNS INDEX OF PIVOT
 *  ***************************************************************** */

int partition(int arr[], int low, int high) {

    // CHOOSE LAST INDEX AS PIVOT
    int pivot = arr[high];

    // SET TEMP PIVOT INDEX
    int i = low - 1;

    for (int j = low; j < high; j++) {
        // IF CURR ELEMENT <= PIVOT
        if (arr[j] <= pivot) {
            // INCREMENT TEMP PIVOT INDEX
            i++;
            // SWAP CURR ELEMENT WITH THE ELEMENT AT TEMP PIVOT INDEX
            swap(&arr[i], &arr[j]);
        } // IF
    } // FOR

    // MOVE PIVOT TO PIVOT INDEX (BETWEEN SMALLER AND LARGER ELEMENTS)
    i++;
    swap(&arr[i], &arr[high]);

    // RETURN PIVOT INDEX
    return i;    

} // function PARTITION

/*  ***************************************************************** *
 *     FUNCTION quickSort(int arr[], int low, int high) SORTS CONTENTS
 *       OF INTEGER ARRAY arr IN ASCENDING ORDER USING QUICK SORT
 *  ***************************************************************** */

void quickSort(int arr[], int low, int high) {

    // BASE CASE; ALSO CHECK THAT INDICES ARE VALID
    if (low >= high || low < 0) {
        return;
    } // IF

    // PARTITION ARRAY AND GET PIVOT INDEX
    int pivotIndex = partition(arr, low, high);

    // CALL quickSort RECURSIVELY ON EACH HALF
    quickSort(arr, low, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, high);

} // function QUICKSORT

/*  ***************************************************************** *
 *     FUNCTION resetArray IS A HELPER FUNCTION FOR compareSorts()    *
 *       THAT COPIES THE CONTENTS OF numbers INTO testArr             * 
 *  ***************************************************************** */

void resetArray() {

    for (int i = 0; i < SIZE; i++) {
        testArr[i] = numbers[i];
    } // FOR
} // function RESETARRAY

/*  ***************************************************************** *
 *     FUNCTION compareSorts() COMPUTES AND PRINTS THE EXECUTION      *
 *       DURATION FOR ALL FIVE SORTS CALLED ON A LARGE RANDOMLY       * 
 *       GENERATED INT ARRAY                                          *
 *  ***************************************************************** */

void compareSorts() {
    
    numbers = malloc(sizeof(int) * SIZE); 
    testArr = malloc(sizeof(int) * SIZE);
    printf("Initializing array of size %d...\n", SIZE);

    srand(time(NULL));
    
    for (int i = 0; i < SIZE; i++) {
        numbers[i] = rand() % SIZE + 1;
    } // FOR

    // COMPUTE EXECUTION DURATION FOR BUBBLE SORT
    resetArray();
    clock_t t = clock();
    printf("Timer started... \n");
    bubbleSort(testArr, SIZE);
    printf("Timer ended... \n");
    t = clock() - t;
    double time_taken = ((double) t) / CLOCKS_PER_SEC;
    printf("Bubble Sort took %f seconds to execute.\n\n", time_taken);

    sleep(1);

    // COMPUTE EXECUTION DURATION FOR SELECTION SORT
    resetArray();
    t = clock();
    printf("Timer started... \n");
    selectionSort(testArr, SIZE);
    printf("Timer ended... \n");
    t = clock() - t;
    time_taken = ((double) t) / CLOCKS_PER_SEC;
    printf("Selection Sort took %f seconds to execute.\n\n", time_taken);

    sleep(1);

    // COMPUTE EXECUTION DURATION FOR INSERTION SORT
    resetArray();
    t = clock();
    printf("Timer started... \n");
    insertionSort(testArr, SIZE);
    printf("Timer ended... \n");
    t = clock() - t;
    time_taken = ((double) t) / CLOCKS_PER_SEC;
    printf("Insertion Sort took %f seconds to execute.\n\n", time_taken);

    sleep(1);

    // COMPUTE EXECUTION DURATION FOR MERGE SORT
    resetArray();
    t = clock();
    printf("Timer started... \n");
    mergeSort(testArr, 0, SIZE - 1);
    printf("Timer ended... \n");
    t = clock() - t;
    time_taken = ((double) t) / CLOCKS_PER_SEC;
    printf("Merge Sort took %f seconds to execute.\n\n", time_taken);
   
    sleep(1);

    // COMPUTE EXECUTION DURATION FOR QUICK SORT
    resetArray();
    t = clock();
    printf("Timer started... \n");
    quickSort(testArr, 0, SIZE - 1);
    printf("Timer ended... \n");
    t = clock() - t;
    time_taken = ((double) t) / CLOCKS_PER_SEC;
    printf("Quick Sort took %f seconds to execute.\n\n", time_taken);

    free(numbers);
    free(testArr);

} // function COMPARESORTS

/*  ***************************************************************** *
 *     FUNCTION getFileName() GETS THE FILENAME STRING FROM USER      *
 *  ***************************************************************** */

char* getFileName() {
    
    // REQUESTS MEM FROM HEAP TO STORE FILE NAME
    fileName = (char*)malloc((sizeof(char) * 50));

    // GET FILE NAME FROM USER
    printf("Enter file name: ");
    scanf("%s", fileName);

    // RETURN POINTER TO FILENAME
    return fileName;  

} // function GETFILENAME

/*  *******************************************************************
 *     FUNCTION clearBuffer INITIALIZES THE BUFFER TO ALL ZEROS
 * ********************************************************************/

void clearBuffer(int buffer[], int size){

    for (int i = 0; i < size; i++) {
        buffer[i] = 0;
    } // FOR

} // function CLEARBUFFER
  
/*  *******************************************************************
 *     FUNCTION readInts READS INTEGERS FROM A FILE AND INSERTS THEM  *
 *        INTO ARRAY BUFFER.  IT RETURNS THE NUMBER OF ENTITIES IN    *
 *        IN THE BUFFER.                                              *
 * ********************************************************************/
  
int readInts(char* fileName, int buffer[300]) {

    // DECLARE AND INITIALIZE VARS FOR USE IN LOOP 
    int currInt = 0;
    int count = 0;

    // OPEN FILE
    FILE* fileHandle = fopen(fileName, "r");

    // IF ERROR READING FILE, EXIT PROGRAM
    if (fileHandle == NULL) {
        perror("ERROR");
        exit(EXIT_FAILURE);
    } // IF

    // RESET POSITION
    rewind(fileHandle);
   
    // READ EACH INT IN FILE UNTIL EOF
    while (1) {
        fscanf(fileHandle, "%d", &currInt);

        if (feof(fileHandle)) {
            break;
        } // IF
       
        *(buffer + count) = currInt;
        count++;
    } // WHILE

    return count;
} // FUNCTION READINTS

/*  ***************************************************************** * 
 *     FUNCTION printBuffer(int buffer[], int size) PRINTS ARRAY buffer
 *  ***************************************************************** */

void printBuffer (int buffer[], int size){

    for (int i = 0; i < size; i++) {
        printf("%d  ", buffer[i]);
    } // FOR

    printf("\n");

} // function PRINTBUFFER


/*  ***************************************************************** */

// ---------------------------------------------------------- 
//  function PRINTMENU prints the menu choices in the QUEUE ADT
// ---------------------------------------------------------- 

void printMenu() {
    system("clear");
    printf("----------------------------------- \n");
    printf("     1 -- Print Unsorted Data \n");
    printf("     2 -- Bubble Sort \n");
    printf("     3 -- Selection Sort \n");
    printf("     4 -- Insertion Sort  \n");
    printf("     5 -- Merge Sort \n");
    printf("     6 -- Quick Sort \n");
    printf("     7 -- Compare Sorts \n");
    printf("     8 -- QUIT \n");
    printf("----------------------------------- \n");
}// function PRINTMENU

/* ********************************************************* */

// ---------------------------------------------------------- 
//  function GETUSERCHOICE gets input from user and returns integer
// ---------------------------------------------------------- 

int getUserChoice() {
    int tempChoice = 0;

    printMenu();
    printf("Enter choice (1-8): ");
    fflush(stdin);
    scanf("%d", &tempChoice);
    printf("\n");
    return tempChoice;

} // function GETUSERCHOICE

/* ********************************************************* */

// ---------------------------------------------------------- 
//  function EXECUTE_MENU displays menu and implements choice
// ---------------------------------------------------------- 

int executeMenu(int buffer[], int count) {
    int tempChoice = 0;
    int myNum = 0;
    int tempNum = 0;
    char myChar = '0';

    tempChoice = getUserChoice(); 
    
    switch (tempChoice) {
        // CASE 1:  
        case (1): {
                  //REINITIALIZE BUFFER AND COUNTER
                   clearBuffer(buffer, 300);
                   count = 0;
                   count = readInts(fileName, buffer);
                   printBuffer(buffer, count);
            break;
        }//CASE 1

        // CASE 2:  BUBBLE SORT
        case (2): {
                  bubbleSort(buffer, count);
                  printBuffer(buffer, count);
            break;
        }//CASE 2

        // CASE 3: SELECTION SORT
        case (3): {
                  selectionSort(buffer, count);
                  printBuffer(buffer, count);
            break;
        }//CASE 3

        // CASE 4: INSERTION SORT
        case (4): {
                  insertionSort(buffer, count);
                  printBuffer(buffer, count);
            break;
        }//CASE 4

        // CASE 5: MERGE SORT
        case (5): {
                  mergeSort(buffer, 0, count - 1);
                  printBuffer(buffer, count);
            break;
        }//CASE 5

        // CASE 6: QUICK SORT
        case (6): {
                  quickSort(buffer, 0, count - 1);
                  printBuffer(buffer, count);
            break;
        }//CASE 6

        // CASE 7: COMPARE SORTS
        case (7): {
                  compareSorts();
            break;
        } // CASE 7

        // CASE 8: Quit program
        case (8): {
            printf("Quitting now.  Bye.  \n");
            break;
        }//CASE 8 

        default: {
            printf("invalid choice ... choose again \n");
        }//DEFAULT
    } //SWITCH

    myChar = getchar();
    myChar = getchar();
    return tempChoice;

} // function EXECUTE MENU

/* ********************************************************** */

// ---------------------------------------------------------- 
// function SHOWADT is a driver function for EXECUTEMENU
// ---------------------------------------------------------- 

void showADT(int buffer[], int size){
    int count = 0;
    int userChoice = 0;

    do {
         //REINITIALIZE BUFFER AND COUNTER
         clearBuffer(buffer, 300);
         count = 0;
         count = readInts(fileName, buffer);

         userChoice = executeMenu(buffer, count); 
    } while (userChoice != 8);

} // function SHOWADT

/*  ********************************************************* */

// ---------------------------------------------------------- 
// MAIN
// ---------------------------------------------------------- 

int main() {
      int count = 0;
      int buffer[300];
      system("clear");

      //GET FILE NAME FROM USER
      fileName = getFileName();
      showADT(buffer, 300);
      free(fileName);
      return 0;
}//MAIN

/*  ********************************************************* */
