/*
 * Graph Implementation using Adjacency List
 * 
 * Represents an undirected graph using adjacency lists.
 * Each vertex has a list of its adjacent vertices.
 */

/*
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node* adj[], int i, int j) {
    struct Node* newNode = createNode(j);
    newNode->next = adj[i];
    adj[i] = newNode;

    newNode = createNode(i);
    newNode->next = adj[j];
    adj[j] = newNode;
}

void displayAdjList(struct Node* adj[], int V) {
    for (int i = 0; i < V; i++) {
        printf("%d: ", i);
        struct Node* temp = adj[i];
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int V = 4;
    struct Node* adj[V];
    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);

    displayAdjList(adj, V);
    return 0;
}
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
     */
    Graph(int vertices) : numVertices(vertices) {
        adjacencyList.resize(numVertices);
    }

    /**
     * Add an undirected edge
     */
    void addEdge(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            adjacencyList[u].push_back(v);
            adjacencyList[v].push_back(u); // Undirected
        }
    }

    /**
     * Remove an undirected edge
     */
    void removeEdge(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            adjacencyList[u].remove(v);
            adjacencyList[v].remove(u); // Undirected
        }
    }

    /**
     * Check if two vertices are connected
     */
    bool isConnected(int u, int v) const {
        if (u < 0 || u >= numVertices || v < 0 || v >= numVertices)
            return false;
        for (int neighbor : adjacencyList[u])
            if (neighbor == v) return true;
        return false;
    }

    /**
     * Return the degree of a vertex
     */
    int degree(int vertex) const {
        if (vertex < 0 || vertex >= numVertices) return 0;
        return adjacencyList[vertex].size();
    }

    /**
     * Display adjacency list
     */
    void displayAdjList() const {
        std::cout << "Adjacency List Representation:\n";
        for (int i = 0; i < numVertices; i++) {
            std::cout << i << ": ";
            for (int neighbor : adjacencyList[i])
                std::cout << neighbor << " ";
            std::cout << "\n";
        }
    }

    /**
     * Get adjacency list of a vertex
     */
    const std::list<int>& getAdjacent(int vertex) const {
        return adjacencyList[vertex];
    }
};

int main() {
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.displayAdjList();

    std::cout << "\nEdge (0, 1) connected? " << (g.isConnected(0, 1) ? "Yes" : "No") << std::endl;
    std::cout << "Edge (1, 3) connected? " << (g.isConnected(1, 3) ? "Yes" : "No") << std::endl;
    std::cout << "Degree of vertex 2: " << g.degree(2) << std::endl;

    std::cout << "\nRemoving edge (0, 2)...\n";
    g.removeEdge(0, 2);
    g.displayAdjList();

    return 0;
}