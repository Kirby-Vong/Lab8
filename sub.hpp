#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"

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
        virtual double evaluate() {
            return leftChild->evaluate() - rightChild->evaluate();
        }
        virtual std::string stringify() {
            str = leftChild->stringify() + " - " + rightChild->stringify();
            return str;
        }
};
#endif
