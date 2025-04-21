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

const std::string inorder_insertion_spaces = "listInventory \"Toys & Games\"";
const std::string reverse_order_insertion_spaces = "listInventory \"Toys & Games\" desc";
const std::string inorder_merge_spaces = "listInventory \"Toys & Games\" merge";
const std::string reverse_order_merge_spaces = "listInventory \"Toys & Games\" merge desc";

class TestArgParse {

    private:
        // tests to run
        TestArgParse& testEvalCommand();
        TestArgParse& testParseArg();

    public:

        // test entry point
        void runTests();

};


#endif