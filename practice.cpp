#include <iostream>
using namespace std;

// Defining a structure 'Node' using typedef
typedef struct node {
    int data;
    struct node *next;
} Node;

// Function to traverse the linked list
void traverseLinkedList(Node* head){
    Node* temp = head;
    while (temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to insert a node at the beginning of the linked list
Node* insertAtBeg(Node* head, int value){
    // Create a new node
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;  // Link the new node to the old head
    head = newNode;  // Update the head to the new node
    return head;
}

int main(){
    Node* head = NULL;

    // Insert nodes at the beginning
    head = insertAtBeg(head, 10);
    head = insertAtBeg(head, 20);
    head = insertAtBeg(head, 30);

    // Traverse and print the linked list
    traverseLinkedList(head);

    return 0;
}
