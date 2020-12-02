#ifndef __ZERO_OP_HPP__
#define __ZERO_OP_HPP__

#include "base.hpp"

class zero_op : Base {
    public: 
    SevenOpMock() { };

    virtual double evaluate() { return 0; }
    virtual string stringify() { return "0"; }
};


#endif
