#ifndef VECTOR_MY_JOSEPHUS
#define VECTOR_MY_JOSEPHUS

#include <vector>
#include <exception>

#include "Destination.hpp"
#include "MyJosephus.hpp"

class VectorMyJosephus : public MyJosephus {
    private:
    std::vector<Destination> mDestinations;
    int mIndex;

    public:

    // constructor
    VectorMyJosephus(const int& M, const int& N);

    // destructor
    ~VectorMyJosephus();

    // public abstract methods
    int* run(); // -> start game and run until one destination,
                // return sequence of deleted destinations

    void clear(); // -> empty the sequence
    int getCurrentSize(); // -> return collection size
    bool isEmpty(); // -> true if collection is empty
    int eliminateDestination(); // -> step and remove destination,
                                // return index of deleted destination

    void printAllDestinations(); // -> print collection contents
    bool contains(const int& pos); // -> true if contains position

};

#endif