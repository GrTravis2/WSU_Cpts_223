#ifndef DESTINATION
#define DESTINATION

#include <string>

class Destination {
    private:
        int mPosition;
        std::string mName;


    public:

        // constructor
        Destination(const int& position, const std::string& destination);

        // destructor
        ~Destination();

        // public methods
        void printPosition();
        void printDestinationName();

};

#endif