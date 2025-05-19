/* SLL */

#include <stdio.h>
#include <stdlib.h>
// Define a node structure
struct Node {
    int data;
    struct Node* next;
};
// Define a deque structure
struct Deque {
    struct Node* front;
    struct Node* rear;
};
// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
// Initialize the deque
struct Deque* createDeque() {
    struct Deque* dq = (struct Deque*)malloc(sizeof(struct Deque));
    dq->front = dq->rear = NULL;
    return dq;
}
// Function to check if deque is empty
int isEmpty(struct Deque* dq) {
    return (dq->front == NULL);
}
// Insert at the front
void insertFront(struct Deque* dq, int data) {
    struct Node* newNode = createNode(data);
    if (isEmpty(dq)) {
        dq->front = dq->rear = newNode;
    } else {
        newNode->next = dq->front;
        dq->front = newNode;
    }
    printf("%d inserted at the front\n", data);
}

// Insert at the rear
void insertRear(struct Deque* dq, int data) {
    struct Node* newNode = createNode(data);
    if (isEmpty(dq)) {
        dq->front = dq->rear = newNode;
    } else {
        dq->rear->next = newNode;
        dq->rear = newNode;
    }
    printf("%d inserted at the rear\n", data);
}
// Delete from the front
void deleteFront(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty, cannot delete from front.\n");
        return;
    }
    struct Node* temp = dq->front;
    dq->front = dq->front->next;
    if (dq->front == NULL) {
        dq->rear = NULL;
    }
    printf("Deleted %d from the front\n", temp->data);
    free(temp);
}

// Delete from the rear
void deleteRear(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty, cannot delete from rear.\n");
        return;
    }

    struct Node* temp = dq->front;

    // If only one element in the deque
    if (dq->front == dq->rear) {
        printf("Deleted %d from the rear\n", dq->rear->data);
        free(dq->rear);
        dq->front = dq->rear = NULL;
        return;
    }

    // Traverse to the second last node
    while (temp->next != dq->rear) {
        temp = temp->next;
    }

    printf("Deleted %d from the rear\n", dq->rear->data);
    free(dq->rear);
    dq->rear = temp;
    dq->rear->next = NULL;
}

// Display the deque
void display(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return;
    }
    struct Node* temp = dq->front;
    printf("Deque: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the deque implementation
int main() {
    struct Deque* dq = createDeque();

    insertRear(dq, 10);
    insertFront(dq, 20);
    insertRear(dq, 30);
    insertFront(dq, 40);

    display(dq);

    deleteFront(dq);
    deleteRear(dq);

    display(dq);

    return 0;
}


/* DLL */

// #include <stdio.h>
// #include <stdlib.h>

// // Structure for a node in the doubly linked list
// struct Node {
//     int data;
//     struct Node* next;
//     struct Node* prev;
// };

// // Structure to represent a deque
// struct Deque {
//     struct Node* front;
//     struct Node* rear;
// };

// // Function to create an empty deque
// struct Deque* createDeque() {
//     struct Deque* deque = (struct Deque*)malloc(sizeof(struct Deque));
//     deque->front = NULL;
//     deque->rear = NULL;
//     return deque;
// }

// // Function to check if deque is empty
// int isEmpty(struct Deque* deque) {
//     return (deque->front == NULL);
// }

// // Insert an element at the front of the deque
// void insertFront(struct Deque* deque, int value) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = value;
//     newNode->next = deque->front;
//     newNode->prev = NULL;

//     if (isEmpty(deque)) {
//         deque->rear = newNode;
//     } else {
//         deque->front->prev = newNode;
//     }
//     deque->front = newNode;
// }

// // Insert an element at the rear of the deque
// void insertRear(struct Deque* deque, int value) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = value;
//     newNode->next = NULL;
//     newNode->prev = deque->rear;

//     if (isEmpty(deque)) {
//         deque->front = newNode;
//     } else {
//         deque->rear->next = newNode;
//     }
//     deque->rear = newNode;
// }

// // Delete an element from the front of the deque
// void deleteFront(struct Deque* deque) {
//     if (isEmpty(deque)) {
//         printf("Deque is empty\n");
//         return;
//     }

//     struct Node* temp = deque->front;
//     printf("Removed from front: %d\n", temp->data);

//     deque->front = deque->front->next;

//     if (deque->front == NULL) {
//         deque->rear = NULL;  // If the deque becomes empty
//     } else {
//         deque->front->prev = NULL;
//     }

//     free(temp);
// }

// // Delete an element from the rear of the deque
// void deleteRear(struct Deque* deque) {
//     if (isEmpty(deque)) {
//         printf("Deque is empty\n");
//         return;
//     }

//     struct Node* temp = deque->rear;
//     printf("Removed from rear: %d\n", temp->data);

//     deque->rear = deque->rear->prev;

//     if (deque->rear == NULL) {
//         deque->front = NULL;  // If the deque becomes empty
//     } else {
//         deque->rear->next = NULL;
//     }

//     free(temp);
// }

// // Function to get the front element of the deque
// int getFront(struct Deque* deque) {
//     if (isEmpty(deque)) {
//         printf("Deque is empty\n");
//         return -1;
//     }
//     return deque->front->data;
// }

// // Function to get the rear element of the deque
// int getRear(struct Deque* deque) {
//     if (isEmpty(deque)) {
//         printf("Deque is empty\n");
//         return -1;
//     }
//     return deque->rear->data;
// }

// // Display the elements in the deque
// void displayDeque(struct Deque* deque) {
//     if (isEmpty(deque)) {
//         printf("Deque is empty\n");
//         return;
//     }

//     printf("Deque elements: ");
//     struct Node* current = deque->front;
//     while (current != NULL) {
//         printf("%d ", current->data);
//         current = current->next;
//     }
//     printf("\n");
// }

// // Main function to test the deque
// int main() {
//     struct Deque* deque = createDeque();
    
//     insertRear(deque, 10);
//     insertRear(deque, 20);
//     insertFront(deque, 30);
//     insertFront(deque, 40);
    
//     displayDeque(deque);
    
//     deleteFront(deque);
//     deleteRear(deque);
    
//     displayDeque(deque);
    
//     printf("Front element: %d\n", getFront(deque));
//     printf("Rear element: %d\n", getRear(deque));
    
//     return 0;
// }
