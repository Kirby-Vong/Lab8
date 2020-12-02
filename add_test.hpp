#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "add.hpp"

TEST(addTest, addEvaluatePositive) {
    Base* firstNumber = new Op(3);
    Base* secondNumber = new Op(4);
    add* test = new add(firstNumber, secondNumber);
    EXPECT_EQ(test->evaluate(), 7);
}

TEST(addTest, addEvaluateNegative) {
    Base* val1 = new Op(2);
    Base* val2 = new Op(-4);
    add* test = new add(val1, val2);
    EXPECT_EQ(test->evaluate(), -2);
}

TEST(addTest, addEvaluateZero) {
    Base* val1 = new Op(5);
    Base* val2 = new Op(0);
    add* test = new add(val1, val2);
	EXPECT_EQ(test->evaluate(), 5);
}

TEST(addTest, addNothing) {
	Base* val1 = new Op(0);
	Base* val2 = new Op(0);
	add* test = new add(val1, val2);
	EXPECT_EQ(test->evaluate(), 0);
}

TEST(addTest, addStringify) {
	Base* val1 = new Op(5);
    Base* val2 = new Op(3);
    add* test = new add(val1, val2);
EXPECT_EQ(test->stringify(),"5.000000 + 3.000000");
}
#endif
