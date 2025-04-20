#ifndef ARG_PARSE
#define ARG_PARSE

#include <iostream>
#include <string>

typedef enum cmd {
    NONE,
    FIND,
    LIST_INSERTION_ASCEND,
    LIST_INSERTION_DESCEND,
    LIST_MERGE_ASCEND,
    LIST_MERGE_DESCEND,
}CMD;

// general functions for parsine cli string args

void printHelp(); // -> print options
bool validCommand(std::string line); // -> returns true if command is correct format
CMD evalCommand(std::string line); // -> returns enum identifier for command
std::string parseArg(std::string line); // -> returns string arg to be passed to function


#endif