#include "grid.h"

#include <array>
#include <cctype>
#include <iostream>

static size_t maxGridLine(Grid const &grid) {
    size_t ret{0};
    for (auto const &line: grid)
        ret = std::max(ret, line.size());
    return ret + 2;
}

inline bool isSymbol(char c) { return (c != '.' && !isdigit(c)); }

bool isSymbolAdjacent(char c, size_t i, size_t j, Grid const &grid) {
    std::array<std::pair<int, int>, 8> positions{
            {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}};
    for (const auto [delta_i, delta_j]: positions) {
        auto c = grid[i + delta_i][j + delta_j];
        if (isSymbol(c)) {
            return true;
        }
    }

    return false;
}

Grid readGrid(std::istream &in) {
    Grid grid;
    std::string line;
    while (std::getline(in, line)) {
        if (line.size() == 0)
            break;
        grid.push_back(line);
    }
    return grid;
}

Grid frameGrid(Grid const &grid, char SEP) {
    Grid framed;
    auto max = maxGridLine(grid);

    framed.push_back(std::string(max, SEP));
    for (auto const &line: grid) {
        std::string new_line =
                '.' + line + std::string(max - 2 - line.size(), ' ') + '.';
        framed.push_back(new_line);
    }
    framed.push_back(std::string(max, SEP));

    return framed;
}

// todo: implement two functions:
void print(std::ostream &out, Grid const &grid) {
    for (const auto &line: grid) {
        out << line << '\n';
    }
}


std::vector<unsigned> findEffectiveNumber(Grid const &grid) {
    std::vector<unsigned> effectiveNumbers;
    unsigned num = 0;
    unsigned row = 0, col = 0;
    bool isNum = false, isEffective = false;
    for (const auto &line: grid) {
        col = 0;
        for (const auto &ch: line) {
            if(isNum && !isdigit(ch)){
                if(isEffective){
                    effectiveNumbers.push_back(num);
                    isEffective = false;
                }
            }
            if (!isdigit(ch)) {
                num = 0;
                col++;
                isNum = false;
                continue;
            }
            isNum = true;
            num *= 10;
            num += int(ch - '0');
            if (!isEffective) {
                isEffective = isSymbolAdjacent(ch, row, col, grid);
            }
            col++;
        }
        row++;
    }

    return effectiveNumbers;
}
