#ifndef TEST_HASH_MAP_H
#define TEST_HASH_MAP_H

#include <string>

#include "HashMap.hpp"

class TestHashMap : public HashMap<std::string, int> {

    private:
        // no data members

        // ** INDIVIDUAL TESTS ** 
        TestHashMap& testSquareBracketOperator();

        TestHashMap& testInsert();
        TestHashMap& testFind();
        TestHashMap& testContains();
        TestHashMap& testPrint();
        


    public:
        // constructor
        TestHashMap();

        void runTests(); // entry point for tests

};

#endif