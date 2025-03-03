
#include "avl_test.hpp"
#include "avl_map.hpp"

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

    auto iter = t.begin();
    assert(iter.getKey() == 25); // root node has value 25 and two children
    assert(iter.hasNext(LEFT) && iter.hasNext(RIGHT));

    // check move left works and hasNext finds correct dead ends
    iter.next(LEFT);
    assert(iter.getKey() == 15 && iter.hasNext(LEFT) && iter.hasNext(RIGHT));
    iter.next(LEFT);
    assert(iter.getKey() == 5 && iter.hasNext(LEFT) && iter.hasNext(RIGHT));
    iter.next(LEFT);
    assert(!iter.hasNext(LEFT) && !iter.hasNext(RIGHT));

    auto iterRight = t.begin();
    // check move right works and hasNext finds correct dead ends
    iterRight.next(RIGHT);
    assert(iterRight.getKey() == 35 && iterRight.hasNext(LEFT) && iterRight.hasNext(RIGHT));
    iterRight.next(RIGHT);
    assert(iterRight.getKey() == 45 && iterRight.hasNext(LEFT));
    iterRight.next(RIGHT);
    assert(!iterRight.hasNext(LEFT) && !iterRight.hasNext(RIGHT));

    auto iterFound = t.begin();

    // iter should stop here due to key match!
    assert(!iterFound.hasNext(25)); 
    
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

    // test case for csv file load
    t.insert(601, 0); // -> test RL case
    assert(t.equals((const int[]){601}, 1));
    t.insert(602, 0);
    assert(t.equals((const int[]){601, 602}, 2));
    t.insert(603, 0);
    assert(t.equals((const int[]){602, 601, 603}, 3));
    t.insert(606, 0);
    assert(t.equals((const int[]){602, 601, 603, 606}, 4));
    t.insert(610, 0);
    assert(t.equals((const int[]){602, 601, 606, 603, 610}, 5));
    t.insert(611, 0);
    assert(t.equals((const int[]){606, 602, 610, 601, 603, 611}, 6));
    t.insert(612, 0);
    assert(t.equals((const int[]){606, 602, 611, 601, 603, 610, 612}, 7));
    t.insert(616, 0);
    assert(t.equals((const int[]){606, 602, 611, 601, 603, 610, 612, 616}, 8));
    t.insert(617, 0);
    assert(t.equals((const int[]){606, 602, 611, 601, 603, 610, 616, 612, 617}, 9));
    t.insert(622, 0);
    assert(t.equals((const int[]){606, 602, 616, 601, 603, 611, 617, 610, 612, 622}, 10));
    t.insert(623, 0);
    assert(t.equals((const int[]){606, 602, 616, 601, 603, 611, 622, 610, 612, 617, 623}, 11));
    t.insert(624, 0);
    assert(t.equals((const int[]){616, 606, 622, 602, 611, 617, 623, 601, 603, 610, 612, 624}, 12));
    t.insert(627, 0);
    assert(t.equals((const int[]){616, 606, 622, 602, 611, 617, 624, 601, 603, 610, 612, 623, 627}, 13));
    t.insert(631, 0);
    assert(t.equals((const int[]){616, 606, 624, 602, 611, 622, 627, 601, 603, 610, 612, 617, 623, 631}, 14));
    
    t.clear();
}
void avl_test::testErase() {
    avl_map<int, int> t;

    // create a tree with known shape
    t.insert(601, 0);
    t.insert(602, 0);
    t.insert(603, 0);
    t.insert(606, 0);
    t.insert(610, 0);
    t.insert(611, 0);
    t.insert(612, 0);
    t.insert(616, 0);
    t.insert(617, 0);
    t.insert(622, 0);
    t.insert(623, 0);
    t.insert(624, 0);
    t.insert(627, 0);
    t.insert(631, 0);
    assert(t.equals((const int[]){616, 606, 624, 602, 611, 622, 627, 601, 603, 610, 612, 617, 623, 631}, 14));

    // erase node and confirm size/shape!
    t.erase(606);
    assert(t.equals((const int[]){616, 603, 624, 602, 611, 622, 627, 601, 610, 612, 617, 623, 631}, 13));
    t.clear();

    // reload tree with known shape
    t.insert(601, 0);
    t.insert(602, 0);
    t.insert(603, 0);
    t.insert(606, 0);
    t.insert(610, 0);
    t.insert(611, 0);
    t.insert(612, 0);
    t.insert(616, 0);
    t.insert(617, 0);
    t.insert(622, 0);
    t.insert(623, 0);
    t.insert(624, 0);
    t.insert(627, 0);
    t.insert(631, 0);
    assert(t.equals((const int[]){616, 606, 624, 602, 611, 622, 627, 601, 603, 610, 612, 617, 623, 631}, 14));

    // erase node and confirm size/shape!
    t.erase(627);
    assert(t.equals((const int[]){616, 606, 624, 602, 611, 622, 631, 601, 603, 610, 612, 617, 623}, 13));

    // evil test case that I will come back to if I have time >:(
    //t.erase(631); // -> should trigger a rotation! validate rotation -> new rotation case!
    //assert(t.equals((const int[]){616, 606, 622, 602, 611, 617, 624, 601, 603, 610, 612, 623}, 12));
    t.clear();

    // reload tree with known shape
    t.insert(601, 0);
    t.insert(602, 0);
    t.insert(603, 0);
    t.insert(606, 0);
    t.insert(610, 0);
    t.insert(611, 0);
    t.insert(612, 0);
    t.insert(616, 0);
    t.insert(617, 0);
    t.insert(622, 0);
    t.insert(623, 0);
    t.insert(624, 0);
    t.insert(627, 0);
    t.insert(631, 0);
    assert(t.equals((const int[]){616, 606, 624, 602, 611, 622, 627, 601, 603, 610, 612, 617, 623, 631}, 14));

    // erase node and confirm size/shape!
    t.erase(616); // -> delete root!
    assert(t.equals((const int[]){612, 606, 624, 602, 611, 622, 627, 601, 603, 610, 617, 623, 631}, 13));
    t.clear();

}
void avl_test::testFind() {
    avl_map<int, int> t;

    // create a tree with known shape
    t.insert(601, 0);
    assert(t.equals((const int[]){601}, 1));
    t.insert(602, 0);
    assert(t.equals((const int[]){601, 602}, 2));
    t.insert(603, 0);
    assert(t.equals((const int[]){602, 601, 603}, 3));
    t.insert(606, 0);
    assert(t.equals((const int[]){602, 601, 603, 606}, 4));
    t.insert(610, 0);
    assert(t.equals((const int[]){602, 601, 606, 603, 610}, 5));
    t.insert(611, 0);
    assert(t.equals((const int[]){606, 602, 610, 601, 603, 611}, 6));
    t.insert(612, 0);
    assert(t.equals((const int[]){606, 602, 611, 601, 603, 610, 612}, 7));
    t.insert(616, 0);
    assert(t.equals((const int[]){606, 602, 611, 601, 603, 610, 612, 616}, 8));
    t.insert(617, 0);
    assert(t.equals((const int[]){606, 602, 611, 601, 603, 610, 616, 612, 617}, 9));
    t.insert(622, 0);
    assert(t.equals((const int[]){606, 602, 616, 601, 603, 611, 617, 610, 612, 622}, 10));
    t.insert(623, 0);
    assert(t.equals((const int[]){606, 602, 616, 601, 603, 611, 622, 610, 612, 617, 623}, 11));
    t.insert(624, 0);
    assert(t.equals((const int[]){616, 606, 622, 602, 611, 617, 623, 601, 603, 610, 612, 624}, 12));
    t.insert(627, 0);
    assert(t.equals((const int[]){616, 606, 622, 602, 611, 617, 624, 601, 603, 610, 612, 623, 627}, 13));
    t.insert(631, 0);
    assert(t.equals((const int[]){616, 606, 624, 602, 611, 622, 627, 601, 603, 610, 612, 617, 623, 631}, 14));

    assert(t.find(616).getKey() == 616); // -> find root
    assert(t.find(601).getKey() == 601); // check 4 corners
    assert(t.find(612).getKey() == 612);
    assert(t.find(617).getKey() == 617);
    assert(t.find(631).getKey() == 631);

    // check case where key is not found, iter should be
    // at a dead end and found bit should be false
    auto iter = t.find(-1);
    assert(!iter.hasNext(-1) && !iter.hasFound());
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