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
    virtual void clear() = 0; // -> empty the sequence
    virtual int getCurrentSize() = 0; // -> return collection size
    virtual bool isEmpty() = 0; // -> true if collection is empty
    virtual void eliminateDestination() = 0; // -> step and remove destination
    virtual void printAllDestinations() = 0; // -> print collection contents

};

#endif