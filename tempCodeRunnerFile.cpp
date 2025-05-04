/* Insertion */

// int main(){
//     int n, element, position;

//     cout<<"Enter the size of your array: ";
//     cin>>n;

//     int arr[n+1];
//     cout<<"Enter the elements of your array: ";
//     for (int i=0; i<n; i++) {
//         cin>>arr[i];
//     }

//     cout<<"Enter the element you want to insert: ";
//     cin>>element;
//     cout<<"Enter the position of insertion: ";
//     cin>>position;

//     if (position<1 || position>n+1) {
//         cout<<"Invalid Position. Cannot insert element.";
//     }
//     else {
//         for (int i=n; i>=position; i--) {
//             arr[i] = arr[i-1];
//         }
//         arr[position-1]=element;

//         cout<<"Array after insertion: ";
//         for (int i=0; i<n+1; i++) {
//             cout<<arr[i]<<" ";
//         }
//     }

//     return 0;
// }