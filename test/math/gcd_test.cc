#include <gtest/gtest.h>
#include <gcd.hpp>

TEST(GCDTest, Test1) {
    EXPECT_EQ(2, gcd(34, 88));
    EXPECT_EQ(1, gcd(635, 253));
    EXPECT_EQ(1, gcd(7, 31));
    EXPECT_EQ(6, gcd(18, 24));
    EXPECT_EQ(10, gcd(30, 20));
    EXPECT_EQ(10, gcd(30, 20));
    EXPECT_EQ(2, gcd(10, 6));
}
