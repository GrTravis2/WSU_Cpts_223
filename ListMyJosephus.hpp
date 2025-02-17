#ifndef LIST_MY_JOSEPHUS
#define LIST_MY_JOSEPHUS

#include <list>
#include <iostream>

#include "Destination.hpp"
#include "MyJosephus.hpp"

class ListMyJosephus : public MyJosephus {
    private:
    std::list<Destination> mDestinations; // collection of destinations
    int mIndex; // track current start position of elim loop!

    public:

    // constructor
    ListMyJosephus(const int& M, const int& N);

    // destructor
    ~ListMyJosephus();

    // public abstract methods
    int* run(); // -> start game and run until one destination,
                // return sequence of deleted destinations

    void clear(); // -> empty the sequence
    int getCurrentSize(); // -> return collection size
    bool isEmpty(); // -> true if collection is empty
    int eliminateDestination(); // -> step and remove destination,
                                // return index of deleted destination

    void printAllDestinations(); // -> print collection contents
    bool contains(const int& pos); // -> true if contains position index
    

};

#endif