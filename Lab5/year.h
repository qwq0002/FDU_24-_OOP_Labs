#pragma once

#include <chrono>
#include <iostream>
#include <ratio>

namespace EXP5 {

using days = std::chrono::duration<
    int, std::ratio_multiply<std::ratio<24>, std::chrono::hours::period>>;
using years = std::chrono::duration<
    int, std::ratio_multiply<std::ratio<146097, 400>, days::period>>;

class year {
    short y_;

  public:
    year() = default;
    explicit year(int y);

    year &operator++();
    year operator++(int);
    year &operator--();
    year operator--(int);

    year &operator+=(const years &y);
    year &operator-=(const years &y);

    year operator-() const;
    year operator+() const;

    explicit operator int() const;

    bool is_leap() const;
    bool ok() const;

    static year min() { return year{-32767}; }
    static year max() { return year{32767}; }
};

bool operator==(const year &x, const year &y);
bool operator!=(const year &x, const year &y);
bool operator<(const year &x, const year &y);
bool operator>(const year &x, const year &y);
bool operator<=(const year &x, const year &y);
bool operator>=(const year &x, const year &y);

year operator+(const year &x, const years &y);
year operator+(const years &x, const year &y);
year operator-(const year &x, const years &y);
years operator-(const year &x, const year &y);

std::ostream &operator<<(std::ostream &os, const year &y);

inline namespace literals {
year operator"" _y(unsigned long long y);
}

}; // namespace EXP5