#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>

#include "HashMap.hpp"
#include "AmazonProduct.hpp"

class Category : public HashMap<std::string, AmazonProduct*>{

    private:
        std::string mCategoryName;

    public:

    // constructor

    // destructor

    // getters

    // setters

    // public methods

    friend bool operator!=(const Category& lhs, const Category& rhs);

};


#endif