/*
 * Breadth-First Search (BFS) using Queue
 * 
 * Implements iterative BFS traversal of a graph using a queue data structure.
 * Uses adjacency matrix representation for the graph.
 */

#include <iostream>
#include <vector>
#include <queue>

class Graph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjacencyMatrix;
    std::vector<bool> visited;

public:
    /**
     * Constructor to initialize the graph
     * @param vertices Number of vertices in the graph
     */
    Graph(int vertices) : numVertices(vertices) {
        adjacencyMatrix.resize(numVertices, std::vector<int>(numVertices, 0));
        visited.resize(numVertices, false);
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
        }
    }

    /**
     * Reset visited array for new traversal
     */
    void resetVisited() {
        std::fill(visited.begin(), visited.end(), false);
    }

    /**
     * Perform BFS traversal starting from a given vertex
     * @param startVertex Starting vertex for BFS
     */
    void bfs(int startVertex) {
        if (startVertex < 0 || startVertex >= numVertices) {
            std::cout << "Invalid starting vertex!" << std::endl;
            return;
        }

        resetVisited();
        std::queue<int> q;

        // Mark start vertex as visited and enqueue it
        visited[startVertex] = true;
        q.push(startVertex);

        std::cout << "BFS traversal starting from vertex " << startVertex << ":\n";

        while (!q.empty()) {
            int currentVertex = q.front();
            q.pop();
            std::cout << currentVertex << " ";

            // Visit all adjacent unvisited vertices
            for (int i = 0; i < numVertices; i++) {
                if (adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        std::cout << std::endl;
    }

    /**
     * Display the adjacency matrix
     */
    void displayMatrix() {
        std::cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                std::cout << adjacencyMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    // Create a graph with 5 vertices
    Graph g(5);

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);

    // Display the graph
    g.displayMatrix();

    // Perform BFS from vertex 0
    g.bfs(0);

    // Perform BFS from vertex 2
    std::cout << "\n";
    g.bfs(2);

    // Perform BFS from vertex 4
    std::cout << "\n";
    g.bfs(4);

    return 0;
}

