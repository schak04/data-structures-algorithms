#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX]; // Adjacency matrix for the graph
bool visited[MAX];   // Array to keep track of visited nodes

// Stack implementation
typedef struct {
    int top;
    int items[MAX];
} Stack;

// Initialize the stack
void initializeStack(Stack* stack) {
    stack->top = -1;
}

// Check if the stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Push an element onto the stack
void push(Stack* stack, int value) {
    if (stack->top < MAX - 1) {
        stack->items[++stack->top] = value;
    }
}

// Pop an element from the stack
int pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->items[stack->top--];
    }
    return -1; // Return -1 if the stack is empty
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

// Function to perform DFS using a stack
void dfs(int start_vertex, int num_vertices) {
    Stack stack;
    initializeStack(&stack);
    push(&stack, start_vertex);

    printf("DFS traversal starting from vertex %d:\n", start_vertex);

    while (!isEmpty(&stack)) {
        int current_vertex = pop(&stack);

        // If the current vertex is not visited
        if (!visited[current_vertex]) {
            visited[current_vertex] = true;
            printf("%d ", current_vertex);

            // Push all adjacent vertices onto the stack (in reverse order for consistent traversal)
            for (int i = num_vertices - 1; i >= 0; i--) {
                if (graph[current_vertex][i] == 1 && !visited[i]) {
                    push(&stack, i);
                }
            }
        }
    }
    printf("\n");
}

int main() {
    int num_vertices = 5;

    initializeGraph(num_vertices);

    // Set edges based on the provided structure
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 3);
    addEdge(2, 4);

    int start_vertex = 0; // Starting vertex for DFS
    dfs(start_vertex, num_vertices);

    return 0;
}