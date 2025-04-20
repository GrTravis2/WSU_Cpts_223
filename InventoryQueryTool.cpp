
#include <fstream>
#include <stdexcept>
#include <string>
#include <iostream>

#include "InventoryQueryTool.hpp"
#include "AmazonProduct.hpp"
#include "SinglyLinkedList.hpp"


// constructor
InventoryQueryTool::InventoryQueryTool() : 
    mSearch(TABLE_SIZE), mCategories(TABLE_SIZE) { // was  TABLE_SIZE, now 10
    //mData = new AmazonProduct[10002]; // exactly the number of rows in csv
    mData = new AmazonProduct[100];

    int i, leading, lagging; // init vars and file
    i = leading = lagging = 0;
    std::string s = "";
    std::string buffer = "";
    std::ifstream f;
    f.open(FILE);

    // dump header for overwrite later
    //std::getline(f, mData[i].id, '\n');
    std::getline(f, buffer, '\n');

    if (f.is_open()) {
        while (i < 100) {
        //while (f.peek() != EOF) {
            leading = lagging = 0;

            // read whole obj as whole line for printing, parse out needed fields
            //mData[i].all.reserve(100);
            std::getline(f, s, '\n');
            mData[i].setAll(s);
            leading = mData[i].getAll().find(',');

            // load id value
            buffer = s.substr(lagging, leading - lagging);
            mData[i].setId(buffer); 

            lagging = leading + 2; // skip over the ,"

            // load product name
            leading = s.find('\"', lagging + 1);
            buffer = s.substr(lagging, leading - lagging);
            mData[i].setProductName(buffer);
            lagging = leading + 1;

            // save category values
            leading = s.find(',', lagging + 1);
            buffer = s.substr(lagging, leading - lagging);
            mData[i].setCategories(buffer);

            // parse string categories for insert into Categories table
            leading = 0;
            while(leading != std::string::npos) {
                lagging = leading + 1; // -> copy each category until end of string
                leading = buffer.find('|', lagging);

                // copy and clean whitespace before/after string before insertion
                try {
                    while(buffer.at(lagging) == ' ' 
                    || buffer.at(lagging) == '\"'
                    || buffer.at(lagging) == ',') {lagging++;}
                } catch (std::out_of_range) {}
                s = buffer.substr(lagging, leading - lagging);
                while(s.back() == ' ' || s.back() == '\"') { s.pop_back(); }

                // search the hash table and insert product into correct category list

                // temp values
                std::string name = mData[i].getProductName();
                std::string id = mData[i].getId();
                if (mCategories.contains(s)) {
                    //mData[i].productName.reserve(50);
                    categoryPair p(name, id);
                    (*mCategories.find(s))->insertAtFront(p);
                } else {
                    SinglyLinkedList<categoryPair>* pList = new SinglyLinkedList<categoryPair>();
                    categoryPair p(name, id);
                    pList->insertAtFront(p);
                    mCategories.insert(s, pList);
                }

                // insert id into main table
                mSearch.insert(id, &mData[i]);
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
void InventoryQueryTool::printCategory(std::string key_category, bool insertion, bool ascending) {

    // retrieve list and print all contents if found
    SinglyLinkedList<categoryPair>** pList = mCategories.find(key_category);

    if(pList != nullptr) {
        std::cout << "Printing all entries from category: " << key_category << std::endl;
        if (insertion) {
            (*pList)->insertionSort(ascending);
        } else {
            (*pList)->mergeSort(ascending);
        }
        
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
    name = "";
    price = "";
}

// assignment operator
InventoryQueryTool::categoryPair& InventoryQueryTool::categoryPair::operator=(categoryPair& other) {

        name = other.getName();
        price = other.getPrice();

    return other;
}

// getters
std::string InventoryQueryTool::categoryPair::getName() {
    return name;
}
std::string InventoryQueryTool::categoryPair::getPrice() {
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