#include <stdio.h>

#define MAX 100

void warshallAlgorithm(int n, int graph[MAX][MAX]) {
    int reach[MAX][MAX], i, j, k;

    // Initialize the reachability matrix as the input graph
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            reach[i][j] = graph[i][j];
        }
    }

    // Apply Warshall's Algorithm
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }

    // Print the transitive closure
    printf("Transitive Closure Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", reach[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, i, j;
    int graph[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (%dx%d):\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    warshallAlgorithm(n, graph);

    return 0;
}
