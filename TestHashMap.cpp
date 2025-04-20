
#include "TestHashMap.hpp"
#include <assert.h>
#include <string>

// constructor
TestHashMap::TestHashMap() : HashMap<std::string, int>(31) {}

void TestHashMap::runTests() { // entry point for tests
    testSquareBracketOperator().testInsert().testFind().testContains().testPrint();
}

// ** INDIVIDUAL TESTS ** 
TestHashMap& TestHashMap::testSquareBracketOperator() {
    for (int i = 0; i < mSize; i++) { mData[i].data = i; } // assign values to index
    unsigned int base = mHash("test");
    unsigned int probing, adjustedIdx = 0;

    for (int i = 0; i < 10; i++) {
        // check pos is empty, insert, check not empty
        probing = (i * i); // check next probing index
        adjustedIdx = (base + probing) % mSize;
        assert(mData[adjustedIdx].empty);
        (*this)["test"].data = probing;
        (*this)["test"].empty = false;
        assert(!mData[adjustedIdx].empty);
        assert((mData[adjustedIdx].data) == probing);
    }
    
    return *this;
}

TestHashMap& TestHashMap::testInsert() {
    // reset data!
    for(int i = 0; i < mSize; i++) { mData[i].empty = true; }
    
    unsigned int base = mHash("test"); // init variables
    int probing = 0;
    int adjustedIdx = 0;

    for (int i = 0; i < 10; i++) {
        probing = (i * i); // check next probing index
        adjustedIdx = (base + probing) % mSize;
        assert(mData[adjustedIdx].empty);
        insert("test", -1);
        assert(
            !mData[adjustedIdx].empty 
            && (mData[adjustedIdx].data) == -1
            && (mData[adjustedIdx].key) == "test"
        );
        mData[adjustedIdx].key = ""; // write over for next insert
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
    for(int i = 0; i < mSize; i++) { // reset data
        mData[i].key = "";
        mData[i].empty = true;
    }

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

    // flip half of the cells to not empty, print all **empty** cells to test
    for (int i = 0; i < mSize; i++) {
        mData[i].key = "key",
        mData[i].data = i;
        mData[i].empty = (i % 2 == 0) ? false : true;
    }

    std::cout 
    << "** VISUAL TEST ONLY **" << std::endl
    << "** MAKE SURE OUTPUT MATCHES SEQUENCE **" << std::endl
    << "ONLY EVEN NUMBERS 0, 2, .., 28, 30" << std::endl;

    print();

    return *this;
}