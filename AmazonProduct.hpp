#ifndef AMAZON_PRODUCT_H
#define AMAZON_PRODUCT_H

#include <string>
#include <iostream>

class AmazonProduct {

    private:
        std::string id;
        std::string all;
        std::string productName;
        std::string sellingPrice;
        std::string categories;

    public:
        

        // constructor
        AmazonProduct();

        // destructor
        ~AmazonProduct();

        // getters
        std::string getId();
        std::string getAll();
        std::string getProductName();
        std::string getSellingPrice();
        std::string getCategories();

        // setters
        AmazonProduct& setId(std::string newId);
        AmazonProduct& setAll(std::string line);
        AmazonProduct& setProductName(std::string newName);
        AmazonProduct& setSellingPrice(std::string newPrice);
        AmazonProduct& setCategories(std::string newCategories);

        // public methods

        friend std::ostream& operator<<(std::ostream& lhs, AmazonProduct& rhs);


        

};


#endif