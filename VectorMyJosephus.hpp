#ifndef VECTOR_MY_JOSEPHUS
#define VECTOR_MY_JOSEPHUS

#include <vector>

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
    void run(); // start game, go until one destination
    void clear(); // -> empty the sequence
    int getCurrentSize(); // -> return collection size
    bool isEmpty(); // -> true if collection is empty
    void eliminateDestination(); // -> step and remove destination
    void printAllDestinations(); // -> print collection contents
    bool contains(const int& pos); // -> true if contains position

};

#endif