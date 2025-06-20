#include <stdio.h>
#include <stdlib.h>

int calculateFactorial(int number) {
    int factorial;
    if (number == 0 || number == 1) {
        factorial = 1;
    }
    else {
        factorial = number * calculateFactorial(number - 1);
    }
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int result = calculateFactorial(n);
    printf("Factorial of %d is %d.\n", n, result);
    return 0;
}