#ifndef TEST_LIST_MY_JOSEPHUS
#define TEST_LIST_MY_JOSEPHUS

#include <assert.h>
#include <ctime>
#include <fstream>

#include "ListMyJosephus.hpp"


class TestListMyJosephus {
    private:
        // O_O!
    public:
        // run the full sim
        void runSimulation();

        // specific tests
        // from slides -> check every step matches ppt
        void testExample();
};

#endif