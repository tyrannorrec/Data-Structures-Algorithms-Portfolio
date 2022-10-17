/* ******************************************************
 *    stack.h    This is the header file for the
 *                 Char Stack ADT (array implementation).
 *
 *               1.  int stackEmpty()
 *               2.  int stackFull()
 *               3.  int push(char item)
 *               4.  char TOS()
 *               5.  int printStack()
 *               6.  char pop()
 *
 *    Norrec Nieh
 *    CS5008 Summer 2022
 *    5/24/22
 *
 * ******************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

// DEFINE GLOBAL VARS; DECLARE AND INITIALIZE STACKARRAY OF MAXSIZE;
// DECLARE AND INITIALIZE TOP INDEX AT -1 (EMPTY STACK)
char stackArray[MAXSIZE];
int TOP = -1;

/* ******************************************************/

// FUNCTION `stackEmpty()` RETURNS TRUE (1) IF STACK IS EMPTY;
// RETURNS FALSE (0) OTHERWISE
int stackEmpty();

// FUCTION `stackFull()` RETURNS TRUE (1) IF STACK IS FULL;
// RETURNS FALSE (0) OTHERWISE
int stackFull();

// FUNCTION `push(char item)` PUSHES A CHAR ITEM TO THE TOP OF THE STACK;
// RETURNS TRUE (1) IF SUCCESSFUL; PRINTS AN ERROR MESSAGE AND
// RETURNS -1 IF STACK IS FULL 
int push(char item);

// FUNCTION `TOS()` RETURNS THE CHAR AT THE TOP OF THE STACK;
// RETURNS BLANK AND PRINTS AN ERROR MESSAGE IF STACK IS EMPTY
char TOS();

// FUNCTION `printStack()` PRINTS EACH CHAR CONTAINED IN THE STACK,
// FROM TOP TO BOTTOM. RETURNS TRUE (1) IF SUCCESSFUL; RETURNS -1
// IF STACK IS EMPTY
int printStack();

// FUNCTION `pop()` REMOVES THE CHAR AT TOP OF STACK AND RETURNS IT.
// IF STACK IS EMPTY, RETURNS BLANK AND PRINTS ERROR MESSAGE.
char pop();

/* ******************************************************/
