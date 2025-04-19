
#include <fstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <iostream>

#include "InventoryQueryTool.hpp"
#include "AmazonProduct.hpp"
#include "SinglyLinkedList.hpp"


// constructor
InventoryQueryTool::InventoryQueryTool() : 
    mSearch(TABLE_SIZE), mCategories(TABLE_SIZE) { // was  TABLE_SIZE, now 10
    mData = new AmazonProduct[10002]; // exactly the number of rows in csv

    int i, leading, lagging; // init vars and file
    i = leading = lagging = 0;
    std::string s = "";
    std::ifstream f;
    f.open(FILE);

    // dump header for overwrite later
    std::getline(f, mData[i].id, '\n');

    if (f.is_open()) {
        while (f.peek() != EOF) {
            leading = lagging = 0;

            // read whole obj as whole line for printing, parse out needed fields
            mData[i].all.reserve(100);
            std::getline(f, mData[i].all, '\n');
            leading = mData[i].all.find(',');
            mData[i].id = mData[i].all.substr(lagging, leading - lagging); // load id value
            lagging = leading + 2; // skip over the ,"
            leading = mData[i].all.find('\"', lagging + 1);
            mData[i].productName = mData[i].all.substr(lagging, leading); // load product name
            lagging = leading + 1;

            leading = mData[i].all.find(',', lagging + 1);
            mData[i].categories = mData[i].all.substr(lagging, leading - lagging); // save values

            // parse string categories for insert into Categories table
            leading = 0;
            while(leading != std::string::npos) {
                lagging = leading + 1; // -> copy each category until end of string
                leading = mData[i].categories.find('|', lagging);

                // copy and clean whitespace before/after string before insertion
                try {
                    while(mData[i].categories.at(lagging) == ' ' 
                    || mData[i].categories.at(lagging) == '\"'
                    || mData[i].categories.at(lagging) == ',') {lagging++;}
                } catch (std::out_of_range) {}
                s = mData[i].categories.substr(lagging, leading - lagging);
                while(s.back() == ' ' || s.back() == '\"') { s.pop_back(); }

                // search the hash table and insert product into correct category list
                if (mCategories.contains(s)) {
                    mData[i].productName.reserve(50);
                    categoryPair p(mData[i].productName, mData[i].id);
                    (*mCategories.find(s))->insertAtFront(p);
                } else {
                    SinglyLinkedList<categoryPair>* pList = new SinglyLinkedList<categoryPair>();
                    categoryPair p(mData[i].productName, mData[i].id);
                    pList->insertAtFront(p);
                    mCategories.insert(s, pList);
                }

                // insert id into main table
                mSearch.insert(mData[i].id, &mData[i]);
            }


            i += 1; // step i to next value
        }
    }

    f.close();
}

// destructor
InventoryQueryTool::~InventoryQueryTool() {
    delete mData;
    // other destructors will clean up hashtables
}

// getters

// setters

// public methods

// -> print data if found, else print error not found
void InventoryQueryTool::find(std::string key) {
    AmazonProduct** pData = mSearch.find(key); // retrieve by key
    if(pData != nullptr && *pData != nullptr) { 
        std::cout << **pData; // check for found key and print if able
    } else {
        std::cout << "Inventory/Product not found." << std::endl;
    }
}

// -> print contents of specified category
void InventoryQueryTool::printCategory(std::string key_category) {

    // retrieve list and print all contents if found
    SinglyLinkedList<categoryPair>** pList = mCategories.find(key_category);

    if(pList != nullptr) {
        std::cout << "Printing all entries from category: " << key_category << std::endl;
        (*pList)->print();
    } else {
        std::cout << "Inventory/Product not found" << std::endl;
    }
}

// categoryPair subclass definitions

// constructor
InventoryQueryTool::categoryPair::categoryPair(std::string& name, std::string& price) {
    name = name;
    price = price;
}

// default constructor
InventoryQueryTool::categoryPair::categoryPair() {
    name = price = "";
}

// assignment operator
InventoryQueryTool::categoryPair& InventoryQueryTool::categoryPair::operator=(categoryPair& other) {
    this->name = other.getName();
    this->price = other.getPrice();
}

// getters
std::string& InventoryQueryTool::categoryPair::getName() {
    return name;
}
std::string& InventoryQueryTool::categoryPair::getPrice() {
    return price;
}

// overloaded operators -> needed for printing and sorting!

// for list print operations 
std::ostream& operator<<(std::ostream& lhs, InventoryQueryTool::categoryPair& rhs) {
    lhs << rhs.getName();

    return lhs;
}

// for sorting operations
bool operator<(InventoryQueryTool::categoryPair& lhs, InventoryQueryTool::categoryPair& rhs) {
    return lhs.getPrice() < rhs.getPrice();
}