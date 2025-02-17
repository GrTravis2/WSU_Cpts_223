
#include "VectorMyJosephus.hpp"

// constructor
VectorMyJosephus::VectorMyJosephus(const int& M, const int& N) : MyJosephus(M, N) {
    // I'm assuming MyJosephus constructor is called first so going to
    // directly load in data to list... may come back to bite me :-)
    // assumptions: mFile is on the **start** of a random row in data file
    

    if (this->mFile.is_open()) { // -> make sure file is still accessible
        std::string name = ""; // buffer!
        this->mDestinations.reserve(N);

        // load the data into the collection
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
int* VectorMyJosephus::run() { // start game, go until one destination
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
void VectorMyJosephus::clear() { // -> empty the sequence
    this->mDestinations.clear();
}

int VectorMyJosephus::getCurrentSize() { // -> return collection size
    return this->mDestinations.size();
}

bool VectorMyJosephus::isEmpty() { // -> true if collection is empty
    return this->mDestinations.empty();
}

int VectorMyJosephus::eliminateDestination() { // -> step and remove destination
   auto iter = this->mDestinations.begin(); // set up data for elim
   int shift = this->M % this->mDestinations.size();
   int deletedPos = -1;

    // find the next node to be delete
    int remainder = distance(iter + this->mIndex, this->mDestinations.end());
    iter = (shift < remainder)? iter + this->mIndex + shift : iter + (shift-remainder);

    // record deleted position and current index before removing destination
    deletedPos = iter->getPosition();
    iter = this->mDestinations.erase(iter);
    this->mIndex = distance(this->mDestinations.begin(), iter);
    if (this->mIndex > this->mDestinations.size() - 1) { this->mIndex = 0; } // -> check if deletion moves iter oob!

    return deletedPos;
    
}

void VectorMyJosephus::printAllDestinations() { // -> print collection contents
    for (auto d : this->mDestinations) { std::cout << d; } //print data op<<
}

bool VectorMyJosephus::contains(const int& pos) { // -> true if contains position
    bool ok = false;
    for (auto d : this->mDestinations) {
        if (d.getPosition() == pos) {
            ok = true;
            break;
        }
    }

    return ok;
}