#ifndef __VECTOR_CONTAINER_TEST_HPP__
#define __VECTOR_CONTAINER_TEST_HPP__

#include "gtest/gtest.h"
#include "container.hpp"
#include "VectorContainer.h"
#include "SelectionSort.h"
#include "mult.hpp"
#include "add.hpp"
#include "sub.hpp"

TEST(VectorContainerTest, VectorTest) {
	Op* seven = new Op(7);
	VectorContainer* test_container = new VectorContainer();

	test_container->add_element(seven);

	ASSERT_EQ(test_container->size(), 1);
	EXPECT_EQ(test_container->at(0)->evaluate(), 7);
}

TEST(VectorContainerTest, AddNegativeTest) {
    Op* seven = new Op(7);
	Op* negfive = new Op(-5);
	Op* negten = new Op(-10);
    VectorContainer* test_container = new VectorContainer();

    test_container->add_element(seven);
	test_container->add_element(negten);
	test_container->add_element(negfive);

    ASSERT_EQ(test_container->size(), 3);
    EXPECT_EQ(test_container->at(0)->evaluate(), 7);
	EXPECT_EQ(test_container->at(1)->evaluate(), -10);
	EXPECT_EQ(test_container->at(2)->evaluate(), -5);
}



TEST(VectorContainerTest, ZeroElementTest) {
	Op* zero = new Op (0);
	VectorContainer* test = new VectorContainer();
	test->add_element(zero);
	test->add_element(zero);
	test->add_element(zero);
	
	ASSERT_EQ(test->size(), 3);
	EXPECT_EQ(test->at(0)->evaluate(), 0);
}

TEST(VectorContainerTest, SwapFirstAndLastTest) {
	Op* seven = new Op(7);
	Op* eight = new Op(8);
	Op* nine = new Op(9);

	VectorContainer* test = new VectorContainer();

	test->add_element(seven);
	test->add_element(eight);
	test->add_element(nine);
	
	test->swap(0,2);
	ASSERT_EQ(test->size(), 3);
	EXPECT_EQ(test->at(0)->evaluate(), 9);
}

TEST(VectorContainerTest, SwapMiddleTest) {
    Op* two = new Op(2);
    Op* five = new Op(5);
    Op* six = new Op(6);
	Op* eight = new Op(8);
    VectorContainer* test_container = new VectorContainer();

	test_container->add_element(two);
    test_container->add_element(five);
    test_container->add_element(six);
	test_container->add_element(eight);

	test_container->swap(1, 2);
    ASSERT_EQ(test_container->size(), 4);
    EXPECT_EQ(test_container->at(1)->evaluate(), 6);
}


TEST(SortTestSet, SortTest) {
	Op* seven = new Op(7);
	Op* eight = new Op(8);
	Op* nine = new Op(9);

	VectorContainer* test = new VectorContainer();
	test->add_element(nine);
	test->add_element(eight);
	test->add_element(seven);

	test->set_sort_function(new SelectionSort());
	test->sort();
	ASSERT_EQ(test->size(), 3);
	EXPECT_EQ(test->at(0)->evaluate(), 7);
	EXPECT_EQ(test->at(1)->evaluate(), 8);
	EXPECT_EQ(test->at(2)->evaluate(), 9);
}


TEST(SortTestSet, SelectionSortTest) {
    Op* seven = new Op(7);
	Op* four = new Op(4);
	mult* TreeA = new mult(seven, four);

	Op* three = new Op(3);
	Op* two = new Op(2);
	add* TreeB = new add(three, two);

	Op* ten = new Op(10);
	Op* six = new Op(6);
	Sub* TreeC = new Sub(ten, six);

	VectorContainer* container = new VectorContainer();
	container->add_element(TreeA);
	container->add_element(TreeB);
	container->add_element(TreeC);

	ASSERT_EQ(container->size(), 3);
	EXPECT_EQ(container->at(0)->evaluate(), 28);
	EXPECT_EQ(container->at(1)->evaluate(), 5);
	EXPECT_EQ(container->at(2)->evaluate(), 4);

	container->set_sort_function(new SelectionSort());
	container->sort();

	ASSERT_EQ(container->size(), 3);
	EXPECT_EQ(container->at(0)->evaluate(), 4);
	EXPECT_EQ(container->at(1)->evaluate(), 5);
	EXPECT_EQ(container->at(2)->evaluate(), 28);
}

TEST(SortTestSet, BunchOfZerosTest) {
	Op* zero = new Op(0);
	Op* two = new Op(2);
	
	VectorContainer* test = new VectorContainer();
	test->add_element(zero);
	test->add_element(zero);
	test->add_element(two);
	test->add_element(zero);
	test->add_element(zero);
	test->add_element(two);
	
	test->set_sort_function(new SelectionSort());
	test->sort();

	ASSERT_EQ(test->size(), 6);
	EXPECT_EQ(test->at(2)->evaluate(), 0);
	EXPECT_EQ(test->at(4)->evaluate(), 2);
	EXPECT_EQ(test->at(5)->evaluate(), 2);

} 

TEST(SortTestSet, RandomNumbers) {
	Op* two = new Op(2);
    Op* five = new Op(5);
    Op* six = new Op(6);
    Op* eight = new Op(8);
	Op* four = new Op(4);
	Op* fifthteen = new Op(15);
    VectorContainer* test_container = new VectorContainer();

    test_container->add_element(five);
    test_container->add_element(two);
    test_container->add_element(eight);
    test_container->add_element(six);
	test_container->add_element(fifthteen);
	test_container->add_element(four);

    test_container->set_sort_function(new SelectionSort());
	test_container->sort();
    ASSERT_EQ(test_container->size(), 6);
    EXPECT_EQ(test_container->at(0)->evaluate(), 2);
    EXPECT_EQ(test_container->at(1)->evaluate(), 4);
    EXPECT_EQ(test_container->at(2)->evaluate(), 5);
    EXPECT_EQ(test_container->at(3)->evaluate(), 6);
    EXPECT_EQ(test_container->at(4)->evaluate(), 8);
    EXPECT_EQ(test_container->at(5)->evaluate(), 15);

}

TEST(SortTestSet, NegativeValuesTest) {
    Op* seven = new Op(7);
    Op* negthree = new Op(-3);
    Op* nine = new Op(9);

    VectorContainer* test = new VectorContainer();
    test->add_element(nine);
    test->add_element(negthree);
    test->add_element(seven);

    test->set_sort_function(new SelectionSort());
    test->sort();
    ASSERT_EQ(test->size(), 3);
    EXPECT_EQ(test->at(0)->evaluate(), -3);
    EXPECT_EQ(test->at(1)->evaluate(), 7);
    EXPECT_EQ(test->at(2)->evaluate(), 9);
}
				



#endif
