#include "ListContainer.h"

ListContainer::ListContainer() {};

void ListContainer::add_element(Base* element) {
    list.push_back(element);
}

void ListContainer::print() {
    for(auto i : list) {
        std::cout << (i)->evaluate() << " ";
    }
    std::cout << std::endl;
}

void ListContainer::sort() {
    sort_function->sort(this);
}

void ListContainer::swap(int i, int j) {
    std::list<Base*>::iterator it1 = list.begin();
    std::advance(it1, i);
    std::list<Base*>::iterator it2 = list.begin();
    std::advance(it2, j);

    std::swap(*it1, *it2);
}

Base* ListContainer::at(int i) {
    std::list<Base*>::iterator it = list.begin();
    std::advance(it, i);
    return *it;
}

int ListContainer::size() {
    return list.size();   
}

