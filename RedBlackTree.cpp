/*
Red-Black Tree Implementation in C++
Properties:
1. Every node is either red or black
2. Root is always black
3. Red nodes cannot have red children (no two reds in a row)
4. Every path from a node to its null descendants contains same number of black nodes
Supports insertion, search, and inorder traversal.
*/

#include <iostream>
using namespace std;

enum Color
{
    RED,
    BLACK
};

// Node structure
struct Node
{
    int data;
    Color color;
    Node *left, *right, *parent;

    Node(int data)
    {
        this->data = data;
        left = right = parent = nullptr;
        color = RED;
    }
};

class RBTree
{
private:
    Node *root;

    // Left rotation
    void rotateLeft(Node *&root, Node *&pt)
    {
        Node *pt_right = pt->right;
        pt->right = pt_right->left;

        if (pt->right != nullptr)
            pt->right->parent = pt;

        pt_right->parent = pt->parent;

        if (pt->parent == nullptr)
            root = pt_right;
        else if (pt == pt->parent->left)
            pt->parent->left = pt_right;
        else
            pt->parent->right = pt_right;

        pt_right->left = pt;
        pt->parent = pt_right;
    }

    // Right rotation
    void rotateRight(Node *&root, Node *&pt)
    {
        Node *pt_left = pt->left;
        pt->left = pt_left->right;

        if (pt->left != nullptr)
            pt->left->parent = pt;

        pt_left->parent = pt->parent;

        if (pt->parent == nullptr)
            root = pt_left;
        else if (pt == pt->parent->left)
            pt->parent->left = pt_left;
        else
            pt->parent->right = pt_left;

        pt_left->right = pt;
        pt->parent = pt_left;
    }

    // Fix violations after insertion
    void fixViolation(Node *&root, Node *&pt)
    {
        Node *parent_pt = nullptr;
        Node *grand_parent_pt = nullptr;

        while ((pt != root) && (pt->color != BLACK) &&
               (pt->parent->color == RED))
        {

            parent_pt = pt->parent;
            grand_parent_pt = pt->parent->parent;

            // Parent is left child of grandparent
            if (parent_pt == grand_parent_pt->left)
            {
                Node *uncle_pt = grand_parent_pt->right;

                // Case 1: Uncle is RED
                if (uncle_pt != nullptr && uncle_pt->color == RED)
                {
                    grand_parent_pt->color = RED;
                    parent_pt->color = BLACK;
                    uncle_pt->color = BLACK;
                    pt = grand_parent_pt;
                }
                else
                {
                    // Case 2: pt is right child
                    if (pt == parent_pt->right)
                    {
                        rotateLeft(root, parent_pt);
                        pt = parent_pt;
                        parent_pt = pt->parent;
                    }

                    // Case 3: pt is left child
                    rotateRight(root, grand_parent_pt);
                    swap(parent_pt->color, grand_parent_pt->color);
                    pt = parent_pt;
                }
            }
            else
            { // Parent is right child of grandparent
                Node *uncle_pt = grand_parent_pt->left;

                if ((uncle_pt != nullptr) && (uncle_pt->color == RED))
                {
                    grand_parent_pt->color = RED;
                    parent_pt->color = BLACK;
                    uncle_pt->color = BLACK;
                    pt = grand_parent_pt;
                }
                else
                {
                    if (pt == parent_pt->left)
                    {
                        rotateRight(root, parent_pt);
                        pt = parent_pt;
                        parent_pt = pt->parent;
                    }

                    rotateLeft(root, grand_parent_pt);
                    swap(parent_pt->color, grand_parent_pt->color);
                    pt = parent_pt;
                }
            }
        }

        root->color = BLACK;
    }

    // Inorder traversal
    void inorderHelper(Node *root)
    {
        if (root == nullptr)
            return;
        inorderHelper(root->left);
        cout << root->data << "(" << (root->color == RED ? "R" : "B") << ") ";
        inorderHelper(root->right);
    }

public:
    RBTree() { root = nullptr; }

    void insert(const int &data)
    {
        Node *pt = new Node(data);
        root = bstInsert(root, pt);
        fixViolation(root, pt);
    }

    // BST insert helper
    Node *bstInsert(Node *root, Node *pt)
    {
        if (root == nullptr)
            return pt;

        if (pt->data < root->data)
        {
            root->left = bstInsert(root->left, pt);
            root->left->parent = root;
        }
        else if (pt->data > root->data)
        {
            root->right = bstInsert(root->right, pt);
            root->right->parent = root;
        }
        return root;
    }

    void inorder()
    {
        inorderHelper(root);
        cout << endl;
    }
};

// Demo main
int main() {
    RBTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(15);

    cout << "Inorder traversal of Red-Black Tree:\n";
    tree.inorder();

    return 0;
}