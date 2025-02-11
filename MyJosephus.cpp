
#include "MyJosephus.hpp"

// constructor
MyJosephus::MyJosephus(const int& M, const int& N) {
    this->M = M;
    this->N = N;

    // set ifstream to random row in range 
    this->mFile.open(file); // put mFile.close() in destructor!!!!!
    if (this->mFile.is_open()) {
        // if file open is good, pick a random row and skip thru file
        // leave ifsteam in that position for loading into STL collection
        std::srand(time(0));
        int stop = std::rand() % DESTINATION_ROW_MAX;
        for (int i = 0; i < stop; i++) {
            this->mFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        }

    }
}

// destructor -> must override!
MyJosephus::~MyJosephus() {
    // M and N will be deleted by stack
    this->mFile.close();
}

// public methods
void MyJosephus::run() { // start game, go until one destination
    //do nothing for now... might have to move into derived classes...
}