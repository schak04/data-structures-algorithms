/*
 * Factorial Calculation using Recursion
 * 
 * Computes the factorial of a number using recursive approach.
 * n! = n * (n-1) * (n-2) * ... * 1
 * Base case: 0! = 1, 1! = 1
 */

#include <iostream>

class Factorial {
public:
    /**
     * Calculate factorial using recursion
     * @param number Number to calculate factorial of
     * @return Factorial of the number
     */
    static int calculateFactorial(int number) {
        if (number == 0 || number == 1) {
            return 1;
        } else {
            return number * calculateFactorial(number - 1);
        }
    }

    /**
     * Calculate factorial using iterative approach
     * @param number Number to calculate factorial of
     * @return Factorial of the number
     */
    static long long calculateFactorialIterative(int number) {
        if (number < 0) {
            return -1; // Invalid input
        }

        long long factorial = 1;
        for (int i = 2; i <= number; i++) {
            factorial *= i;
        }
        return factorial;
    }
};

int main() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    if (n < 0) {
        std::cout << "Factorial is not defined for negative numbers." << std::endl;
        return 0;
    }

    int result = Factorial::calculateFactorial(n);
    std::cout << "Factorial of " << n << " (recursive) is: " << result << std::endl;

    // For larger numbers, use iterative to avoid stack overflow
    if (n > 12) {
        long long resultIter = Factorial::calculateFactorialIterative(n);
        std::cout << "Factorial of " << n << " (iterative) is: " << resultIter << std::endl;
    }

    // Demo with sample values
    std::cout << "\n=== Sample Factorials ===" << std::endl;
    for (int i = 0; i <= 10; i++) {
        std::cout << i << "! = " << Factorial::calculateFactorial(i) << std::endl;
    }

    return 0;
}

