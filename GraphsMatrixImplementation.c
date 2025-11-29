#include<stdio.h>

#define V 4

// Function to add an edge
void addEdge(int mat[V][V], int i, int j) {
    mat[i][j] = 1;
    mat[j][i] = 1; // Since the graph is undirected
}

// Function to remove an edge
void removeEdge(int mat[V][V], int i, int j) {
    mat[i][j] = 0;
    mat[j][i] = 0; // Undirected
}

// Function to check if two vertices are connected
int isConnected(int mat[V][V], int i, int j) {
    return mat[i][j] == 1;
}

// Function to find degree of a vertex
int degree(int mat[V][V], int vertex) {
    int deg = 0;
    for (int i = 0; i < V; i++)
        deg += mat[vertex][i];
    return deg;
}

// Function to display adjacency matrix
void displayMatrix(int mat[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

int main() {
    // Create a graph with 4 vertices and no edges
    int mat[V][V] = {0};

    // Add edges one by one
    addEdge(mat, 0, 1);
    addEdge(mat, 0, 2);
    addEdge(mat, 1, 2);
    addEdge(mat, 2, 3);

    /* Alternatively, we can also create using the below
       code if we know all edges in advance

    int mat[V][V] = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 0}
    };
    */

    printf("Adjacency Matrix Representation\n");
    displayMatrix(mat);

    printf("\nEdge 0-1 connected? %s\n", isConnected(mat, 0, 1) ? "Yes" : "No");
    printf("Edge 1-3 connected? %s\n", isConnected(mat, 1, 3) ? "Yes" : "No");
    printf("Degree of vertex 2: %d\n", degree(mat, 2));

    printf("\nRemoving edge 0-2\n");
    removeEdge(mat, 0, 2);
    displayMatrix(mat);

    return 0;
}
