#include <iostream>
#include "op.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "sub.hpp"
#include "add.hpp"
#include "ListContainer.h"
#include "BubbleSort.h"
#include "container.hpp"
#include "sort.hpp"
#include "ListContainer.cpp"
using namespace std;

int main() {
    ListContainer* list = new ListContainer();
    Op* seven = new Op(7);
    Op* eight = new Op(8);
    Op* nine = new Op(9);
    list->add_element(seven);
    list->add_element(eight);
    list->add_element(nine);
    cout << "Values in list: ";
    list->print();


    cout << "Swapping 7 and 9..." << endl;
    list->swap(0,2);

    cout << "Values in new list: ";
    list->print();

    cout << "Value at index 1: " << endl;
    double num = list->at(0)->evaluate();
    cout << num << endl;


return 0;
}
