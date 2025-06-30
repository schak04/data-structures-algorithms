#include <iostream>
#include <queue>
using namespace std;

// Definition of a tree node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Function to insert a node in a binary tree using recursion
// Inserts in the first available position found in the tree
void insertNode(Node*& root, int data) {
    if (root == nullptr) {
        root = createNode(data);
        return;
    }
    // Use a queue for level order traversal to find the first available spot
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if (temp->left == nullptr) {
            temp->left = createNode(data);
            return;
        } else {
            q.push(temp->left);
        }
        if (temp->right == nullptr) {
            temp->right = createNode(data);
            return;
        } else {
            q.push(temp->right);
        }
    }
}

// Function to perform in-order traversal (for testing purposes)
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

// Function to perform pre-order traversal (for testing purposes)
void preorderTraversal(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to perform post-order traversal (for testing purposes)
void postorderTraversal(Node* root) {
    if (root != nullptr) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }
}

// Main function
int main() {
    // Creating the root of the binary tree
    Node* root = createNode(10);

    // Manually creating some nodes
    root->left = createNode(11);
    root->left->left = createNode(7);
    root->right = createNode(9);
    root->right->left = createNode(15);
    root->right->right = createNode(8);

    cout << "In-order traversal before insertion: " << endl;
    inorderTraversal(root);
    cout << endl;

    cout << "Pre-order traversal before insertion: " << endl;
    preorderTraversal(root);
    cout << endl;

    cout << "Post-order traversal before insertion: " << endl;
    postorderTraversal(root);
    cout << endl;

    // Inserting a new node at first available position
    int newData = 12;
    insertNode(root, newData);

    cout << "In-order traversal after insertion of " << newData << ": " << endl;
    inorderTraversal(root);
    cout << endl;

    cout << "Pre-order traversal after insertion of " << newData << ": " << endl;
    preorderTraversal(root);
    cout << endl;
    
    cout << "Post-order traversal after insertion of " << newData << ": " << endl;
    postorderTraversal(root);
    cout << endl;

    return 0;
}
