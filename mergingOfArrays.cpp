#include <iostream>
using namespace std;

void mergeUnsorted(int arr1[], int n1, int arr2[], int n2, int arr3[]) {
    for (int i=0; i<n1; i++) {
        arr3[i] = arr1[i];
    }
    for (int i=0; i<n2; i++) {
        arr3[i+n1] = arr2[i];
    }
}

void mergeSorted(int arr1[], int n1, int arr2[], int n2, int arr3[]) {
    int i = 0, j = 0, k = 0;

    // Traverse both arrays
    while (i < n1 && j < n2) {
        // Pick the smaller element from arr1 or arr2
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        }
        else {
            arr3[k++] = arr2[j++];
        }
    }

    // Store remaining elements of the first array
    while(i < n1) {
        arr3[k++] = arr1[i++];
    }

    // Store remaining elements of the second array
    while(j < n2) {
        arr3[k++] = arr2[j++];
    }
}

int main(){
    int n1, n2;

    cout << "Enter the number of elements for the first array: ";
    cin >> n1;
    int arr1[n1];
    cout << "Enter the elements for the first array: ";
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }

    cout << "Enter the number of elements for the second array: ";
    cin >> n2;
    int arr2[n2];
    cout << "Enter the elements for the second array: ";
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }

    int arr3[n1+n2];
    
    // mergeUnsorted(arr1, n1, arr2, n2, arr3);
    mergeSorted(arr1, n1, arr2, n2, arr3);

    cout << "Merged array: ";
    for(int i = 0; i < n1+n2; i++) {
        cout << arr3[i] << " ";
    }

    return 0;
}
