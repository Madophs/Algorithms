#include <gtest/gtest.h>
#include "prime_factors.hpp"
#include "utils/assert_utils.hpp"

TEST(PrimeFactors, Test1)
{
    ASSERT_TRUE(algo::vector_are_equal(primeFactors(600851475143), vector<int>({71, 839, 1471, 6857})));
}

TEST(PrimeFactors, Test2)
{
    ASSERT_TRUE(algo::vector_are_equal(primeFactors(599), vector<int>({599})));
}

TEST(PrimeFactors, Test3)
{
    ASSERT_TRUE(algo::vector_are_equal(primeFactors(123456789), vector<int>({3, 3, 3607, 3803})));
}

TEST(PrimeFactors, Test4)
{
    ASSERT_TRUE(algo::vector_are_equal(primeFactors(289317), vector<int>({3, 7, 23, 599})));
}

TEST(PrimeFactors, Test5)
{
    ASSERT_TRUE(algo::vector_are_equal(primeFactors(1000000007), vector<int>({1000000007})));
}
