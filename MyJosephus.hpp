#ifndef MY_JOSEPHUS
#define MY_JOSEPHUS

#include <string>

class MyJosephus {
    protected:
        int M; // step move, where M lands that destination is removed from collection
        int N; // number of destinations read in from data

    public:
        // constructor
        MyJosephus(const int& M, const int& N);

        // destructor -> must override!
        virtual ~MyJosephus() = 0;

        // public methods
        void run(); // start game, go until one destination
        std::string& getRow(const int& index); // get ith row from file

        // public abstract methods
        virtual void clear() = 0; // -> empty the sequence
        virtual int getCurrentSize() = 0; // -> return collection size
        virtual bool isEmpty() = 0; // -> true if collection is empty
        virtual void eliminateDestination() = 0; // -> step and remove destination
        virtual void printAllDestinations() = 0; // -> print collection contents
};


#endif