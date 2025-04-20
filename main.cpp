#include <iostream>
#include <string>

#include "InventoryQueryTool.hpp"
#include "TestArgParse.hpp"
#include "TestSinglyLinkedList.hpp"
#include "TestHashMap.hpp"
#include "ArgParse.hpp"
#include "TestArgParse.hpp"


int main(int argc, char const *argv[])
{

    // testing entry points!
    TestSinglyLinkedList().runTests();
    TestHashMap().runTests();
    TestArgParse().runTests();

    InventoryQueryTool inventory;
    CMD cmd = NONE;

    std::cout <<
        "\n Welcome to Amazon Inventory Query System"
        << std::endl;
    std::cout <<
        " enter :quit to exit. or :help to list supported commands."
        << std::endl;
    std::cout << "\n> ";

    
    // REPL start
    std::string line, arg;
    while (getline(std::cin, line) && line != ":quit")
    {

        if (validCommand(line))
        {
            cmd = evalCommand(line);
        }
        else
        {
            cmd = NONE;
            std::cout << 
            "Command not supported. Enter :help for list of supported commands"
            << std::endl;
        }
        std::cout << "> ";

        std::string arg = parseArg(line);
        bool insertion = true;
        bool ascending = true;

        switch(cmd) {
            case NONE:
                break;
            case FIND:
                inventory.find(arg);
                break;
            case LIST_INSERTION_ASCEND:
                // default -> just break!
                break;
            case LIST_INSERTION_DESCEND:
                ascending = false; // just update ascending
                break;
            case LIST_MERGE_ASCEND:
                insertion = false; // just update insertion
                break;
            case LIST_MERGE_DESCEND:
                insertion = false; // update both!
                ascending = false;
                break;
            default:
                break;
        }

        inventory.printCategory(arg,insertion,ascending);
        std::cout << std::endl << "> ";

    }
    
    return 0;
}
