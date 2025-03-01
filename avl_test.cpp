
#include "avl_test.hpp"

// run all tests
void avl_test::runTests() {

    // testing public methods
    testEmpty();
    testInsert();
    /*testErase();
    testFind();

    // testing private methods
    testNext();
    testHasNext();
    testGetMaxHeight();
    testBalance();
    testRotate();

    */

}

// testing private methods
void avl_test::testNext() {

}
void avl_test::testHasNext() {

}
void avl_test::testGetMaxHeight() {

}
void avl_test::testBalance() {

}
void avl_test::testRotate() {

}

// testing public methods
void avl_test::testEmpty() {
    avl_map<int, int> t;

    assert(t.empty());

    t.insert(0, 0);
    assert(!t.empty());
}

void avl_test::testInsert() {
    avl_map<int, int> t;
    
    t.insert(0, 0);
    int keys[] = {0};
    assert(t.equals(keys, sizeof(keys) / sizeof(keys[0])));

    t.insert(-1, 0);
    int keys[] = {0, -1};
    assert(t.equals(keys, sizeof(keys) / sizeof(keys[0])));

    t.insert(-2, 0);
    int keys[] = {-1, -2, 0};
    assert(t.equals(keys, sizeof(keys) / sizeof(keys[0])));

}
void avl_test::testErase() {

}
void avl_test::testFind() {

}