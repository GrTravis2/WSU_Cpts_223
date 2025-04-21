
#include "AmazonProduct.hpp"

// constructor
AmazonProduct::AmazonProduct() {
    // allocate ahead of time to help with malloc load
    id.reserve(33);
    productName.reserve(150);
    categories.reserve(100);
    all.reserve(300);

    id = "id";
    all = "all";
    categories = "categories";
    productName = "product name";

};

// destructor
AmazonProduct::~AmazonProduct() {
    // nothing on the heap
}

// getters
std::string AmazonProduct::getId() { return id; }
std::string AmazonProduct::getAll() { return all; }
std::string AmazonProduct::getProductName() { return productName; }
std::string AmazonProduct::getSellingPrice() {return sellingPrice; }
std::string AmazonProduct::getCategories() { return categories; }

// setters
AmazonProduct& AmazonProduct::setId(std::string newId) {
    this->id = newId;

    return *this;
}

AmazonProduct& AmazonProduct::setAll(std::string line) {
    all = line;

    return *this;
}

AmazonProduct& AmazonProduct::setProductName(std::string newName) {
    productName = newName;

    return *this;
}

AmazonProduct& AmazonProduct::setSellingPrice(std::string newPrice) {
    sellingPrice = newPrice;

    return *this;
}

AmazonProduct& AmazonProduct::setCategories(std::string newCategories) {
    categories = newCategories;

    return *this;
}

// print all data to console for find operation
std::ostream& operator<<(std::ostream& lhs, AmazonProduct& rhs) {
    lhs << rhs.getAll() << std::endl;

    return lhs;
}