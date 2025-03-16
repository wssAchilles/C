#include <stdio.h>

void fibonacci_sequence(int n) {
    int fib_sequence[n];
    fib_sequence[0] = 0;
    fib_sequence[1] = 1;

    for (int i = 2; i < n; i++) {
        fib_sequence[i] = fib_sequence[i - 1] + fib_sequence[i - 2];
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", fib_sequence[i]);
    }
}

int main() {
    int n = 20;
    fibonacci_sequence(n);
    return 0;
}