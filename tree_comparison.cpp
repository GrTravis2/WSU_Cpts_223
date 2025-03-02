

#include "tree_comparison.hpp"

// constructor
tree_comparison::tree_comparison() {
    
    std::ifstream file; // open data file
    file.open("uszips.csv");

    if (file.is_open()) { // check file opened successfully

        int zipCode = -1; // set up buffer variables
        int i = 0;
        std::string fields[17];
        file.ignore(10000, '\n'); // ignore header line
        //USCity* buffer = nullptr;

        // read in one line at a time and create a new USCity obj
        // to load into map and avl_map
        while(file.peek() != EOF) { 
            std::getline(file, fields[0], ','); // read in zip and convert
            zipCode = std::stoi(fields[0]);

            // read in string fields
            std::getline(file, fields[i++], ','); // lat
            std::getline(file, fields[i++], ','); // lat
            std::getline(file, fields[i++], ','); // city
            std::getline(file, fields[i++], ','); // state_id
            std::getline(file, fields[i++], ','); // state_name
            std::getline(file, fields[i++], ','); // zcta
            std::getline(file, fields[i++], ','); // parent_zcta
            std::getline(file, fields[i++], ','); // population
            std::getline(file, fields[i++], ','); // density
            std::getline(file, fields[i++], ','); // county_fips
            std::getline(file, fields[i++], ','); // county_name
            std::getline(file, fields[i++], ','); // county_weights
            std::getline(file, fields[i++], ','); // county_names_all
            std::getline(file, fields[i++], ','); // county_fips_all
            std::getline(file, fields[i++], ','); // imprecise
            std::getline(file, fields[i++], ','); // military
            std::getline(file, fields[i], '\n');  // timezone

             // insert pair into maps
            mStdMap[zipCode] = USCity(
                fields[LAT],
                fields[LNG],
                fields[CITYNAME],
                fields[STATEID],
                fields[STATENAME],
                fields[ZCTA],
                fields[PARENTZCTA],
                fields[POP],
                fields[DENSITY],
                fields[COUNTYFIPS],
                fields[COUNTYNAME],
                fields[COUNTYWEIGHTS],
                fields[COUNTYNAMESALL],
                fields[COUNTYFIPSALL],
                fields[IMPRECISE],
                fields[MILITARY],
                fields[TIMEZONE]
            );
            mAvlMap.insert(zipCode, USCity(
                fields[LAT],
                fields[LNG],
                fields[CITYNAME],
                fields[STATEID],
                fields[STATENAME],
                fields[ZCTA],
                fields[PARENTZCTA],
                fields[POP],
                fields[DENSITY],
                fields[COUNTYFIPS],
                fields[COUNTYNAME],
                fields[COUNTYWEIGHTS],
                fields[COUNTYNAMESALL],
                fields[COUNTYFIPSALL],
                fields[IMPRECISE],
                fields[MILITARY],
                fields[TIMEZONE]
            ));

            mKeys.push_front(zipCode); // save current zip as a key
        }
    }

    file.close(); // close file stream!
}

//destructor
tree_comparison::~tree_comparison() {
    // nothing on the heap!
}

//public methods
void tree_comparison::runSimulation() {

}