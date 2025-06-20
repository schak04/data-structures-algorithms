/*
This code defines a singly linked list and deletes the first node that contains a given value.
The deletion is done by:
1. Checking if the head node contains the value.
2. Otherwise, traversing the list while tracking the previous node.
3. When the node with the target value is found, it is removed by updating the `next` pointer of the previous node.
4. Edge cases like empty list and value not found are handled.
*/

/* Delete by Value in a Singly Linked List */

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to delete a node by value
void deleteByValue(Node*& head, int val) {
    if (head == nullptr) return; // Empty list

    // If the value is in the head node
    if (head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Traverse the list to find the node
    Node* prev = head;
    Node* curr = head->next;

    while (curr != nullptr) {
        if (curr->data == val) {
            prev->next = curr->next;
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    // Value not found: do nothing
}

// Helper function to insert at end
void insertEnd(Node*& head, int val) {
    Node* newNode = new Node{val, nullptr};
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
}

// Helper function to print the list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

/* Example: Deleting a Node by Value */
int main() {
    Node* head = nullptr;
    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);
    printList(head); // 10 -> 20 -> 30 -> 40 -> NULL

    deleteByValue(head, 30);
    printList(head); // 10 -> 20 -> 40 -> NULL

    deleteByValue(head, 10);
    printList(head); // 20 -> 40 -> NULL

    deleteByValue(head, 99); // Not found
    printList(head); // 20 -> 40 -> NULL
}
