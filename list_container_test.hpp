#ifndef __LIST_CONTAINER_TEST_HPP__
#define __LIST_CONTAINER_TEST_HPP__

#include "gtest/gtest.h"
#include "container.hpp"
#include "ListContainer.h"
#include "BubbleSort.h"
#include "add.hpp"
TEST(ListContainerTest, ListTest) {
    Op* seven = new Op(7);
    ListContainer* test_container = new ListContainer();

    test_container->add_element(seven);

    ASSERT_EQ(test_container->size(), 1);
    EXPECT_EQ(test_container->at(0)->evaluate(), 7);

}

TEST(ListContainerTest, ZeroElementTest) {
    Op* zero = new Op(0);
    ListContainer* test = new ListContainer();
    test->add_element(zero);
    test->add_element(zero);
    test->add_element(zero);

    ASSERT_EQ(test->size(), 3);
    EXPECT_EQ(test->at(0)->evaluate(), 0);
}

TEST(ListContainerTest, NegativeNumberTest) {
    Op* neg_one = new Op(-1);
    Op* neg_two = new Op(-2);
    Op* neg_three = new Op(-3);
    Op* neg_four = new Op(-4);

    ListContainer* test = new ListContainer();
    test->add_element(neg_one);
    test->add_element(neg_two);
    test->add_element(neg_three);
    test->add_element(neg_four);

    ASSERT_EQ(test->size(), 4);
    EXPECT_EQ(test->at(0)->evaluate(), -1);
}

TEST(ListContainerTest, AddingNumberTest) {
    Op* neg_three = new Op(-3);
    Op* neg_four = new Op(-4);
    Op* five = new Op(5);
    Add* a1 = new Add(neg_three, neg_four);
    Add* a2 = new Add(neg_three, five);

    

    ListContainer* test = new ListContainer();
    test->add_element(neg_three);
    test->add_element(neg_four);
    test->add_element(a1);
    test->add_element(a2);
    
    ASSERT_EQ(test->size(), 4);
    EXPECT_EQ(test->at(3)->evaluate(), 2);
}
  
TEST(ListContainerTest, SwapTest) {
    Op* seven = new Op(7);
    Op* eight = new Op(8);
    Op* nine = new Op(9);
    ListContainer* test_container = new ListContainer();

    test_container->add_element(seven);
    test_container->add_element(eight);
    test_container->add_element(nine);

    test_container->swap(0, 2);
    ASSERT_EQ(test_container->size(), 3);
    cout << "Expected: 9 8 7" << endl << "Actual: ";
    test_container->print();
    
}

TEST(BubbleSortTest, BubbleSortTest) {
    Op* one = new Op(1);
    Op* two = new Op(2);
    Op* three = new Op(3);
    
    ListContainer* test = new ListContainer();
    test->add_element(three);
    test->add_element(two);;
    test->add_element(one);
    
    test->set_sort_function(new BubbleSort());
    test->sort();
    ASSERT_EQ(test->size(), 3);
    EXPECT_EQ(test->at(0)->evaluate(), 1);
    EXPECT_EQ(test->at(1)->evaluate(), 2);
    EXPECT_EQ(test->at(2)->evaluate(), 3);
}

TEST(BubbleSortTest, AddingBubbleSortTest) {
     Op* neg_three = new Op(-3);
     Op* neg_four = new Op(-4);
     Op* five = new Op(5);
     Add* a1 = new Add(neg_three, neg_four);
     Add* a2 = new Add(neg_three, five);
     
     ListContainer* test = new ListContainer();
     test->add_element(neg_three);
     test->add_element(neg_four);
     test->add_element(a1);
     test->add_element(a2);
     
     ASSERT_EQ(test->size(), 4);
     EXPECT_EQ(test->at(3)->evaluate(), 2);
     cout << "unsorted numbers: ";
     test->print();

     test->set_sort_function(new BubbleSort());
     test->sort();
     ASSERT_EQ(test->size(), 4);
     EXPECT_EQ(test->at(0)->evaluate(), -7);
     cout << "bubble sorted numbers: ";
     test->print();

} 

TEST(BubbleSortTest, BubbleZeroTest) {
    Op* zero = new Op(0);
    Op* three = new Op(3);
    Op* four = new Op(4);
    Op* five = new Op(5);

    ListContainer* list = new ListContainer();
    list->add_element(three);
    list->add_element(five);
    list->add_element(four);
    list->add_element(zero);

    list->set_sort_function(new BubbleSort());
    list->sort();
    ASSERT_EQ(list->size(), 4);
    EXPECT_EQ(list->at(0)->evaluate(), 0);
    EXPECT_EQ(list->at(1)->evaluate(), 3);
    EXPECT_EQ(list->at(2)->evaluate(), 4);
    EXPECT_EQ(list->at(3)->evaluate(), 5);
}

TEST(BubbleSortTest, BubbleNegTest) {
    Op* zero = new Op(0);
    Op* n_three = new Op(-3);
    Op* four = new Op(4);
    Op* n_five = new Op(-5);
    ListContainer* list = new ListContainer();
    list->add_element(n_three);
    list->add_element(n_five);
    list->add_element(four);
    list->add_element(zero);
    
    list->set_sort_function(new BubbleSort());
    list->sort();
    ASSERT_EQ(list->size(), 4);
    EXPECT_EQ(list->at(0)->evaluate(), -5);
    EXPECT_EQ(list->at(1)->evaluate(), -3);
    EXPECT_EQ(list->at(2)->evaluate(), 0);
    EXPECT_EQ(list->at(3)->evaluate(), 4);
}
TEST(BubbleSortTest, BubbleTest) {
    Op* zero = new Op(-36);
    Op* three = new Op(26);
    Add* a1 = new Add(zero, three);
    Add* a2 = new Add(a1,three);
    
    ListContainer* list = new ListContainer();
    list->add_element(zero); 
    list->add_element(three); 
    list->add_element(a1); 
    list->add_element(a2);
    
    list->set_sort_function(new BubbleSort());
    list->sort();
    ASSERT_EQ(list->size(), 4);
    EXPECT_EQ(list->at(0)->evaluate(), -36);
    EXPECT_EQ(list->at(1)->evaluate(), -10);
    EXPECT_EQ(list->at(2)->evaluate(), 16);
    EXPECT_EQ(list->at(3)->evaluate(), 26);
}
    

#endif
