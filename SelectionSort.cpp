#include "SelectionSort.h"
#include "sort.hpp"

#include <iostream>
#include <vector>

using namespace std;

SelectionSort::SelectionSort() {}

void SelectionSort::sort(Container* c) {
	int i, j, min_index;
	for(i = c->size() - 1; i > 0; i--) {
		min_index = 0;
		for(j = 1; j <= i; j++) {
			if(c->at(j)->evaluate() > c->at(min_index)->evaluate()) {
				min_index = j;
			}
		}
		c->swap(i, min_index);
	}
}
