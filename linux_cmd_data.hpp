#ifndef LINUX_CMD_DATA_HPP
#define LINUX_CMD_DATA_HPP

#include <string>
#include <iostream>

#define QUIT 5

class linux_cmd_data {
    private:
        std::string mName;
        std::string mDescription;

    public:

        // constructors
        linux_cmd_data();
        linux_cmd_data(const std::string& name, const std::string& description);

        // destructor
        ~linux_cmd_data();

        // getters
        std::string getName();
        std::string getDescription();

        // setters
        void setName(std::string newName); // deep copies!
        void setDescription(std::string newDesc);

        

};

// overloaded operators

bool operator==(linux_cmd_data& lhs, linux_cmd_data& rhs);

// writing data
std::istream& operator>>(std::istream& lhs, linux_cmd_data& rhs);

// reading data
std::ostream& operator<<(std::ostream& lhs, linux_cmd_data& rhs);


#endif