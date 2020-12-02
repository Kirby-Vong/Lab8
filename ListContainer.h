#ifndef __LIST_CONTAINER_H__
#define __LIST_CONTAINER_H__

#include "container.hpp"
#include <iostream>
#include <list>
#include "sort.hpp"

class ListContainer : public Container {
    private:
        std::list<Base*> list;
    public:
        ListContainer();
        void add_element(Base* element);
        void print();
        void sort();
        void swap(int, int);
        Base* at(int);
        int size(); 

};
#endif
        
