#ifndef __NEGATIVE_OP__
#define __NEGATIVE_OP__

#include "base.hpp"

class NegativeOp : public Base {
	public:
		NegativeOp() { };

		virtual double evaluate() { return -7.5; }
		virtual string stringify() { return "-7.5"; )
}

#endif
