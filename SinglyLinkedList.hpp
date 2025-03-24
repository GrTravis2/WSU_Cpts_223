#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <iostream>
#include <assert.h>

// ** linked list node class **

template <class T>
class ListNode {

    private:
        T mData;
        ListNode* mpNext;

    public:

        // constructor
        ListNode(const T& data);

        // destructor
        ~ListNode();

        // getters
        T& getData() const;
        ListNode* getNextPtr();

        // setters
        ListNode& setData(const T& data);
        ListNode& setNextPtr(const ListNode& nextPtr);

        // public methods
        // nothing for now!

};

// constructor
template <class T>
ListNode<T>::ListNode(const T& data) {
    mData = data;
    mpNext = nullptr;
}

// destructor
template <class T>
ListNode<T>::~ListNode() {
    // do nothing, list will handle memory
}

// getters
template <class T>
T& ListNode<T>::getData() const {
    return mData;
}

template <class T>
ListNode<T>* ListNode<T>::getNextPtr() {
    return mpNext;
}

// setters

template <class T>
ListNode<T>& ListNode<T>::setData(const T& data) {
    mData = data;

    return *this; // return self for method chaining
}

template <class T>
ListNode<T>& ListNode<T>::setNextPtr(const ListNode& nextPtr) {
    mpNext = nextPtr;

    return *this; // return self for method chaining 
}

// ** singly linked list class **

template <class T>
class SinglyLinkedList {

    private:
        ListNode<T>* mpHead;
        int mSize;

        // private methods
        void deleteList(ListNode<T>* pNode);


    public:

        // constructor
        SinglyLinkedList();

        // destructor
        ~SinglyLinkedList();

        // getters
        int getSize() const;

        // setters

        // public methods
        void insertAtFront(const T& data); // -> allocate and insert new node containing data
        ListNode<T>* find(const T& data); // -> return ptr to node matching data
        void print(); // -> print all data in list to console


};

// constructor
template <class T>
SinglyLinkedList<T>::SinglyLinkedList() {
    mpHead = nullptr, mSize = 0;
}

// destructor
template <class T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    this->deleteList(mpHead);
}

// getters

template <class T>
int SinglyLinkedList<T>::getSize() const {
    return mSize;
}

// setters

// public methods
template <class T>
void SinglyLinkedList<T>::insertAtFront(const T& data) { // -> allocate and insert new node containing data

    // create new node and check for succesful allocation
    ListNode<T>* pNew = new ListNode<T>(data); 
    assert(pNew != nullptr);

    if (mpHead == nullptr) { // insert at root if empty tree
        mpHead = pNew;
        mSize++;
    } else { // insert and shift nodes
        pNew->setNextPtr(mpHead);
        mpHead = pNew;
        mSize++;
    }
}

// return ptr to node matching data or nullptr if not found, requires operator!=
template <class T>
ListNode<T>* SinglyLinkedList<T>::find(const T& data) { 

    ListNode<T>* pNode = mpHead; // traverse list until end or value found
    while (pNode != nullptr && pNode->getData() != data) { pNode = pNode->getNextPtr(); }

    return pNode;
}

// print all data in list to console, requires overloaded operator<<
template <class T>
void SinglyLinkedList<T>::print() { 

    ListNode<T>* pNode = mpHead; // traverse list until end, print to console
    while (pNode != nullptr) { std::cout << pNode->getData() << ",\n";}
}

// private methods
template <class T>
void SinglyLinkedList<T>::deleteList(ListNode<T>* pNode) {
    if (pNode != nullptr) {
        deleteList(pNode->getNextPtr());
        delete pNode->getNextPtr();
    }
}


#endif