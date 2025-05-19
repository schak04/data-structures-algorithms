#include <stdio.h>
#include <stdlib.h>

int sumOfFirstN(int n) {
    int sum = 0;
    if (n < 0) {
        return -1;
    }
    else if (n == 0) {
        sum = 0;
    }
    else {
        for (int i = 1; i<=n; i++) {
            sum = i + sumOfFirstN(i-1);
        }
    }
    return sum;
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    int result = sumOfFirstN(n);
    printf("Sum of first %d natural numbers is %d.\n", n, result);

    return 0;
}