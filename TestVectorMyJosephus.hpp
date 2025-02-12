#ifndef TEST_VECTOR_MY_JOSEPHUS
#define TEST_VECTOR_MY_JOSEPHUS

#include <assert.h>

#include "VectorMyJosephus.hpp"

#define MAX_N 1025

class TestVectorMyJosephus {
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