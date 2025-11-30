/*
Two pointers technique

- Solves problems on arrays or strings by maintaining two indices that move
  towards each other or in the same direction.
- Example: Given a sorted array and a target sum, determine if there exists
  a pair whose sum equals the target.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>

class TwoPointers {
public:
    /*
    Check if there exists a pair with the given sum using two pointers.
    Assumes the input array is sorted in non-decreasing order.
    @param arr Sorted input array
    @param target Target sum
    @return true if a pair exists, false otherwise
    */
    static bool hasPairWithSum(const std::vector<int>& arr, int target) {
        int left = 0;
        int right = static_cast<int>(arr.size()) - 1;

        while (left < right) {
            int currentSum = arr[left] + arr[right];

            if (currentSum == target) {
                return true;
            } else if (currentSum < target) {
                // Need a larger sum -> move left pointer to the right
                left++;
            } else {
                // Need a smaller sum -> move right pointer to the left
                right--;
            }
        }

        return false;
    }
};

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 6, 8, 9};
    int target = 10;

    std::cout << "Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\nTarget sum: " << target << std::endl;

    bool found = TwoPointers::hasPairWithSum(arr, target);

    if (found) {
        std::cout << "A pair with the given sum exists in the array." << std::endl;
    } else {
        std::cout << "No pair with the given sum found in the array." << std::endl;
    }

    return 0;
}
