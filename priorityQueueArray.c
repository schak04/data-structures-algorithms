#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

struct priorityQueue {
    int arr[MAX];
    int priority[MAX];
    int size;
};

void initQueue(struct priorityQueue* pq) {
    pq->size = -1;
}

int isEmpty(struct priorityQueue* pq) {
    return pq->size == -1;
}

int isFull(struct priorityQueue* pq) {
    return pq->size == MAX;
}

void enqueue(struct priorityQueue* pq, int value, int priorityValue) {
    if (isFull(pq)) {
        printf("Cannot enqueue. Queue is already full.\n");
        return;
    }
    pq->arr[++pq->size] = value;
    pq->priority[pq->size] = priorityValue;
}

int getHighestPriorityIndex(struct priorityQueue* pq) {
    int maxPriority = INT_MIN;
    int index = -1;

    for (int i=0; i<=pq->size; i++) {
        if (pq->priority[i] > maxPriority) {
            maxPriority = pq->priority[i];
            index = i;
        }
    }
    return index;
}

int dequeue(struct priorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty.\n");
        return -1;
    }
    int index = getHighestPriorityIndex(pq);
    int value = pq->arr[index];

    // Shift elements to maintain the array structure --> we wouldn't need this if the least value is taken as the one with the least priority
    for (int i = index; i < pq->size; i++) {
        pq->arr[i] = pq->arr[i+1];
        pq->priority[i] = pq->priority[i+1];
    }
    pq->size--;
    return value;
}

void display(struct priorityQueue* pq) {
    for (int i=0; i<=pq->size; i++) {
        printf("%d ", pq->arr[i]);
    }
    printf("\n");
}

int main() {
    struct priorityQueue pq;
    initQueue(&pq);

    enqueue(&pq, 10, 3);
    enqueue(&pq, 20, 4);
    enqueue(&pq, 30, 2);
    enqueue(&pq, 40, 5);

    display(&pq);

    printf("Dequeued element: %d\n", dequeue(&pq));

    display(&pq);

    return 0;
}