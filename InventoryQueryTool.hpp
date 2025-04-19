#ifndef INVENTORY_QUERY_TOOL_H
#define INVENTORY_QUERY_TOOL_H

#include <string>
#include <utility>
#include <iostream>

#include "AmazonProduct.hpp"
#include "HashMap.hpp"
#include "SinglyLinkedList.hpp"

#define TABLE_SIZE 20011 // fixed size of data set
#define FILE "AmazonData_Clean.csv"

typedef struct pair{
    std::string& name;
    std::string& price;
}PAIR;

class InventoryQueryTool {

    public:

        // sub class for joining data inside the category hash table
        class categoryPair {
            private:
                std::string name;
                std::string price;

            public:

                // constructor
                categoryPair(std::string& name, std::string& price);

                // default constructor
                categoryPair();

                // assignment operator
                categoryPair& operator=(categoryPair& other);

                // getters
                std::string& getName();
                std::string& getPrice();


        };

        // constructor
        InventoryQueryTool();

        // destructor
        ~InventoryQueryTool();

        // getters

        // setters

        // public methods
        void find(std::string key); // -> print data if found, else print error not found
        void printCategory(std::string key_category); // -> print contents of specified category

    private:
        AmazonProduct* mData; // raw data referenced by hashmaps
        HashMap<std::string, AmazonProduct*> mSearch; // main table for searching raw product id

        // hash tables with separate chaining for tuple (product name, price) within the category
        HashMap<std::string, SinglyLinkedList<categoryPair>* > mCategories;

        // private methods
};

// overloaded operators -> needed for printing and sorting!

// for list print operations
std::ostream& operator<<(std::ostream& lhs, InventoryQueryTool::categoryPair& rhs);

// for sorting operations
bool operator<(const InventoryQueryTool::categoryPair& lhs, const InventoryQueryTool::categoryPair& rhs);

#endif