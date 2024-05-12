#include "year.h"

namespace EXP5 {
// remove inline definition
#define inline

// year implementation

    inline year::year(int y) : y_(static_cast<decltype(y_)>(y)) {}

// TODO1 ++/++, --/--, +=, -=
    inline year &year::operator++() {
        // prefix call
        ++(this->y_);
        return *this;
    }

    inline year year::operator++(int) {
        // suffix call
        year tmp = *this;
        ++(*this);
        return tmp;
    }

    inline year &year::operator--() {
        // prefix call
        --(this->y_);
        return *this;
    }

    inline year year::operator--(int) {
        // suffix call
        year tmp = *this;
        --(*this);
        return tmp;
    }

    inline year &year::operator+=(const years &y){
        this->y_ += y.count();
        return *this;
    }

    inline year &year::operator-=(const years &y){
        this->y_ -= y.count();
        return *this;
    }

    inline year year::operator-() const { return year{-y_}; }

    inline year year::operator+() const { return *this; }

    inline year::operator int() const { return y_; }

// TODO2 : is_leap, ok
    bool year::is_leap() const {
        int y = this->y_;
        return (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0));
    }

    bool year::ok() const {
        return (*this >= this->min() && *this < this->max());
    }

// comparison
    inline bool operator==(const year &x, const year &y) {
        return static_cast<int>(x) == static_cast<int>(y);
    }

    inline bool operator<(const year &x, const year &y) {
        return static_cast<int>(x) < static_cast<int>(y);
    }

    inline bool operator>(const year &x, const year &y) { return y < x; }

// TODO3 !=, <=, >=
    inline bool operator!=(const year &x, const year &y){
        return !(x == y);
    }

    inline bool operator<=(const year &x, const year &y){
        return (x < y || x == y);
    }
    inline bool operator>=(const year &x, const year &y){
        return (x > y || x == y);
    }

    inline year operator+(const year &x, const years &y) {
        return year{static_cast<int>(x) + y.count()};
    }

    inline year operator+(const years &x, const year &y) {
        return y + x; }

// TODO4 operator-
    inline year operator-(const year &x, const years &y) {
        return year{static_cast<int>(x) - y.count()}; }

    inline years operator-(const year &x, const year &y) {
        return years{static_cast<int>(x) - static_cast<int>(y) }; }

    inline std::ostream &operator<<(std::ostream &os, const year &y) {
        os << static_cast<int>(y);
        return os;
    }

    namespace literals {
        year operator"" _y(unsigned long long y) { return year(static_cast<int>(y)); }
    } // namespace literals

}; // namespace EXP5
