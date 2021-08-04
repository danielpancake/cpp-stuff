#include <chrono>
#include <iostream>

long long int Fib(int n) {
    if (n <= 0) return 0;

    long long int a = 1, b = 1;
    for (int i = 0; i < n - 1; i++) {
        b = a + b;
        a = b - a;
    }

    return a;
}

long long int FibRecursive(int n) {
    if (n < 1) return 0;
    if (n < 2) return 1;
    return FibRecursive(n - 2) + FibRecursive(n - 1);
}

std::chrono::steady_clock::time_point getNow() {
    return std::chrono::steady_clock::now();
}

double getTime(std::chrono::steady_clock::time_point start, std::chrono::steady_clock::time_point end) {
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

int main() {
    int N, t; std::cin >> N;
    long long int result;
    std::chrono::steady_clock::time_point start, end;

    start = getNow();
    result = Fib(N);
    end = getNow();

    std::cout << result << " ";
    t = getTime(start, end);

    std::cout << "Iterative exec. time: " << t << "μs" << std::endl;

    start = getNow();
    result = FibRecursive(N);
    end = getNow();

    std::cout << result << " ";
    t = getTime(start, end);

    std::cout << "Recursive exec. time: " << t << "μs" << std::endl;
}