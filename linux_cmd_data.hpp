#include <string>
#include <iostream>

class linux_cmd_data {
    private:
        std::string mName;
        std::string mDescription;

    public:

        // constructor
        linux_cmd_data(const std::string& name, const std::string& description);

        // destructor
        ~linux_cmd_data();

        

};

// overloaded operators

bool operator==(linux_cmd_data& lhs, linux_cmd_data& rhs);

// writing data
std::istream& operator>>(std::istream& lhs, linux_cmd_data& rhs);

// reading data
std::ostream& operator<<(std::ostream& lhs, linux_cmd_data& rhs);
