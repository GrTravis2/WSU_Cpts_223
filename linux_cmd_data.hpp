#ifndef LINUX_CMD_DATA_HPP
#define LINUX_CMD_DATA_HPP

#include <string>
#include <iostream>

#define QUIT 5

class linux_cmd_data {
    private:
        std::string mName;
        std::string mDescription;
        int mPoints;

    public:

        // constructors
        linux_cmd_data();
        linux_cmd_data(const std::string& name, const std::string& description, const int& points);

        // destructor
        ~linux_cmd_data();

        // getters
        std::string getName() const;
        std::string getDescription() const;
        int getPoints() const;

        // setters
        void setName(std::string newName); // deep copies!
        void setDescription(std::string newDesc);
        void setPoints(int newPoints);

        

};

// overloaded operators

bool operator==(const linux_cmd_data& lhs, const linux_cmd_data& rhs);

bool operator!=(const linux_cmd_data& lhs, const linux_cmd_data& rhs);

// writing data
std::istream& operator>>(std::istream& lhs, linux_cmd_data& rhs);

// reading data
std::ostream& operator<<(std::ostream& lhs, const linux_cmd_data& rhs);


#endif