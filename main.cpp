
#include "TestListMyJosephus.hpp"
#include "TestVectorMyJosephus.hpp"

int main(void) {

    // quick tests -> will error if failing!
    TestListMyJosephus t;
    t.testExample();

    TestVectorMyJosephus t1;
    t1.testExample();

    //t.runSimulation();
    t1.runSimulation();


    return 0;
}