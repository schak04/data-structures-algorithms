/*
 * Graph Implementation using Adjacency Matrix
 * 
 * Represents an undirected graph using an adjacency matrix.
 * Supports adding edges and displaying the matrix representation.
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
     * @param vertices Number of vertices in the graph
     */
    Graph(int vertices) : numVertices(vertices) {
        // Initialize matrix with all zeros (no edges)
        adjacencyMatrix.resize(numVertices, std::vector<int>(numVertices, 0));
    }

    /**
     * Add an undirected edge between two vertices
     * @param u First vertex
     * @param v Second vertex
     */
    void addEdge(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            adjacencyMatrix[u][v] = 1;
            adjacencyMatrix[v][u] = 1; // Undirected graph
        } else {
            std::cout << "Invalid edge: (" << u << ", " << v << ")" << std::endl;
        }
    }

    /**
     * Remove an edge between two vertices
     * @param u First vertex
     * @param v Second vertex
     */
    void removeEdge(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            adjacencyMatrix[u][v] = 0;
            adjacencyMatrix[v][u] = 0; // Undirected graph
        }
    }

    /**
     * Check if an edge exists between two vertices
     * @param u First vertex
     * @param v Second vertex
     * @return true if edge exists, false otherwise
     */
    bool hasEdge(int u, int v) const {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            return adjacencyMatrix[u][v] == 1;
        }
        return false;
    }

    /**
     * Display the adjacency matrix
     */
    void displayMatrix() const {
        std::cout << "Adjacency Matrix Representation:\n";
        std::cout << "   ";
        for (int i = 0; i < numVertices; i++) {
            std::cout << i << " ";
        }
        std::cout << "\n";

        for (int i = 0; i < numVertices; i++) {
            std::cout << i << ": ";
            for (int j = 0; j < numVertices; j++) {
                std::cout << adjacencyMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    /**
     * Get the number of vertices
     */
    int getNumVertices() const {
        return numVertices;
    }
};

int main() {
    // Create a graph with 4 vertices
    Graph g(4);

    // Add edges one by one
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    // Display the adjacency matrix
    g.displayMatrix();

    // Test edge existence
    std::cout << "\nEdge (0, 1) exists: " << (g.hasEdge(0, 1) ? "Yes" : "No") << std::endl;
    std::cout << "Edge (0, 3) exists: " << (g.hasEdge(0, 3) ? "Yes" : "No") << std::endl;

    // Remove an edge and display again
    std::cout << "\nRemoving edge (1, 2)...\n";
    g.removeEdge(1, 2);
    g.displayMatrix();

    return 0;
}

