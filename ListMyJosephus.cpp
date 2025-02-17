
#include "ListMyJosephus.hpp"

// constructor
ListMyJosephus::ListMyJosephus(const int& M, const int& N) : MyJosephus(M, N) {
    // I'm assuming MyJosephus constructor is called first so going to
    // directly load in data to list... may come back to bite me :-)
    // assumptions: mFile is on the **start** of a random row in data file

    if (this->mFile.is_open()) { // -> make sure file is still accessible
        std::string name = ""; // buffer!

        // load the data into the collection
        for (int i = 0; i < this->N; i++) {
            std::getline(this->mFile, name, ';');
            this->mDestinations.push_back(Destination(i, name));
        }
    }
    this->mIndex = 0; // start index

}

// destructor
ListMyJosephus::~ListMyJosephus() {
    //nothing to do here, handled in ~MyJosephus :)
}

// public methods
int* ListMyJosephus::run() { // start game, go until one destination
    std::cout << "**START M = " << this->M << ", N = " << this->N <<  "**\n";

    // remove elements and save in array of removed positions
    int* p = new int[this->N-1];
    for (int i = 0; i < this->N - 1; i++) {
        p[i] = this->eliminateDestination();
    }
    std::cout << " the last destination remaining: ";
    this->printAllDestinations();

    std::cout << "**END**\n";

    return p; // return sequence of ints on the heap -> delete later!
}

// public abstract methods
void ListMyJosephus::clear() { // -> empty the sequence
    this->mDestinations.clear();
}
int ListMyJosephus::getCurrentSize() { // -> return collection size
    return this->mDestinations.size();
}
bool ListMyJosephus::isEmpty() { // -> true if collection is empty
    return this->mDestinations.empty();
}
int ListMyJosephus::eliminateDestination() { // -> step and remove destination

    auto iter = this->mDestinations.begin(); // create iter for list and move to
    auto end = this->mDestinations.end();    // current index position before elim
    // index should be in collection somewheres, dont worry about looping just go
    while (iter != end && iter->getPosition() != this->mIndex) { iter++; }

    // step M nodes, wrapping back to front of collection if needed
    for (int i = 0; i < this->M; i++) {
        if (++iter == end) { iter = this->mDestinations.begin(); } // loop back
    }

    // remove the element, returning iter to next element
    // which will be saved as index for next elim cycle
    int deletedPos = iter->getPosition();
    iter = this->mDestinations.erase(iter);
    if (iter == this->mDestinations.end()) { 
        iter = this->mDestinations.begin(); // wrap if needed
    }
    this->mIndex = iter->getPosition();

    return deletedPos;
}

void ListMyJosephus::printAllDestinations() { // -> print collection contents
    for (auto d : this->mDestinations) { std::cout << d; } //print data op<<
}

bool ListMyJosephus::contains(const int& pos) { // true if contains position
    bool ok = false;
    for (auto d : this->mDestinations) {
        if(d.getPosition() == pos) {
            ok = true;
            break;
        }
    }
    return ok;
}