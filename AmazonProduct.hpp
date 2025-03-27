#ifndef AMAZON_PRODUCT_H
#define AMAZON_PRODUCT_H

#include <string>
#include <iostream>

class AmazonProduct {

    public:
        std::string id, productName, categories, all;
        /* upcCode, listPrice, sellingPrice, quantity, modelNum, about,
        spec, technicals, weight, dimensions, image, variants, sku,
        url, stock, details, dimensions2, color, ingrediants, directions, isSeller,
        sizeQtyVariant, description; */

        // constructor
        AmazonProduct() {}; // set all to default and assign individually during parse

        friend std::ostream& operator<<(std::ostream& lhs, AmazonProduct& rhs) {
            lhs << rhs.all << std::endl;

            return lhs;
        }

};


#endif