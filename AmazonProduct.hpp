#ifndef AMAZON_PRODUCT_H
#define AMAZON_PRODUCT_H

#include <string>

class AmazonProduct {

    public:
        std::string id, productName, brandName, Asin, categories,
        upcCode, listPrice, sellingPrice, quantity, modelNum, about,
        spec, technicals, weight, dimensions, image, variants, sku,
        url, stock, details, dimensions2, color, ingrediants, directions, isSeller,
        sizeQtyVariant, description;

        // constructor
        AmazonProduct() {}; // set all to default and assign individually during parse

};


#endif