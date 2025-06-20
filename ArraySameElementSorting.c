// Using Dutch National Flag Algorithm
// Time Complexity should be O(n)

// C Program to sort an array of 0s, 1s and 2s

#include <stdio.h>

// Function to sort the array of 0s, 1s and 2s
void sort012(int a[], int n)
{
    int c0 = 0, c1 = 0, c2 = 0;

    // Count 0s, 1s and 2s
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            c0 += 1;
        }
        else if (a[i] == 1) {
            c1 += 1;
        }
        else {
            c2 += 1;
        }
    }

    int idx = 0;
    // Place all the 0s
    for (int i = 0; i < c0; i++)
        a[idx++] = 0;

    // Place all the 1s
    for (int i = 0; i < c1; i++)
        a[idx++] = 1;

    // Place all the 2s
    for (int i = 0; i < c2; i++)
        a[idx++] = 2;
}

int main()
{
    // Sample Input
    int a[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
    int n = sizeof(a) / sizeof(a[0]);

    sort012(a, n);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
