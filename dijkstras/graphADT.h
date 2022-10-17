#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "list.c"
#include "queue.c"
#include "stack.c"

/* **************************************************************
 *      Header File:  graphADT.h
 * 
 *      Programmer:   Norrec Nieh
 *      Course:       CS5008, Summer 2022
 *      Date:         July 26, 2022
 * **************************************************************/

typedef struct edgeNode {
    int    parentData;
    int    data;
    int    edgeCost;
    struct edgeNode* next;
} edgeNode_t;

typedef struct edgeList {
    edgeNode_t* head;
    edgeNode_t* tail;
} edgeList_t;

typedef struct vertexNode {
    int    data;
    int    visited;
    int    expanded;
    int    lastHop;
    int    totalCost;
    int	   numEdges;
    edgeList_t* edges;
} vertexNode_t;

/* ------------------------------------------------------------- */

#define       MAX_VERTICES 20
vertexNode_t* graphArray[MAX_VERTICES];
int	      unexploredArray[MAX_VERTICES + 1];
int           unexploredArraySize = 0;
int	      NUM_VERTICES = 0;
int	      NUM_EDGES = 0;
 
/* ------------------------------------------------------------- */

vertexNode_t* createVertexNode(int inData);
edgeNode_t* createEdgeNode(int inParentData, int inData, int inCost);
edgeList_t* createEdgeList();
void printVertexNode(vertexNode_t* inVertexNode); 
void printEdgeNode(edgeNode_t* inEdgeNode);
void printEdgeList(edgeList_t* inEdgeList);
void printGraph();
void initializeGraph();
int edgeListEmpty(edgeList_t* inEdgeList);
int edgeListLength(edgeList_t* inEdgeList);
int insertFrontEdge(edgeList_t* inEdgeList, edgeNode_t* inEdgeNode);
int insertRearEdge(edgeList_t* inEdgeList, edgeNode_t* inEdgeNode);
int deleteVertexNode(vertexNode_t* inVertexNode);
int deleteEdgeNode(edgeNode_t* inEdgeNode);
int deleteFrontEdge(edgeList_t* inEdgeList);
int deleteRearEdge(edgeList_t* inEdgeList);
int deleteEdgeList(edgeList_t* inEdgeList);
void deleteGraphArray();
void markAsVisited(int vertex);
int isVisited(int vertex);
void markAsExpanded(int vertex);
int isExpanded(int vertex);
void resetFlags();
void graphBFS(int startVertex);
void graphDFS(int startVertex);
edgeNode_t* parseGraphLine(char inLine[300]);
int populateGraph();

/* ------------------------------------------------------------- */

int addToUnexploredArray(int inData);
void removeFromUnexploredArray(int inData);
int findMinCostVertex();
int dijkstra(int source);
int printShortestPaths(int source);
