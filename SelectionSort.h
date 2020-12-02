#ifndef __SELECTION_SORT_H__
#define __SELECTION_SORT_H__

#include "sort.hpp"
#include "container.hpp"
using namespace std;

class SelectionSort : public Sort {
	public:
		SelectionSort();
		void sort(Container* c);
};

#endif
