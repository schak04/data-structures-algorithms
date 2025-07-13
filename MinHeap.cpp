#include <iostream>
#define MAX 100

using namespace std;

int heap[MAX];     // Array to store heap
int heapSize = 0;  // Current size of the heap

// Swap utility
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Heapify down (for delete operation)
void heapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

// ---------------------- Variant 1 ----------------------
// Insert using full re-heapify (not optimal)
void insert1(int value) {
    if (heapSize >= MAX) {
        cout << "Heap is full\n";
        return;
    }

    heap[heapSize++] = value;

    // Reheapify entire heap
    for (int i = heapSize / 2 - 1; i >= 0; i--) {
        heapify(heap, heapSize, i);
    }
}

// Delete min using heapify down
void deleteMin1() {
    if (heapSize == 0) {
        cout << "Heap is empty\n";
        return;
    }

    heap[0] = heap[heapSize - 1];
    heapSize--;

    heapify(heap, heapSize, 0);
}

// ---------------------- Variant 2 ----------------------
// Insert using up-heapify (efficient)
void insert2(int value) {
    if (heapSize >= MAX) {
        cout << "Heap is full\n";
        return;
    }

    heap[heapSize] = value;
    int current = heapSize;
    heapSize++;

    // Move up to maintain min-heap property
    while (current > 0 && heap[current] < heap[(current - 1) / 2]) {
        swap(heap[current], heap[(current - 1) / 2]);
        current = (current - 1) / 2;
    }
}

// Delete min using down-heapify (efficient)
int deleteMin2() {
    if (heapSize == 0) {
        cout << "Heap is empty\n";
        return -1;
    }

    int minValue = heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize--;

    int current = 0;

    while (current * 2 + 1 < heapSize) {
        int left = current * 2 + 1;
        int right = current * 2 + 2;
        int minChild = left;

        if (right < heapSize && heap[right] < heap[left])
            minChild = right;

        if (heap[current] <= heap[minChild])
            break;

        swap(heap[current], heap[minChild]);
        current = minChild;
    }

    return minValue;
}

// Display heap
void displayHeap() {
    for (int i = 0; i < heapSize; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

// ---------------------- Main ----------------------
int main() {
    cout << "=== Using Efficient Insert/Delete (Variant 2) ===\n";
    insert2(20);
    insert2(15);
    insert2(30);
    insert2(5);
    insert2(10);

    cout << "Min-Heap elements: ";
    displayHeap();

    cout << "Deleted min element: " << deleteMin2() << endl;

    cout << "Heap after deletion: ";
    displayHeap();

    insert2(3);
    cout << "Heap after inserting 3: ";
    displayHeap();

    return 0;
}