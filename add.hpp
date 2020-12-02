#ifndef _ADD_HPP__
#define _ADD_HPP__

#include "base.hpp"
#include <string>
#include "iterator.hpp"
#include "visitor.hpp"

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
        void accept(CountVisitor* vi) {
            vi->visit_add();
        }
		virtual double evaluate() { return leftChild->evaluate() + rightChild->evaluate(); }
		virtual std::string stringify() {
			str = leftChild->stringify() + " + " + rightChild->stringify();
			return str;
		}


};

#endif
