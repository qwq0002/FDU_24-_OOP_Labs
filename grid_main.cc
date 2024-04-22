#include "grid.h"

#include <fstream>
#include <iostream>
#include <numeric>

int main() {
    std::ifstream in{"input2.txt"};

    auto grid = readGrid(in);
    grid = frameGrid(grid);

//    print(std::cout, grid);

    auto numbers = findEffectiveNumber(grid);

    auto total = std::accumulate(numbers.begin(), numbers.end(), 0);

    std::cout << "numbers size: " << numbers.size() << " total: " << total
              << '\n';
}