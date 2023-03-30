#include <stdio.h>
#include <stdlib.h>
#include "my_bellman.h"

int unitTest1(){
    int n = 5; // number of vertices
    int m = 6; // number of edges
    int s = 0; // source vertex

    // Create a graph
    struct Graph* graph = createGraph(n, m);

    // Give the example graph
    int src[] = {0, 0, 1, 1, 2, 2};
    int dest[] = {1, 2, 2, 3, 3, 4};
    int weight[] = {6, 3, 2, 5, 3, -4};

    // Add edges to the graph
    for(int i = 0; i < m; i++){
        graph->edge[i].src = src[i];
        graph->edge[i].dest = dest[i];
        graph->edge[i].weight = weight[i];
    }

    // Print the graph
    printf(" 0-----(6)---->1<--+ \n");
    printf(" |             |  (3)\n");
    printf(" |             |---+ \n");
    printf("(3)            |     \n");
    printf(" |            (5)    \n");
    printf(" |             |     \n");
    printf(" v             v     \n");
    printf(" 2-----(3)---->3     \n");
    printf(" |                   \n");
    printf(" |                   \n");
    printf("(-4)                 \n");
    printf(" |                   \n");
    printf(" v                   \n");
    printf(" 4                   \n");

    // Run Bellman-Ford algorithm
    bellmanFord(graph, s);

    // Free the graph
    freeGraph(graph);
    return 0;
}

int unitTest2(){
	int n = 4; // number of vertices
	int m = 5; // number of edges
	int s = 0; // source vertex
	
	struct Graph* graph = createGraph(n, m);
	
	int src[] = {0, 1, 1, 2, 3};
	int dest[] = {1, 2, 3, 1, 2};
	int weight[] = {-3, -2, -5, -1, -7};
	
	for (int i = 0; i < m; i++){
		graph->edge[i].src = src[i];
		graph->edge[i].dest = dest[i];
		graph->edge[i].weight = weight[i];
	}

	// Print the graph
	printf(" 0-----(-3)---->1<----(-2)----3 \n");
	printf("         |             |        \n");
	printf("       (-5)           (1)      \n");
	printf("         |             |        \n");
	printf("         v             v        \n");
	printf("         2             4        \n");

	bellmanFord(graph, s);

	freeGraph(graph);
	return 0;
}

int unitTest3(){
	int n = 10;
	int m = 18;
	int s = 0;

	struct Graph* graph = createGraph(n,m);

	int src[] = {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8};
	int dest[] = {1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 0};
	int weight[] = {3, 4, -2, 5, -6, 2, 1, 3, -5, -2, 1, 5, 2, 4, 6, 3, 1, 5};

	for (int i = 0; i < m; i++){
		graph->edge[i].src = src[i];
		graph->edge[i].dest = dest[i];
		graph->edge[i].weight = weight[i];
	}

	bellmanFord(graph, s);
	freeGraph(graph);
	return 0;
}	
