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
        cout << "Evavluate: " << bit->current()->evaluate() << endl;
        cout << endl;
    }
}
TEST(IteratorTesting, NullIteratorTest) {
    Op* op1 = new Op(4);
    Op* op2 = new Op(1);
    Op* op3 = new Op(6);
    

    NullIterator* nit = new NullIterator(op1);

    cout << "should be 0 cuz nullptr!!: " << nit->current() << endl;
}

