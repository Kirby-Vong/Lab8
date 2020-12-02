#ifndef _RAND_HPP_
#define _RAND_HPP_

#include <string>
#include "base.hpp"

#include "iterator.hpp"
#include "visitor.hpp"

#include <stdlib.h> //srand, rand
//This class is exactly the same as the Op class, but rather than being able to set its value, its value is set during
//construction by the the equation rand() % 100

class Rand : public Base {
    public:
    double v;
    Rand() {
        v = rand() % 100;
    }

	Base* get_left() {
		return nullptr;
	}
	Base* get_right() {
		return nullptr;
	}
	Iterator* create_iterator() {
		Iterator* iter = new NullIterator(this);
		return iter;
	}
    void accept(CountVisitor* vi) {
        vi->visit_rand();
    }

    virtual double evaluate() { return v; }
    virtual std::string stringify() { return std::to_string(v); }
};

#endif //__RAND_HPP__

