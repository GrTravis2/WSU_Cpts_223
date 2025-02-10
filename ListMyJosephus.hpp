#ifndef LIST_MY_JOSEPHUS
#define LIST_MY_JOSEPHUS

#include <list>

#include "Destination.hpp"
#include "MyJosephus.hpp"

class ListMyJosephus : public MyJosephus {
    private:
    std::list<Destination> mDestinations;

    public:

    // constructor
    ListMyJosephus(const int& M, const int& N);

    // destructor
    ~ListMyJosephus();

};

#endif