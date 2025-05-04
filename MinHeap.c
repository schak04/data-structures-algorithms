#include <stdio.h>
#define MAX 100

int heap[MAX];     // Array to store the heap
int heapSize = 0;  // Current size of the heap

// Swap function
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function (fix downwards)
void heapify(int arr[], int n, int i) {
    int smallest = i;          // Initialize smallest as root
    int left = 2 * i + 1;      // Left child
    int right = 2 * i + 2;     // Right child

    // If left child exists and is smaller than root
    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }

    // If right child exists and is smaller than the smallest so far
    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }

    // If the smallest is not the root
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}

// Insert a new value into the heap
void insert(int value) {
    if (heapSize >= MAX) {
        printf("Heap is full\n");
        return;
    }

    // Insert the new value at the end of the heap
    heap[heapSize] = value;
    heapSize++;

    // Reheapify the entire heap to maintain the min-heap property
    for (int i = heapSize / 2 - 1; i >= 0; i--) {
        heapify(heap, heapSize, i);
    }
}

// Delete the minimum element (root) from the heap
void deleteMin() {
    if (heapSize == 0) {
        printf("Heap is empty\n");
        return;
    }

    // Replace the root with the last element
    heap[0] = heap[heapSize - 1];
    heapSize--;

    // Call heapify to maintain the heap property
    heapify(heap, heapSize, 0);
}

// Display the heap elements
void displayHeap() {
    for (int i = 0; i < heapSize; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

// Main function
int main() {
    insert(12);
    insert(7);
    insert(15);
    insert(10);
    insert(5);

    printf("Heap after insertion: ");
    displayHeap(); // Output: 5 7 15 12 10

    deleteMin();
    printf("Heap after deleting minimum: ");
    displayHeap(); // Output: 7 10 15 12

    insert(3);
    printf("Heap after inserting 3: ");
    displayHeap(); // Output: 3 7 15 12 10

    return 0;
}


/*
#include <stdio.h>
#define MAX 100

int heap[MAX];
int heapSize = 0;

// Function to insert an element into the min-heap
void insert(int value) {
    if (heapSize >= MAX) {
        printf("Heap is full\n");
        return;
    }

    // Insert the new element at the end of the heap
    heap[heapSize] = value;
    int current = heapSize;
    heapSize++;

    // Heapify the element upwards to maintain min-heap property
    while (current > 0 && heap[current] < heap[(current - 1) / 2]) {
        // Swap the current element with its parent
        int temp = heap[(current - 1) / 2];
        heap[(current - 1) / 2] = heap[current];
        heap[current] = temp;

        // Move up to the parent
        current = (current - 1) / 2;
    }
}

// Function to remove and return the minimum element from the min-heap
int deleteMin() {
    if (heapSize <= 0) {
        printf("Heap is empty\n");
        return -1;
    }

    int min = heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize--;

    int current = 0;
    // Heapify the element downwards to maintain min-heap property
    while (current * 2 + 1 < heapSize) {
        int left = current * 2 + 1;
        int right = current * 2 + 2;
        int minChild = left;

        if (right < heapSize && heap[right] < heap[left]) {
            minChild = right;
        }

        if (heap[current] <= heap[minChild]) {
            break;
        }

        // Swap the current element with the smaller child
        int temp = heap[current];
        heap[current] = heap[minChild];
        heap[minChild] = temp;

        current = minChild;
    }

    return min;
}

// Function to display the elements of the min-heap
void displayHeap() {
    for (int i = 0; i < heapSize; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() { 
    insert(20);
    insert(15);
    insert(30);
    insert(5);
    insert(10);

    printf("Min-Heap elements: ");
    displayHeap();

    printf("Deleted min element: %d\n", deleteMin());

    printf("Heap after deletion: ");
    displayHeap();

    return 0;
}
*/


