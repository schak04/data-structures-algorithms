/*
 * Warshall's Algorithm (Transitive Closure)
 * 
 * Finds the transitive closure of a directed graph.
 * Determines if there is a path from vertex i to vertex j for all pairs (i, j).
 * Time Complexity: O(V^3)
 */

#include <iostream>
#include <vector>

class Warshall {
private:
    int numVertices;
    std::vector<std::vector<bool>> reach;

public:
    /**
     * Constructor
     * @param n Number of vertices
     */
    Warshall(int n) : numVertices(n) {
        reach.resize(numVertices, std::vector<bool>(numVertices, false));
    }

    /**
     * Add an edge to the graph
     * @param u Source vertex
     * @param v Destination vertex
     */
    void addEdge(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            reach[u][v] = true;
        }
    }

    /**
     * Set the adjacency matrix directly
     * @param graph Adjacency matrix (0 = no edge, 1 = edge)
     */
    void setGraph(const std::vector<std::vector<int>>& graph) {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                reach[i][j] = (graph[i][j] != 0);
            }
        }
    }

    /**
     * Compute transitive closure using Warshall's algorithm
     */
    void computeTransitiveClosure() {
        // Try all intermediate vertices
        for (int k = 0; k < numVertices; k++) {
            // Pick all vertices as source
            for (int i = 0; i < numVertices; i++) {
                // Pick all vertices as destination
                for (int j = 0; j < numVertices; j++) {
                    // If there's a path from i to k and from k to j,
                    // then there's a path from i to j
                    reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
                }
            }
        }
    }

    /**
     * Display the transitive closure matrix
     */
    void display() const {
        std::cout << "Transitive Closure Matrix:\n";
        std::cout << "   ";
        for (int i = 0; i < numVertices; i++) {
            std::cout << i << " ";
        }
        std::cout << "\n";

        for (int i = 0; i < numVertices; i++) {
            std::cout << i << ": ";
            for (int j = 0; j < numVertices; j++) {
                std::cout << (reach[i][j] ? 1 : 0) << " ";
            }
            std::cout << "\n";
        }
    }

    /**
     * Check if there's a path from u to v
     * @param u Source vertex
     * @param v Destination vertex
     * @return true if path exists, false otherwise
     */
    bool isReachable(int u, int v) const {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            return reach[u][v];
        }
        return false;
    }
};

int main() {
    int n;
    std::cout << "Enter the number of vertices: ";
    std::cin >> n;

    Warshall w(n);

    std::cout << "Enter the adjacency matrix (" << n << "x" << n << "):\n";
    
    std::vector<std::vector<int>> graph(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> graph[i][j];
        }
    }

    w.setGraph(graph);
    w.computeTransitiveClosure();
    w.display();

    // Demo with sample graph
    std::cout << "\n=== Sample Graph Demo ===\n";
    Warshall demo(4);
    demo.addEdge(0, 1);
    demo.addEdge(1, 2);
    demo.addEdge(2, 3);
    demo.addEdge(0, 3);
    
    demo.computeTransitiveClosure();
    demo.display();

    std::cout << "\nPath from 0 to 3: " << (demo.isReachable(0, 3) ? "Yes" : "No") << std::endl;
    std::cout << "Path from 3 to 0: " << (demo.isReachable(3, 0) ? "Yes" : "No") << std::endl;

    return 0;
}

