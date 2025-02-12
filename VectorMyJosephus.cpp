
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

// public methods
void VectorMyJosephus::run() { // start game, go until one destination
    std::cout << "**START M = " << this->M << ", N = " << this->N <<  "**\n";
    while (this->getCurrentSize() > 1) {
        this->eliminateDestination();
    }
    std::cout << " the last destination remaining: ";
    this->printAllDestinations();

    std::cout << "**END**\n";
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
    int diff = (this->mIndex + 1 + this->M) - this->mDestinations.size();
    auto start = this->mDestinations.begin();

    //while (diff > this->mDestinations.size()) { diff -= this->mDestinations.size(); }
    // wrap if needed || put me back -> start + diff - 1
    auto iter = (diff > 0) ? 
    start + (diff % this->mDestinations.size()) - 1 : start + mIndex + M;
    
    // delete vec element and reassign new index (have to call begin() in case
    // old begin() happens to be the one that got erased
    this->mIndex = distance(this->mDestinations.begin(), iter);
    iter = this->mDestinations.erase(iter);

    if (this->mIndex + 1 > this->mDestinations.size()) {
        this->mIndex = this->mIndex - this->mDestinations.size();
    }
    
}

void VectorMyJosephus::printAllDestinations() { // -> print collection contents
    for (auto d : this->mDestinations) { std::cout << d; }
}

bool VectorMyJosephus::contains(const int& pos) { // -> true if contains position
    bool ok = false;
    for (auto d : this->mDestinations) {
        if (d.getPosition() == pos) { ok = true; }
    }

    return ok;
}