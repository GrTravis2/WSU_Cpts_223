
#include "list_test.hpp"

void list_test::run() {
    std::cout
    << "testInsertAtFront Pass: " << this->testInsertAtFront() << std::endl
    << "testFindNode Pass: " << this->testFindNode() << std::endl
    << "testDeleteNode Pass: " << this->testDeleteNode() << std::endl;
}

bool list_test::testInsertAtFront() {

    list<int> t;

    t.insertAtFront(3);
    t.print();
    t.insertAtFront(2);
    t.print();
    t.insertAtFront(1);
    t.print();

    return true;
}
bool list_test::testFindNode() {
    list<int> t;
    bool ok = false;

    t.insertAtFront(3);
    
    

    if (t.findNode(3) != nullptr) {

        t.insertAtFront(2);
        if (t.findNode(2) != nullptr) {

            t.insertAtFront(1);
            if (t.findNode(1) != nullptr) {

                if (t.findNode(4) == nullptr) { ok = true; }
            }
        }
    }

    return ok;
}
bool list_test::testDeleteNode() {

    list<int> t;
    bool ok = false;

    // delete should return false on empty list
    if (!t.deleteNode(0)) {
        t.insertAtFront(3);
        t.insertAtFront(2);
        t.insertAtFront(1);
    
        if (t.deleteNode(1)) {

            if (t.deleteNode(3)) {

                if (t.deleteNode(2)) { ok = true; }
            }
        }
    }

    return ok;
}