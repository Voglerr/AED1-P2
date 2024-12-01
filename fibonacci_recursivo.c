#include <stdio.h>

int fibonacci(int n);

int main() {
    printf("%d\n%d\n%d\n%d\n%d\n%d\n", fibonacci(1), fibonacci(2), fibonacci(3), fibonacci(4), fibonacci(5), fibonacci(6));
}

int fibonacci(int n) {
    if (n == 1 || n == 2) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}