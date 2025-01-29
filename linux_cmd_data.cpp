#include "linux_cmd_data.hpp"

// constructors
linux_cmd_data::linux_cmd_data() {
    this->mName = "";
    this->mDescription = "";
}

linux_cmd_data::linux_cmd_data(
    const std::string& name,
    const std::string& description) {

        this->mName = name;
        this->mDescription = description;
}

// destructor
linux_cmd_data::~linux_cmd_data() {
    // pass
}

// getters
std::string linux_cmd_data::getName() const {
    return this->mName;
}
std::string linux_cmd_data::getDescription() const {
    return this->mDescription;
}

// setters
void linux_cmd_data::setName(std::string newName) {
    this->mName = newName;
}
void linux_cmd_data::setDescription(std::string newDesc) {
    this->mDescription = newDesc;
}

// overloaded operators

bool operator==(const linux_cmd_data& lhs, const linux_cmd_data& rhs) {
    return lhs.getName() == rhs.getName();
}

bool operator!=(const linux_cmd_data& lhs, const linux_cmd_data& rhs) {
    return !(lhs.getName() == rhs.getName());
}

// writing data
std::istream& operator>>(std::istream& lhs, linux_cmd_data& rhs) {
    std::string s = "";

    std::getline(lhs, s, ',');// -> s has cmd name
    rhs.setName(s);

    std::getline(lhs, s, '\n');// -> s has cmd description
    rhs.setName(s);

    return lhs;
}

// reading data
std::ostream& operator<<(std::ostream& lhs, const linux_cmd_data& rhs) {
    lhs << rhs.getName() << ", " << rhs.getDescription() << std::endl;

    return lhs;
}