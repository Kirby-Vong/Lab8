#ifndef __MULT_HPP__
#define __MULT_HPP__


#include "base.hpp"
#include <string>

#include "iterator.hpp"
#include "visitor.hpp"

using namespace std;

class Mult : public Base {
	public:
		string str;
		Base* left;
		Base* right;
		Mult(Base* firstValue, Base* secondValue) {
			left = firstValue;
			right = secondValue;
		}
		
		Base* get_left() {
			return left;
		}
		Base* get_right() {
			return right;
		}
		Iterator* create_iterator() {
			Iterator* iter = new BinaryIterator(this);
			return iter;
		}
		virtual double evaluate() {
			return left->evaluate() * right->evaluate(); 
		}
		virtual string stringify() {
			str = left->stringify() + " * " + right->stringify();
			return str;
		}
        void accept(CountVisitor* vi) {
            vi->visit_mult();
        }
};

#endif
