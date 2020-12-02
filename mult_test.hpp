#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "mult.hpp"
#include "add.hpp"
#include "sub.hpp"

TEST(multTest, multEvaluateNonZero) {
	Base* firstNumber = new Op(3);
	Base* secondNumber = new Op(4);
	mult* test = new mult(firstNumber, secondNumber);
	EXPECT_EQ(test->evaluate(), 12);
} 

TEST(multTest, multEvaluateNegative) {
	Base* val1 = new Op(-2);
	Base* val2 = new Op(4);
	mult* test = new mult(val1, val2);
	EXPECT_EQ(test->evaluate(), -8);
}

TEST(multTest, multEvaluateZero) {
	Base* val1 = new Op(5);
	Base* val2 = new Op(0);
	mult* test = new mult(val1, val2);
	EXPECT_EQ(test->evaluate(), 0);
}

TEST(multTest, multDiv) {
	Base* val1 = new Op(4);
	Base* val2 = new Op(2);
	Div* test1 = new Div(val1, val2);
	Base* val3 = new Op(7);
	mult* test2 = new mult(test1, val3);
	EXPECT_EQ(test2->evaluate(), 14);
}

TEST(multTest, multSub) {
	Base* val1 = new Op(7);
	Base* val2 = new Op(3);
	Sub* test1 = new Sub(val1, val2);
	Base* val3 = new Op(7);
	mult* test2 = new mult(test1, val3);
	EXPECT_EQ(test2->evaluate(), 28);
}

TEST(multTest, multAdd) {
	Base* val1 = new Op(5);
	Base* val2 = new Op(3);
	add* test1 = new add(val1, val2);
	Base* val3 = new Op(5);
	mult* test2 = new mult(val3, test1);
	EXPECT_EQ(test2->evaluate(), 40);
}

TEST(multTest, multAddmult) {
	Base* val1 = new Op(2);
	Base* val2 = new Op(2);
	mult* test1 = new mult(val1, val2);
	Base* val3 = new Op(4); 
	add* test2 = new add(test1, val3);
	Base* val4 = new Op(7);
	mult* test3 = new mult(test2, val4);
	EXPECT_EQ(test3->evaluate(), 56);
}


TEST(multTest, multStringify) {
	Base* val1 = new Op(5);
	Base* val2 = new Op(3);
	mult* test = new mult(val1, val2);
	EXPECT_EQ(test->stringify(),"5.000000 * 3.000000");
}

#endif //__OP_TEST_HPP__
