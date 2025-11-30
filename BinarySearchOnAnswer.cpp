/*
Binary search on answer

- Uses binary search on the range of possible answers instead of directly
  searching in an array.
- Requires a monotonic predicate: if P(x) is true, then P(y) is also true
  for all y > x (or vice versa).
- Example: find the smallest integer x such that x * x >= target.

Time Complexity: O(log R) where R is the search range
Space Complexity: O(1)
*/

#include <iostream>

class BinarySearchOnAnswer {
public:
    /*
    Find the smallest integer x such that x * x >= target.
    This demonstrates the binary search on answer pattern.
    @param target Positive integer target
    @return Smallest integer x with x * x >= target
    */
    static int smallestSquareGreaterOrEqual(int target) {
        int low = 0;
        int high = target;
        int answer = target;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long square = 1LL * mid * mid;

            if (square >= target) {
                answer = mid;
                high = mid - 1; // Try to find a smaller valid x
            } else {
                low = mid + 1; // Need a larger x
            }
        }

        return answer;
    }
};

int main() {
    int target = 20;
    int result = BinarySearchOnAnswer::smallestSquareGreaterOrEqual(target);

    std::cout << "Target: " << target << std::endl;
    std::cout << "Smallest x such that x * x >= target: " << result << std::endl;

    return 0;
}
