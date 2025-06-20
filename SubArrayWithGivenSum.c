#include <stdio.h>

void findSubarrayWithSum(int arr[], int n, int target_sum) {
    int current_sum = 0, start = 0;

    for (int end = 0; end < n; end++) {
        // Add the current element to the current sum
        current_sum += arr[end];

        // Shrink the window as long as current_sum is greater than target_sum
        while (current_sum > target_sum && start <= end) {
            current_sum -= arr[start];
            start++;
        }

        // Check if we found the subarray with the given sum
        if (current_sum == target_sum) {
            printf("Subarray found from index %d to %d\n", start, end);
            return;
        }
    }

    printf("No subarray with the given sum found.\n");
}

int main() {
    int arr[] = {1, 4, 20, 3, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target_sum = 33;

    findSubarrayWithSum(arr, n, target_sum);

    return 0;
}
