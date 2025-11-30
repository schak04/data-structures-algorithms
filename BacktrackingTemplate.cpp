/*
Backtracking template (subsets generation)

- Explores all possible choices by building the solution incrementally
  and backtracking when a choice leads to no valid solution.
- Example: generate all subsets (the power set) of a given set of numbers.

Time Complexity: O(2^n) to generate all subsets
Space Complexity: O(n) extra space for recursion (excluding output)
*/

#include <iostream>
#include <vector>

class Backtracking {
public:
    /*
    Generate all subsets of the given array using backtracking.
    @param nums Input array
    @return Vector of all subsets
    */
    static std::vector<std::vector<int>> subsets(const std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        backtrack(0, nums, current, result);
        return result;
    }

private:
    /*
    Helper function for backtracking.
    */
    static void backtrack(int index,
                          const std::vector<int>& nums,
                          std::vector<int>& current,
                          std::vector<std::vector<int>>& result) {
        // Every state of "current" is a valid subset
        result.push_back(current);

        for (int i = index; i < static_cast<int>(nums.size()); i++) {
            // Choose nums[i]
            current.push_back(nums[i]);

            // Explore further with nums[i] included
            backtrack(i + 1, nums, current, result);

            // Undo the choice (backtrack)
            current.pop_back();
        }
    }
};

int main() {
    std::vector<int> nums = {1, 2, 3};

    std::cout << "Input: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << "\nSubsets:\n";

    std::vector<std::vector<int>> result = Backtracking::subsets(nums);

    for (const auto& subset : result) {
        std::cout << "{";
        for (std::size_t i = 0; i < subset.size(); i++) {
            std::cout << subset[i];
            if (i + 1 < subset.size()) {
                std::cout << ", ";
            }
        }
        std::cout << "}" << std::endl;
    }

    return 0;
}
