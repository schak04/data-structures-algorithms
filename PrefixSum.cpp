/*
Prefix sum technique

- Builds a prefix sum array where prefix[i] stores the sum of elements
  from index 0 to i.
- Allows answering range sum queries in O(1) time after O(n) preprocessing.

Time Complexity: O(n) to build, O(1) per query
Space Complexity: O(n) for the prefix array
*/

#include <iostream>
#include <vector>

class PrefixSum {
public:
    /*
    Build prefix sum array for the given input.
    @param arr Input array
    @return Prefix sum array
    */
    static std::vector<int> buildPrefixSum(const std::vector<int>& arr) {
        std::vector<int> prefix(arr.size(), 0);
        if (arr.empty()) {
            return prefix;
        }

        prefix[0] = arr[0];
        for (std::size_t i = 1; i < arr.size(); i++) {
            prefix[i] = prefix[i - 1] + arr[i];
        }
        return prefix;
    }

    /*
    Compute sum of elements in range [l, r] using prefix sums.
    @param prefix Prefix sum array
    @param l Left index (0-based)
    @param r Right index (0-based)
    @return Sum of elements from l to r (inclusive)
    */
    static int rangeSum(const std::vector<int>& prefix, int l, int r) {
        if (l == 0) {
            return prefix[r];
        }
        return prefix[r] - prefix[l - 1];
    }
};

int main() {
    std::vector<int> arr = {2, 4, 5, 7, 1, 3};

    std::cout << "Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> prefix = PrefixSum::buildPrefixSum(arr);

    std::cout << "Prefix sums: ";
    for (int sum : prefix) {
        std::cout << sum << " ";
    }
    std::cout << std::endl;

    int l = 1;
    int r = 4;
    std::cout << "Sum of range [" << l << ", " << r << "]: "
              << PrefixSum::rangeSum(prefix, l, r) << std::endl;

    return 0;
}
