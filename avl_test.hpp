

#include "avl_map.hpp"

class avl_test {

    private:
    // no data members

    // testing private methods
    void testNext();
    void testHasNext();
    void testGetMaxHeight();
    void testBalance();
    void testRotate();

    // testing public methods
    void testEmpty();
    void testInsert();
    void testErase();
    void testFind();

    public:
    void runTests();

};