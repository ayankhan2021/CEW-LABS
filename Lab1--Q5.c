#include <stdio.h>


int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

void printFibonacciSeriesRecursive(int n, int current) {
    if (current <= n) {
        printf("%d ", fibonacci(current));
        printFibonacciSeriesRecursive(n, ++current);
    }
}

int main() {
    int n;

    printf("Enter the value of n to calculate the nth Fibonacci number and series: ");
    scanf("%d", &n);

    printf("Fibonacci Series up to the %dth number: ", n);
    printFibonacciSeriesRecursive(n, 0);

    printf("\n");

    printf("The %dth Fibonacci number is: %d\n", n, fibonacci(n));

    return 0;
}
