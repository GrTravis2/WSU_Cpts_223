#ifndef AVL_TEST_H
#define AVL_TEST_H

#include "avl_node.hpp"
#include "avl_map.hpp"

#define LEFT -1 * std::numeric_limits<int>::infinity() // for stepping iter left and right in testing
#define RIGHT std::numeric_limits<int>::infinity()

class avl_test {

    private:
    // no data members

    // testing private methods
    void testIter();
    void testGetMaxHeight();

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