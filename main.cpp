#include <iostream>
#include <string>

#include "InventoryQueryTool.hpp"
#include "TestSinglyLinkedList.hpp"
#include "TestHashMap.hpp"

using namespace std;

typedef enum cmd {
    NONE,
    FIND,
    LIST,
}CMD;

void printHelp()
{
    cout << "Supported list of commands: " << endl;
    cout << " 1. find <inventoryid> - Finds if the inventory exists. If exists, prints details. If not, prints 'Inventory not found'." << endl;
    cout << " 2. listInventory <category_string> - Lists just the id and name of all inventory belonging to the specified category. If the category doesn't exists, prints 'Invalid Category'.\n"
         << endl;
}

bool validCommand(string line)
{
    return (line == ":help") ||
           (line.rfind("find", 0) == 0) ||
           (line.rfind("listInventory") == 0);
}

CMD evalCommand(string line)
{
    CMD cmd = NONE;

    if (line == ":help")
    {
        printHelp();
    }
    // if line starts with find
    else if (line.rfind("find", 0) == 0)
    {
        cmd = FIND;
    }
    // if line starts with listInventory
    else if (line.rfind("listInventory") == 0)
    {
        cmd = LIST;
    }

    return cmd;
}

int main(int argc, char const *argv[])
{

    // testing entry points!
    //TestSinglyLinkedList().runTests();
    //TestHashMap().runTests();

    InventoryQueryTool inventory;
    CMD cmd = NONE;

    cout << "\n Welcome to Amazon Inventory Query System" << endl;
    cout << " enter :quit to exit. or :help to list supported commands." << endl;
    cout << "\n> ";

    
    string line, arg;
    while (getline(cin, line) && line != ":quit")
    {

        if (validCommand(line))
        {
            cmd = evalCommand(line);
        }
        else
        {
            cmd = NONE;
            cout << "Command not supported. Enter :help for list of supported commands" << endl;
        }
        cout << "> ";

        // parse arg and pass to correct function
        // copy string after space, should grab everything after command type
        arg = line.substr(line.find(' ') + 1);

        switch(cmd) {
            case NONE:
                break;
            case FIND:
                inventory.find(arg);
                break;
            case LIST:
                inventory.printCategory(arg);
                std::cout << std::endl << "> ";
                break;
            default:
                break;
        }
    }
    
    return 0;
}
