#ifndef __VISITOR_TEST_HPP__
#define __VISITOR_TEST_HPP__

#include <iostream>
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "container.hpp"
#include "rand.hpp"
#include "op.hpp"
#include "sort.hpp"
#include "ListContainer.h"
#include "VectorContainer.h"
#include "iterator.hpp"
#include "visitor.hpp"
#include "base.hpp"

using namespace std;

TEST(CountVisitorTest, SimpleTree) {
    Op* op1 = new Op(2);
    Op* op2 = new Op(3);
    Op* op3 = new Op(5);
    Op* op4 = new Op(4);
    Add* first = new Add(op1, op2);
    Mult* second = new Mult(op3, op4);

    Sub* dummy = new Sub(second, first);
    CountVisitor* test1 = new CountVisitor();
    PreorderIterator* test2 = new PreorderIterator(dummy);
    test2->first();
    while(!test2->is_done()) {
        test2->current()->accept(test1);
        test2->next();
    }
    EXPECT_EQ(test1->add_count(), 1);
    EXPECT_EQ(test1->mult_count(), 1);
    EXPECT_EQ(test1->op_count(), 4);
}

TEST(CountVisitorTest, MultTree) {
    Op* op1 = new Op(2);
    Op* op2 = new Op(3);
    Op* op3 = new Op(5);
    Op* op4 = new Op(4);
	Op*	op5 = new Op(6);
    Mult* first = new Mult(op1, op2);
    Mult* second = new Mult(op3, op4);
	Mult* third = new Mult(op1, op5);
	Mult* fourth = new Mult(first, second);

    Sub* dummy = new Sub(third, fourth);
    CountVisitor* test1 = new CountVisitor();
    PreorderIterator* test2 = new PreorderIterator(dummy);
    test2->first();
    while(!test2->is_done()) {
        test2->current()->accept(test1);
        test2->next();
    }
    EXPECT_EQ(test1->mult_count(), 4);
    EXPECT_EQ(test1->op_count(), 6);
}

TEST(CountVisitorTest, AddTree) {
    Op* op1 = new Op(2);
    Op* op2 = new Op(4);
    Op* op3 = new Op(6);
    Op* op4 = new Op(10);
    Op* op5 = new Op(23);
    Add* first = new Add(op1, op2);
    Add* second = new Add(op3, op4);
    Add* third = new Add(op1, op5);
    Add* fourth = new Add(first, second);

    Sub* dummy = new Sub(third, fourth);
    CountVisitor* test1 = new CountVisitor();
    PreorderIterator* test2 = new PreorderIterator(dummy);
    test2->first();
    while(!test2->is_done()) {
        test2->current()->accept(test1);
        test2->next();
    }
    EXPECT_EQ(test1->add_count(), 4);
    EXPECT_EQ(test1->op_count(), 6);
}

TEST(CountVisitorTest, SubTree) {
	Op* op1 = new Op(24);
	Op* op2 = new Op(15);
	Op* op3 = new Op(34);
	Op* op4 = new Op(23);
	Op* op5 = new Op(12);
	Op* op6 = new Op(2);
	Sub* first = new Sub(op1, op2);
	Sub* second = new Sub(op3, op4);
	Sub* third = new Sub(op5, op6);
	Sub* fourth = new Sub(first, second);
	
	Add* dummy = new Add(third, fourth);
	CountVisitor* test1 = new CountVisitor();
	PreorderIterator* test2 = new PreorderIterator(dummy);
	test2->first();
	while(!test2->is_done()){
		test2->current()->accept(test1);
		test2->next();
	}
	EXPECT_EQ(test1->sub_count(), 4);
	EXPECT_EQ(test1->op_count(), 6);

}

TEST(CountVisitorTest, DivTree) {
    Op* op1 = new Op(24);
    Op* op2 = new Op(12);
    Op* op3 = new Op(36);
    Op* op4 = new Op(18);
    Op* op5 = new Op(12);
    Op* op6 = new Op(2);
    Div* first = new Div(op1, op2);
    Div* second = new Div(op3, op4);
    Div* third = new Div(op5, op6);
    Div* fourth = new Div(first, second);

    Add* dummy = new Add(third, fourth);
    CountVisitor* test1 = new CountVisitor();
    PreorderIterator* test2 = new PreorderIterator(dummy);
    test2->first();
    while(!test2->is_done()){
        test2->current()->accept(test1);
        test2->next();
    }
    EXPECT_EQ(test1->div_count(), 4);
    EXPECT_EQ(test1->op_count(), 6);
}

TEST(CountVisitorTest, PowTree) {
    Op* op1 = new Op(1);
    Op* op2 = new Op(2);
    Op* op3 = new Op(3);
    Op* op4 = new Op(4);
    Op* op5 = new Op(5);
    Op* op6 = new Op(6);
    Pow* first = new Pow(op1, op2);
    Pow* second = new Pow(op3, op4);
    Pow* third = new Pow(op5, op6);
    Pow* fourth = new Pow(first, second);

    Add* dummy = new Add(third, fourth);
    CountVisitor* test1 = new CountVisitor();
    PreorderIterator* test2 = new PreorderIterator(dummy);
    test2->first();
    while(!test2->is_done()){
       test2->current()->accept(test1);
       test2->next();
    }
    EXPECT_EQ(test1->pow_count(), 4);
    EXPECT_EQ(test1->op_count(), 6);
}

TEST(CountVisitorTest, AdvancedTree) {
    Op* op1 = new Op(2);
    Op* op2 = new Op(3);
    Op* op3 = new Op(5);
    Op* op4 = new Op(4);
	Op* op5 = new Op(6);
	Op* op6 = new Op(12);
	Op* op7 = new Op(1);
	Op* op8 = new Op(7);
    Add* first = new Add(op1, op2);
	Add* second = new Add(op3, op4);
    Mult* third = new Mult(op5, op6);
	Div* fourth = new Div(op8, op7);
	Mult* fifth = new Mult(first, second);
	Pow* sixth = new Pow(third, fourth);

    Sub* dummy = new Sub(fifth, sixth);
    CountVisitor* test1 = new CountVisitor();
    PreorderIterator* test2 = new PreorderIterator(dummy);
    test2->first();
    while(!test2->is_done()) {
        test2->current()->accept(test1);
        test2->next();
    }
    EXPECT_EQ(test1->add_count(), 2);
    EXPECT_EQ(test1->mult_count(), 2);
	EXPECT_EQ(test1->div_count(), 1);
	EXPECT_EQ(test1->pow_count(), 1);
    EXPECT_EQ(test1->op_count(), 8);
}




TEST(CountVisitorTest, AdvancedTree2) {
    Op* op1 = new Op(1);
    Op* op2 = new Op(2);
    Op* op3 = new Op(12);
    Op* op4 = new Op(4);
    Op* op5 = new Op(5);
    Op* op6 = new Op(6);
    Op* op7 = new Op(8);
    Op* op8 = new Op(48);
    Pow* first = new Pow(op1, op2);
    Div* second = new Div(op3, op4);
    Mult* third = new Mult(op5, op6);
    Div* fourth = new Div(op8, op7);
    Mult* fifth = new Mult(first, second);
    Pow* sixth = new Pow(third, fourth);
 
    Sub* dummy = new Sub(fifth, sixth);
    CountVisitor* test1 = new CountVisitor();
    PreorderIterator* test2 = new PreorderIterator(dummy);
    test2->first();
    while(!test2->is_done()) {
        test2->current()->accept(test1);
        test2->next();
    }
    
    EXPECT_EQ(test1->mult_count(), 2);
    EXPECT_EQ(test1->div_count(), 2);
    EXPECT_EQ(test1->pow_count(), 2);
    EXPECT_EQ(test1->op_count(), 8);
}

TEST(CountVisitorTest, SuperAdvancedTree) {
    Op* op1 = new Op(1);
    Op* op2 = new Op(2);
    Op* op3 = new Op(12);
    Op* op4 = new Op(4);
    Op* op5 = new Op(5);
    Op* op6 = new Op(6);
    Op* op7 = new Op(8);
    Op* op8 = new Op(48);
	Op* op9 = new Op(7);
	Op* op10 = new Op(10);
	Op* op11 = new Op(3);
	Op* op12 = new Op(11);
    Pow* first = new Pow(op1, op2);
    Div* second = new Div(op3, op4);
    Mult* third = new Mult(op5, op6);
    Div* fourth = new Div(op8, op7);
	Add* fifth = new Add(op9, op10);
	Sub* sixth = new Sub(op12, op11);
    Mult* seventh = new Mult(first, second);
    Pow* eighth = new Pow(third, fourth);
	Add* ninth = new Add(seventh, eighth);
	Mult* tenth = new Mult(fifth, sixth);

    Sub* dummy = new Sub(ninth, tenth);
    CountVisitor* test1 = new CountVisitor();
    PreorderIterator* test2 = new PreorderIterator(dummy);
    test2->first();
    while(!test2->is_done()) {
        test2->current()->accept(test1);
        test2->next();
    }
	EXPECT_EQ(test1->add_count(), 2);
	EXPECT_EQ(test1->sub_count(), 1);
    EXPECT_EQ(test1->mult_count(), 3);
    EXPECT_EQ(test1->div_count(), 2);
    EXPECT_EQ(test1->pow_count(), 2);
    EXPECT_EQ(test1->op_count(), 12);
}

#endif
