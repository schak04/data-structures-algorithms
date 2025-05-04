#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int key) {
    if (low > high) {
        return -1; // Key not found
    }

    int mid = low + (high - low) / 2; // Avoid overflow

    if (arr[mid] == key) {
        return mid; // Key found
    }

    if (arr[mid] > key) {
        return binarySearch(arr, low, mid - 1, key); // Search in the left half
    } else {
        return binarySearch(arr, mid + 1, high, key); // Search in the right half
    }
}

int main() {
    int n, key;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the key to search: ";
    cin >> key;

    int result = binarySearch(arr, 0, n - 1, key);

    if (result != -1) {
        cout << "Key found at index " << result << endl;
    } else {
        cout << "Key not found." << endl;
    }

    return 0;
}
