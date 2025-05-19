#include <iostream>
using namespace std;

void insertElement(int *arr, int &size, int index, int element) {    
    for (int i = size; i >= index; i--) {
        *(arr + i) = *(arr + i - 1);
    }
    *(arr + index) = element;    
    size++;
}

void deleteElement(int *arr, int &size, int index) {
    for (int i = index; i < size; i++) {        
        *(arr + i) = *(arr + i + 1);    
    }    
    size--;
}

int searchElement(int *arr, int size, int element) {
    for (int i = 0; i < size; i++) {        
        if (*(arr + i) == element) {  // Dereference the pointer to compare values
            return i;        
        }    
    }    
    return -1;
}

int main() {
    int size, index, element;
    cout << "Enter the size of the array: ";    
    cin >> size;    

    // Dynamically allocate memory for the array
    int* arr = new int[size + 1];    
    
    cout << "Enter the elements of the array: ";    
    for (int i = 0; i < size; i++) {
        cin >> *(arr + i);    
    }    
    
    // Insert an element
    cout << "Enter the index where you want to insert the element: ";    
    cin >> index;    
    cout << "Enter the element to be inserted: ";    
    cin >> element;    
    insertElement(arr, size, index, element);    
    
    // Print updated array
    cout << "Updated array after insertion: ";    
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";    
    }    
    cout << endl;    

    // Delete an element
    cout << "Enter the index of the element to be deleted: ";    
    cin >> index;    
    deleteElement(arr, size, index);    
    
    // Print updated array
    cout << "Updated array after deletion: ";    
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";    
    }    
    cout << endl;    
    
    // Search for an element
    cout << "Enter the element to search: ";    
    cin >> element;    
    index = searchElement(arr, size, element);    
    
    // Check if element is found
    if (index != -1) {
        cout << "Element found at index: " << index << endl;    
    } else {
        cout << "Element not found" << endl;    
    }

    // Free the dynamically allocated memory
    delete[] arr;

    return 0;
}
