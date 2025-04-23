
#include <iostream>

#include "ma4.hpp"

int main(void) {

    // tests
    runTests();

    std::cout << " ** INSERTION SORT START ** " << std::endl;
    sortBenchmark(insertionSort);   // insertion sort testing
    std::cout << " ** INSERTION SORT END ** " << std::endl;

    std::cout << " ** QUICK SORT START ** " << std::endl;
    sortBenchmark(quickSort);       // quickSort...
    std::cout << " ** QUICK SORT END ** " << std::endl;

    std::cout << " ** SHELL SORT START ** " << std::endl;
    sortBenchmark(shellSort);       // shell sort...
    std::cout << " ** SHELL SORT END ** " << std::endl;

    std::cout << " ** HEAP SORT START ** " << std::endl;
    sortBenchmark(heapSort);        // and heap sort
    std::cout << " ** HEAP SORT END ** " << std::endl;


    return 0;
}