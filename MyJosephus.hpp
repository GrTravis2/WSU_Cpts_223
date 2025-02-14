#ifndef MY_JOSEPHUS
#define MY_JOSEPHUS

#include <string>
#include <fstream>

#define DESTINATION_ROW_MAX 25
const std::string file = "destinations.csv";

class MyJosephus {
    protected:
        int M; // step move, where M lands that destination is removed from collection
        int N; // number of destinations read in from data

        std::ifstream mFile; // track file for reading in data

    public:
        // constructor
        MyJosephus(const int& M, const int& N);

        // destructor -> must override!
        ~MyJosephus();

        // public abstract methods
        virtual int* run() = 0; // start game, go until one destination
        virtual void clear() = 0; // -> empty the sequence
        virtual int getCurrentSize() = 0; // -> return collection size
        virtual bool isEmpty() = 0; // -> true if collection is empty
        virtual int eliminateDestination() = 0; // -> step and remove destination
        virtual void printAllDestinations() = 0; // -> print collection contents
        virtual bool contains(const int& pos) = 0; // -> true if contains position
};


#endif