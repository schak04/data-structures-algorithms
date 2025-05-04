#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}

void initQueue(struct Queue* q) {
    q->front=NULL;
    q->rear=NULL;
}

// Note: No need for isFull() function, because a linked list can never be full

int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

void enqueue(struct Queue* q, int value) {
    struct Node* newNode = createNode(value);
    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Enqueued element: %d\n", value);
}

void dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Cannot dequeue. The queue is empty already.\n");
        return;
    }
    struct Node* temp = q->front;
    q->front = q->front->next;
    
    if (q->front == NULL) {
        q->rear = NULL;
    }

    printf("Dequeued element: %d\n", temp->data);
    free(temp);
}

void displayQueue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = q->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Queue q;
    printf("Initialising a queue...\n");
    initQueue(&q);
    printf("Queue initialised!\n");
    printf("Enqueuing elements into the queue...\n");
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    printf("Displaying the queue...\n");
    displayQueue(&q);
    printf("Dequeuing two elements..\n");
    dequeue(&q);
    dequeue(&q);
    printf("Displaying the queue...\n");
    displayQueue(&q);

    return 0;
}