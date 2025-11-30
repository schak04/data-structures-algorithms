/*
 * Quick Sort Algorithm
 * 
 * A divide-and-conquer sorting algorithm.
 * Time Complexity: 
 *   - Average: O(n log n)
 *   - Worst: O(n^2) when pivot is always smallest/largest
 * Space Complexity: O(log n) due to recursion
 */

#include <iostream>
#include <vector>
#include <algorithm>

class QuickSort {
public:
    /*
    Sort an array using quick sort.
    @param arr Array to sort
    @param low Starting index
    @param high Ending index
    */
    static void quickSort(std::vector<int>& arr, int low, int high) {
        if (low < high) {
            // Partition the array and get pivot index
            int pi = partition(arr, low, high);

            // Recursively sort elements before and after partition
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    /*
    Partition function - places pivot at correct position.
    @param arr Array to partition
    @param low Starting index
    @param high Ending index
    @return Index of pivot after partitioning
    */
    static int partition(std::vector<int>& arr, int low, int high) {
        int pivot = arr[high]; // Select last element as pivot
        int i = low - 1;       // Index of smaller element

        for (int j = low; j < high; j++) {
            // If current element is smaller than or equal to pivot
            if (arr[j] <= pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }

        // Place pivot in correct position
        std::swap(arr[i + 1], arr[high]);
        return (i + 1);
    }

    /*
    Print array.
    */
    static void printArray(const std::vector<int>& arr) {
        for (size_t i = 0; i < arr.size(); i++) {
            std::cout << arr[i];
            if (i < arr.size() - 1) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    std::vector<int> arr = {10, 7, 8, 9, 1, 5};

    std::cout << "Given array is:" << std::endl;
    QuickSort::printArray(arr);

    QuickSort::quickSort(arr, 0, arr.size() - 1);

    std::cout << "Sorted array is:" << std::endl;
    QuickSort::printArray(arr);

    // Additional test cases
    std::cout << "\n=== Additional Test Cases ===" << std::endl;

    std::vector<int> arr2 = {64, 34, 25, 12, 22, 11, 90};
    std::cout << "\nOriginal: ";
    QuickSort::printArray(arr2);
    QuickSort::quickSort(arr2, 0, arr2.size() - 1);
    std::cout << "Sorted: ";
    QuickSort::printArray(arr2);

    std::vector<int> arr3 = {5, 2, 8, 1, 9};
    std::cout << "\nOriginal: ";
    QuickSort::printArray(arr3);
    QuickSort::quickSort(arr3, 0, arr3.size() - 1);
    std::cout << "Sorted: ";
    QuickSort::printArray(arr3);

    return 0;
}

