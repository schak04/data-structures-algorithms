#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int x) {
    for (int i=0; i<n; i++) {
        if (arr[i]==x) {
            return i;
        }
    }
    return -1;
}

/*
In Binary Search:
  middle = start + (end-start)/2
  same as --> (start + end) / 2
*/

int binarySearch(int arr[], int l, int r, int x) {
    while (l<=r) {
        int mid = l + (r - l)/2;

        if (arr[mid]==x) {
            return mid;
        }

        if (arr[mid] < x) {
            l = mid+1;
        }
        if (arr[mid] > x) {
            r = mid-1;
        }
    }
    return -1;
}

int main(){
    int n, key;
    cout<<"Enter the number of elements of an array: ";
    cin>>n;
    
    int arr[n];

    cout<<"Enter the elements of the array: ";
    for (int i=0; i<n; i++) {
        cin>>arr[i];
    }

    cout<<"Here's your very own array: {";
    for (int i=0; i<n-1; i++) {
        cout<<arr[i]<<", ";
    }
    cout<<arr[n-1]<<"}\n";
    
    cout<<"Enter the element you want to search: ";
    cin>>key;

    // int result = linearSearch(arr, n, key);
    int result = binarySearch(arr, 0, n-1, key);

    if (result==-1) {
        cout<<key<<" is not present in the array."<<endl;
    }
    else {
        cout<<key<<" found in the array at position "<<result + 1<<"."<<endl;
    }

    return 0;
}