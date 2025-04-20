#ifndef TEST_ARG_PARSE
#define TEST_ARG_PARSE

#include <assert.h>
#include <string>

#include "ArgParse.hpp"

// example strings used for testing

const std::string inorder_insertion = "listInventory Skateboarding";
const std::string reverse_order_insertion = "listInventory Skateboarding desc";
const std::string inorder_merge = "listInventory Skateboarding merge";
const std::string reverse_order_merge = "listInventory Skateboarding merge desc";

class TestArgParse {

    private:
        // tests to run
        TestArgParse& testEvalCommand();
        TestArgParse& testParseArg();

    public:
        void runTests();

};


#endif