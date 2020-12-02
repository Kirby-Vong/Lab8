#ifndef __MULT_HPP__
#define __MULT_HPP__


#include "base.hpp"
#include <string>

using namespace std;

class mult : public Base {
	public:
		string str;
		Base* left;
		Base* right;
		mult(Base* firstValue, Base* secondValue) {
			left = firstValue;
			right = secondValue;
		}

		virtual double evaluate() {
			return left->evaluate() * right->evaluate(); 
		}
		virtual string stringify() {
			str = left->stringify() + " * " + right->stringify();
			return str;
		}
};

#endif
