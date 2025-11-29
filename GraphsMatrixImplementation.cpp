/*
 * Graph Implementation using Adjacency Matrix
 * 
 * Represents an undirected graph using an adjacency matrix.
 * Supports adding edges, removing edges, checking connectivity,
 * finding degree, and displaying the matrix representation.
 */

/*
#define V 4

void addEdge(int mat[V][V], int i, int j) {
    mat[i][j] = 1;
    mat[j][i] = 1; // Since the graph is undirected
}

void displayMatrix(int mat[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

int main() {
    int mat[V][V] = {0};
    addEdge(mat, 0, 1);
    addEdge(mat, 0, 2);
    addEdge(mat, 1, 2);
    addEdge(mat, 2, 3);

    displayMatrix(mat);
    return 0;
}
*/

#include <iostream>
#include <vector>

class Graph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjacencyMatrix;

public:
    /**
     * Constructor to initialize the graph
     * @param vertices Number of vertices
     */
    Graph(int vertices) : numVertices(vertices) {
        adjacencyMatrix.resize(numVertices, std::vector<int>(numVertices, 0));
    }

    /**
     * Add an undirected edge between two vertices
     */
    void addEdge(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            adjacencyMatrix[u][v] = 1;
            adjacencyMatrix[v][u] = 1; // Undirected graph
        }
    }

    /**
     * Remove an edge between two vertices
     */
    void removeEdge(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            adjacencyMatrix[u][v] = 0;
            adjacencyMatrix[v][u] = 0; // Undirected graph
        }
    }

    /**
     * Check if two vertices are connected
     */
    bool isConnected(int u, int v) const {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices)
            return adjacencyMatrix[u][v] == 1;
        return false;
    }

    /**
     * Return the degree of a vertex
     */
    int degree(int vertex) const {
        int deg = 0;
        for (int i = 0; i < numVertices; i++)
            deg += adjacencyMatrix[vertex][i];
        return deg;
    }

    /**
     * Display the adjacency matrix
     */
    void displayMatrix() const {
        std::cout << "Adjacency Matrix Representation:\n   ";
        for (int i = 0; i < numVertices; i++)
            std::cout << i << " ";
        std::cout << "\n";

        for (int i = 0; i < numVertices; i++) {
            std::cout << i << ": ";
            for (int j = 0; j < numVertices; j++)
                std::cout << adjacencyMatrix[i][j] << " ";
            std::cout << std::endl;
        }
    }
};

int main() {
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.displayMatrix();

    std::cout << "\nEdge (0, 1) connected? " << (g.isConnected(0, 1) ? "Yes" : "No") << std::endl;
    std::cout << "Edge (0, 3) connected? " << (g.isConnected(0, 3) ? "Yes" : "No") << std::endl;
    std::cout << "Degree of vertex 2: " << g.degree(2) << std::endl;

    std::cout << "\nRemoving edge (1, 2)...\n";
    g.removeEdge(1, 2);
    g.displayMatrix();

    return 0;
}