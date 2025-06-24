/*
In a Binary Search Tree (BST):
- All nodes of the left subtree are smaller.
- All nodes of the right subtree are greater.
- Left and Right subtrees are also BSTs.
- Some BSTs allow duplicate keys, while others do not.
- In-order traversal of a BST gives an ascendingly sorted array.
- In a Binary Search Tree (BST), keys are unique values stored
  in each node of the tree, and they are used to determine the
  order of the nodes.
- The rank of a key k is the number of keys in the BST
  that are less than k.
- The inorder successor of a node cannot have a left child.
  If it did, it would violate the definition of being the "smallest" node
  greater than the key of the original node since there would be a
  smaller node (the left child) in its subtree.
*/

#include <iostream>
using namespace std;

// Node structure for BST
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Insert a value into the BST
Node* insert(Node* root, int val) {
    if (root == nullptr) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else if (val > root->data) root->right = insert(root->right, val);
    return root;
}

// In-order Traversal (Left, Root, Right)
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

// Search for a key in BST
Node* search(Node* root, int key) {
    if (root == nullptr || root->data == key) return root;
    if (key < root->data) return search(root->left, key);
    return search(root->right, key);
}

// Find minimum value node (used to find inorder successor)
Node* findMin(Node* root) {
    while (root && root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Delete a node from BST
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return root;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Case 1: No or one child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 2: Two children
        Node* temp = findMin(root->right); // find the inorder successor
        // inorder successor = ->  the smallest node in the right subtree and the next larger element
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Main function to test the BST operations
int main() {
    Node* root = nullptr;

    // Insertion
    root = insert(root, 60);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 35);
    root = insert(root, 80);
    root = insert(root, 10);
    root = insert(root, 75);

    // Inorder Traversal
    cout << "In-order Traversal: ";
    inorderTraversal(root);
    cout << "\n";

    // Search for a value
    int val1 = 100;
    cout << "Searching for: " << val1 << endl;
    if (search(root, val1) != nullptr)
        cout << "Element found in BST.\n";
    else
        cout << "Element not found in BST.\n";

    // Deletion
    int val2 = 10;
    cout << "Deleting: " << val2 << endl;
    root = deleteNode(root, val2);
    cout << "After deletion: ";
    inorderTraversal(root);
    cout << "\n";

    return 0;
}
