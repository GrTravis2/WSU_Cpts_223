

#include "tree_comparison.hpp"
#include "USCity.hpp"
#include <ctime>
#include <iomanip>
#include <ios>
#include <string>
#include <utility>

// constructor
tree_comparison::tree_comparison() {
    
    std::ifstream file; // open data file
    file.open("uszips.csv");

    if (file.is_open()) { // check file opened successfully

        int zipCode = -1; // set up buffer variables
        int i = 0;
        std::string fields[17];
        file.ignore(10000, '\n'); // ignore header line
        USCity* buffer = nullptr;
        std::srand(time(0));

        // read in one line at a time and create a new USCity obj
        // to load into map and avl_map
        while(file.peek() != EOF) {
            i = 0;
            std::getline(file, fields[0], ','); // read in zip and convert
            fields[0].erase(0, 1), fields[0].pop_back(); // make sure to trim \" char!
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
            std::getline(file, fields[i], '{');   // split on {}
            std::getline(file, fields[i++], '}'); // county_weights
            std::getline(file, fields[i], ',');   // jump to next ,
            std::getline(file, fields[i++], ','); // county_names_all
            std::getline(file, fields[i++], ','); // county_fips_all
            std::getline(file, fields[i++], ','); // imprecise
            std::getline(file, fields[i++], ','); // military
            std::getline(file, fields[i], '\n');  // timezone

             // insert pair into maps
            buffer = new USCity(
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
            
            mStdMap.insert(std::map<int, USCity>::value_type(zipCode, *buffer));
            mAvlMap.insert(zipCode, *buffer);

            // csv file has 33,784 entries, to get 1000 saved keys at random
            // save about 3% of rows until 1000 is hit, call it 4% to get 1000 for sure
            if (mKeys.size() < 1000 && (std::rand() % 100) < 4) {
                mKeys.push_back(zipCode); // save current zip as a key
            }

            delete buffer;
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

    clock_t start, end; // init variables for tracking performance
    double avlMapTime, stdMapTime, delta;
    double sum = 0;

    std::cout << std::scientific << std::setprecision(4);

    for (auto it = mKeys.begin(); it != mKeys.end(); it++) {

        // test stdMap first
        start = clock();
        mStdMap.find(*it);
        end = clock();
        stdMapTime = (double)(end - start)/CLOCKS_PER_SEC;

        // test avl_map
        start = clock();
        mAvlMap.find(*it);
        end = clock();
        avlMapTime = (double)(end - start)/CLOCKS_PER_SEC;

        delta = avlMapTime - stdMapTime;

        std::cout
        << "search time in seconds for key: " << *it 
        << ", std::map = " << stdMapTime
        << ", avl_map = " << avlMapTime 
        << ", delta = avl_map duration - std::map duration = " 
        << delta << '\n';

        sum += delta; // track sum of search differences to see which 
                      // collection is faster on average
    }

    std::cout
    << "across " << mKeys.size() 
    << " samples the average difference between avl_map and std::map was: "
    << sum / mKeys.size() << '\n';
}