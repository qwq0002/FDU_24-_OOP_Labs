#include <cassert>
#include <sstream>
#include <type_traits>

#include "year.h"

using namespace EXP5;

// int static_test()
// {
//     static_assert( std::is_trivially_destructible<year>{}, "");
//     static_assert( std::is_trivially_default_constructible<year>{}, "");
//     static_assert( std::is_trivially_constructible<year>{}, "");
//     static_assert( std::is_trivially_copy_constructible<year>{}, "");
//     static_assert( std::is_trivially_copy_assignable<year>{}, "");
//     static_assert( std::is_trivially_move_constructible<year>{}, "");
//     static_assert( std::is_trivially_move_assignable<year>{}, "");

//     static_assert( std::is_trivially_copyable<year>{}, "");

//     static_assert( std::is_default_constructible<year>{}, "");
//     static_assert( std::is_standard_layout<year>{}, "");
//     static_assert( std::is_literal_type<year>{}, "");

//     static_assert( std::is_constructible<year, int>{}, "");
//     static_assert( std::is_constructible<int, year>{}, "");
//     static_assert(!std::is_convertible<year, int>{}, "");
//     static_assert(!std::is_convertible<int, year>{}, "");

//     return 1;
// };

void test_year() {
    assert(year{2015} == 2015_y);
    assert(int{year{2015}} == 2015);
    assert(year{2015} != 2016_y);
    assert(year{2015} < 2016_y);
    assert(year{2016} > 2015_y);
    assert(year{2015} <= 2015_y);
    assert(year{2016} >= 2015_y);

    auto y = year{2014};
    assert(++y == year{2015});
    assert(y == year{2015});
    assert(y++ == year{2015});
    assert(y == year{2016});
    assert(--y == year{2015});
    assert(y == year{2015});
    assert(y-- == year{2015});
    assert(y == year{2014});

    assert(year::min().ok());
    assert(year{2015}.ok());
    assert(year{2016}.ok());
    assert(!year::max().ok());

    assert(year{2016}.is_leap());

    assert(2015_y - 2010_y == years{5});
    assert(2015_y - years{5} == 2010_y);
    assert(2015_y == years{5} + 2010_y);
    assert(2015_y == 2010_y + years{5});
    y = 2015_y;
    assert((y += years{5}) == 2020_y);
    assert((y -= years{5}) == 2015_y);

    y = 2015_y;
    std::ostringstream os;
    os << y;
    assert(os.str() == "2015");

    // clear the stream & set the state to good
    os.str("");
    os.clear();
    auto z = -y;
    os << z;
    assert(os.str() == "-2015");
}

int main() {
    test_year();
    return 0;
}