#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node* next;
};

struct Node* createNode(int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

void enqueue(struct Node** head, int data, int priority) {
    struct Node* newNode = createNode(data, priority);
    // Special case: the head is NULL or the new node has priority higher than the head's
    if (*head == NULL || (*head)->priority > priority) {
        newNode->next = *head;
        *head = newNode;
    } else {
        // Traverse the list and find the appropriate position to insert the new node
        struct Node* temp = *head;
        while (temp->next!=NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

//Function to remove the highest priority node from the priority queue
void dequeue(struct Node** head) {
    if (*head == NULL) {
        printf("Priority Queue is empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

int isEmpty(struct Node* head) {
    return head == NULL;
}

int peek(struct Node* head) {
    if (head == NULL) {
        printf("No element at the front.\n");
        return -1;
    }

}