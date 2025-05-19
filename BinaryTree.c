#include <stdio.h>
#include <stdlib.h>

// Definition of a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node* )malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in a binary tree using recursion
// Inserts in the first available position found in the tree
void insertNode(struct Node** root, int data) {
    if (*root == NULL) {
        // Create and insert the new node if root is NULL
        *root = createNode(data);
        return;
    }
    // Recursively insert in left subtree if available
    else if ((*root)->left == NULL) {
        insertNode(&(*root)->left, data);
    }
    // Else recursively insert in right subtree
    else if ((*root)->right == NULL) {
        insertNode(&(*root)->right, data);
    }
    // If both left and right subtrees are occupied, continue recursively
    else {
        insertNode(&(*root)->left, data);
    }
}

// Function to perform in-order traversal (for testing purposes)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to perform pre-order traversal (for testing purposes)
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to perform post-order traversal (for testing purposes)
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Main function
int main() {
    // Creating the root of the binary tree
    struct Node* root = createNode(10);

    // Manually creating some nodes
    root->left = createNode(11);
    root->left->left = createNode(7);
    root->right = createNode(9);
    root->right->left = createNode(15);
    root->right->right = createNode(8);

    printf("In-order traversal before insertion: \n");
    inorderTraversal(root);
    printf("\n");

    printf("Pre-order traversal before insertion: \n");
    preorderTraversal(root);
    printf("\n");

    printf("Post-order traversal before insertion: \n");
    postorderTraversal(root);
    printf("\n");

    // Inserting a new node at first available position
    int newData = 12;
    insertNode(&root, newData);

    printf("In-order traversal after insertion of %d: \n", newData);
    inorderTraversal(root);
    printf("\n");

    printf("Pre-order traversal after insertion of %d: \n", newData);
    preorderTraversal(root);
    printf("\n");
    
    printf("Post-order traversal after insertion of %d: \n", newData);
    postorderTraversal(root);
    printf("\n");

    return 0;
}
