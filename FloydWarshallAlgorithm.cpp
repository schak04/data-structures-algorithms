/*
 * Floyd-Warshall Algorithm
 * 
 * Finds shortest paths between all pairs of vertices in a weighted graph.
 * Can handle negative edge weights (but not negative cycles).
 * Time Complexity: O(V^3)
 */

#include <iostream>
#include <vector>
#include <iomanip>
#include <climits>

class FloydWarshall {
private:
    int numVertices;
    std::vector<std::vector<int>> dist;
    static constexpr int INF = 99999;

public:
    /**
     * Constructor
     * @param n Number of vertices
     */
    FloydWarshall(int n) : numVertices(n) {
        dist.resize(numVertices, std::vector<int>(numVertices, INF));
        
        // Initialize diagonal to 0
        for (int i = 0; i < numVertices; i++) {
            dist[i][i] = 0;
        }
    }

    /**
     * Add an edge to the graph
     * @param u Source vertex
     * @param v Destination vertex
     * @param weight Edge weight
     */
    void addEdge(int u, int v, int weight) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            dist[u][v] = weight;
        }
    }

    /**
     * Set the adjacency matrix directly
     * @param graph Adjacency matrix (use INF for no edge)
     */
    void setGraph(const std::vector<std::vector<int>>& graph) {
        dist = graph;
        for (int i = 0; i < numVertices; i++) {
            dist[i][i] = 0;
        }
    }

    /**
     * Compute shortest paths using Floyd-Warshall algorithm
     */
    void computeShortestPaths() {
        // Try all intermediate vertices
        for (int k = 0; k < numVertices; k++) {
            // Pick all vertices as source
            for (int i = 0; i < numVertices; i++) {
                // Pick all vertices as destination
                for (int j = 0; j < numVertices; j++) {
                    // If vertex k is on the shortest path from i to j,
                    // then update the value of dist[i][j]
                    if (dist[i][k] != INF && dist[k][j] != INF &&
                        dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

    /**
     * Display the shortest distance matrix
     */
    void display() const {
        std::cout << "Shortest distances between every pair of vertices:\n";
        std::cout << "   ";
        for (int i = 0; i < numVertices; i++) {
            std::cout << std::setw(5) << i;
        }
        std::cout << "\n";

        for (int i = 0; i < numVertices; i++) {
            std::cout << i << ": ";
            for (int j = 0; j < numVertices; j++) {
                if (dist[i][j] == INF) {
                    std::cout << std::setw(5) << "INF";
                } else {
                    std::cout << std::setw(5) << dist[i][j];
                }
            }
            std::cout << "\n";
        }
    }

    /**
     * Get shortest distance between two vertices
     * @param u Source vertex
     * @param v Destination vertex
     * @return Shortest distance, or INF if unreachable
     */
    int getDistance(int u, int v) const {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            return dist[u][v];
        }
        return INF;
    }
};

int main() {
    int n;
    std::cout << "Enter the number of vertices: ";
    std::cin >> n;

    FloydWarshall fw(n);

    std::cout << "Enter the adjacency matrix (" << n << "x" << n 
              << ") (Use 99999 for INF):\n";
    
    std::vector<std::vector<int>> graph(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> graph[i][j];
        }
    }

    fw.setGraph(graph);
    fw.computeShortestPaths();
    fw.display();

    // Demo with sample graph
    std::cout << "\n=== Sample Graph Demo ===\n";
    FloydWarshall demo(4);
    demo.addEdge(0, 1, 5);
    demo.addEdge(0, 3, 10);
    demo.addEdge(1, 2, 3);
    demo.addEdge(2, 3, 1);
    
    demo.computeShortestPaths();
    demo.display();

    return 0;
}

