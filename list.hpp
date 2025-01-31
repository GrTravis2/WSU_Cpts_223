#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

#include "node.hpp"

template <class T>
class list {
    protected:
        node<T>* mpHead;
    private:
        void deleteList(node<T>* pNode);

    public:

        // constructor
        list();

        // destructor
        ~list();

        // methods

        // true if data inserted successfully
        bool insertAtFront(const T& newData);

        // returns nullptr if not found
        node<T>* findNode(const T& data);

        // search by key value of data
        // req overloaded 
        // returns true if data was found and deleted
        bool deleteNode(const T& data);

        // print list data
        void print();

};

// constructor
template <class T>
list<T>::list() {
    this->mpHead = nullptr;
}

// destructor
template <class T>
list<T>::~list() {
    this->deleteList(this->mpHead);
}

template <class T>
void list<T>::deleteList(node<T>* pNode) {
    if (pNode != nullptr) {
        this->deleteList(pNode->getNextPtr());
        delete pNode;
    }
}

// methods

// allocates new node on the heap and inserts in list
// -> true if data inserted successfully
template <class T>
bool list<T>::insertAtFront(const T& newData) {
    bool ok = false;

    node<T>* pNew = new node<T>(newData);

    // check if memory allocated successfully
    if (pNew != nullptr) {

        if (this->mpHead == nullptr) {
            // list is empty, head ptr now points to new node
            this->mpHead = pNew;
        } else {
            // list is not empty, new node points to old head node
            // new node becomes new head node
            pNew->setNextPtr(this->mpHead);
            this->mpHead = pNew;
        }

        ok = true;

    }

    return ok;
}

// -> returns nullptr if not found
template <class T>
node<T>* list<T>::findNode(const T& data) {
    node<T>* pCurrent = this->mpHead;

    while (pCurrent != nullptr && pCurrent->getData() != data) {
        pCurrent = pCurrent->getNextPtr(); 
    }

    return pCurrent;
}

// -> returns true if data was found and deleted
template <class T>
bool list<T>::deleteNode(const T& data) {
    node<T>* pCurrent = this->mpHead;
    node<T>* pPrev = nullptr;
    bool ok = false;

    while (pCurrent != nullptr && pCurrent->getData() != data) {
        pPrev = pCurrent;
        pCurrent = pCurrent->getNextPtr();

    }

    if (pCurrent != nullptr) { // data was found

        // case: data found in first node
        if (pPrev == nullptr) {
            // 2nd node becomes new head
            this->mpHead = pCurrent->getNextPtr();
            // remove pCurrent which will be head node
        } else {
            // previous node points to next node
            pPrev->setNextPtr(pCurrent->getNextPtr());
        }
        // delete the node with the found data
        delete pCurrent;
        ok = true;
    }

    return ok;
}

// print list data
template <class T>
void list<T>::print() {
    node<T>* pCurrent = this->mpHead;

    while (pCurrent != nullptr) {
        std::cout << pCurrent->getData() << std::endl;
        pCurrent = pCurrent->getNextPtr();
    }
}

#endif