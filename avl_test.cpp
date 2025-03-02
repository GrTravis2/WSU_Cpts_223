
#include "avl_test.hpp"

// run all tests
void avl_test::runTests() {

    // testing public methods
    testEquals();
    testEmpty();
    testInsert();
    testErase();
    testFind();

    // testing private methods
    testIter();
}

// testing private methods
void avl_test::testIter() {
    avl_map<int, int> t;
    auto iter = t.begin();
    assert(iter.getKey() == 25); // root node has value 25 and two children
    assert(iter.hasNext(LEFT) && iter.hasNext(RIGHT));

    t.insert(25, 0); // set up tree for traversal
    assert(t.equals((const int[]){25}, 1));
    t.insert(15, 0);
    assert(t.equals((const int[]){25, 15}, 2));
    t.insert(35, 0);
    assert(t.equals((const int[]){25, 15, 35}, 3));
    t.insert(5, 0);
    assert(t.equals((const int[]){25, 15, 35, 5}, 4));
    t.insert(45, 0);
    assert(t.equals((const int[]){25, 15, 35, 5, 45}, 5));

    // check move left works and hasNext finds correct dead ends
    iter.next(LEFT);
    assert(iter.getKey() == 15 && iter.hasNext(LEFT) && !iter.hasNext(RIGHT));
    iter.next(LEFT);
    assert(iter.getKey() == 5 && !iter.hasNext(LEFT) && !iter.hasNext(RIGHT));

    auto iterRight = t.begin();
    // check move right works and hasNext finds correct dead ends
    iterRight.next(RIGHT);
    assert(iterRight.getKey() == 35 && !iterRight.hasNext(LEFT) && iterRight.hasNext(RIGHT));
    iterRight.next(RIGHT);
    assert(iterRight.getKey() == 45 && !iterRight.hasNext(LEFT) && !iterRight.hasNext(RIGHT));

    auto iterFound = t.begin();

    // iter should stop here due to key match!
    assert(!iterFound.hasNext(25)); 
    
}

void avl_test::testGetMaxHeight() {

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
    
    // test rotations about the root
    t.insert(0, 0); // -> test LL case
    assert(t.equals((const int[]){0}, 1));
    t.insert(-1, 0);
    assert(t.equals((const int[]){0, -1}, 2));
    t.insert(-2, 0);
    assert(t.equals((const int[]){-1, -2, 0}, 3));
    t.clear();

    t.insert(0, 0); // -> test RR case
    assert(t.equals((const int[]){0}, 1));
    t.insert(1, 0);
    assert(t.equals((const int[]){0, 1}, 2));
    t.insert(2, 0);
    assert(t.equals((const int[]){1, 0, 2}, 3));
    t.clear();

    t.insert(2, 0); // -> test LR case
    assert(t.equals((const int[]){2}, 1));
    t.insert(0, 0);
    assert(t.equals((const int[]){2, 0}, 2));
    t.insert(1, 0);
    assert(t.equals((const int[]){1, 0, 2}, 3));
    t.clear();

    t.insert(1, 0); // -> test RL case
    assert(t.equals((const int[]){1}, 1));
    t.insert(3, 0);
    assert(t.equals((const int[]){1, 3}, 2));
    t.insert(2, 0);
    assert(t.equals((const int[]){2, 1, 3}, 3));
    t.clear();

    // test rotations in a subtree
    t.insert(25, 0); // -> test LL case
    assert(t.equals((const int[]){25}, 1));
    t.insert(15, 0);
    assert(t.equals((const int[]){25, 15}, 2));
    t.insert(35, 0);
    assert(t.equals((const int[]){25, 15, 35}, 3));
    t.insert(5, 0);
    assert(t.equals((const int[]){25, 15, 35, 5}, 4));
    t.insert(45, 0);
    assert(t.equals((const int[]){25, 15, 35, 5, 45}, 5));
    t.insert(4, 0);
    assert(t.equals((const int[]){25, 5, 35, 4, 15, 45}, 6));
    t.clear();

    t.insert(25, 0); // -> test RR case
    assert(t.equals((const int[]){25}, 1));
    t.insert(15, 0);
    assert(t.equals((const int[]){25, 15}, 2));
    t.insert(35, 0);
    assert(t.equals((const int[]){25, 15, 35}, 3));
    t.insert(5, 0);
    assert(t.equals((const int[]){25, 15, 35, 5}, 4));
    t.insert(45, 0);
    assert(t.equals((const int[]){25, 15, 35, 5, 45}, 5));
    t.insert(46, 0);
    assert(t.equals((const int[]){25, 15, 45, 5, 35, 46}, 6));
    t.clear();

    t.insert(25, 0); // -> test LR case
    assert(t.equals((const int[]){25}, 1));
    t.insert(15, 0);
    assert(t.equals((const int[]){25, 15}, 2));
    t.insert(35, 0);
    assert(t.equals((const int[]){25, 15, 35}, 3));
    t.insert(5, 0);
    assert(t.equals((const int[]){25, 15, 35, 5}, 4));
    t.insert(45, 0);
    assert(t.equals((const int[]){25, 15, 35, 5, 45}, 5));
    t.insert(6, 0);
    assert(t.equals((const int[]){25, 6, 35, 5, 15, 45}, 6));
    t.clear();

    t.insert(25, 0); // -> test RL case
    assert(t.equals((const int[]){25}, 1));
    t.insert(15, 0);
    assert(t.equals((const int[]){25, 15}, 2));
    t.insert(35, 0);
    assert(t.equals((const int[]){25, 15, 35}, 3));
    t.insert(5, 0);
    assert(t.equals((const int[]){25, 15, 35, 5}, 4));
    t.insert(45, 0);
    assert(t.equals((const int[]){25, 15, 35, 5, 45}, 5));
    t.insert(44, 0);
    assert(t.equals((const int[]){25, 15, 44, 5, 35, 45}, 6));
    t.clear();
}
void avl_test::testErase() {

}
void avl_test::testFind() {

}

void avl_test::testEquals() {
    avl_map<int, int> t;

    t.insert(10, 0); // match tree
    t.insert(5, 0);
    t.insert(15, 0);
    t.insert(4, 0);
    t.insert(6, 0);
    t.insert(13, 0);
    t.insert(16, 0);
    t.insert(3, 0);
    t.insert(14, 0);
    t.insert(17, 0);
    assert(t.equals((const int[]){
        10, 
        5, 
        15,
        4,
        6,
        13,
        16,
        3,
        14,
        17
    }, 10));
}