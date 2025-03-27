#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>
#include <iostream>

#include "HashMap.hpp"
#include "SinglyLinkedList.hpp"

class Category : public HashMap<std::string, std::string>{

    public:
        std::string mCategoryName;

        // default constructor
        Category() : mCategoryName(), HashMap(53) {}

        // constructor -> might have to increment size if 53 isnt enough...
        Category(const std::string category) : mCategoryName(category), HashMap<std::string, std::string>(53) {}

        // destructor -> let HashMap destructor clean up!

        // getters

        // setters

        // public methods

        friend bool operator!=(const Category& lhs, const Category& rhs) {
            return !(lhs.mCategoryName == rhs.mCategoryName);
        }

        friend std::ostream& operator<<(std::ostream& lhs, Category& rhs) {
            lhs 
            << "All products from category: " << rhs.mCategoryName << "\n"
            << "id, product name" << std::endl;

            rhs.print();

            return lhs;
        }

};

class Categories {

    public:
        SinglyLinkedList<Category>* mListCategories;
        HashMap<std::string, bool>* mCheck;

        // constructor
        //Categories() : mListCategories(), mCheck(51) {}
        Categories() {
            mListCategories = new SinglyLinkedList<Category>();
            mCheck = new HashMap<std::string, bool>(51);
        }

        // destructor
        ~Categories() {
            delete mListCategories;
            delete mCheck;
        }

        // public methods
        // none, just use each class individually
};


#endif