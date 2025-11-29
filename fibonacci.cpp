/*
 * Fibonacci Sequence using Recursion
 * 
 * Computes the nth Fibonacci number using recursive approach.
 * Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21, ...
 * F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2)
 * 
 * Note: This recursive approach has exponential time complexity O(2^n).
 * For better performance, use iterative approach or memoization.
 */

#include <iostream>
#include <vector>

class Fibonacci {
public:
    /**
     * Recursive Fibonacci calculation
     * @param n Index of Fibonacci number
     * @return nth Fibonacci number
     */
    static int fibonacci(int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else {
            return fibonacci(n - 1) + fibonacci(n - 2);
        }
    }

    /**
     * Iterative Fibonacci calculation (more efficient)
     * @param n Index of Fibonacci number
     * @return nth Fibonacci number
     */
    static int fibonacciIterative(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        int a = 0, b = 1;
        for (int i = 2; i <= n; i++) {
            int temp = a + b;
            a = b;
            b = temp;
        }
        return b;
    }

    /**
     * Fibonacci with memoization (optimized recursive)
     * @param n Index of Fibonacci number
     * @param memo Memoization array
     * @return nth Fibonacci number
     */
    static int fibonacciMemo(int n, std::vector<int>& memo) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (memo[n] != -1) return memo[n];

        memo[n] = fibonacciMemo(n - 1, memo) + fibonacciMemo(n - 2, memo);
        return memo[n];
    }
};

int main() {
    int n;
    std::cout << "Enter the number of terms: ";
    std::cin >> n;

    std::cout << "Fibonacci sequence (recursive): ";
    for (int i = 0; i < n; i++) {
        std::cout << Fibonacci::fibonacci(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "Fibonacci sequence (iterative): ";
    for (int i = 0; i < n; i++) {
        std::cout << Fibonacci::fibonacciIterative(i) << " ";
    }
    std::cout << std::endl;

    // Using memoization for larger values
    if (n > 20) {
        std::vector<int> memo(n + 1, -1);
        std::cout << "Fibonacci sequence (memoized): ";
        for (int i = 0; i < n; i++) {
            std::cout << Fibonacci::fibonacciMemo(i, memo) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

