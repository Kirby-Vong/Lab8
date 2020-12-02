#ifndef _ADD_HPP__
#define _ADD_HPP__

#include "base.hpp"
#include <string>

using namespace std;

class Add : public Base {
	public: 
		string str;
		Base* leftChild;
		Base* rightChild;
		Add(Base* firstValue, Base* secondValue) {
			leftChild = firstValue;
			rightChild = secondValue;
		};
		Base* get_left() {
			return leftChild;
		}
		Base* get_right() {
			return rightChild;
		}
		Iterator* create_iterator() {
			Iterator* iter = new BinaryIterator(this);
			return iter;
		}
		virtual double evaluate() { return leftChild->evaluate() + rightChild->evaluate(); }
		virtual std::string stringify() {
			str = leftChild->stringify() + " + " + rightChild->stringify();
			return str;
		}

};

#endif
