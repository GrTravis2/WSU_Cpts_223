
#include "avl_test.hpp"
#include "tree_comparison.hpp"

int main(void) {

    avl_test().runTests();
    
    tree_comparison app;
    app.runSimulation();
    

    return 0;
}