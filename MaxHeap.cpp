#include <iostream>
#define MAX 100

using namespace std;

int heap[MAX];      // Array to store heap elements
int heapSize = 0;   // Current size of the heap

// Swap utility function
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Heapify function (down-heapify for maintaining max-heap)
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Insert a new element into the heap (up-heapify)
void insert(int value) {
    if (heapSize >= MAX) {
        cout << "Heap is full\n";
        return;
    }

    heap[heapSize] = value;
    int current = heapSize;
    heapSize++;

    // Move up the inserted element to maintain heap property
    while (current > 0 && heap[current] > heap[(current - 1) / 2]) {
        swap(heap[current], heap[(current - 1) / 2]);
        current = (current - 1) / 2;
    }
}

// Delete and return the maximum element (root)
int deleteMax() {
    if (heapSize == 0) {
        cout << "Heap is empty\n";
        return -1;
    }

    int maxValue = heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize--;

    // Restore the max-heap property by heapifying down
    heapify(heap, heapSize, 0);

    return maxValue;
}

// Display all elements of the heap
void displayHeap() {
    for (int i = 0; i < heapSize; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

// Main driver
int main() {
    insert(10);
    insert(20);
    insert(5);
    insert(15);
    insert(30);

    cout << "Max-Heap elements: ";
    displayHeap();  // Output should be max-heap ordered

    cout << "Deleted max element: " << deleteMax() << endl;

    cout << "Heap after deletion: ";
    displayHeap();

    insert(25);
    cout << "Heap after inserting 25: ";
    displayHeap();

    return 0;
}