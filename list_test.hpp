#ifndef LIST_TEST_HPP
#define LIST_TEST_HPP

#include <iostream>

#include "list.hpp"

class list_test {
    private:
        bool testInsertAtFront();
        bool testFindNode();
        bool testDeleteNode();

    public:
        void run();

};

#endif