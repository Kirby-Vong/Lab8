#include <iostream>
#include "iterator.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "rand.hpp"
#include "op.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "base.hpp"
#include "visitor.hpp"
#include "gtest/gtest.h"

using namespace std;

TEST(IteratorTesting, BinaryIteratorTest) {
    Op* op1 = new Op(3);
    Op* op2 = new Op(5);
    Op* op3 = new Op(2);
    Op* op4 = new Op(8);

    Add* a = new Add(op1, op2);
    Div* d = new Div(op4, op3);
    
    Sub* test = new Sub(a, d);

    BinaryIterator* bit = new BinaryIterator(test);
    
    for(bit->first(); !bit->is_done(); bit->next()) {
        cout << "Stringify: " <<  bit->current()->stringify() << endl;
        cout << "Evaluate: " << bit->current()->evaluate() << endl;
        cout << endl;
    }
}
TEST(IteratorTesting, BinaryIteratorMultPowTest) {
    Op* op1 = new Op(3);
    Op* op2 = new Op(6);
    Op* op3 = new Op(2);

    Mult* m = new Mult(op1, op2);
    Pow* p = new Pow(m, op3);

    Sub* test = new Sub(m, p);

    BinaryIterator* bit = new BinaryIterator(test);

    for(bit->first(); !bit->is_done(); bit->next()) {
        cout << "Stringify: " << bit->current()->stringify() << endl;
        cout << "Evaluate: " << bit->current()->evaluate() << endl;
        cout << endl;
    }
}
TEST(IteratorTesting, PreorderDummyVisitorTest) {
    Op* op1 = new Op(4);
    Op* op2 = new Op(3);
    Op* op3 = new Op(5);
    Op* op4 = new Op(9);

    Add* a = new Add(op1, op3);
    Div* d = new Div(op4, op2);

    Pow* p = new Pow(op1, op2);
    Mult* t = new Mult(a, d);
   
    Sub* dummy = new Sub(p ,t);
    CountVisitor* test = new CountVisitor();
    PreorderIterator* pit = new PreorderIterator(dummy);
    pit->first();
    while(!pit->is_done()) {
        pit->current()->accept(test);
        pit->next();
    }
    EXPECT_EQ(test->op_count(), 6);
    EXPECT_EQ(test->add_count(), 1);
    EXPECT_EQ(test->div_count(), 1);
    EXPECT_EQ(test->mult_count(), 1);
    EXPECT_EQ(test->pow_count(), 1);
    }
TEST(IteratorTesting, NullIteratorTest) {
    Op* op1 = new Op(4);
    Op* op2 = new Op(1);
    Op* op3 = new Op(6);
    

    NullIterator* nit = new NullIterator(op1);

    cout << "should be 0 cuz nullptr!!: " << nit->current() << endl;
}

