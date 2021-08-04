#include <iostream>
#include <vector>

unsigned int factorial(int n) {
    unsigned int result = 1;

    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    
    return result;
}

void find_shortest_path(int count, std::vector <std::vector <int>> map) {

    count -= 1; // Excluding first city

    int premutations[count], optimalPath[count];
    for (int i = 0; i < count; i++) {
        premutations[i] = i + 1; // Filling array with the first path (order of cities: 1, 2, 3...)
    }

    int numberOfPremutations = factorial(count);
    int swapIndex = 0;

    int minLength = INT32_MAX, length;
    for (int i = 0; i < numberOfPremutations; i++) {

        length = 0;

        length += map[0][ premutations[0] ];
        length += map[ premutations[count - 1] ][ 0 ];

        for (int j = 1; j < count; j++) {
            length += map[ premutations[j - 1] ][ premutations[j] ];
        }

        if (length < minLength) {
            std::copy(premutations, premutations + count, optimalPath);
            minLength = length;
        }

        std::iter_swap(&premutations[swapIndex], &premutations[swapIndex + 1]);
        swapIndex = (swapIndex + 1) % (count - 1); // Cycling from 0 to count - 2
    }

    std::cout << "Shortest path has length of " << minLength << std::endl;
    std::cout << "The order of cities is: 0 ";
    for (int e : optimalPath) {
        std::cout << e << " ";
    }
}

int main() {
    std::cout << "Enter the number of cities: ";
    int N; std::cin >> N;

    std::vector <std::vector <int>> map;
    for (int i = 0; i < N; i++) {
        std::vector <int> line(N);

        for (int j = 0; j < N; j++) {
            std::cin >> line[j];
        }

        map.push_back(line);
    }

    find_shortest_path(N, map);

    return 0;
}