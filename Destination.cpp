
#include "Destination.hpp"

// constructor
Destination::Destination(const int& position, const std::string& destination) {
    this->mPosition = position;
    this->mName = destination;
}

// destructor
Destination::~Destination() {
    // nothing on the stack -> do nothing
}

// getters
int Destination::getPosition() {
    return this->mPosition;
}
std::string Destination::getName() {
    return this->mName;
}

// public methods

// printing data individually
void Destination::printPosition() {
    std::cout << this->mPosition;
}
void Destination::printDestinationName() {
    std::cout << this->mName;
}

// print destination data as a pair
std::ostream& operator<<(std::ostream& lhs, Destination& rhs) {
    lhs << rhs.mPosition << ", " << rhs.mName << "\n";

    return lhs;
}