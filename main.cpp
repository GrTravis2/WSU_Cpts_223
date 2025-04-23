
#include <iostream>

#include "ma4.hpp"

int main(void) {

    // tests
    runTests();

    // I think i'm seeing a cold start issue, first insertion sort always
    // way slow, adding another run in front. Measure off the 2nd one tho!
    sortBenchmark(insertionSort);
    std::cout << "** END OF WARM UP RUN **" << std::endl;

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