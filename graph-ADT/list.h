/* *******************************************************
 *         list.h    This is the implementation file for the
 *                   Singly-Linked List ADT upon which our
 *	             queue and stack programs are based.
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
 * *******************************************************/

#include <stdio.h>
#include <stdlib.h>

/* --------------------------------------------------------
 * DEFINE `Node_t` TYPE
 */
 
typedef struct node {
    int data;
    struct node* next;
} Node_t;

/* --------------------------------------------------------
 * DEFINE `sList_t` TYPE
 */
 
typedef struct sList {
    Node_t* head;
    Node_t* tail;
    //int size;
} sList_t;

/* --------------------------------------------------------
 * FUNCTION `createNode` CREATES A NODE ON THE HEAP,
 * ASSIGNS `inData` TO THE NODE'S `data` ATTRIBUTE, AND
 * RETURNS THE NODE'S ADDRESS 
 */
 
Node_t* createNode(int inData);

/* --------------------------------------------------------
 * FUNCTION `createList` CREATES A LIST AND RETURNS ITS ADDRESS
 */
 
sList_t* createList();

/* --------------------------------------------------------
 * FUNCTION `listEmpty` RETURNS 1 IF A LIST IS EMPTY
 * AND RETURNS 0 IF IT IS NOT EMPTY
 */

int listEmpty(sList_t* inList_p);
 
/* --------------------------------------------------------
 * FUNCTION `listLength` COUNTS THE NUMBER OF NODES/ITEMS
 * IN A LIST AND RETURNS THE COUNT
 */

int listLength(sList_t* inList_p);

/* --------------------------------------------------------
 * FUNCTION `printNode` PRINTS THE VALUE STORED IN THE
 * `data` ATTRIBUTE IN A NODE
 */
 
void printNode(Node_t* inNode_p);

/* --------------------------------------------------------
 * FUNCTION `printList` ITERATES THROUGH A LIST FROM
 * HEAD TO TAIL AND PRINTS THE VALUE STORED IN EACH NODE.
 * RETURNS 1 IF SUCCESSFUL AND 0 IF NOT SUCCESSFUL
 */ 

int printList(sList_t* inList_p);

/* --------------------------------------------------------
 * FUNCTION `deleteNode` FREES A SINGLE NODE
 */
 
void deleteNode(Node_t* inNode_p);

/* --------------------------------------------------------
 * FUNCTION `insertFront` INSERTS A NEW VALUE `inValue` AT
 * THE BEGINNING OF THE LIST; RETURNS 1 IF SUCCESSFUL AND
 * -1 IF NOT SUCCESSFUL
 */
 
int insertFront(sList_t* inList_p, int inValue);

/* --------------------------------------------------------
 * FUNCTION `insertRear` INSERTS A NEW VALUE `inValue` AT
 * THE END OF THE LIST; RETURNS 1 IF SUCCESSFUL AND -1
 * IF NOT SUCCESSFUL
 */
 
int insertRear(sList_t* inList_p, int inValue);

/* --------------------------------------------------------
 * FUNCTION `deleteFront` REMOVES THE FIRST NODE IN A LIST;
 * RETURNS 1 IF SUCCESSFUL AND -1 IF NOT SUCCESSFUL
 */
 
int deleteFront(sList_t* inList_p);

/* --------------------------------------------------------
 * FUNCTION `deleteRear` REMOVES THE NODE AT THE TAIL OF
 * THE LIST; RETURNS 1 IF SUCCESSFUL AND -1 IF NOT SUCCESSFUL
 */
 
int deleteRear(sList_t* inList_p);

/* --------------------------------------------------------
 * FUNCTION `insert` INSERTS A VALUE `inValue` AT POSITION
 * 'pos' IN LIST; RETURNS 1 IF SUCCESSFUL AND -1 IF NOT
 * SUCCESSFUL
 */
 
int insert(sList_t* inList_p, int inValue, int pos);

/* --------------------------------------------------------
 * FUNCTION `delete` REMOVES A NODE AT POSITION `pos` OF
 * A LIST; RETURNS 1 IF SUCCESSFUL AND -1 IF NOT SUCCESSFUL
 */
 
int delete(sList_t* inList_p, int pos);

/* --------------------------------------------------------
 * FUNCTION `findItem` FINDS A NODE CONTAINING THE VALUE
 * `inValue` IN ITS `data` ATTRIBUTE; RETURNS THE POSITION
 * IN LIST OF THE CORRESPONDING NODE; RETURNS 0 IF NOT IN LIST
 */ 

int findItem(sList_t* inList_p, int inValue);
 
/* -------------------------------------------------------
 * FUNCTION `deleteItem` FINDS THE FIRST INSTANCE OF
 * A NODE CONTAINING THE VALUE `inValue` AND DELETES
 * THE NODE FROM THE LIST; RETURNS 1 IF SUCCESSFUL
 * AND -1 IF NOT SUCCESSFUL
 */
 
int deleteItem(sList_t* inList_p, int inValue);

/* -------------------------------------------------------
 * FUNCTION `deleteList` TRAVERSES AND DELETES EACH NODE
 * IN THE LIST; RETURNS 1 IF SUCCESSFUL AND -1 IF NOT
 * SUCCESSFUL
 */

int deleteList(sList_t* inList_p);

/* -------------------------------------------------------
 * FUNCTION `populateList` GETS A FILE NAME FROM USER,
 * AND FOR EACH INT IN THE FILE, INSERTS THE INT TO THE
 * REAR OF THE LIST; RETURNS 1 IF SUCCESSFUL AND -1 IF NOT
 * SUCCESSFUL
 */

int populateList(sList_t* inList_p);

/* -------------------------------------------------------
 * FUNCTION `populateListFront` GETS A FILE NAME FROM USER,
 * AND FOR EACH INT IN THE FILE, INSERTS THE INT TO THE
 * FRONT OF THE LIST; RETURNS 1 IF SUCCESSFUL AND -1 IF NOT
 * SUCCESSFUL
 */

int populateListFront(sList_t* inList_p);

/* ------------------------------------------------------- */
