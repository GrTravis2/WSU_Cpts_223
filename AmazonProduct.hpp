#ifndef AMAZON_PRODUCT_H
#define AMAZON_PRODUCT_H

#include <string>
#include <iostream>

class AmazonProduct {

    public:
        std::string id, productName, categories, all;

        // constructor
        AmazonProduct() {
            // allocate ahead of time to help with malloc load
            id.reserve(33);
            productName.reserve(150);
            categories.reserve(100);
            all.reserve(100);
        };

        // print all data to console for find operation
        friend std::ostream& operator<<(std::ostream& lhs, AmazonProduct& rhs) {
            lhs << rhs.all << std::endl;

            return lhs;
        }

};


#endif