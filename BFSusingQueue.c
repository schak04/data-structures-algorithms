#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX]; // Adjacency matrix for the graph
bool visited[MAX];   // Array to keep track of visited nodes

// Queue implementation
typedef struct {
    int front, rear;
    int items[MAX];
} Queue;

// Initialize the queue
void initializeQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
bool isEmpty(Queue* q) {
    return q->front == -1;
}

// Enqueue an element
void enqueue(Queue* q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

// Dequeue an element
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = q->items[q->front];
    if (q->front >= q->rear) {
        // Reset the queue
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

// Function to initialize the graph and visited arrays
void initializeGraph(int num_vertices) {
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            graph[i][j] = 0;
        }
        visited[i] = false;
    }
}

// Function to add an edge between two vertices
void addEdge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

// Function to perform BFS
void bfs(int start_vertex, int num_vertices) {
    Queue q;
    initializeQueue(&q);

    // Initialize the BFS starting point
    visited[start_vertex] = true;
    enqueue(&q, start_vertex);

    printf("BFS traversal starting from vertex %d:\n", start_vertex);

    while (!isEmpty(&q)) {
        int current_vertex = dequeue(&q);
        printf("%d ", current_vertex);

        // Traverse all adjacent vertices
        for (int i = 0; i < num_vertices; i++) {
            if (graph[current_vertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

int main() {
    int num_vertices = 5;

    // Initialize the graph with 5 vertices
    initializeGraph(num_vertices);

    // Set edges based on the provided structure
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 3);
    addEdge(2, 4);

    int start_vertex = 0; // Starting vertex for BFS
    bfs(start_vertex, num_vertices);

    return 0;
}