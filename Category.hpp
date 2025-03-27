#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>

#include "HashMap.hpp"
#include "AmazonProduct.hpp"

class Category : public HashMap<std::string, AmazonProduct*>{

    public:
        std::string mCategoryName;

    // constructor -> might have to increment size if 53 isnt enough...
    Category(const std::string& category) : mCategoryName(category), HashMap(53) {}

    // destructor -> let HashMap destructor clean up!

    // getters

    // setters

    // public methods

    friend bool operator!=(const Category& lhs, const Category& rhs);

};


#endif