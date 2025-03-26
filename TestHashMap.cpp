
#include "TestHashMap.hpp"
#include <cassert>
#include <string>

// constructor
TestHashMap::TestHashMap() : HashMap<std::string, int>(31) {}

void TestHashMap::runTests() { // entry point for tests
    testSquareBracketOperator().testInsert().testFind().testContains().testPrint();
}

// ** INDIVIDUAL TESTS ** 
TestHashMap& TestHashMap::testSquareBracketOperator() {
    for (int i = 0; i < mSize; i++) { *mData[i].data = i; } // assign values to index

    int index = mHash("test") % mSize;
    int probing = 0;
    int adjustedIdx = 0;

    for (int i = 0; i < 10; i++) {
        // check pos is empty, insert, check not empty
        probing = index + pow(i, 2); // check next probing index
        adjustedIdx = (index + probing) % mSize;
        assert(mData[adjustedIdx].empty); 
        *(*this)["test"].data = -1;
        assert(!mData[adjustedIdx].empty && *(mData[adjustedIdx].data) == -1);
    }
    
    return *this;
}

TestHashMap& TestHashMap::testInsert() {
    int index = mHash("test") % mSize;
    int probing = 0;
    int adjustedIdx = 0;

    for (int i = 0; i < 10; i++) {
        // check pos is empty, insert, check not empty
        probing = index + pow(i, 2); // check next probing index
        adjustedIdx = (index + probing) % mSize;
        assert(mData[adjustedIdx].empty); 
        insert("test", -1);
        assert(
            !mData[adjustedIdx].empty 
            && *(mData[adjustedIdx].data) == -1
            && *(mData[adjustedIdx].key) == "test"
        );
    }

    return *this;
}

TestHashMap& TestHashMap::testFind() {
    std::string k;

    for(int i = 0; i < 15; i++) {
        k = std::to_string(i);

        // check before and after inserting unique key!
        assert(find(k) == nullptr);
        insert(k, i);
        assert(find(k) != nullptr);
    }

    return *this;
}

TestHashMap& TestHashMap::testContains() {
    std::string k = "";

    for(int i = 0; i < 15; i++) {
        k = std::to_string(i);

        // check before and after inserting unique key!
        assert(!contains(k));
        insert(k, i);
        assert(contains(k));
    }

    return *this;
}

TestHashMap& TestHashMap::testPrint() {
    for (int i = 0; i < mSize; i++) {
        *mData[i].data = i;
        if (i % 2 == 0) { mData[i].empty = false; }
    }

    std::cout 
    << "** VISUAL TEST ONLY **" << std::endl
    << "** MAKE SURE OUTPUT MATCHES SEQUENCE **" << std::endl
    << "ONLY EVEN NUMBERS 0, 2, .., 28, 30";

    print();

    return *this;
}