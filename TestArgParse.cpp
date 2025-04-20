
#include "TestArgParse.hpp"
#include "ArgParse.hpp"
#include <cassert>



// tests to run
TestArgParse& TestArgParse::testEvalCommand() {

    assert(evalCommand(inorder_insertion) == LIST_INSERTION_ASCEND);
    assert(evalCommand(reverse_order_insertion) == LIST_INSERTION_DESCEND);
    assert(evalCommand(inorder_merge) == LIST_MERGE_ASCEND);
    assert(evalCommand(reverse_order_merge) == LIST_MERGE_DESCEND);

    return *this;
}

TestArgParse& TestArgParse::testParseArg() {

    const std::string ans = "Skateboarding";
    assert(parseArg(inorder_insertion) == ans);
    assert(parseArg(reverse_order_insertion) == ans);
    assert(parseArg(inorder_merge) == ans);
    assert(parseArg(reverse_order_merge) == ans);

    return *this;
}

// test entry point
void TestArgParse::runTests() {
    testEvalCommand().testParseArg();
}