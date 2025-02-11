

#include "TestListMyJosephus.hpp"

void TestListMyJosephus::runSimulation() {
    
}

// ppt example M = 2, N = 5
void TestListMyJosephus::testExample() {
    ListMyJosephus t(2, 5);
    // first step -> remove 2
    t.eliminateDestination();
    assert(!t.contains(2));

    // 2nd step -> remove 0
    t.eliminateDestination();
    assert(!t.contains(0));

    // 3rd step -> remove 4
    t.eliminateDestination();
    assert(!t.contains(4));

    // 4th step -> remove 1
    t.eliminateDestination();
    assert(!t.contains(1));

    // final -> one destination remaining -> should be 3
    assert(t.getCurrentSize() == 1 && t.contains(3));
}

