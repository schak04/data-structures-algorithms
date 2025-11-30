/*
Topological sort (Kahn's algorithm)

- Orders the vertices of a directed acyclic graph (DAG) so that for every
  directed edge u -> v, vertex u comes before v in the ordering.
- Uses indegree counting and a queue.

Time Complexity: O(V + E)
Space Complexity: O(V + E)
*/

#include <iostream>
#include <vector>
#include <queue>

class DirectedGraph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjacencyList;

public:
    /*
    Constructor.
    @param vertices Number of vertices
    */
    DirectedGraph(int vertices) : numVertices(vertices) {
        adjacencyList.resize(numVertices);
    }

    /*
    Add a directed edge u -> v.
    @param u Source vertex
    @param v Destination vertex
    */
    void addEdge(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            adjacencyList[u].push_back(v);
        }
    }

    /*
    Perform topological sort using Kahn's algorithm.
    @return A topological ordering of vertices. If the graph has a cycle,
            the returned ordering will have fewer than numVertices items.
    */
    std::vector<int> topologicalSort() const {
        std::vector<int> indegree(numVertices, 0);
        for (int u = 0; u < numVertices; u++) {
            for (int v : adjacencyList[u]) {
                indegree[v]++;
            }
        }

        std::queue<int> q;
        for (int i = 0; i < numVertices; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        std::vector<int> order;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            order.push_back(u);

            for (int v : adjacencyList[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return order;
    }
};

int main() {
    // Example DAG
    // 5 -> 2, 5 -> 0, 4 -> 0, 4 -> 1, 2 -> 3, 3 -> 1
    DirectedGraph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    std::vector<int> order = g.topologicalSort();

    std::cout << "Topological ordering: ";
    for (int v : order) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    return 0;
}
