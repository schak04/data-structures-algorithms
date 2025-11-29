/*
 * Merge Sort Algorithm
 * 
 * A divide-and-conquer sorting algorithm.
 * Time Complexity: O(n log n) in all cases
 * Space Complexity: O(n) for temporary arrays
 */

#include <iostream>
#include <vector>

class MergeSort {
public:
    /**
     * Sort an array using Merge Sort
     * @param arr Array to sort
     * @param left Starting index
     * @param right Ending index
     */
    static void mergeSort(std::vector<int>& arr, int left, int right) {
        if (left < right) {
            // Find the middle point
            int mid = left + (right - left) / 2;

            // Sort the first and second halves
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);

            // Merge the sorted halves
            merge(arr, left, mid, right);
        }
    }

    /**
     * Merge two subarrays
     * @param arr Array containing subarrays
     * @param left Starting index
     * @param mid Middle index
     * @param right Ending index
     */
    static void merge(std::vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // Create temporary arrays
        std::vector<int> L(n1);
        std::vector<int> R(n2);

        // Copy data to temporary arrays
        for (int i = 0; i < n1; i++) {
            L[i] = arr[left + i];
        }
        for (int i = 0; i < n2; i++) {
            R[i] = arr[mid + 1 + i];
        }

        // Merge the two subarrays back into arr[]
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k++] = L[i++];
            } else {
                arr[k++] = R[j++];
            }
        }

        // Copy any remaining elements of L[]
        while (i < n1) {
            arr[k++] = L[i++];
        }

        // Copy any remaining elements of R[]
        while (j < n2) {
            arr[k++] = R[j++];
        }
    }

    /**
     * Print array
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
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};

    std::cout << "Given array is:" << std::endl;
    MergeSort::printArray(arr);

    MergeSort::mergeSort(arr, 0, arr.size() - 1);

    std::cout << "Sorted array is:" << std::endl;
    MergeSort::printArray(arr);

    // Additional test cases
    std::cout << "\n=== Additional Test Cases ===" << std::endl;

    std::vector<int> arr2 = {38, 27, 43, 3, 9, 82, 10};
    std::cout << "\nOriginal: ";
    MergeSort::printArray(arr2);
    MergeSort::mergeSort(arr2, 0, arr2.size() - 1);
    std::cout << "Sorted: ";
    MergeSort::printArray(arr2);

    std::vector<int> arr3 = {5, 2, 8, 1, 9, 3};
    std::cout << "\nOriginal: ";
    MergeSort::printArray(arr3);
    MergeSort::mergeSort(arr3, 0, arr3.size() - 1);
    std::cout << "Sorted: ";
    MergeSort::printArray(arr3);

    return 0;
}

