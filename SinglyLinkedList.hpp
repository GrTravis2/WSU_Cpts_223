#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <cmath>
#include <iostream>
#include <assert.h>
#include <cmath>

// ** linked list node class **

template <class T>
class ListNode {

    private:
        T mData;
        ListNode* mpNext;

    public:

        // constructor
        ListNode(T& data);

        // destructor
        ~ListNode();

        // getters
        T& getData();
        ListNode* getNextPtr();

        // setters
        ListNode& setData(const T& data);
        ListNode& setNextPtr(ListNode* nextPtr);

        // public methods
        // nothing for now!

};

// constructor
template <class T>
ListNode<T>::ListNode(T& data) {
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
T& ListNode<T>::getData() {
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
ListNode<T>& ListNode<T>::setNextPtr(ListNode* nextPtr) {
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

        // comparators
        static bool ascendingOrder(T& lhs,T& rhs);
        static bool descendingOrder(T& lhs, T& rhs);

        // recursive insertion sort swap
        void insertionSortHelper(T* arr, int index, bool (*fun)(T&, T&)); 

        // recursive merge sort swap
        T* mergeSortHelper(T* arr, int size, bool (*fun)(T&, T&));


    public:

        // constructor
        SinglyLinkedList();

        // destructor
        ~SinglyLinkedList();

        // getters
        int getSize() const;
        T& front() const;

        // setters

        // public methods
        void insertAtFront(T data); // -> allocate and insert new node containing data
        T* find(const T& data); // -> return ptr to node matching data
        void print(); // -> print all data in list to console
        void insertionSort(bool ascending); // -> insertion sort list and print contents
        void mergeSort(bool ascending); // -> merge sort list and print contents

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

template <class T>
T& SinglyLinkedList<T>::front() const {
    return mpHead->getData();
}

// setters

// public methods
template <class T>
void SinglyLinkedList<T>::insertAtFront(T data) { // -> allocate and insert new node containing data

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
T* SinglyLinkedList<T>::find(const T& data) { 

    ListNode<T>* pNode = mpHead; // traverse list until end or value found
    while (pNode != nullptr && pNode->getData() != data) {
        pNode = pNode->getNextPtr();
    }

    return &pNode->getData();
}

// print all data in list to console, requires overloaded operator<<
template <class T>
void SinglyLinkedList<T>::print() { 

    ListNode<T>* pNode = mpHead; // traverse list until end, print to console
    while (pNode != nullptr) {
        std::cout << pNode->getData() << ",\n";
        pNode = pNode->getNextPtr();
    }
}

// comparators
template<class T>
bool SinglyLinkedList<T>::ascendingOrder(T& lhs, T& rhs) {
    return lhs < rhs;
}

template <class T>
bool SinglyLinkedList<T>::descendingOrder(T& lhs, T& rhs) {
    return !(lhs < rhs);
}

template <class T>
void SinglyLinkedList<T>::insertionSort(bool ascending) { // -> insertion sort list and print contents
    // since we are just printing the results im going to create an array, print it, then discard
    ListNode<T>* pNode = mpHead;
    T* arr = new T[mSize]; // copy all list values to new array before sort
    int i = 0;
    while(pNode != nullptr) { // copy values into array until end
        arr[i++] = pNode->getData();
        pNode = pNode->getNextPtr();
    }

    bool (*method)(T&, T&) = ascending? ascendingOrder : descendingOrder;
    // once array has been populated, start sorting from 2nd element
    for (int i = 1; i < mSize; i++) {
        insertionSortHelper(arr, i, method);
    }
    

    // print contents of array
    for(int i = 0; i < mSize; i++) {
        std::cout << arr[i] << ",\n";
    }

    delete arr;
}

template <class T>
void SinglyLinkedList<T>::mergeSort(bool ascending) { // -> merge sort list and print cotents
    // since we are just printing the results, create an array, print it, then discard
    ListNode<T>* pNode = mpHead;
    T* arr = new T[mSize]; // copy all list values to new array before sort
    int i = 0;
    while(pNode != nullptr) { // copy values into array until end
        arr[i++] = pNode->getData();
        pNode = pNode->getNextPtr();
    }

    bool (*method)(T&, T&) = ascending? ascendingOrder : descendingOrder;

    // once array has been populated, start sorting
    T* result = mergeSortHelper(arr, mSize, method);


    // print contents of array
    for(int i = 0; i < mSize; i++) {
        std::cout << result[i] << ",\n";
    }

    delete arr;
    delete result;

}

// private methods

// recursively delete list - destructor helper
template <class T>
void SinglyLinkedList<T>::deleteList(ListNode<T>* pNode) {
    if (pNode != nullptr) {
        deleteList(pNode->getNextPtr());
        //delete pNode->getNextPtr();
        delete pNode;
    }
}

template <class T>
void SinglyLinkedList<T>::insertionSortHelper(T* arr, int index, bool (*fun)(T&, T&)) { // recursive insertion sort swap

    // base case - if front of array hit or the elements are in order end!
    if(index < 1 || fun(arr[index - 1], arr[index])) {
        return;
    } else {
        T swap = arr[index]; // swap left and right elements
        arr[index] = arr[index - 1];
        arr[index - 1] = swap;
        insertionSortHelper(arr, index - 1, fun); // call again until base case
    }
}

// recursive merge sort swap

template <class T>
T* SinglyLinkedList<T>::mergeSortHelper(T* arr, int size, bool (*fun)(T&, T&)) {
    if(size > 1){
        int middle = std::floor(size / 2);
        T* left = mergeSortHelper(arr, middle, fun);
        T* right = mergeSortHelper(&arr[middle], size - middle, fun);

        int i, j, k;   // process vars and result array
        i = j = k = 0; // left[i]. right[j], and result[k]
        T* result = new T[size];
        while (i < middle && j < size - middle) { // loop until one array fully copied!
            if(fun(left[i], right[j])){
                result[k++] = left[i++]; // merge left arr value
            } else {
                result[k++] = right[j++]; // merge right arr value
            }
        }
        // at this point one of the arrays will be fully processed, copy the other array!
        if(i < middle) { // left array needs more work
            while(i < middle) { result[k++] = left[i++]; }
        } else { // right array must need more work
            while(j < size - middle) { result[k++] = right[j++]; }
        }
        assert(i + j == size); // validate that all elements have been processed

        // also dont forget to clean up smaller arrays...
        delete left;
        delete right;

        return result;

    } else { // base case -> return 1 element array
        T* result = new T[size];
        result[0] = arr[0];

        return result;
    }
}


#endif