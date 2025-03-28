#ifndef INVENTORY_QUERY_TOOL_H
#define INVENTORY_QUERY_TOOL_H

#include <string>
#include <fstream>

#include "AmazonProduct.hpp"
#include "Category.hpp"
#include "HashMap.hpp"
#include "SinglyLinkedList.hpp"

#define TABLE_SIZE 10002 // fixed size of data set
#define FILE "AmazonData_Clean.csv"

class InventoryQueryTool {

    private:
        AmazonProduct* mData; // raw data referenced by hashmaps
        HashMap<std::string, AmazonProduct*> mSearch; // main table for searching raw product id
        //Categories mCategories; // list of categories containing individual maps
        HashMap<std::string, SinglyLinkedList<std::string>* > mCategories;

        // private methods

    public:

        // constructor
        InventoryQueryTool();

        // destructor
        ~InventoryQueryTool();

        // getters

        // setters

        // public methods
        void find(const std::string& key); // -> print data if found, else print error not found
        void printCategory(const std::string& key_category); // -> print contents of specified category
};

#endif