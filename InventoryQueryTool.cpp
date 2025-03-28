

#include "InventoryQueryTool.hpp"
#include "AmazonProduct.hpp"
#include "Category.hpp"
#include "SinglyLinkedList.hpp"
#include <fstream>
#include <stdexcept>
#include <string>
#include <utility>

// constructor
InventoryQueryTool::InventoryQueryTool() : 
    mSearch(10 * 2), mCategories() { // was  TABLE_SIZE, now 10
    mData = new AmazonProduct[10]; // was TABLE_SIZE -> 10

    int i, leading, lagging; // init vars and file
    i = leading = lagging = 0;
    std::string s = "";
    std::ifstream f;
    f.open(FILE);

    // dump header for overwrite later
    std::getline(f, mData[i].id, '\n');

    if (f.is_open()) {
        while (f.peek() != EOF) {

            // read whole obj as whole line for printing, parse out needed fields
            std::getline(f, mData[i].all, '\n');
            leading = mData[i].all.find(',');
            mData[i].id = mData[i].all.substr(lagging, leading - lagging); // load id value
            lagging = leading + 2; // skip over the ,"
            leading = mData[i].all.find('\"', lagging + 1);
            mData[i].productName = mData[i].all.substr(lagging, leading); // load product name

            leading = mData[i].all.find(',', lagging + 1);
            mData[i].categories = mData[i].all.substr(lagging, leading - lagging); // save values

            // parse string categories for insert into Categories class
            leading = 0;
            Category* cat = new Category(s);
            while(leading != std::string::npos) {
                lagging = leading + 1; // -> copy each category until end of string
                leading = mData[i].categories.find('|', lagging);

                // copy and clean whitespace before/after string before insertion
                while(mData[i].categories.at(lagging) == ' ' 
                || mData[i].categories.at(lagging) == '\"') {lagging++;}
                s = mData[i].categories.substr(lagging, leading - lagging);
                while(s.back() == ' ' || s.back() == '\"') { s.pop_back(); }

                // record category to save other products by category in the future
                if (!mCategories.mCheck->contains(s)) { // if already recorded, skip
                    mCategories.mCheck->insert(s, true);
                    mCategories.mListCategories->insertAtFront(*cat);
                }

                // search the list and insert product into correct category table
                mCategories.mListCategories->find(*cat)->insert(mData[i].id, mData[i].productName);
            }


            i += 1; // step i to next value
        }
    }

    f.close();
}

// destructor
InventoryQueryTool::~InventoryQueryTool() {
    delete mData;
}

// getters

// setters

// public methods

// -> print data if found, else print error not found
void InventoryQueryTool::find(const std::string& key) {
    AmazonProduct** pData = mSearch.find(key);
    if(pData != nullptr && *pData != nullptr) {
        std::cout << **pData;
    } else {
        std::cout << "Inventory/Product not found." << std::endl;
    }
}

// -> print contents of specified category
void InventoryQueryTool::printCategory(const std::string& key_category) {
    Category* pCat = mCategories.mListCategories->find(key_category);

    if(pCat != nullptr) {
        std::cout << *pCat;
    } else {
        std::cout << "Inventory/Product not found" << std::endl;
    }
}