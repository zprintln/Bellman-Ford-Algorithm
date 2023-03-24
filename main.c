// Run with: clang -Wall main.c -o main
#include <stdio.h>
#include "my_bellman.h"
#include "my_bellman.c"

int main() {
    int n = 5; // number of vertices
    int m = 6; // number of edges
    int s = 1; // source vertex

    // Input some edges as an example
    Edge edges[MAX_EDGES] = {
        {1, 2, 6},
        {1, 3, 3},
        {2, 3, 2},
        {2, 4, 5},
        {3, 4, 3},
        {3, 5, -4} // negative-weighted edge
    };

    // Print graph using ASCII art
    printf(" 1-----(6)---->2<--+ \n");
    printf(" |             |  (3)\n");
    printf(" |             |---+ \n");
    printf("(3)            |     \n");
    printf(" |            (5)    \n");
    printf(" |             |     \n");
    printf(" v             v     \n");
    printf(" 3-----(3)---->4     \n");
    printf(" |                   \n");
    printf(" |                   \n");
    printf("(-4)                 \n");
    printf(" |                   \n");
    printf(" v                   \n");
    printf(" 5                   \n");

    // Run Bellman-Ford algorithm
    int dist[MAX_VERTICES];
    bellman_ford(n, m, s, edges, dist);

    // Print distances
    for (int i = 1; i <= n; i++) {
        printf("Distance from %d to %d: %d\n", s, i, dist[i]);
    }

    return 0;
}
