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

// Heapify function (fix downwards for max-heap)
void heapify(int arr[], int n, int i) {
    int largest = i;           // Initialize largest as root
    int left = 2 * i + 1;      // Left child
    int right = 2 * i + 2;     // Right child

    // If left child exists and is greater than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child exists and is greater than the largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If the largest is not the root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
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

    // Reheapify the entire heap to maintain the max-heap property
    for (int i = heapSize / 2 - 1; i >= 0; i--) {
        heapify(heap, heapSize, i);
    }
}

// Delete the maximum element (root) from the heap
void deleteMax() {
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
    displayHeap(); // Output: 15 12 7 10 5

    deleteMax();
    printf("Heap after deleting maximum: ");
    displayHeap(); // Output: 12 10 7 5

    insert(20);
    printf("Heap after inserting 20: ");
    displayHeap(); // Output: 20 12 7 5 10

    return 0;
}



/*
#include <stdio.h>
#define MAX 100

int heap[MAX];
int heapSize = 0;

// Function to insert an element into the max-heap
void insert(int value) {
    if (heapSize >= MAX) {
        printf("Heap is full\n");
        return;
    }
    
    // Insert the new element at the end of the heap
    heap[heapSize] = value;
    int current = heapSize;
    heapSize++;
    
    // Heapify the element upwards to maintain max-heap property
    while (current > 0 && heap[current] > heap[(current - 1) / 2]) {
        // Swap the current element with its parent
        int temp = heap[(current - 1) / 2];
        heap[(current - 1) / 2] = heap[current];
        heap[current] = temp;
        
        // Move up to the parent
        current = (current - 1) / 2;
    }
}

// Function to remove and return the maximum element from the max-heap
int deleteMax() {
    if (heapSize <= 0) {
        printf("Heap is empty\n");
        return -1;
    }
    
    int max = heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize--;
    
    int current = 0;
    // Heapify the element downwards to maintain max-heap property
    while (current * 2 + 1 < heapSize) {
        int left = current * 2 + 1;
        int right = current * 2 + 2;
        int maxChild = left;
        
        if (right < heapSize && heap[right] > heap[left]) {
            maxChild = right;
        }
        
        if (heap[current] >= heap[maxChild]) {
            break;
        }
        
        // Swap the current element with the larger child
        int temp = heap[current];
        heap[current] = heap[maxChild];
        heap[maxChild] = temp;
        
        current = maxChild;
    }
    
    return max;
}

// Function to display the elements of the heap
void displayHeap() {
    for (int i = 0; i < heapSize; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    insert(10);
    insert(20);
    insert(5);
    insert(15);
    insert(30);

    printf("Max-Heap elements: ");
    displayHeap();

    printf("Deleted max element: %d\n", deleteMax());

    printf("Heap after deletion: ");
    displayHeap();

    return 0;
}
*/