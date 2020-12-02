#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"

#include "iterator.hpp"
#include "visitor.hpp"


class Sub : public Base {
    public:
        string str;
        Sub() { };
        Base* leftChild;
        Base* rightChild;
        Sub(Base* left, Base* right) {
            leftChild = left;
            rightChild = right;
        }

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
            vi->visit_sub();
        }

        virtual double evaluate() {
            return leftChild->evaluate() - rightChild->evaluate();
        }
        virtual std::string stringify() {
            str = leftChild->stringify() + " - " + rightChild->stringify();
            return str;
        }
};
#endif
