#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

#include "iterator.hpp"

#include <string>

class Op : public Base {
    public:
        double v;
        Op(double value) : Base() {
            v = value;
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


        virtual double evaluate() { return v; }
        virtual std::string stringify() { return std::to_string(v); }
};

#endif //__OP_HPP__
