/*
Kadane's algorithm (maximum subarray sum)

- Finds the maximum possible sum of a contiguous subarray within a given
  array of integers (can include negative numbers).

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <climits>

class Kadane {
public:
    /*
    Compute the maximum subarray sum using Kadane's algorithm.
    @param arr Input array (may contain negative numbers)
    @return Maximum subarray sum
    */
    static int maxSubarraySum(const std::vector<int>& arr) {
        int maxSoFar = INT_MIN;
        int currentSum = 0;

        for (int num : arr) {
            // Either extend the previous subarray or start a new one at num
            currentSum = std::max(num, currentSum + num);
            maxSoFar = std::max(maxSoFar, currentSum);
        }

        return maxSoFar;
    }
};

int main() {
    std::vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    std::cout << "Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int maxSum = Kadane::maxSubarraySum(arr);
    std::cout << "Maximum subarray sum: " << maxSum << std::endl;

    return 0;
}
