#include <gtest/gtest.h>
#include <extended_euclidean.hpp>

TEST(ExtendedEuclideanTest, Test1) {
    int x, y;
    EXPECT_EQ(1, extendedEuclidean(7, 31, x, y));
    EXPECT_EQ(9, x);
    EXPECT_EQ(-2, y);
}

TEST(ExtendedEuclideanTest, Test2) {
    int x, y;
    EXPECT_EQ(10, extendedEuclidean(30, 20, x, y));
    EXPECT_EQ(1, x);
    EXPECT_EQ(-1, y);
}

TEST(ExtendedEuclideanTest, Test3) {
    int x, y;
    EXPECT_EQ(2, extendedEuclidean(16, 10, x, y));
    EXPECT_EQ(2, x);
    EXPECT_EQ(-3, y);
}

TEST(ExtendedEuclideanTest, Test4) {
    int x, y;
    EXPECT_EQ(1, extendedEuclidean(635, 253, x, y));
    EXPECT_EQ(51, x);
    EXPECT_EQ(-128, y);
}

TEST(ExtendedEuclideanTest, Test5) {
    int x, y;
    EXPECT_EQ(10, extendedEuclidean(10, 30, x, y));
    EXPECT_EQ(1, x);
    EXPECT_EQ(0, y);
}

TEST(ExtendedEuclideanTest, Test6) {
    int x, y;
    EXPECT_EQ(2, extendedEuclidean(34, 88, x, y));
    EXPECT_EQ(13, x);
    EXPECT_EQ(-5, y);
}
