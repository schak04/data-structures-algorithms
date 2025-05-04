#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted at index `i`
// The heapify function ensures a subtree rooted at index i satisfies the max-heap property
void heapify(int arr[], int n, int i) {
    int largest = i; // Assume the root is the largest
    int left = 2 * i + 1; // Index of the left child
    int right = 2 * i + 2; // Index of the right child

    // Check if the left child is larger than the root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Check if the right child is larger than the current largest
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If the largest is not the root, swap and continue heapifying
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest); // Recursively fix the affected subtree
    }
}

// Main function to do heap sort
// This function sorts the array using two steps:
    // - Build a Max-Heap:
    //     Start from the last non-leaf node and heapify upwards.
    // - Sort:
    //     - Swap the root (largest element) with the last element in the heap.
    //     - Reduce the heap size and re-heapify the root.

void heapSort(int arr[], int n) {
    // Step 1: Build the max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    // Step 2: Extract elements one by one from the heap
    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]); // Move the largest to the end
        heapify(arr, i, 0); // Restore the heap property for the reduced heap
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver code
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
