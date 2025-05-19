#include <stdio.h>
#include <stdlib.h>

// Node structure for two-way linked list
struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
};

// Function to insert a new node at the end of the list
void insertAtTail(struct Node** head, char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to display the list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to rotate the list by k positions (left rotation)
void rotateByN(struct Node** head, int k) {
    if (*head == NULL || k == 0) return;

    // Find the length of the list
    struct Node* temp = *head;
    int length = 1;
    while (temp->next != NULL) {
        temp = temp->next;
        length++;
    }

    // Make the list circular by connecting the last node to the first node
    temp->next = *head;
    (*head)->prev = temp;

    // Calculate the effective number of rotations
    k = k % length;
    if (k == 0) {
        temp->next = NULL;
        (*head)->prev = NULL;
        return;
    }

    // Move the head to the k-th node (to rotate left by k)
    struct Node* newTail = *head;
    for (int i = 1; i < k; i++) {
        newTail = newTail->next;
    }

    // Set the new head to be the node after the k-th node
    struct Node* newHead = newTail->next;
    newHead->prev = NULL;
    newTail->next = NULL;

    // Update the head pointer
    *head = newHead;
}

// Main function
int main() {
    struct Node* head = NULL;
    int n, k;
    char data;

    // Input number of nodes
    scanf("%d", &n);
    getchar(); // To consume the newline character

    // Input characters and create the list
    for (int i = 0; i < n; i++) {
        scanf("%c", &data);
        getchar(); // To consume the newline character
        insertAtTail(&head, data);
    }

    // Input number of positions to rotate
    scanf("%d", &k);

    // Rotate the list by k positions
    rotateByN(&head, k);

    // Display the rotated list
    display(head);

    return 0;
}
