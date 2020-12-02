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

#endif
