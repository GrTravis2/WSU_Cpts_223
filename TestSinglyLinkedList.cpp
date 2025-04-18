
#include "TestSinglyLinkedList.hpp"
#include "SinglyLinkedList.hpp"
#include <__config>
#include <cassert>

// run all tests
void TestSinglyLinkedList::runTests() {

    // chain all tests -> will crash if any test fails
    testInsertAtFront()
    .testFind()
    .testGetSize()
    .testInsertionSort()
    .testMergeSort();
}

// method tests set up for method chaining
TestSinglyLinkedList& TestSinglyLinkedList::testInsertAtFront() {
    SinglyLinkedList<int> t;
    int value = 0;

    // insert integers and validate that each insert successful
    for (int i = 1; i < 10; i++) {
        value = i * 2;
        t.insertAtFront(value);
        assert(t.front() == value);
    }

    return *this;
}

TestSinglyLinkedList& TestSinglyLinkedList::testFind() {
    SinglyLinkedList<int> t;

    for (int i = 0; i < 10; i++) {
        // check before and after inserting value
        assert(t.find(i) == nullptr);
        t.insertAtFront(i);
        assert(*t.find(i) == i);
    }

    return *this;
}

TestSinglyLinkedList& TestSinglyLinkedList::testGetSize() {
    SinglyLinkedList<int> t;

    int max = 10;
    for(int i = 0; i < max; i++) {
        assert(t.getSize() == i);
        t.insertAtFront(i);
    }

    assert(t.getSize() == max);

    return *this;
}

TestSinglyLinkedList& TestSinglyLinkedList::testPrint() {
    std::cout 
    << "** VISUAL TEST ONLY **" << std::endl
    << "** MAKE SURE OUTPUT MATCHES SEQUENCE **" << std::endl
    << "9,\n8,\n7,\n6,\n5,\n4,\n3,\n2,\n1,\n0\n";
    // -> 9 .. 0
    SinglyLinkedList<int> t;
    for(int i = 0; i < 10; i++) { t.insertAtFront(i); }
    t.print();

    return *this;
}


TestSinglyLinkedList& TestSinglyLinkedList::testInsertionSort() {

    // list has sequence -> 9 .. 0
    SinglyLinkedList<int> t;
    for(int i = 0; i < 10; i++) { t.insertAtFront(i); }

    std::cout
    << "** INSERTION SORT - VISUAL TEST ONLY **" << std::endl
    << "** MAKE SURE OUTPUT IN ASCENDING ORDER **" << std::endl;

    t.insertionSort(true);

    // list has sequence -> 9 .. 0
    SinglyLinkedList<int> t2;
    for(int i = 0; i < 10; i++) { t2.insertAtFront(i); }

    std::cout
    << "** INSERTION SORT - VISUAL TEST ONLY **" << std::endl
    << "** MAKE SURE OUTPUT IN DESCENDING ORDER **" << std::endl;

    t.insertionSort(false);

    return *this;
}

TestSinglyLinkedList& TestSinglyLinkedList::testMergeSort() {

    // list has sequence -> 9 .. 0
    SinglyLinkedList<int> t;
    for(int i = 0; i < 10; i++) { t.insertAtFront(i); }

    std::cout
    << "** MERGE SORT - VISUAL TEST ONLY **" << std::endl
    << "** MAKE SURE OUTPUT IN ASCENDING ORDER **" << std::endl;

    t.mergeSort(true);

    // list has sequence -> 9 .. 0
    SinglyLinkedList<int> t2;
    for(int i = 0; i < 10; i++) { t2.insertAtFront(i); }

    std::cout
    << "** MERGE SORT - VISUAL TEST ONLY **" << std::endl
    << "** MAKE SURE OUTPUT IN DESCENDING ORDER **" << std::endl;

    t.mergeSort(false);

    return *this;
}