/*
Subarray with given sum

- Finds a contiguous subarray with a given sum using sliding window technique.

Time Complexity: O(n)
*/

#include <iostream>
#include <vector>

class SubarraySum {
public:
    /*
    Find subarray with given sum using sliding window.
    @param arr Input array
    @param target_sum Target sum
    @return Pair of start and end indices, or (-1, -1) if not found
    */
    static std::pair<int, int> findSubarrayWithSum(const std::vector<int>& arr, int target_sum) {
        int current_sum = 0;
        int start = 0;

        for (int end = 0; end < arr.size(); end++) {
            // Add the current element to the current sum
            current_sum += arr[end];

            // Shrink the window as long as current_sum is greater than target_sum
            while (current_sum > target_sum && start <= end) {
                current_sum -= arr[start];
                start++;
            }

            // Check if we found the subarray with the given sum
            if (current_sum == target_sum) {
                return {start, end};
            }
        }

        return {-1, -1}; // Not found
    }

    /*
    Find all subarrays with given sum.
    @param arr Input array
    @param target_sum Target sum
    @return Vector of pairs (start, end) indices
    */
    static std::vector<std::pair<int, int>> findAllSubarraysWithSum(
        const std::vector<int>& arr, int target_sum) {
        
        std::vector<std::pair<int, int>> results;
        int current_sum = 0;
        int start = 0;

        for (int end = 0; end < arr.size(); end++) {
            current_sum += arr[end];

            while (current_sum > target_sum && start <= end) {
                current_sum -= arr[start];
                start++;
            }

            if (current_sum == target_sum) {
                results.push_back({start, end});
            }
        }

        return results;
    }
};

int main() {
    std::vector<int> arr = {1, 4, 20, 3, 10, 5};
    int target_sum = 33;

    std::cout << "Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << "Target sum: " << target_sum << std::endl;

    auto result = SubarraySum::findSubarrayWithSum(arr, target_sum);

    if (result.first != -1) {
        std::cout << "Subarray found from index " << result.first 
                  << " to " << result.second << std::endl;
        std::cout << "Elements: ";
        for (int i = result.first; i <= result.second; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "No subarray with the given sum found." << std::endl;
    }

    // Additional test cases
    std::cout << "\n=== Additional Test Cases ===" << std::endl;

    std::vector<int> arr2 = {1, 2, 3, 7, 5};
    int target2 = 12;
    std::cout << "\nArray: ";
    for (int num : arr2) {
        std::cout << num << " ";
    }
    std::cout << "\nTarget: " << target2 << std::endl;
    
    auto result2 = SubarraySum::findSubarrayWithSum(arr2, target2);
    if (result2.first != -1) {
        std::cout << "Subarray found from index " << result2.first 
                  << " to " << result2.second << std::endl;
    }

    // Find all subarrays
    std::vector<int> arr3 = {1, 2, 3, 4, 5};
    int target3 = 9;
    std::cout << "\nFinding all subarrays with sum " << target3 << ":" << std::endl;
    auto allResults = SubarraySum::findAllSubarraysWithSum(arr3, target3);
    for (const auto& res : allResults) {
        std::cout << "Index " << res.first << " to " << res.second << std::endl;
    }

    return 0;
}

