/*
Dynamic programming patterns (1D, 2D, strings)

Demonstrates three common DP patterns:
- 1D DP (climbing stairs / Fibonacci-like recurrence)
- 2D DP on a grid (count unique paths in an m x n grid)
- DP on strings (longest common subsequence - LCS)

Time Complexity:
- 1D DP: O(n)
- 2D DP: O(m * n)
- LCS: O(n * m)

Space Complexity:
- 1D DP: O(n) or O(1) optimized
- 2D DP: O(m * n)
- LCS: O(n * m)
*/

#include <iostream>
#include <string>
#include <vector>

class DynamicProgrammingPatterns {
public:
    /*
    1D DP: Climbing stairs.
    Each step you can climb 1 or 2 stairs. How many distinct ways
    to reach the top?
    @param n Number of steps
    @return Number of distinct ways to reach step n
    */
    static int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }

        // dp[i] = number of ways to reach step i
        std::vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }

    /*
    2D DP: unique paths in an m x n grid.
    You can move only right or down from each cell.
    @param m Number of rows
    @param n Number of columns
    @return Number of unique paths from top-left to bottom-right
    */
    static int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0) {
            return 0;
        }

        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 1));

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }

    /*
    DP on strings: longest common subsequence (LCS).
    @param s First string
    @param t Second string
    @return Length of the longest common subsequence between s and t
    */
    static int longestCommonSubsequence(const std::string& s, const std::string& t) {
        int n = static_cast<int>(s.size());
        int m = static_cast<int>(t.size());

        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][m];
    }
};

int main() {
    // 1D DP example
    int steps = 5;
    std::cout << "Number of ways to climb " << steps << " steps: "
              << DynamicProgrammingPatterns::climbStairs(steps) << std::endl;

    // 2D DP example
    int m = 3, n = 3;
    std::cout << "Unique paths in a " << m << "x" << n << " grid: "
              << DynamicProgrammingPatterns::uniquePaths(m, n) << std::endl;

    // DP on strings example
    std::string s = "abcde";
    std::string t = "ace";
    std::cout << "LCS length between \"" << s << "\" and \"" << t << "\": "
              << DynamicProgrammingPatterns::longestCommonSubsequence(s, t)
              << std::endl;

    return 0;
}
