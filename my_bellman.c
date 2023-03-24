#include <stdio.h>
#include <stdlib.h>
#include "my_bellman.h"

void bellman_ford(int n, int m, int s, Edge edges[], int dist[]) {
    // Initialize distances
    for (int i = 1; i <= n; i++) {
        // Make the distance to all edge is infinite.
        dist[i] = INT_MAX;
    }
    // The distance of source vertex to itself is 0
    dist[s] = 0;

    // Relax edges repeatedly
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Get current start vertex
            int u = edges[j].u;
            // Get current end vertex
            int v = edges[j].v;
            // Get current edge weight
            int w = edges[j].w;
            // check if finding a smaller distance
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                // Update the distance
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative-weight cycles
    for (int i = 0; i < m; i++) {
        // Get current start vertex
        int u = edges[i].u;
        // Get current end vertex
        int v = edges[i].v;
        // Get current edge weight
        int w = edges[i].w;
        // Check if find a negative-weight cycle
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("Negative-weight cycle found!\n");
            // Exit the program
            exit(0);
        }
    }
}
