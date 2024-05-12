#include "year.h"

#include <sstream>

#include <gtest/gtest.h>

using namespace EXP5;

TEST(year, comparison_of_year) {
    EXPECT_EQ(2023_y, year{2023});
    EXPECT_NE(2022_y, year{2023});
    EXPECT_LT(2022_y, year{2023});
    EXPECT_GT(2023_y, year{2022});
    EXPECT_GE(2023_y, year{2023});
    EXPECT_LE(2023_y, year{2023});
}

TEST(year, auto_inc_dec_operator) {
    auto y = year{2023};
    EXPECT_EQ(++y, year{2024});
    EXPECT_EQ(y, year{2024});
    EXPECT_EQ(y++, year{2024});
    EXPECT_EQ(y, year{2025});

    EXPECT_EQ(--y, year{2024});
    EXPECT_EQ(y, year{2024});
    EXPECT_EQ(y--, year{2024});
    EXPECT_EQ(y, year{2023});
}

TEST(year, ok) {
    auto y = year{2023};

    EXPECT_EQ(true, year::min().ok());
    EXPECT_EQ(true, year::max().ok());
}

TEST(year, is_leap) {
    EXPECT_EQ(year{2020}.is_leap(), true);
    EXPECT_EQ(year{2021}.is_leap(), false);
    EXPECT_EQ(year{2000}.is_leap(), true);
    EXPECT_EQ(year{1900}.is_leap(), false);
}

TEST(year, uni_operations) {
    EXPECT_EQ(+year{-2023}, year{-2023});
    EXPECT_EQ(+year{2023}, year{2023});
    EXPECT_EQ(-year{2023}, year{-2023});
    EXPECT_EQ(-year{-2023}, year{2023});
}

TEST(year, math_operations) {
    EXPECT_EQ(2015_y - 2010_y, years{5});
    EXPECT_EQ(2015_y - years{5}, 2010_y);
    EXPECT_EQ(2015_y, years{5} + 2010_y);
    EXPECT_EQ(2015_y, 2010_y + years{5});
    auto y = 2015_y;
    EXPECT_EQ((y += years{5}), 2020_y);
    EXPECT_EQ((y -= years{5}), 2015_y);
}

TEST(year, stream) {
    auto y = 2023_y;
    std::ostringstream os;
    os << y;
    EXPECT_EQ("2023", os.str());
    // clear the stream & set the state to good

    os.str("");
    os.clear();
    os << year{-2023};
    EXPECT_EQ("-2023", os.str());
}
