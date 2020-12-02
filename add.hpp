#ifndef _ADD_HPP__
#define _ADD_HPP__

#include "base.hpp"
#include <string>

using namespace std;

class add : public Base {
	public: 
		string str;
		Base* leftChild;
		Base* rightChild;
		add(Base* firstValue, Base* secondValue) {
			leftChild = firstValue;
			rightChild = secondValue;
		};

		virtual double evaluate() { return leftChild->evaluate() + rightChild->evaluate(); }
		virtual std::string stringify() {
			str = leftChild->stringify() + " + " + rightChild->stringify();
			return str;
		}
};

#endif
