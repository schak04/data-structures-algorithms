/*
Depth-first search (DFS) using stack

- Implements iterative DFS traversal of a graph using a stack data structure.
- Uses adjacency matrix representation for the graph.
*/

#include <iostream>
#include <vector>
#include <stack>

class Graph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjacencyMatrix;
    std::vector<bool> visited;

public:
    /*
    Constructor to initialize the graph.
    @param vertices Number of vertices in the graph
    */
    Graph(int vertices) : numVertices(vertices) {
        adjacencyMatrix.resize(numVertices, std::vector<int>(numVertices, 0));
        visited.resize(numVertices, false);
    }

    /*
    Add an undirected edge between two vertices.
    @param u First vertex
    @param v Second vertex
    */
    void addEdge(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            adjacencyMatrix[u][v] = 1;
            adjacencyMatrix[v][u] = 1; // Undirected graph
        }
    }

    /*
    Reset visited array for new traversal.
    */
    void resetVisited() {
        std::fill(visited.begin(), visited.end(), false);
    }

    /*
    Perform DFS traversal starting from a given vertex.
    @param startVertex Starting vertex for DFS
    */
    void dfs(int startVertex) {
        if (startVertex < 0 || startVertex >= numVertices) {
            std::cout << "Invalid starting vertex!" << std::endl;
            return;
        }

        resetVisited();
        std::stack<int> stk;
        stk.push(startVertex);

        std::cout << "DFS traversal starting from vertex " << startVertex << ":\n";

        while (!stk.empty()) {
            int currentVertex = stk.top();
            stk.pop();

            // Process vertex only if not visited
            if (!visited[currentVertex]) {
                visited[currentVertex] = true;
                std::cout << currentVertex << " ";

                // Push all adjacent unvisited vertices onto the stack
                // Push in reverse order to maintain consistent traversal order
                for (int i = numVertices - 1; i >= 0; i--) {
                    if (adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                        stk.push(i);
                    }
                }
            }
        }
        std::cout << std::endl;
    }

    /*
    Display the adjacency matrix.
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

    // Perform DFS from vertex 0
    g.dfs(0);

    // Perform DFS from vertex 2
    std::cout << "\n";
    g.dfs(2);

    // Perform DFS from vertex 4
    std::cout << "\n";
    g.dfs(4);

    return 0;
}

