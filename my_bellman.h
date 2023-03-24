#ifndef BELLMAN_FORD_H
#define BELLMAN_FORD_H

#include <limits.h>

// Set the max number of vertices
#define MAX_VERTICES 1000
// Set the max numebr of edges
#define MAX_EDGES 10000

// Build a struct to store the edges
typedef struct {
    // Start vertex
    int u;
    // End vertex
    int v;
    // Edge weight
    int w;
} Edge;

// n: the number of vertices
// m: the number of edges
// s: source vertex
// edges[]: an array of Edge structs
// dist[]: an array of distances
// dist[i] represnts the distance from source vertex to vertex i
void bellman_ford(int n, int m, int s, Edge edges[], int dist[]);


#endif
