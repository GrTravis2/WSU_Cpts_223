
#include "VectorMyJosephus.hpp"

// constructor
VectorMyJosephus::VectorMyJosephus(const int& M, const int& N) : MyJosephus(M, N) {
    // I'm assuming MyJosephus constructor is called first so going to
    // directly load in data to list... may come back to bite me :-)
    // assumptions: mFile is on the **start** of a random row in data file

    if (this->mFile.is_open()) { // -> make sure file is still accessible
        std::string name = ""; // buffer!

        for (int i = 0; i < this->N; i++) {
            std::getline(this->mFile, name, ';');
            this->mDestinations.push_back(Destination(i, name));
        }
    }
    this->mIndex = 0; // start index
}

// destructor
VectorMyJosephus::~VectorMyJosephus() {
    // do no thing
}

// public abstract methods
void VectorMyJosephus::clear() { // -> empty the sequence
    this->mDestinations.clear();
}

int VectorMyJosephus::getCurrentSize() { // -> return collection size
    return this->mDestinations.size();
}

bool VectorMyJosephus::isEmpty() { // -> true if collection is empty
    return this->mDestinations.empty();
}

void VectorMyJosephus::eliminateDestination() { // -> step and remove destination
    // TODO
}

void VectorMyJosephus::printAllDestinations() { // -> print collection contents
    for (auto d : this->mDestinations) { std::cout << d; }
}