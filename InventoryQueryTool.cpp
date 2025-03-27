

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

            /*
            // read into each field
            std::getline(f, mData[i].id, ',');
            std::getline(f, mData[i].productName, ',');
            std::getline(f, mData[i].brandName, ',');
            std::getline(f, mData[i].Asin, ',');
            std::getline(f, mData[i].categories, '"'); // dulpicate in order to
            std::getline(f, mData[i].categories, '"'); // overwrite junk before "
            std::getline(f, mData[i++].rest, '\n'); // dump last of data into str

            */

            // read whole obj as whole line for printing, parse out needed fields
            std::getline(f, mData[i].all, '\n');
            leading = mData[i].all.find(',');
            mData[i].id = mData[i].all.substr(lagging, leading - lagging); // load id value
            lagging = ++leading;
            leading = mData[i].all.find(',', lagging);
            mData[i].productName = mData[i].all.substr(lagging, leading); // load product name

            // advance until categories is accessible
            lagging = ++leading;
            leading = mData[i].all.find(',', lagging); // step to brand name
            lagging = ++leading;
            leading = mData[i].all.find(',', lagging); // step to Asin
            lagging = ++leading;
            leading = mData[i].all.find('\"', lagging); // step to front of categories field
            lagging = ++leading;
            leading = mData[i].all.find('\"', lagging); // step to end of categories field before assigning
            mData[i].categories = mData[i].all.substr(lagging, leading - lagging); // save values

            // parse string categories for insert into Categories class
            leading = 0;
            Category* cat = new Category(s);
            while(leading != std::string::npos) {
                lagging = leading; // -> copy each category until end of string
                leading = mData[i].categories.find('|', lagging);

                // copy and clean whitespace around string before insertion
                s = mData[i].categories.substr(lagging, leading++ - lagging);
                try {if(s.at(leading++) == ' ') {}} catch (std::out_of_range) {
                    leading = std::string::npos;
                }
                while(s.back() == ' ') { s.pop_back(); }

                // record category to save other products by category in the future
                if (!mCategories.mCheck->contains(s)) { // if already recorded, skip
                    mCategories.mCheck->insert(s, true);
                    mCategories.mListCategories->insertAtFront(*cat);
                }

                // search the list and insert product into correct category table
                mCategories.mListCategories->find(*cat)->insert(mData[i].id, mData[i].productName);
            }


            i += 1; // step i to next value

            /*
            std::getline(f, mData[i].upcCode, ','); // same here, call twice to skip
            std::getline(f, mData[i].upcCode, ','); // the extra comma
            std::getline(f, mData[i].listPrice, ',');
            std::getline(f, mData[i].sellingPrice, ',');
            std::getline(f, mData[i].quantity, ',');
            std::getline(f, mData[i].modelNum, ',');
            std::getline(f, mData[i].about, '"'); // dulpicate in order to
            std::getline(f, mData[i].about, '"'); // overwrite junk before "
            std::getline(f, mData[i].spec, ','); // same here, call twice to skip
            std::getline(f, mData[i].spec, ','); // the extra comma
            std::getline(f, mData[i].technicals, '"');
            std::getline(f, mData[i].technicals, '"');
            std::getline(f, mData[i].weight, ',');
            std::getline(f, mData[i].weight, ',');
            std::getline(f, mData[i].dimensions, ',');
            std::getline(f, mData[i].image, ',');
            std::getline(f, mData[i].variants, ',');
            std::getline(f, mData[i].sku, ',');
            std::getline(f, mData[i].url, ',');
            std::getline(f, mData[i].stock, ',');
            std::getline(f, mData[i].details, ',');
            std::getline(f, mData[i].dimensions2, ',');
            std::getline(f, mData[i].color, ',');
            std::getline(f, mData[i].ingrediants, ',');
            std::getline(f, mData[i].directions, ',');
            std::getline(f, mData[i].isSeller, ',');
            std::getline(f, mData[i].sizeQtyVariant, ',');
            std::getline(f, mData[i++].description, '\n'); // endl
            */
            

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