#pragma once

#include <string>
#include <vector>

using Grid = std::vector<std::string>;

Grid readGrid(std::istream &in);
Grid frameGrid(Grid const &, char SEP = '.');
// todo: to complete
void print(std::ostream &out, Grid const &);
std::vector<unsigned> findEffectiveNumber(Grid const &);
