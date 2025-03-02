#ifndef TREE_COMPARISON_H
#define TREE_COMPARISON_H

#include <map>
#include <string>
#include <forward_list>
#include <iostream>
#include <fstream>

#include "USCity.hpp"
#include "avl_map.hpp"

class tree_comparison {

    private:
    std::map<int, USCity> mStdMap; // STL map to compare against
    avl_map<int, USCity> mAvlMap; // my custom self balancing avl_map
    std::forward_list<int> mKeys; // list of keys to search during bench marking
    
    public:

    // constructor
    tree_comparison();

    //destructor
    ~tree_comparison();

    //public methods
    void runSimulation();

};


#endif