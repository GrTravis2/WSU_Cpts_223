

#include "InventoryQueryTool.hpp"
#include "AmazonProduct.hpp"
#include <fstream>
#include <string>

// constructor
InventoryQueryTool::InventoryQueryTool() : 
    mSearch(TABLE_SIZE * 2), mCategories() { // create 
    mData = new AmazonProduct[TABLE_SIZE];

    int i = 0; // init vars and file
    std::ifstream f;
    f.open(FILE);

    // dump header for overwrite later
    std::getline(f, mData[i].id, '\n'); 

    if (f.is_open()) {
        while (f.peek() != EOF) {

            // read into each field
            std::getline(f, mData[i].id, ',');
            std::getline(f, mData[i].productName, ',');
            std::getline(f, mData[i].brandName, ',');
            std::getline(f, mData[i].Asin, ',');
            std::getline(f, mData[i].categories, '"'); // dulpicate in order to
            std::getline(f, mData[i].categories, '"'); // overwrite junk before "
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
            std::getline(f, mData[i].technicals, ',');
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
            std::getline(f, mData[i].description, ',');
            
            
        }
    }

    f.close();
}

// destructor
InventoryQueryTool::~InventoryQueryTool() {

}

// getters

// setters

// public methods

// -> return ptr to data if found, else nullptr
AmazonProduct* InventoryQueryTool::find(const std::string& key) {

}

// -> print contents of specified category
void InventoryQueryTool::printCategory(const std::string& key_category) {

}