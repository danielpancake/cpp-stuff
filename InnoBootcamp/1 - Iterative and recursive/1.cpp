#include <iostream>

int Fib(int n) {
    if (n <= 0) return 0;

    int a = 1, b = 1;
    for (int i = 0; i < n - 1; i++) {
        b = a + b;
        a = b - a;
    }

    return a;
}

int FibRecursive(int n) {
    if (n < 1) return 0;
    if (n < 2) return 1;
    return FibRecursive(n - 2) + FibRecursive(n - 1);
}

int main() {
    int N; std::cin >> N;

    std::cout << Fib(N) << "   " << FibRecursive(N);
}