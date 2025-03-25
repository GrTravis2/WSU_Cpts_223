#ifndef HASH_MAP_H
#define HASH_MAP_H

#include <cmath>
#include <functional>
#include <math.h>
#include <iostream>
#include <assert.h>




// class K must have std::hash available
// class V must have operator<<, operator= available
template <class K, class V>
class HashMap {

    typedef enum status {
        EMPTY,
        FULL,
        DELETED,
    }STATUS;

    typedef struct hashRow {
        K& key;
        V& data;
        bool empty = true;
    }HASH_ROW;

    protected:
        V* mData; // array of value type on the heap, with size mSize
        int mSize;
        std::hash<K> mHash; // init hash function

        // private methods

        // returns cell value from hash map with several cases
        // case value.status = FULL -> key match
        // case value.status = EMPTY -> empty cell, assign to insert
        V& operator[](const K&);

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
        bool insert(const K& key, const V& value);

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
    delete mData; // delete heap array
}

// getters
template <class K, class V>
int HashMap<K, V>::getSize() const {
    return mSize;
}

// public methods

// dont forget quadratic probing >:(
template <class K, class V>
V& HashMap<K, V>::operator[](const K& key) { // -> handles find and insert given key
    int i = 0;
    int base = mHash(key);
    hashRow& cell = mData[base % mSize];

    while (cell.key != key && !cell.empty) { // iterate until key match or empty cell
        cell = mData[(base + pow(i++, 2)) % mSize];

        assert(i < 10); // crash if too many insert attempts
    }

    return cell; // returns record of matching key or empty cell for insert
}

template <class K, class V>
V* HashMap<K, V>::find(const K& key) {
    hashRow cell = this[key];
    V* pCell = &cell;
    if (cell.empty) { pCell = nullptr; }

    return pCell;
}

template <class K, class V>
bool HashMap<K, V>::insert(const K& key, const V& value ) {
    hashRow cell = this[key];
    bool ok = false;

    if (value.empty) {
        cell.key = key;
        cell.data = value;
        cell.empty = false;

        ok = true;
    }

    return ok;
}


template <class K, class V>
bool HashMap<K, V>::contains(const K& key) { // -> returns true if key in hash map
    hashRow cell = this[key];

    return !cell.empty;
}

template <class K, class V>
void HashMap<K, V>::print() const { // -> prints contents of hashmap to console
    for (int i : mData) { 
       if (!mData[i].empty) { std::cout << mData[i].data; }
    }
}

#endif