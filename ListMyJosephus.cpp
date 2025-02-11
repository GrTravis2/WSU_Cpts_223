
#include "ListMyJosephus.hpp"

// constructor
ListMyJosephus::ListMyJosephus(const int& M, const int& N) : MyJosephus(M, N) {
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
ListMyJosephus::~ListMyJosephus() {
    //nothing to do here, handled in ~MyJosephus :)
}

// public methods
void ListMyJosephus::run() { // start game, go until one destination
    std::cout << "**START SIM**\n";
    this->printAllDestinations(); // just for debug
    while (this->getCurrentSize() > 1) {
        std::cout << "**elim start**\n";
        this->eliminateDestination();
        this->printAllDestinations(); // just for debug
        std::cout << "**elim end**\n";
    }
    std::cout << " the last destination remaining: ";
    this->printAllDestinations();

    std::cout << "  **END SIM**\n";
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
void ListMyJosephus::eliminateDestination() { // -> step and remove destination

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
    std::cout << "deleting destination " << *iter;
    iter = this->mDestinations.erase(iter);
    if (iter == this->mDestinations.end()) { 
        iter = this->mDestinations.begin(); // wrap if needed
    }
    this->mIndex = iter->getPosition();
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