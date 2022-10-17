#include "graphADT.h"
#include "graphADT.c"

/* **************************************************************
 *      Driver File:  graphMenu.c
 * 
 *      Programmer:   Norrec Nieh
 *      Course:       CS5008, Summer 2022
 *      Date:         July 27, 2022
 * **************************************************************/

/* --------------------------------------------------------------
 * `printGraphMenu()` prints the menu choices for the graph.
 * ------------------------------------------------------------ */
void printGraphMenu() {

    system("clear");
    printf("----------------------------------------- \n");
    printf("     1 -- CREATE AND POPULATE GRAPH \n");
    printf("     2 -- BREADTH FIRST SEARCH \n");
    printf("     3 -- DEPTH FIRST SEARCH \n");
    printf("     4 -- PERFORM DIJKSTRAS ALGORITHM \n");
    printf("     5 -- GENERATE SHORTEST PATHS \n");
    printf("     6 -- QUIT \n");
    printf("----------------------------------------- \n");

} // FUNCTION `printGraphMenu()`

/* --------------------------------------------------------------
 * `getUserGraphChoice()` gets an integer from the user.
 * ------------------------------------------------------------ */
int getUserGraphChoice() {

    int choice = 0;
    printGraphMenu();
    printf("Enter choice (1-6): ");
    fflush(stdin);
    scanf("%d", &choice);
    printf("\n");
    return choice;

} // FUNCTION `getUserGraphChoice()`

/* --------------------------------------------------------------
 * `executeGraphMenu()` displays the menu and executes the user's
 *   selected choice.
 * ------------------------------------------------------------ */
int executeGraphMenu() {

    int choice = 0;
    int startVertex = 0;
    
    choice = getUserGraphChoice();
    
    switch(choice) {

        // CASE 1: CREATE AND POPULATE GRAPH
        case (1) : {
            populateGraph();
	    printGraph();
	    break;
        } // CASE 1

        // CASE 2: BREADTH FIRST SEARCH
        case (2) : {
            printGraph();
            printf("Enter vertex to start BFS traversal: ");
            scanf("%d", &startVertex);
	    graphBFS(startVertex);
            break;
        } // CASE 2

        // CASE 3: DEPTH FIRST SEARCH
        case (3) : {
            printGraph();
            printf("Enter vertex to start DFS traversal: ");
            scanf("%d", &startVertex);
	    graphDFS(startVertex);
            break;
        } // CASE 3

        // CASE 4: PERFORM DIJKSTRAS ALGORITHM
        case (4) : {
            printf("Enter SOURCE vertex: ");
	    scanf("%d", &startVertex);

            if (dijkstra(startVertex) < 1) {
	        printf("Invalid source vertex entered. Returning to menu.\n");
	    } // IF

	    else {
	        printDijkstraTable();
	        resetFlags();
            } // ELSE
	    break;
        } // CASE 4

        // CASE 5: GENERATE SHORTEST PATHS
        case (5) : {
            printf("Enter SOURCE vertex: ");
	    scanf("%d", &startVertex);
	    if (printShortestPaths(startVertex) < 1) {
                printf("Invalid source vertex entered. Returning to menu.\n");
	    } // IF
            break;
        } // CASE 5 

        // CASE 6: QUIT
        case (6) : {
	    printf("Quitting program...\n");
	    deleteGraphArray();
	    break;
        } // CASE 6

	// DEFAULT
	default: {
	    printf("Invalid choice. Enter a number between 1 and 6.\n");
	} // DEFAULT
    } // SWITCH

    fflush(stdin);
    getchar();
    getchar();
    fflush(stdout);
    return choice;

} // FUNCTION `executeGraphMenu()`

/* --------------------------------------------------------------
 * MAIN
 * ------------------------------------------------------------ */
int main() {

    int choice = -1;
    do {
        choice = executeGraphMenu();
    } while (choice != 6);

    return 0;
} // MAIN

