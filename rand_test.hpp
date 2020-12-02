#ifndef __RAND_TEST_HPP__
#define __RAND_TEST_HPP__

#include "gtest/gtest.h"

#include "rand.hpp"
TEST(RandTest, RandEvaluateNonZero) {
    Rand* test = new Rand();
    EXPECT_LT(test->evaluate(),99);
}
TEST(RandTest, RandStringifyCheck) {
    Rand* test = new Rand();
    ASSERT_EQ(test->stringify(),"86.000000" );
}
#endif //__RAND_TEST_HPP__

