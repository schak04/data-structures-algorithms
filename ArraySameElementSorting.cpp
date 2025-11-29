/*
 * Dutch National Flag Algorithm - Array Sorting
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * 
 * Sorts an array containing only 0s, 1s, and 2s in a single pass.
 */

#include <iostream>
#include <vector>
#include <algorithm>

/**
 * Sorts an array of 0s, 1s, and 2s using counting approach
 * @param arr Reference to the vector to be sorted
 */
void sort012(std::vector<int>& arr) {
    int count0 = 0, count1 = 0, count2 = 0;
    
    // Count the occurrences of 0s, 1s, and 2s
    for (int num : arr) {
        if (num == 0) {
            count0++;
        } else if (num == 1) {
            count1++;
        } else if (num == 2) {
            count2++;
        }
    }
    
    // Fill the array with 0s, then 1s, then 2s
    int idx = 0;
    for (int i = 0; i < count0; i++) {
        arr[idx++] = 0;
    }
    for (int i = 0; i < count1; i++) {
        arr[idx++] = 1;
    }
    for (int i = 0; i < count2; i++) {
        arr[idx++] = 2;
    }
}

/**
 * Alternative implementation using Dutch National Flag algorithm (two-pointer approach)
 * More efficient as it sorts in a single pass
 * @param arr Reference to the vector to be sorted
 */
void sort012Optimized(std::vector<int>& arr) {
    int low = 0, mid = 0, high = arr.size() - 1;
    
    while (mid <= high) {
        if (arr[mid] == 0) {
            std::swap(arr[low], arr[mid]);
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++;
        } else { // arr[mid] == 2
            std::swap(arr[mid], arr[high]);
            high--;
        }
    }
}

/**
 * Utility function to print the array
 */
void printArray(const std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i];
        if (i < arr.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    // Test case 1: Original sample
    std::vector<int> arr1 = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    
    std::cout << "Original array: ";
    printArray(arr1);
    
    sort012(arr1);
    
    std::cout << "Sorted array (counting method): ";
    printArray(arr1);
    
    // Test case 2: Using optimized method
    std::vector<int> arr2 = {2, 0, 2, 1, 1, 0};
    
    std::cout << "\nOriginal array: ";
    printArray(arr2);
    
    sort012Optimized(arr2);
    
    std::cout << "Sorted array (optimized method): ";
    printArray(arr2);
    
    // Test case 3: Already sorted
    std::vector<int> arr3 = {0, 0, 1, 1, 2, 2};
    
    std::cout << "\nOriginal array: ";
    printArray(arr3);
    
    sort012(arr3);
    
    std::cout << "Sorted array: ";
    printArray(arr3);
    
    return 0;
}

