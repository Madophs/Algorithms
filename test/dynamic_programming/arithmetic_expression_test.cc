#include <gtest/gtest.h>
#include <arithmetic_expression.hpp>

TEST(ArithmeticExpression, Test1) {
    MinMaxArithmeticExpression expression("5-8+7*4-8+9");
    expression.evaluate();
    EXPECT_EQ(expression.max(), 200);
    EXPECT_EQ(expression.min(), -94);
    EXPECT_EQ(expression.constructMaxSolution(), "(5-((8+7)*(4-(8+9))))");
    EXPECT_EQ(expression.constructMinSolution(), "((5-8)+(7*(4-(8+9))))");
}

TEST(ArithmeticExpression, Test2) {
    MinMaxArithmeticExpression expression("6*3+2*5");
    expression.evaluate();
    EXPECT_EQ(expression.max(), 150);
    EXPECT_EQ(expression.min(), 28);
    EXPECT_EQ(expression.constructMaxSolution(), "(6*((3+2)*5))");
    EXPECT_EQ(expression.constructMinSolution(), "((6*3)+(2*5))");
}

TEST(ArithmeticExpression, Test3) {
    MinMaxArithmeticExpression expression("1*2-7*4-8");
    expression.evaluate();
    EXPECT_EQ(expression.max(), 30);
    EXPECT_EQ(expression.min(), -34);
    EXPECT_EQ(expression.constructMaxSolution(), "(1*(2-(7*(4-8))))");
    EXPECT_EQ(expression.constructMinSolution(), "(1*((2-(7*4))-8))");
}

TEST(ArithmeticExpression, Test4) {
    MinMaxArithmeticExpression expression("1-20-10+60");
    expression.evaluate();
    EXPECT_EQ(expression.max(), 51);
    EXPECT_EQ(expression.min(), -89);
    EXPECT_EQ(expression.constructMaxSolution(), "(1-(20-(10+60)))");
    EXPECT_EQ(expression.constructMinSolution(), "((1-20)-(10+60))");
}

TEST(ArithmeticExpression, Test5) {
    MinMaxArithmeticExpression expression("1+3-7*6-4");
    expression.evaluate();
    EXPECT_EQ(expression.max(), -6);
    EXPECT_EQ(expression.min(), -42);
    EXPECT_EQ(expression.constructMaxSolution(), "((1+(3-7))*(6-4))");
    EXPECT_EQ(expression.constructMinSolution(), "(1+((3-(7*6))-4))");
}

TEST(ArithmeticExpression, Test6) {
    MinMaxArithmeticExpression expression("1+2*3+4*5");
    expression.evaluate();
    EXPECT_EQ(expression.max(), 105);
    EXPECT_EQ(expression.min(), 27);
    EXPECT_EQ(expression.constructMaxSolution(), "((1+2)*((3+4)*5))");
    EXPECT_EQ(expression.constructMinSolution(), "(1+((2*3)+(4*5)))");
}
