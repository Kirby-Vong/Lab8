#ifndef __VECTOR_CONTAINER_H__
#define __VECTOR_CONTAINER_H__

#include "container.hpp"
#include <iostream>
#include <vector>

using namespace std;

class VectorContainer : public Container {
	private:
		vector<Base*> v;
	public:
		VectorContainer() {};
		void add_element(Base* element);
		void print();
		void sort();
		void swap(int, int);
		Base* at(int);
		int size();
};

#endif


