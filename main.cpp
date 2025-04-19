#include <iostream>
#include <string>

#include "InventoryQueryTool.hpp"
#include "TestSinglyLinkedList.hpp"
#include "TestHashMap.hpp"

using namespace std;

typedef enum cmd {
    NONE,
    FIND,
    LIST_INSERTION_ASCEND,
    LIST_INSERTION_DESCEND,
    LIST_MERGE_ASCEND,
    LIST_MERGE_DESCEND,
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
        // array to hold args with
        // [0] = listInventory, [1] = category, [2] = "" | desc | merge, [3] = desc | ""
        std::string args[4] = {"", "", "", ""};
        int leading, lagging;
        leading = lagging = 0;
        for(int i = 0; i < 4 && lagging != std::string::npos; i++) {
            // copy str between spaces and load into array
            // exit when lagging index hits end of string
            leading = line.find(' '); 
            args[i] = line.substr(lagging, leading - leading);
            leading += 1;
            lagging = leading;
        }
        // assign the command here
        if (args[2] == "" && args[3] == "") { // default case -> insertion + ascending
            cmd = LIST_INSERTION_ASCEND;
        } else if (args[2] == "desc") { // second case -> insertion + descending
            cmd = LIST_INSERTION_DESCEND;
        } else if (args[2] == "merge") { // 3rd case -> merge + ascending
            cmd = LIST_MERGE_ASCEND;
        } else if (args[2] == "merge" && args[3] == "desc") { // case 4 -> merge + descending
            cmd = LIST_MERGE_DESCEND;
        }
    }

    return cmd;
}

int main(int argc, char const *argv[])
{

    // testing entry points!
    TestSinglyLinkedList().runTests();
    TestHashMap().runTests();

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
            cout << 
            "Command not supported. Enter :help for list of supported commands"
            << endl;
        }
        cout << "> ";

        // parse arg and pass to correct function
        // copy string after space, should grab everything after command type
        arg = line.substr(line.find(' ') + 1);

         // delete everything after word, starting with first space
        arg.erase(arg.find(' '));
        bool isInsertionSort = true;
        bool isAscending = true;

        switch(cmd) {
            case NONE:
                break;
            case FIND:
                inventory.find(arg);
                break;
            case LIST_INSERTION_ASCEND:
                inventory.printCategory(
                    arg,
                    isInsertionSort,
                    isAscending);
                std::cout << std::endl << "> ";
                break;
            case LIST_INSERTION_DESCEND:
                isAscending = false;
                inventory.printCategory(
                    arg,
                    isInsertionSort,
                    isAscending);
                std::cout << std::endl << "> ";
                break;
            case LIST_MERGE_ASCEND:
                isInsertionSort = false;
                inventory.printCategory(
                    arg,
                    isInsertionSort,
                    isAscending);
                std::cout << std::endl << "> ";
                break;
            case LIST_MERGE_DESCEND:
                isInsertionSort = false;
                isAscending = false;
                inventory.printCategory(
                    arg,
                    isInsertionSort,
                    isAscending);
                std::cout << std::endl << "> ";
                break;
            default:
                break;
        }
    }
    
    return 0;
}
