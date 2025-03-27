#ifndef INVENTORY_QUERY_TOOL_H
#define INVENTORY_QUERY_TOOL_H

#include <string>
#include <fstream>

#include "AmazonProduct.hpp"
#include "Category.hpp"
#include "HashMap.hpp"
#include "SinglyLinkedList.hpp"

#define TABLE_SIZE 10002 // fixed size of data set
#define FILE "marketing_sample_for_amazon_com-ecommerce__20200101_20200131__10k_data.csv"

class InventoryQueryTool {

    private:
        AmazonProduct* mData; // raw data referenced by hashmaps
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
        AmazonProduct* find(const std::string& key); // -> return ptr to data if found, else nullptr
        void printCategory(const std::string& key_category); // -> print contents of specified category
};

#endif