// For a singly-linked list, take a user-defined integer k as the input and rotate the elements of the list k times
// For example, we have a linked list
// 10->20->30->40->50
// and k = 3.
// Then, the output becomes:
// 40->50->10->20->30

// C program to rotate a linked list
// by changing moving first node to end k times.

#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int new_data) {
    struct Node* new_node = 
       (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

// Function to rotate the linked list
// left by k nodes
struct Node* rotate(struct Node *head, int k) {
    if (k == 0 || head == NULL)
        return head;

    // Rotate the list by k nodes
    for (int i = 0; i < k; ++i) {
        struct Node *curr = head;
        while (curr->next != NULL)
            curr = curr->next;

        // Move the first node to the last
        curr->next = head;
        curr = curr->next;
        head = head->next;
        curr->next = NULL;
    }
    return head;
}

void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
  
    // Create a hard-coded linked list:
    // 10 -> 20 -> 30 -> 40
    struct Node *head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
  
    head = rotate(head, 6);
    printList(head);

    return 0;
}
