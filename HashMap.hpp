#ifndef HASH_MAP_H
#define HASH_MAP_H

#include <functional>
#include <iostream>
#include <assert.h>




// class K must have std::hash available
// class V must have operator<<, operator= available
template <class K, class V>
class HashMap {

    protected:

    class hashRow { // sub-class for each entry in the hashmap
        public:
            K key; // [{.key, .data, .empty}] each row
            V data;
            bool empty;

            // constructor
            hashRow() : empty(true) {}

            // copy assignment
            hashRow& operator=(hashRow& rhs) {
                key = rhs.key;
                data = rhs.data;
                empty = rhs.empty;

                return *this;
            }
        };

        hashRow* mData; // array of value type on the heap, with size mSize
        int mSize;
        std::hash<K> mHash; // init hash function

        // private methods

        // returns cell value from hash map with several cases
        // case value.empty = false -> key match
        // case value.empty = true -> empty cell, assign to insert
        hashRow& operator[](const K&);

    public:

        // constructor
        HashMap(int size);

        // destructor
        ~HashMap();

        // getters
        int getSize() const;

        // setters

        // public methods

        // returns ptr to found value or nullptr if not found
        V* find(const K& key);

        // inserts key, value pair, returns true on success
        bool insert( K key, V value);

        // returns true if key in hash map
        bool contains(const K& key);
        
        // prints contents of hashmap to console
        void print() const;                        
};

// constructor
template <class K, class V>
HashMap<K, V>::HashMap(int size) {
    mData = new hashRow[size];
    mSize = size;
}

// destructor
template <class K, class V>
HashMap<K, V>::~HashMap() {
    delete[] mData; // delete heap array
}

// getters
template <class K, class V>
int HashMap<K, V>::getSize() const {
    return mSize;
}

// public methods


// -> handles find and insert given key with quadratic probing!
template <class K, class V>
typename HashMap<K, V>::hashRow& HashMap<K, V>::operator[](const K& key) { 
    unsigned int i, adjustedIdx, base;
    i = 0;
    base = mHash(key);
    hashRow* cell = &mData[base % mSize]; // get initial index before looping

    while (cell->key != key && !(cell->empty)) { // iterate until key match or empty cell
        adjustedIdx = (base + (i * i)) % mSize;
        cell = &mData[adjustedIdx];

        assert(i++ < 15); // crash if too many insert attempts
    }

    return *cell; // returns record of matching key or empty cell for insert
}

template <class K, class V>
V* HashMap<K, V>::find(const K& key) {
    hashRow* pCell = &(*this)[key]; // retrieve by key
    if (pCell->empty) { // check if found and return matching ptr
        return nullptr;
    } else {
        return &pCell->data;
    }
}

template <class K, class V>
bool HashMap<K, V>::insert( K key, V value) {
    hashRow& cell = (*this)[key]; // retrieve by key
    bool ok = false;

    if (cell.empty) { // if cell is not already used, assign!
        cell.key = key;
        cell.data = value;
        cell.empty = false;

        ok = true; // make sure to return success
    }

    return ok;
}


template <class K, class V>
bool HashMap<K, V>::contains(const K& key) { // -> returns true if key in hash map
    hashRow& cell = (*this)[key];

    return !cell.empty;
}

template <class K, class V>
void HashMap<K, V>::print() const { // -> prints contents of hashmap to console
    for (int i = 0; i < mSize; i++) { 
       if (!mData[i].empty) { // print all non-empty cells!
            std::cout << mData[i].key << ", " << mData[i].data << std::endl;
        }
    }
}

#endif