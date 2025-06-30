// Implementation of Level Order Traversal for a binary tree in C++

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
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        cout << current->data << " ";
        q.pop();
        if (current->left != NULL)
            q.push(current->left);
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
    cout << endl;
    return 0;
}
