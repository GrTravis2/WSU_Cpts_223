#ifndef LIST_MY_JOSEPHUS
#define LIST_MY_JOSEPHUS

#include <list>

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
    virtual void clear() = 0; // -> empty the sequence
    virtual int getCurrentSize() = 0; // -> return collection size
    virtual bool isEmpty() = 0; // -> true if collection is empty
    virtual void eliminateDestination() = 0; // -> step and remove destination
    virtual void printAllDestinations() = 0; // -> print collection contents

};

#endif