#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"
#include <string>

using namespace std;

class Div : public Base {
    public:
    string str;
    //Div() : Base(){ };
    Base* leftChild;
    Base* rightChild;
    Div(Base* left, Base* right){
        leftChild = left;
        rightChild = right;
    }

    virtual double evaluate() {
        if(rightChild->evaluate() == 0) return -1;
        return leftChild->evaluate() /  rightChild->evaluate();
    }
    virtual string stringify() {
        str = leftChild->stringify() + " / " + rightChild->stringify();
        return str;
    }
};

#endif //__DIV_HPP__
        
