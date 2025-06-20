#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Queue {
    int front;
    int rear;
    int arr[MAX];
};

void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(struct Queue* q) {
    return q->rear == MAX-1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1 || q->front > q->rear;
}

void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow. Cannot insert any more elements.\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    printf("The value inserted is %d.\n", value);
    q->arr[++q->rear] = value;
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow. Cannot remove any more elements.\n");
        return -1;
    }
    printf("Dequeued Element: %d\n", q->arr[q->front]);
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    }
    return q->arr[q->front++];
}

void displayQueue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Nothing to display.\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

void front(struct Queue* q) {
    if (isEmpty(q)) {
        printf("The queue is empty. There's nothing at the front.\n");
        return;
    }
    printf("Element at the front of the queue is: %d\n", q->arr[q->front]);
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
    front(&q);
    printf("Dequeuing one element..\n");
    dequeue(&q);
    front(&q);
    printf("Displaying the queue...\n");
    displayQueue(&q);
    printf("Dequeuing the rest of the elements...\n");
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    printf("Displaying the queue...\n");
    displayQueue(&q);
    
    return 0;
}