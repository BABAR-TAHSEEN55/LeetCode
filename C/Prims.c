
#include <stdio.h>
#include <limits.h>

#define V 7  // Number of vertices

int A[V][V] = {  // Adjacency matrix representation
    {0, 2, 4, 1, 0, 0, 0},
    {2, 0, 3, 0, 7, 0, 0},
    {4, 3, 0, 5, 8, 0, 0},
    {1, 0, 5, 0, 9, 6, 0},
    {0, 7, 8, 9, 0, 10, 12},
    {0, 0, 0, 6, 10, 0, 15},
    {0, 0, 0, 0, 12, 15, 0}
};

int visited[V] = {0};  // To track visited nodes

void PrimMST() {
    int parent[V];   // Store constructed MST
    int key[V];      // Minimum weight edge for each node
    int totalCost = 0;  // Store MST cost

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;  // Set all weights to infinity initially
    }
    
    key[0] = 0;    // Start from node 0
    parent[0] = -1;  // Root has no parent

    for (int count = 0; count < V - 1; count++) {
        int min = INT_MAX, u;

        // Find the minimum key vertex not yet included
        for (int v = 0; v < V; v++) {
            if (!visited[v] && key[v] < min) {
                min = key[v];
                u = v;
            }
        }

        visited[u] = 1;  // Mark node as visited

        // Update adjacent nodes
        for (int v = 0; v < V; v++) {
            if (A[u][v] && !visited[v] && A[u][v] < key[v]) {
                parent[v] = u;
                key[v] = A[u][v];
            }
        }
    }

    printf("Minimum Spanning Tree Edges:\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d (Weight: %d)\n", parent[i], i, A[i][parent[i]]);
        totalCost += A[i][parent[i]];
    }
    printf("Total Cost of MST: %d\n", totalCost);
}

int main() {
    PrimMST();
    return 0;
}


