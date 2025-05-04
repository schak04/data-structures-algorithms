// Implementation of Level Order Traversal for a binary tree in C

#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to calculate the height of the tree
int height(struct Node* node) {
    if (node == NULL)
        return 0;
    else {
        // Compute the height of each subtree
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        // Use the larger one
        if (leftHeight > rightHeight)
            return (leftHeight + 1);
        else
            return (rightHeight + 1);
    }
}

// Function to print nodes at the current level
void printCurrentLevel(struct Node* root, int level) {
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

// Function for Level Order Traversal
void levelOrderTraversal(struct Node* root) {
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        printCurrentLevel(root, i);
        printf("\n");
    }
}

// Driver program to test the above functions
int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printf("Level Order Traversal of binary tree is:\n");
    levelOrderTraversal(root);

    return 0;
}


/*
//Implementation of Level Order Traversal for a binary tree in C++ using a queue

#include <iostream>
#include <queue>
using namespace std;

// Structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    // Constructor to create a new node
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function for Level Order Traversal using a queue
void levelOrderTraversal(Node* root) {
    if (root == NULL)
        return;

    // Create a queue for level order traversal
    queue<Node*> q;
    
    // Enqueue the root
    q.push(root);
    
    while (!q.empty()) {
        // Get the front node of the queue and print it
        Node* current = q.front();
        cout << current->data << " ";
        q.pop(); // Remove the node from the queue
        
        // Enqueue the left child
        if (current->left != NULL)
            q.push(current->left);
        
        // Enqueue the right child
        if (current->right != NULL)
            q.push(current->right);
    }
}

// Driver code to test the above function
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    cout << "Level Order Traversal of binary tree is: ";
    levelOrderTraversal(root);
    
    return 0;
}
*/