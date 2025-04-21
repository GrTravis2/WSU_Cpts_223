
#include "TestArgParse.hpp"
#include "ArgParse.hpp"
#include <cassert>



// tests to run
TestArgParse& TestArgParse::testEvalCommand() {

    // no spaces
    assert(evalCommand(inorder_insertion) == LIST_INSERTION_ASCEND);
    assert(evalCommand(reverse_order_insertion) == LIST_INSERTION_DESCEND);
    assert(evalCommand(inorder_merge) == LIST_MERGE_ASCEND);
    assert(evalCommand(reverse_order_merge) == LIST_MERGE_DESCEND);

    // spaces
    assert(evalCommand(inorder_insertion_spaces) == LIST_INSERTION_ASCEND);
    assert(evalCommand(reverse_order_insertion_spaces) == LIST_INSERTION_DESCEND);
    assert(evalCommand(inorder_merge_spaces) == LIST_MERGE_ASCEND);
    assert(evalCommand(reverse_order_merge_spaces) == LIST_MERGE_DESCEND);

    return *this;
}

TestArgParse& TestArgParse::testParseArg() {

    // standard input
    const std::string ans = "Skateboarding";
    
    assert(parseArg(inorder_insertion) == ans);
    assert(parseArg(reverse_order_insertion) == ans);
    assert(parseArg(inorder_merge) == ans);
    assert(parseArg(reverse_order_merge) == ans);

    // input that requires quotes around due to spaces
    const std::string ans_w_spaces = "Toys & Games";

    assert(parseArg(inorder_insertion_spaces) == ans_w_spaces);
    assert(parseArg(reverse_order_insertion_spaces) == ans_w_spaces);
    assert(parseArg(inorder_merge_spaces) == ans_w_spaces);
    assert(parseArg(reverse_order_merge_spaces) == ans_w_spaces);

    return *this;
}

// test entry point
void TestArgParse::runTests() {
    testEvalCommand().testParseArg();
}