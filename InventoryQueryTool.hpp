#ifndef INVENTORY_QUERY_TOOL_H
#define INVENTORY_QUERY_TOOL_H

#include <string>

#include "AmazonProduct.hpp"
#include "Category.hpp"
#include "HashMap.hpp"
#include "SinglyLinkedList.hpp"

class InventoryQueryTool {

    private:
        AmazonProduct* mData; // raw data referenced by hashmaps
        const int TABLE_SIZE; // fixed size of data set
        HashMap<std::string, AmazonProduct*> mSearch; // main table for searching raw product id
        SinglyLinkedList<Category> mCategories; // list of categories containing individual maps

        // private methods

    public:

        // constructor
        InventoryQueryTool();

        // destructor
        ~InventoryQueryTool();

        // getters

        // setters

        // public methods
        AmazonProduct* find(const std::string& key);

};

#endif