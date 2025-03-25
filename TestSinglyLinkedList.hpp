#ifndef TEST_SINGLY_LINKED_LIST_H
#define TEST_SINGLY_LINKED_LIST_H

#include <assert.h>

#include "SinglyLinkedList.hpp"

class TestSinglyLinkedList {

    private:
        // no data members needed

        // method tests set up for method chaining
        TestSinglyLinkedList& testInsertAtFront();
        TestSinglyLinkedList& testFind();
        TestSinglyLinkedList& testGetSize();
        TestSinglyLinkedList& testPrint();


    public:
        // run all tests
        void runTests();

};

#endif