#ifndef __POW_TEST_HPP__
#define __POW_TEST_HPP__

#include "gtest/gtest.h"

#include "pow.hpp"
#include "div.hpp"
#include "sub.hpp"

TEST(PowTest, PowEvaluateNonZero) {
    Base* num1 = new Op(2);
    Base* num2 = new Op(3);
    Pow* test = new Pow(num1, num2);
    EXPECT_EQ(test->evaluate(), 8);
}
TEST(PowTest, PowEvaluateNeg) {
     Base* num1 = new Op(-2);
     Base* num2 = new Op(3);
     Pow* test = new Pow(num1, num2);
     EXPECT_EQ(test->evaluate(), -8);
}
TEST(PowTest, PowEvaluateZero) {
     Base* num1 = new Op(0);
     Base* num2 = new Op(1);
     Pow* test = new Pow(num1, num2);
     EXPECT_EQ(test->evaluate(), 0);
}
TEST(PowTest, PowEvaluateZeroExp) {
     Base* num1 = new Op(2);
     Base* num2 = new Op(0);
     Pow* test = new Pow(num1, num2);
     EXPECT_EQ(test->evaluate(), 1);
}
TEST(PowTest, PowStringifyCheck) {
     Base* num1 = new Op(2);
     Base* num2 = new Op(3);
     Pow* test = new Pow(num1, num2);
     EXPECT_EQ(test->stringify(),"2.000000 ** 3.000000");
}
TEST(PowTest, PowEvaluateNegExp) {
    Base* num1 = new Op(2);
    Base* num2 = new Op(-3);
    Pow* test = new Pow(num1, num2);
    EXPECT_EQ(test->evaluate(), 0.125);
}
TEST(PowTest, PowDiv) {
    Base* num1 = new Op(2);
    Base* num2 = new Op(3);
    Base* num3 = new Op(4);
    Pow* test1 = new Pow(num1, num2);
    Div* test2 = new Div(test1, num3);
    EXPECT_EQ(test2->evaluate(), 2);
}
TEST(PowTest, PowSub) {
    Base* num1 = new Op(4);
    Base* num2 = new Op(2);
    Base* num3 = new Op(2);
    Pow* test1 = new Pow(num1, num2);
    Sub* test2 = new Sub(test1, num3);
    EXPECT_EQ(test2->evaluate(), 14);
}
#endif

