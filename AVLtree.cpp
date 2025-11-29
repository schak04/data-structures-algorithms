/*
 * AVL Tree Implementation
 * 
 * AVL tree is a self-balancing Binary Search Tree.
 * Balance factor = left height - right height
 * Balance factor can be -1, 0, or +1 for a balanced AVL tree.
 * Balance factor for leaf nodes is always zero.
 * 
 * Rotations:
 *   1. LL (Left Left) - Right rotation
 *   2. RR (Right Right) - Left rotation
 *   3. LR (Left Right) - Left then Right rotation
 *   4. RL (Right Left) - Right then Left rotation
 * 
 * Rotation happens one node below the node where the imbalance is
 * (in the case of single rotations LL and RR).
 */

#include <iostream>
#include <algorithm>

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    Node* root;

    /**
     * Get height of a node
     */
    int height(Node* node) const {
        return node ? node->height : 0;
    }

    /**
     * Get balance factor of a node
     */
    int getBalance(Node* node) const {
        return node ? height(node->left) - height(node->right) : 0;
    }

    /**
     * Update height of a node
     */
    void updateHeight(Node* node) {
        if (node) {
            node->height = 1 + std::max(height(node->left), height(node->right));
        }
    }

    /**
     * Right rotation (LL case)
     */
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        updateHeight(y);
        updateHeight(x);

        return x; // New root
    }

    /**
     * Left rotation (RR case)
     */
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        updateHeight(x);
        updateHeight(y);

        return y; // New root
    }

    /**
     * Insert a node recursively
     */
    Node* insertNode(Node* node, int key) {
        // Perform normal BST insertion
        if (!node) {
            return new Node(key);
        }

        if (key < node->key) {
            node->left = insertNode(node->left, key);
        } else if (key > node->key) {
            node->right = insertNode(node->right, key);
        } else {
            // Equal keys not allowed
            return node;
        }

        // Update height
        updateHeight(node);

        // Get balance factor
        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && key < node->left->key) {
            return rightRotate(node);
        }

        // Right Right Case
        if (balance < -1 && key > node->right->key) {
            return leftRotate(node);
        }

        // Left Right Case
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    /**
     * Find minimum value node
     */
    Node* minValueNode(Node* node) const {
        Node* current = node;
        while (current && current->left) {
            current = current->left;
        }
        return current;
    }

    /**
     * Delete a node recursively
     */
    Node* deleteNode(Node* node, int key) {
        if (!node) {
            return node;
        }

        if (key < node->key) {
            node->left = deleteNode(node->left, key);
        } else if (key > node->key) {
            node->right = deleteNode(node->right, key);
        } else {
            // Node to be deleted found
            if (!node->left || !node->right) {
                Node* temp = node->left ? node->left : node->right;

                if (!temp) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;
                }
                delete temp;
            } else {
                // Node with two children
                Node* temp = minValueNode(node->right);
                node->key = temp->key;
                node->right = deleteNode(node->right, temp->key);
            }
        }

        if (!node) {
            return node;
        }

        // Update height
        updateHeight(node);

        // Get balance factor
        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && getBalance(node->left) >= 0) {
            return rightRotate(node);
        }

        // Left Right Case
        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Right Case
        if (balance < -1 && getBalance(node->right) <= 0) {
            return leftRotate(node);
        }

        // Right Left Case
        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    /**
     * Preorder traversal helper
     */
    void preOrder(Node* node) const {
        if (node) {
            std::cout << node->key << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    /**
     * Inorder traversal helper
     */
    void inOrder(Node* node) const {
        if (node) {
            inOrder(node->left);
            std::cout << node->key << " ";
            inOrder(node->right);
        }
    }

public:
    AVLTree() : root(nullptr) {}

    /**
     * Insert a key
     */
    void insert(int key) {
        root = insertNode(root, key);
    }

    /**
     * Delete a key
     */
    void remove(int key) {
        root = deleteNode(root, key);
    }

    /**
     * Preorder traversal
     */
    void preOrder() const {
        preOrder(root);
    }

    /**
     * Inorder traversal
     */
    void inOrder() const {
        inOrder(root);
    }
};

int main() {
    AVLTree tree;

    // Insert elements
    std::cout << "Inserting: 10, 20, 30, 40, 50, 25\n";
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    std::cout << "Preorder traversal after insertion: ";
    tree.preOrder();
    std::cout << "\n";

    std::cout << "Inorder traversal after insertion: ";
    tree.inOrder();
    std::cout << "\n";

    // Delete nodes
    std::cout << "\nDeleting: 10, 20\n";
    tree.remove(10);
    tree.remove(20);

    std::cout << "Preorder traversal after deletion: ";
    tree.preOrder();
    std::cout << "\n";

    std::cout << "Inorder traversal after deletion: ";
    tree.inOrder();
    std::cout << "\n";

    return 0;
}

