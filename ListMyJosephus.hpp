#ifndef LIST_MY_JOSEPHUS
#define LIST_MY_JOSEPHUS

#include <list>
#include <iostream>

#include "Destination.hpp"
#include "MyJosephus.hpp"

class ListMyJosephus : public MyJosephus {
    private:
    std::list<Destination> mDestinations;
    int mIndex; // track current start position of elim loop!

    public:

    // constructor
    ListMyJosephus(const int& M, const int& N);

    // destructor
    ~ListMyJosephus();

    // public abstract methods
    void run(); // start game, go until one destination
    void clear(); // -> empty the sequence
    int getCurrentSize(); // -> return collection size
    bool isEmpty(); // -> true if collection is empty
    void eliminateDestination(); // -> step and remove destination
    void printAllDestinations(); // -> print collection contents
    bool contains(const int& pos); // true if contains position
    

};

#endif