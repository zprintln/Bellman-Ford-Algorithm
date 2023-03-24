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