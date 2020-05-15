#include "function.h"
#include "Coord.h"
#include <gtest/gtest.h>

TEST(PERIMETER, PerimeterCorrect)
{
    ASSERT_FLOAT_EQ(6.28, P(1));

    ASSERT_FLOAT_EQ(3.14, P(0.5));

    ASSERT_FLOAT_EQ(0.05024, P(0.008));

    ASSERT_FLOAT_EQ(39.4384, P(6.28));
}

TEST(AREA, AreaCorrect)
{
    ASSERT_FLOAT_EQ(28.26, S(3));

    ASSERT_FLOAT_EQ(0.0314, S(0.1));

    ASSERT_FLOAT_EQ(12.56, S(2));

    ASSERT_FLOAT_EQ(12.2852, S(1.978));
}

TEST(COORD, Correct)
{
    float x, y, r;
    std::string str = "(-12.5 -9.8, 7.36)";
    EXPECT_TRUE(Coord(str, x, y, r));

    str = "(7 18, 6)";
    EXPECT_TRUE(Coord(str, x, y, r));

    str = "(0.000001 -0.00002, 0.00007)";
    EXPECT_TRUE(Coord(str, x, y, r));

    str = "(-758 982, 78.258)";
    EXPECT_TRUE(Coord(str, x, y, r));
}

TEST(COORD, inCorrect)
{
    float x, y, r;
    std::string str = "()";
    EXPECT_FALSE(Coord(str, x, y, r));

    str = "7 18, 6";
    EXPECT_FALSE(Coord(str, x, y, r));

    str = "(0.1 0.2,0.7)";
    EXPECT_FALSE(Coord(str, x, y, r));

    str = "(758 982 78.258)";
    EXPECT_FALSE(Coord(str, x, y, r));

    str = "(sacvvd 0avds2, 0.afsfs7)";
    EXPECT_FALSE(Coord(str, x, y, r));

    str = "(@#$%^& asc, 78)";
    EXPECT_FALSE(Coord(str, x, y, r));

    str = "(144 82, -78)";
    EXPECT_FALSE(Coord(str, x, y, r));
}
