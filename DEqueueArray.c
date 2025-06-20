/* Linear Array */

#include <stdio.h>
#include <stdlib.h>

#define MAX 10  // Maximum size of the deque

// Structure to represent a deque
struct Deque {
    int front;
    int rear;
    int arr[MAX];
};

// Function to create an empty deque
struct Deque* createDeque() {
    struct Deque* deque = (struct Deque*)malloc(sizeof(struct Deque));
    deque->front = -1;
    deque->rear = -1;
    return deque;
}

// Function to check if deque is full
int isFull(struct Deque* deque) {
    return (deque->rear == MAX - 1);
}

// Function to check if deque is empty
int isEmpty(struct Deque* deque) {
    return (deque->front == -1);
}

// Insert an element at the front of the deque
void insertFront(struct Deque* deque, int value) {
    if (isFull(deque)) {
        printf("Deque is full\n");
        return;
    }

    // If deque is empty, initialize front and rear
    if (isEmpty(deque)) {
        deque->front = deque->rear = 0;
    } else if (deque->front == 0) {  // Front is already at the start, no space
        printf("Cannot insert at front, no space\n");
        return;
    } else {
        deque->front--;
    }

    deque->arr[deque->front] = value;
}

// Insert an element at the rear of the deque
void insertRear(struct Deque* deque, int value) {
    if (isFull(deque)) {
        printf("Deque is full\n");
        return;
    }

    if (isEmpty(deque)) {
        deque->front = deque->rear = 0;
    } else {
        deque->rear++;
    }

    deque->arr[deque->rear] = value;
}

// Delete an element from the front of the deque
void deleteFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return;
    }

    printf("Removed from front: %d\n", deque->arr[deque->front]);

    if (deque->front == deque->rear) {  // Only one element in deque
        deque->front = deque->rear = -1;  // Reset deque
    } else {
        deque->front++;
    }
}

// Delete an element from the rear of the deque
void deleteRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return;
    }

    printf("Removed from rear: %d\n", deque->arr[deque->rear]);

    if (deque->front == deque->rear) {  // Only one element in deque
        deque->front = deque->rear = -1;  // Reset deque
    } else {
        deque->rear--;
    }
}

// Function to get the front element of the deque
int getFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return -1;
    }
    return deque->arr[deque->front];
}

// Function to get the rear element of the deque
int getRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return -1;
    }
    return deque->arr[deque->rear];
}

// Display the elements in the deque
void displayDeque(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");
    for (int i = deque->front; i <= deque->rear; i++) {
        printf("%d ", deque->arr[i]);
    }
    printf("\n");
}

// Main function to test the deque
int main() {
    struct Deque* deque = createDeque();
    
    insertRear(deque, 10);
    insertRear(deque, 20);
    insertFront(deque, 30);
    insertFront(deque, 40);
    
    displayDeque(deque);
    
    deleteFront(deque);
    deleteRear(deque);
    
    displayDeque(deque);
    
    printf("Front element: %d\n", getFront(deque));
    printf("Rear element: %d\n", getRear(deque));
    
    return 0;
}


/* Circular Array */

// #include <stdio.h>
// #include <stdlib.h>

// #define MAX 5  // Define the maximum size of the deque

// // Structure to represent a deque
// struct Deque {
//     int arr[MAX];
//     int front;
//     int rear;
//     int size;
// };

// // Function to create an empty deque
// struct Deque* createDeque() {
//     struct Deque* deque = (struct Deque*)malloc(sizeof(struct Deque));
//     deque->front = -1;
//     deque->rear = -1;
//     deque->size = 0;
//     return deque;
// }

// // Function to check if deque is full
// int isFull(struct Deque* deque) {
//     return deque->size == MAX;
// }

// // Function to check if deque is empty
// int isEmpty(struct Deque* deque) {
//     return deque->size == 0;
// }

// // Insert an element at the front of the deque
// void insertFront(struct Deque* deque, int value) {
//     if (isFull(deque)) {
//         printf("Deque is full\n");
//         return;
//     }

//     if (isEmpty(deque)) {
//         deque->front = deque->rear = 0;
//     } else if (deque->front == 0) {
//         deque->front = MAX - 1;  // Wrap around to the last index
//     } else {
//         deque->front--;
//     }

//     deque->arr[deque->front] = value;
//     deque->size++;
// }

// // Insert an element at the rear of the deque
// void insertRear(struct Deque* deque, int value) {
//     if (isFull(deque)) {
//         printf("Deque is full\n");
//         return;
//     }

//     if (isEmpty(deque)) {
//         deque->front = deque->rear = 0;
//     } else {
//         deque->rear = (deque->rear + 1) % MAX;  // Wrap around using modulo
//     }

//     deque->arr[deque->rear] = value;
//     deque->size++;
// }

// // Delete an element from the front of the deque
// void deleteFront(struct Deque* deque) {
//     if (isEmpty(deque)) {
//         printf("Deque is empty\n");
//         return;
//     }

//     printf("Removed from front: %d\n", deque->arr[deque->front]);

//     if (deque->front == deque->rear) {  // Only one element was present
//         deque->front = deque->rear = -1;  // Reset deque
//     } else {
//         deque->front = (deque->front + 1) % MAX;  // Wrap around using modulo
//     }

//     deque->size--;
// }

// // Delete an element from the rear of the deque
// void deleteRear(struct Deque* deque) {
//     if (isEmpty(deque)) {
//         printf("Deque is empty\n");
//         return;
//     }

//     printf("Removed from rear: %d\n", deque->arr[deque->rear]);

//     if (deque->front == deque->rear) {  // Only one element was present
//         deque->front = deque->rear = -1;  // Reset deque
//     } else if (deque->rear == 0) {
//         deque->rear = MAX - 1;  // Wrap around to the last index
//     } else {
//         deque->rear--;
//     }

//     deque->size--;
// }

// // Function to get the front element of the deque
// int getFront(struct Deque* deque) {
//     if (isEmpty(deque)) {
//         printf("Deque is empty\n");
//         return -1;
//     }
//     return deque->arr[deque->front];
// }

// // Function to get the rear element of the deque
// int getRear(struct Deque* deque) {
//     if (isEmpty(deque)) {
//         printf("Deque is empty\n");
//         return -1;
//     }
//     return deque->arr[deque->rear];
// }

// // Display the elements in the deque
// void displayDeque(struct Deque* deque) {
//     if (isEmpty(deque)) {
//         printf("Deque is empty\n");
//         return;
//     }

//     printf("Deque elements: ");
//     int i = deque->front;
//     for (int count = 0; count < deque->size; count++) {
//         printf("%d ", deque->arr[i]);
//         i = (i + 1) % MAX;  // Wrap around using modulo
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
//     insertRear(deque, 50);
    
//     displayDeque(deque);
    
//     deleteFront(deque);
//     deleteRear(deque);
    
//     displayDeque(deque);
    
//     printf("Front element: %d\n", getFront(deque));
//     printf("Rear element: %d\n", getRear(deque));
    
//     return 0;
// }
