#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function to place the pivot element at its correct position
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Select the last element as the pivot
    int i = low - 1;        // Index of the smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;  // Increment index of the smaller element
            swap(&arr[i], &arr[j]);
        }
    }

    // Place the pivot in the correct position
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quick Sort recursive function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi is the partitioning index
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is: \n");
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    printf("Sorted array is: \n");
    printArray(arr, size);

    return 0;
}
