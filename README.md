# CptS 223 PA4 - Amazon Inventory Query Tool
The Amazon inventory query tool needs to support two search operations with the requirements listed below. For this assignment data structure and class design is left up to the students to pick the right tool for the job. I will be documenting my thought process in selecting the correct design.

## Top level tool must support the following search operations:

- find "inventory id"
    - finds a product who's unique id matches the inventory id passed to find(). Find will print the details of the returned product if found, otherwise the tool will print "product not found."
- listInventory "category"
    - lists the unqiue id and product name of all products whose tagged categories contain a match with the category passed to listInventory(). If the given category does not match any category then the tool should print "invalid category"

## Design: First Impressions
- The Inventory query tool must be optimized for searching a fixed size/number of products! Given that the requirements to not call out inserting or deleting any products, this is a big hint that the data structure can be more optimized for searching. Since all possible products can be known ahead of time, and will not change - a hash table is a natural choice to solve this problem. Hash tables guarantee look up of a value given a key in O(1) time, in this case the key will be the unique id of the product and the value will be the data class containing product information. 
- In addition to a find operation based on product id, the tool must also support a way to find all products that contain a matching category property. This problem is challenging in that products may have a variable number of categories, including no category, and there are an unknown number of categories within the data set. Since we do not know the possible categories for each product ahead of time, I will use a dynamic data structure to store the possible categories. To help optimize searching products with matching categories I will also use the list to populate hash maps for each category so that the contents of the map can be output when each category is selected.
- In short I will need to implement a few data structures:
    - singly linked list supporting insertAtFront(), find(), print() functions this will hold categories
    - hash map supporting operator[] overload for find(), print()
        - due to risk of hash collisions I will also need to implement quadratic probing so that the map will not overwrite or lose data!
        - to maxmize code reusability I should also be able to reuse the hash map for several uses consisting of (product id key, */& data class) which can be used in the main product table as for finding, and for the category tables as a hash set - set invalid ptr to nullptr as not been inserted value :\)
        - note that since there will be several structures referencing existing data classes I think I will also need to hold the original data in a stand alone structure, likely an array since the data is of a fixed size

## Cleaning the Data Set
- Due to the number of fields in each entry and the inconsistency of characters used in each entry I elected to pre-process the data to simplify the program and it's output. There were a few common issues worth noting that influenced how I cleaned the data for the application:
    - Delimiters sometimes in the middle of data fields
        - while identifying ',' characters within a field is not too difficult, there are not many other consistent characters to split on. Double quotes (' " ' ) are sometimes available, but that is also inconsistent! To prevent the complexity from growing unneccessarily I removed commas from within the category field and wrapped the product name in quotations. This allows faster and simpler parsing code!
    - Excessively long strings leading to heap allocation failures
        - After parsing many fields from the data set I ran into intermittent issues with long strings, to help free up memory for the hash tables I have decided to remove data fields unneccessary to the program requirements. Simplifying the data will reduce memory usage, speed up program loading, and also simplify the data printed for the end user.


