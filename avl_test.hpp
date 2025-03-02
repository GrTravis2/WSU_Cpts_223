#ifndef AVL_TEST_H
#define AVL_TEST_H

#include "avl_map.hpp"

#define LEFT -1000
#define RIGHT 1000

class avl_test {

    private:
    // no data members

    // testing private methods
    void testIter();

    // testing public methods
    void testEmpty();
    void testInsert();
    void testErase();
    void testFind();
    void testEquals();

    public:
    void runTests();

};

#endif