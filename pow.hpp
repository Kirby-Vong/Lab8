#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include <cmath>

#include "iterator.hpp"
#include "visitor.hpp"


class Pow : public Base {
    public:
        string str;
        double v = 1;
        double neg = -1;
        Base* leftChild;
        Base* rightChild;
        Pow(Base* left, Base* right) {
            leftChild = left;
            rightChild = right;
        }

		Base* get_left() {
			return leftChild;
		}
		Base* get_right() {
			return rightChild;
		}
		Iterator* create_iterator(){ 
			Iterator* iter = new BinaryIterator(this);
			return iter;
		}

        void accept(CountVisitor* vi) {
            vi->visit_pow();
        }
        virtual double evaluate() {
            if(rightChild->evaluate() == 0) {
                return 1;
            }
            if(rightChild->evaluate() < 0) {
                neg *= rightChild->evaluate();       
                for(int i = 0; i < neg; i++) {
                    v = v * leftChild->evaluate();
                }
                v = 1 / v;
            }
            else {
                for(int i = 0; i < rightChild->evaluate(); i++) {
                    v = v * leftChild->evaluate();
                }
            }
            return v;
        }
        
        virtual std::string stringify() {
            str = leftChild->stringify() + " ** " + rightChild->stringify();
            return str;
        }
};

#endif
