/*
Greedy algorithm pattern (activity selection)

- Makes locally optimal choices at each step with the hope of finding
  a global optimum.
- Selects the maximum number of non-overlapping intervals (activities)
  by always picking the interval that ends first.

Time Complexity: O(n log n) due to sorting
Space Complexity: O(1) extra space (excluding input/output)
*/

#include <algorithm>
#include <iostream>
#include <vector>

struct Interval {
    int start;
    int end;
};

class GreedyActivitySelection {
public:
    /*
    Select the maximum number of non-overlapping intervals.
    @param intervals List of intervals with start and end times
    @return Selected intervals forming the maximum-size compatible set
    */
    static std::vector<Interval> selectMaxActivities(std::vector<Interval> intervals) {
        // Sort by end time
        std::sort(intervals.begin(), intervals.end(),
                  [](const Interval& a, const Interval& b) {
                      return a.end < b.end;
                  });

        std::vector<Interval> result;
        if (intervals.empty()) {
            return result;
        }

        // Always pick the interval that finishes first
        result.push_back(intervals[0]);
        int lastEnd = intervals[0].end;

        for (std::size_t i = 1; i < intervals.size(); i++) {
            if (intervals[i].start >= lastEnd) {
                result.push_back(intervals[i]);
                lastEnd = intervals[i].end;
            }
        }

        return result;
    }
};

int main() {
    std::vector<Interval> intervals = {
        {1, 3}, {2, 4}, {3, 5}, {0, 6}, {5, 7}, {8, 9}, {5, 9}
    };

    std::cout << "Intervals: ";
    for (const auto& in : intervals) {
        std::cout << "(" << in.start << ", " << in.end << ") ";
    }
    std::cout << std::endl;

    std::vector<Interval> selected = GreedyActivitySelection::selectMaxActivities(intervals);

    std::cout << "Selected (non-overlapping) intervals: ";
    for (const auto& in : selected) {
        std::cout << "(" << in.start << ", " << in.end << ") ";
    }
    std::cout << std::endl;

    return 0;
}
