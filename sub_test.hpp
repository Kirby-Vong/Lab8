#ifndef __SUB_TEST_HPP__
#define __SUB_TEST_HPP__

#include "gtest/gtest.h"

#include "sub.hpp"
#include "div.hpp"

TEST(SubTest, SubEvaluateNonZero) {
    Base* val1 = new Op(4);
    Base* val2 = new Op(2);
    Sub* test = new Sub(val1, val2);
    EXPECT_EQ(test->evaluate(), 2);
}
TEST(SubTest, SubEvaluateNeg) {
    Base* val1 = new Op(-4);
    Base* val2 = new Op(2);
    Sub* test = new Sub(val1, val2);
    EXPECT_EQ(test->evaluate(), -6);
}
TEST(SubTest, SubEvaluateZero) {
     Base* val1 = new Op(2);
     Base* val2 = new Op(2);
     Sub* test = new Sub(val1, val2);
     EXPECT_EQ(test->evaluate(), 0);
}
TEST(SubTest, SubStringifyCheck) {
     Base* val1 = new Op(4);
     Base* val2 = new Op(2);
     Sub* test = new Sub(val1, val2);
     EXPECT_EQ(test->stringify(), "4.000000 - 2.000000");
}
TEST(SubTest, SubDiv) {
    Base* val1 = new Op(8);
    Base* val2 = new Op(2);
    Base* val3 = new Op(2);
    Sub* test1 = new Sub(val1, val2);
    Div* test2 = new Div(test1, val3);
    EXPECT_EQ(test2->evaluate(), 3);
}
#endif

