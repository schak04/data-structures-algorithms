/*
 * Graph Implementation using Adjacency List
 * 
 * Represents an undirected graph using adjacency lists.
 * Each vertex has a list of its adjacent vertices.
 */

#include <iostream>
#include <vector>
#include <list>

class Graph {
private:
    int numVertices;
    std::vector<std::list<int>> adjacencyList;

public:
    /**
     * Constructor
     * @param vertices Number of vertices in the graph
     */
    Graph(int vertices) : numVertices(vertices) {
        adjacencyList.resize(numVertices);
    }

    /**
     * Add an undirected edge between two vertices
     * @param u First vertex
     * @param v Second vertex
     */
    void addEdge(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            adjacencyList[u].push_back(v);
            adjacencyList[v].push_back(u); // Undirected graph
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
            adjacencyList[u].remove(v);
            adjacencyList[v].remove(u); // Undirected graph
        }
    }

    /**
     * Display the adjacency list representation
     */
    void displayAdjList() const {
        std::cout << "Adjacency List Representation:\n";
        for (int i = 0; i < numVertices; i++) {
            std::cout << i << ": ";
            for (int vertex : adjacencyList[i]) {
                std::cout << vertex << " ";
            }
            std::cout << "\n";
        }
    }

    /**
     * Get the number of vertices
     */
    int getNumVertices() const {
        return numVertices;
    }

    /**
     * Get the adjacency list for a vertex
     */
    const std::list<int>& getAdjacent(int vertex) const {
        return adjacencyList[vertex];
    }
};

int main() {
    // Create a graph with 4 vertices
    Graph g(4);

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    // Display the adjacency list
    g.displayAdjList();

    // Display neighbors of vertex 2
    std::cout << "\nNeighbors of vertex 2: ";
    for (int neighbor : g.getAdjacent(2)) {
        std::cout << neighbor << " ";
    }
    std::cout << "\n";

    return 0;
}

