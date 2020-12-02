#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__

#include "gtest/gtest.h"

#include "div.hpp"

TEST(DivTest, DivEvaluateNonZero) {
    Base* val1 = new Op(4);
    Base* val2 = new Op(2); 
    Div* test = new Div(val1, val2);
    EXPECT_EQ(test->evaluate(), 2);
}
TEST(DivTest, DivEvaluateZero) {
    Base* val1 = new Op(0);
    Base* val2 = new Op(2);
    Div* test = new Div(val1, val2);
    EXPECT_EQ(test->evaluate(), 0);
}
TEST(DivTest, DivideByZeroDenom) {
     Base* val1 = new Op(2);
     Base* val2 = new Op(0);
     Div* test = new Div(val1, val2);
     EXPECT_EQ(test->evaluate(), -1);
}
TEST(DivTest, DivEvaluateNegNum) {
     Base* val1 = new Op(-4);
     Base* val2 = new Op(2);
     Div* test = new Div(val1, val2);
     EXPECT_EQ(test->evaluate(), -2);
}
TEST(DivTest, DivideByZeroNumer) {
     Base* val1 = new Op(0);
     Base* val2 = new Op(2);
     Div* test = new Div(val1, val2);
     EXPECT_EQ(test->evaluate(), 0);
}
TEST(DivTest, DivStringifyCheck) {
    Base* val1 = new Op(4);
    Base* val2 = new Op(2);
    Div* test = new Div(val1, val2);
    EXPECT_EQ(test->stringify(), "4.000000 / 2.000000");
}

#endif 
