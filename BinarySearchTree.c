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

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node in the binary search tree
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary search tree
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);                         // return is used to get results without altering the tree structure
    }                                                                                  // ||
    else if (value < root->data) {                                                     // \/
        root->left = insert(root->left, value);           // while assigning pointers is used to maintain tree integrity during insertions and deletions
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to search for a value in the binary search tree
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    else if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

// Function to find the minimum value node in a subtree
struct Node* findMin(struct Node* root) {
    struct Node* current = root;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from the binary search tree
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return root;
    }
    // If the key is smaller than the root's key, go to the left subtree
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    // If the key is greater than the root's key, go to the right subtree
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } 
    // If key is same as root's key, this is the node to be deleted
    else {
        // Case 1: Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        // Case 2: Node with two children
        struct Node* temp = findMin(root->right);  // Find the inorder successor
        // The inorder successor is the smallest node in the right subtree of the node being deleted. It is the next larger element.
        root->data = temp->data; // Copy the inorder successor's value to this node
        root->right = deleteNode(root->right, temp->data); // Delete the inorder successor (it cannot have a left child)
    }
    return root;
}

// Function to perform in-order traversal of the binary search tree
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 60);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 35);
    root = insert(root, 80);
    root = insert(root, 10);
    root = insert(root, 75);
    
    printf("In-order Traversal: ");
    inorderTraversal(root);
    printf("\n");
    
    int val1=100;
    printf("Element to be searched for: %d\n", val1);
    if (search(root, val1) != NULL) {
        printf("Element found in the BST.\n");
    } 
    else {
        printf("Element not found in the BST.\n");
    }
    
    int val2=10;
    printf("Element to be deleted from BST: %d\n", val2);
    printf("After deletion the updated list is: ");
    root = deleteNode(root, val2);
    
    inorderTraversal(root);
    printf("\n");
    
    // int choice, val;

    // do {
    //     printf("\n1. Insert\n2. Search\n3. Delete\n4. In-order Traversal\n5. Exit\n");
    //     printf("Enter your choice: ");
    //     scanf("%d", &choice);

    //     switch (choice) {
    //         case 1:
    //             printf("Enter the value to insert: ");
    //             scanf("%d", &val);
    //             root = insert(root, val);
    //             break;

    //         case 2:
    //             printf("Enter the value to search: ");
    //             scanf("%d", &val);
    //             if (search(root, val) != NULL) {
    //                 printf("Element %d found in the BST.\n", val);
    //             } else {
    //                 printf("Element %d not found in the BST.\n", val);
    //             }
    //             break;

    //         case 3:
    //             printf("Enter the value to delete: ");
    //             scanf("%d", &val);
    //             root = deleteNode(root, val);
    //             break;

    //         case 4:
    //             printf("In-order Traversal of the BST: ");
    //             inorderTraversal(root);
    //             printf("\n");
    //             break;

    //         case 5:
    //             printf("Exiting...\n");
    //             break;

    //         default:
    //             printf("Invalid choice!\n");
    //     }
    // } while (choice != 5);

    return 0;
}
