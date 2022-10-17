/* ******************************************************************
 *        		   MIDTERM PROGRAM
 *
 *        Program:     hashMapMenu.c 
 *        Purpose:     Contains the menu code and main driver of
 *        		    hashMap ADT, with customerRec as data type
 *
 *        Programmer:  Norrec Nieh
 *        Course:      CS5008, Summer 2022
 *        Date:        July 4, 2022 
 *
 ******************************************************************* */
#include <stdio.h>
#include <stdlib.h>
#include "newList.h"
#include "newList.c"


#define NUMBUCKETS 7

list_t* hashMapArray[NUMBUCKETS];

int hasKey(int key);



/* ****************************************************** */
// `computeHashIndex` CALCULATES AND RETURNS THE HASH INDEX
// OF AN ENTRY FROM AN INTEGER INPUT. 
/* ****************************************************** */
int computeHashIndex(int key) {

    return ((key % 10) * 10000) % NUMBUCKETS;

}//FUNCTION COMPUTEHASHINDEX


/* ****************************************************** */
// `insertKey` CALCULATES THE HASH INDEX OF A CUSTOMERREC 
// OBJ AND INSERTS IT INTO THE HASH MAP. RETURNS 1 IF
// SUCCESSFUL AND 0 IF NOT SUCCESSFUL.
/* ****************************************************** */
int insertKey(int key, customerRec* myCR){

    // IF KEY IN HASH MAP, RETURN TO MENU
    if (hasKey(key)) {
        printf("Key already in Hash Map. Returning to menu. \n");
        return 0;
    } // IF

    // GENERAL CASE
    int hashIndex = computeHashIndex(key);
    kvpair_t* newKVpair = getKVpair(myCR);
    insertRear(hashMapArray[hashIndex], newKVpair);
    printf("\nKey %d has been added to index %d.\n", key, hashIndex);

    return 1;
}//FUNCTION INSERTKEY

/* ****************************************************** */
// `deleteKey` FINDS A CUSTOMERREC OBJ WITH A MATCHING KEY
// AND DELETES THE ENTRY FROM THE HASH MAP. RETURNS 1 IF
// SUCCESSFUL, AND 0 IF NOT SUCCESSFUL.
/* ****************************************************** */
int deleteKey(int key){

    // IF KEY NOT IN HASH MAP, RETURN TO MENU
    if (!hasKey(key)) {
        printf("No such key in Hash Map. Returning to menu.\n");
        return 0;
    } // IF

    // GENERAL CASE
    int hashIndex = computeHashIndex(key);
    deleteItem(hashMapArray[hashIndex], key);
    printf("\nKey %d has been deleted from the Hash Map.\n", key);

    return 1;
}//FUNCTION DELETEKEY

/* ****************************************************** */
// `findCustomerRec` SEARCHES A BUCKET FOR A HASH INDEX.
// RETURNS THE CUSTOMERREC OBJ WITH THE MATCHING INDEX.
/* ****************************************************** */
customerRec* findCustomerRec(list_t* bucket, int key) {

    if (listEmpty(bucket)) {
        return NULL;
    } // IF

    // GET INDEX
    int index = findItem(bucket, key);
   
    // DECLARE ITERATOR
    node_t* iter = bucket->head;    

    // FIND THE CORRECT ITEM
    for (int i = 1; i < index; i++) {
        iter = iter->next;
    } // FOR

    return iter->data->value;

}//function FINDCUSTOMERREC

/* ****************************************************** */
// `printBucket` PRINTS THE LIST CONTAINED IN THE BUCKET
/* ****************************************************** */
void printBucket(int bucketNumber){

    printf("******************** BUCKET %d ********************\n", bucketNumber);
    printList(hashMapArray[bucketNumber]);
    printf("****************** BUCKET %d END ******************\n\n", bucketNumber);
    printf("///////////////////////////////////////////////////\n\n");

}//function PRINTBUCKET

/* ****************************************************** */
// `printHashMap` PRINTS EVERY BUCKET IN THE HASH MAP
/* ****************************************************** */
void printHashMap(){

    for (int i = 0; i < NUMBUCKETS; i++) {
        printBucket(i);
    } // FOR

}//function PRINTHASHMAP

/* ****************************************************** */
// `hasKey` DETERMINES WHETHER OR NOT THE KEY IS ALREADY
// IN THE HASH MAP. RETURNS 1 IF TRUE AND 0 IF FALSE.
/* ****************************************************** */
int hasKey(int key){

    for (int i = 0; i < NUMBUCKETS; i++) {
        if (findItem(hashMapArray[i], key) > 0) {
            return 1;
        } // IF
    } // FOR
    
    return 0;
}// FUNCTION HASKEY

/* ****************************************************** */
// `populateHash` READS IN A FILE OF CUSTOMERREC OBJECTS
// AND INSERTS EACH OBJECT INTO THE HASH MAP IN ORDER.
// RETURNS 1 IF SUCCESSFUL, -1 IF THERE WAS AN ERROR READING
// THE FILE, AND -2 IF THERE WAS AN ERROR OPENING THE FILE.
/* ****************************************************** */
int populateHash() {

    // GET PHYSICAL FILE NAME
    char* fileName = (char*)malloc((sizeof(char) * 40));
    printf("Enter file name: ");
    scanf("%s", fileName);

    // OPEN FILE
    FILE* fileHandle = fopen(fileName, "r");

    // IF ERROR OPENING FILE, RAISE ERROR
    if (fileHandle == NULL) {
        perror("ERROR");
        return -2;
    } // IF

    // DECLARE VARS FOR LOOP
    char tempStr[300];
    int currKey = 0;
    int duplicates = 0; 
    int successes = 0;

    // WHILE NOT END OF FILE
    while (!feof(fileHandle)) {

        // GET NEXT LINE
        fgets(tempStr, 300, fileHandle);
        tempStr[strlen(tempStr)] = '\0';
 
        // IF LINE IS A FULL LINE
        if (strlen(tempStr) > 50) {

            // READ INTO CUSTOMERREC OBJ
            customerRec* currCustomer = parseLine(tempStr);

            // IF MALLOC SUCCEEDED
            if (currCustomer != NULL) {

                // GET KEY
                currKey = currCustomer->empNum;

                // IF KEY NOT ALREADY IN HASH MAP, INSERT CUSTOMERREC;
                // INCREMENT SUCCESS COUNTER
                if (!hasKey(currKey)) { 
                    insertKey(currKey, currCustomer);
                    successes++;
                } // IF

                // ELSE, KEY ALREADY IN HASHMAP; FREE OBJ;
                // INCREMEMENT DUPLICATE COUNTER
                else {
                    deleteCustomerRecord(currCustomer);
                    duplicates++;
                } // ELSE

            } // IF
  
            // ELSE IF MALLOC FAILURE, OUTPUT FAILURE
            else {
                printf("Error reading file.\n");
                return -1;
            } // ELSE

        } // IF
    } // WHILE

    // PRINT RESULT
    printf("\n%d keys added to Hash Map.\n", successes);

    // IF ANY DUPLICATES, PRINT NUM OF DUPLICATES IGNORED
    if (duplicates > 0) {
        printf("%d duplicate keys ignored.\n", duplicates);
    } // IF
    
    // CLOSE FILE AND FREE STRING USED FOR FILE NAME
    fclose(fileHandle);
    free(fileName);
    return 1;
}//function POPULATEHASH


/* ********************************************************* */

// ---------------------------------------------------------- 
//  function PRINTMENU prints the menu choices for HASH MAP ADT
// ---------------------------------------------------------- 

void printMenu() {
    system("clear");
    printf("----------------------------------- \n");
    printf("     1 -- INSERT CUSTOMER REC INTO HASHMAP \n");
    printf("     2 -- DELETE CUSTOMER REC FROM HASHMAP \n");
    printf("     3 -- CUSTOMER RECORD IN HASHMAP? \n");
    printf("     4 -- ACCESS CUSTOMER RECORD FROM HASHMAP\n");
    printf("     5 -- POPULATE HASHMAP\n");
    printf("     6 -- COMPUTE HASHKEY\n");
    printf("     7 -- PRINT HASHMAP \n");
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

int executeMenu(){
    int tempChoice = 0;
    int myNum = 0;
    int tempNum = 0;
    int tempKey = 0;
    char myChar = '0';
    customerRec*  myCR;
    kvpair_t*     myKV;

    tempChoice = getUserChoice();
    int statusNum = 0;
    int userPosition = 0;
    int tempHash = -1;

    
    
    switch (tempChoice) {

        // -------------------------------------------------------------------------

        // CASE 1:  INSERT CUSTOMER REC INTO HASHMAP
       case (1): {
            // GET CUSTOMERREC;  GET KVPAIR
            myCR = getCustomer();
            tempKey=myCR->empNum;
            insertKey(tempKey, myCR);

            break;
        }//CASE 1 ...  INSERT CUSTOMER RECORD

        // -------------------------------------------------------------------------

        // CASE 2:  DELETE CUSTOMER REC FROM HASHMAP
        case (2): {

            // GET CUSTOMERREC;  GET KVPAIR
            printf("Enter Employee Number (KEY) of the Record to Delete: "); 
            scanf("%d",&tempKey);
            statusNum = deleteKey(tempKey);

            break;
        }//CASE 2  DELETE CUSTOMER RECORD FROM HASHMAP

        // -------------------------------------------------------------------------
        
        // CASE 3:  BOOLEAN PRESENCE IN HASHMAP??
        case (3): {
            printf("Enter Employee ID of RECORD TO CHECK: ");
            scanf("%d",&tempKey);
            statusNum = hasKey(tempKey);
            if (statusNum == 1){
                printf("Record with KEY %d EXISTS in Hash Map.\n",tempKey);
            }// RECORD EXISTS
            else{
                printf("Record with KEY %d DOES NOT EXIST in Hash Map.\n", tempKey);
                
            }//RECORD NOT IN HASHMAP

            break;
        }//CASE 3  CHECKING IF KEY IN HASHMAP

        // -------------------------------------------------------------------------

        //CASE 4  ACCESS RECORD IN HASHMAP
        case (4): {
             //GET KEY FROM USER
              printf("Enter Employee ID of RECORD TO PRINT: ");
              scanf("%d",&tempKey);

             //COMPUTE BUCKET
              tempHash = computeHashIndex(tempKey);

             //CALL FIND AND GET
              myCR = findCustomerRec(hashMapArray[tempHash], tempKey);
              if (myCR == NULL){
                  printf("Cannot ACCESS -- Employee %d NOT in Hash Map \n", tempKey);
              }//IF
              else{
                  printf("\n");
                  printCustomerRec(myCR);
              }//

             break;
         }//CASE 4 ACCESS CUSTOMER RECORD

        // -------------------------------------------------------------------------

         //CASE 5  POPULATE HASH MAP
         case (5): {
               populateHash();
               break;
         }//CASE 5 POPULATE HASH MAP

        // -------------------------------------------------------------------------
        
        // CASE 6:  COMPUTE HASH INDEX
        case (6): {
            printf("Enter position Employee Number (KEY): ");
            scanf("%d", &tempNum);

            //COMPUTE BUCKET
            tempHash = computeHashIndex(tempNum);
            printf("The computed Hash Bucket (Index) is: %d\n",tempHash);

            break;
        }//CASE 6 COMPUTE HASH INDEX

        // -------------------------------------------------------------------------

        // CASE 7: PRINT HASH MAP
        case (7): {
            printHashMap();
            break;
        }//CASE 7

        // -------------------------------------------------------------------------

        // CASE 8:  QUIT
        case (8): {
            printf("Quitting now.  Bye.  \n");
            break;
        }//CASE 8

        // -------------------------------------------------------------------------

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
void showListADT(){

    int userChoice = -1;

    do {
        userChoice = executeMenu(); 
    } while (userChoice != 8);

} // function SHOWLISTADT

/****************************************************************/
int sizeOfHashMap(){

   int sizeSoFar = 0;

   // COMPUTE AND ADD SIZE OF ALL BUCKETS
   for (int i = 0; i < NUMBUCKETS; i++){
         sizeSoFar = sizeSoFar + listLength(hashMapArray[i]);
   }//FOR
   return sizeSoFar;

}// function SIZEOFHASHMAP

/****************************************************************/

int main() {

    //CREATE AND INSTANTIATE AN ARRAY OF LINKED LISTS
    for (int i = 0; i < NUMBUCKETS; i++){
         hashMapArray[i] = makeList();
    }//FOR

    showListADT();

    //FREE ALL LISTS
    for (int i = 0; i < NUMBUCKETS; i++){ 
        deleteList(hashMapArray[i]);
    } //FOR
    return 0;
} //MAIN

/* ************************************************************* */
