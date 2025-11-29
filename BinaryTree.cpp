#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Level-order insert
void insertNode(Node*& root, int data) {
    if (root == nullptr) {
        root = createNode(data);
        return;
    }

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

bool search(Node* root, int key) {
    if (!root) return false;
    if (root->data == key) return true;

    return search(root->left, key) || search(root->right, key);
}

int height(Node* root) {
    if (!root) return 0;
    int h1 = height(root->left);
    int h2 = height(root->right);
    return max(h1, h2) + 1;
}

int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

Node* getDeepest(Node* root) {
    if (!root) return nullptr;
    queue<Node*> q;
    q.push(root);
    Node* temp;

    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }

    return temp;
}

void deleteDeepest(Node* root, Node* dnode) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->left) {
            if (temp->left == dnode) {
                delete temp->left;
                temp->left = nullptr;
                return;
            } else q.push(temp->left);
        }

        if (temp->right) {
            if (temp->right == dnode) {
                delete temp->right;
                temp->right = nullptr;
                return;
            } else q.push(temp->right);
        }
    }
}

Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr;
    if (!root->left && !root->right) {
        if (root->data == key) {
            delete root;
            return nullptr;
        }
        return root;
    }

    Node* keyNode = nullptr;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->data == key)
            keyNode = temp;

        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }

    if (!keyNode) return root;

    Node* deepest = getDeepest(root);
    keyNode->data = deepest->data;
    deleteDeepest(root, deepest);

    return root;
}

// Traversals
void inorderTraversal(Node* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

void preorderTraversal(Node* root) {
    if (root) {
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(Node* root) {
    if (root) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }
}

int main() {
    Node* root = createNode(10);

    root->left = createNode(11);
    root->left->left = createNode(7);
    root->right = createNode(9);
    root->right->left = createNode(15);
    root->right->right = createNode(8);

    cout << "Height: " << height(root) << endl;
    cout << "Nodes: " << countNodes(root) << endl;

    cout << "Search 15: " << search(root, 15) << endl;
    cout << "Search 99: " << search(root, 99) << endl;

    root = deleteNode(root, 11);

    inorderTraversal(root);

    return 0;
}
