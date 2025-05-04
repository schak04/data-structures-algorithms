#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    int isSorted = 0;
    for (int i=0; i<n-1; i++) {
        cout<<"Working on pass number "<<i+1<<endl;
        isSorted = 1;
        for (int j=0; j<n-i-1; j++) {
            if (arr[j]>arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted) {
            return;
        }
    }
}

void insertionSort(int arr[], int n) {
    for (int i=1; i<n; i++) {
        int key = arr[i];
        int j = i-1;
        while (j>=0 && arr[j] > key) {
            arr[j+1] = arr[j--];
        }
        arr[j+1] = key;
    }
}

void selectionSort(int arr[], int n) {
    for (int i=0; i<n-1; i++) {
        int indexOfMin = i;
        for (int j=i+1; j<n; j++) {
            if (arr[j] < arr[indexOfMin]) {
                indexOfMin = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[indexOfMin];
        arr[indexOfMin] = temp;
    }
}

int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // bubbleSort(arr, n);
    // insertionSort(arr, n);
    selectionSort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}