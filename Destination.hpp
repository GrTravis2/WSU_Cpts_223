#ifndef DESTINATION
#define DESTINATION

#include <string>
#include <iostream>

class Destination {
    private:
        int mPosition;
        std::string mName;


    public:

        // constructor
        Destination(const int& position, const std::string& destination);

        // destructor
        ~Destination();

        // getters
        int getPosition();
        std::string getName();

        // public methods
        // Doing this with a getter and std::cout instead,
        // I think its easier to read when print comes from top level
        // void printPosition(); 
        // void printDestinationName();

        friend std::ostream& operator<<(std::ostream& lhs, Destination& rhs);

};



#endif