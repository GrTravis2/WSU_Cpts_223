#ifndef HASH_MAP_H
#define HASH_MAP_H

#include <string>

template <class K, class V>
class HashMap {

    protected:
        V* mData; // array of value type on the heap
        int mSize;

    public:

        // constructor
        HashMap();

        // destructor
        ~HashMap();

        // getters

        // setters

        // public methods

        // dont forget quadratic probing >:(
        friend V& HashMap<K, V>::operator[](const K&); // -> handles find and insert given key
        bool contains(const K& key); // -> returns true if key in hash map
        void print() const; // -> prints contents of hashmap to console
};

#endif