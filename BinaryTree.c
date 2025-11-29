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
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert at first available position
void insertNode(struct Node** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
        return;
    }

    else if ((*root)->left == NULL) {
        insertNode(&(*root)->left, data);
    }
    else if ((*root)->right == NULL) {
        insertNode(&(*root)->right, data);
    }
    else {
        insertNode(&(*root)->left, data);
    }
}

// Search a value in the binary tree
int search(struct Node* root, int key) {
    if (root == NULL) return 0;
    if (root->data == key) return 1;

    return search(root->left, key) || search(root->right, key);
}

// Height of tree
int height(struct Node* root) {
    if (root == NULL) return 0;

    int hl = height(root->left);
    int hr = height(root->right);

    return (hl > hr ? hl : hr) + 1;
}

// Count nodes
int countNodes(struct Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Delete any node → replace with deepest node
struct Node* getDeepestNode(struct Node* root) {
    if (!root) return NULL;
    struct Node* res = root;

    if (root->left)  res = getDeepestNode(root->left);
    if (root->right) res = getDeepestNode(root->right);

    return res;
}

void deleteDeepest(struct Node* root, struct Node* dnode) {
    if (!root) return;

    if (root->left) {
        if (root->left == dnode) {
            free(root->left);
            root->left = NULL;
            return;
        }
        deleteDeepest(root->left, dnode);
    }

    if (root->right) {
        if (root->right == dnode) {
            free(root->right);
            root->right = NULL;
            return;
        }
        deleteDeepest(root->right, dnode);
    }
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return NULL;
    if (root->left == NULL && root->right == NULL) {
        if (root->data == key) {
            free(root);
            return NULL;
        }
        return root;
    }

    struct Node* keyNode = NULL;
    struct Node* temp;

    // Search recursively (only logical approach since your insert is recursive)
    if (root->data == key) keyNode = root;

    if (root->left) {
        temp = deleteNode(root->left, key);
        root->left = temp;
    }

    if (root->right) {
        temp = deleteNode(root->right, key);
        root->right = temp;
    }

    if (!keyNode) return root;

    struct Node* deepest = getDeepestNode(root);
    keyNode->data = deepest->data;

    deleteDeepest(root, deepest);

    return root;
}

// Traversals
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node* root = createNode(10);

    root->left = createNode(11);
    root->left->left = createNode(7);
    root->right = createNode(9);
    root->right->left = createNode(15);
    root->right->right = createNode(8);

    printf("Height: %d\n", height(root));
    printf("Nodes: %d\n", countNodes(root));

    printf("Search 15: %d\n", search(root, 15));
    printf("Search 99: %d\n", search(root, 99));

    root = deleteNode(root, 11);

    inorderTraversal(root);

    return 0;
}
