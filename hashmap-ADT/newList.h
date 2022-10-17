/* *********************************************************
 *                    MIDTERM PROGRAM
 *
 *     newList.h    header file for updated List ADT,
 *                      with each node containing a kvpair
 *                      whose value is a customerRec obj
 *
 *     Programmer:  Norrec Nieh
 *     Course:      CS5008, Summer 2022
 *     Date:        July 4, 2022
 *
 * *********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 // ---------------------------------------------------------

 typedef struct custRec {
      char*  lname;
      char*  fname;
      int    salary;
      int    empNum;
      char*  ssNum;
 }customerRec;

 // ---------------------------------------------------------

 typedef struct kvpair {
      int            key;
      customerRec*   value;
 }kvpair_t;

 // ---------------------------------------------------------

 typedef struct node {
     kvpair_t*     data;
     struct node*  next;
 }node_t;
 
 // ---------------------------------------------------------

 typedef struct list {
     node_t*	head;
     node_t*	tail;
 }list_t;

 // ---------------------------------------------------------

char* getString(int length);
customerRec* getCustomer();
customerRec* parseLine(char tempStr[300]);
kvpair_t* getKVpair(customerRec* inCust);
void printCustomerRec(customerRec* inCust);
void printKVpair(kvpair_t* inPair);
node_t* makeNode(kvpair_t* inPair);
list_t* makeList();
int listEmpty(list_t* inList);
int listLength(list_t* inList);
void printNode(node_t* inNode);
void printList(list_t* inList);
int insertFront(list_t* inList, kvpair_t* inKVpair);
int insertRear(list_t* inList, kvpair_t* inKVpair);
int deleteCustomerRecord(customerRec* inRec);
int deleteKVpair(kvpair_t* inKVpair);
int deleteNode(node_t* inNode);
int deleteFront(list_t* inList);
int deleteRear(list_t* inList);
int deleteList(list_t* inList);
int insert(list_t* inList, int position, kvpair_t* inKVpair);
int delete(list_t* inList, int position);
int findItem(list_t* inList, int item);
int deleteItem(list_t* inList, int item);
int populateList(list_t* inList);

// -----------------------------------------------------------
