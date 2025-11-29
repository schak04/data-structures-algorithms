/*
 * Sum of First N Natural Numbers using Recursion
 * 
 * Computes the sum of first n natural numbers: 1 + 2 + 3 + ... + n
 * Formula: n * (n + 1) / 2
 */

#include <iostream>

class SumCalculator {
public:
    /**
     * Calculate sum of first n natural numbers using recursion
     * @param n Number of natural numbers
     * @return Sum of first n natural numbers, or -1 if invalid
     */
    static int sumOfFirstN(int n) {
        if (n < 0) {
            return -1;
        } else if (n == 0) {
            return 0;
        } else {
            return n + sumOfFirstN(n - 1);
        }
    }

    /**
     * Calculate sum using iterative approach
     * @param n Number of natural numbers
     * @return Sum of first n natural numbers
     */
    static int sumOfFirstNIterative(int n) {
        if (n < 0) return -1;
        
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += i;
        }
        return sum;
    }

    /**
     * Calculate sum using formula
     * @param n Number of natural numbers
     * @return Sum of first n natural numbers
     */
    static int sumOfFirstNFormula(int n) {
        if (n < 0) return -1;
        return n * (n + 1) / 2;
    }
};

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    int result = SumCalculator::sumOfFirstN(n);
    if (result == -1) {
        std::cout << "Invalid input. n must be non-negative." << std::endl;
    } else {
        std::cout << "Sum of first " << n << " natural numbers (recursive) is: " 
                  << result << std::endl;
    }

    // Compare with other methods
    std::cout << "Sum (iterative): " << SumCalculator::sumOfFirstNIterative(n) << std::endl;
    std::cout << "Sum (formula): " << SumCalculator::sumOfFirstNFormula(n) << std::endl;

    // Demo with sample values
    std::cout << "\n=== Sample Sums ===" << std::endl;
    for (int i = 1; i <= 10; i++) {
        std::cout << "Sum of first " << i << " natural numbers = " 
                  << SumCalculator::sumOfFirstN(i) << std::endl;
    }

    return 0;
}
