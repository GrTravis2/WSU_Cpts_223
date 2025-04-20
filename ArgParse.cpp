#include "ArgParse.hpp"

// -> print options
void printHelp()
{
    std::cout << "Supported list of commands: " << std::endl;
    std::cout << " 1. find <inventoryid> - Finds if the inventory exists. If exists, prints details. If not, prints 'Inventory not found'." << std::endl;
    std::cout << " 2. listInventory <category_string> - Lists just the id and name of all inventory belonging to the specified category. If the category doesn't exists, prints 'Invalid Category'.\n"
         << std::endl;
}

// -> returns true if command is correct format
bool validCommand(std::string line)
{
    return (line == ":help") ||
           (line.rfind("find", 0) == 0) ||
           (line.rfind("listInventory") == 0);
}

// -> returns enum identifier for command
CMD evalCommand(std::string line)
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
            leading = line.find(' ', lagging);
            args[i] = line.substr(lagging, leading - lagging);
            if(leading != std::string::npos) { leading += 1; }
            lagging = leading;
        }
        // assign the command here
        if (args[2] == "" && args[3] == "") { // default case -> insertion + ascending
            cmd = LIST_INSERTION_ASCEND;
        } else if (args[2] == "desc") { // second case -> insertion + descending
            cmd = LIST_INSERTION_DESCEND;
        } else if (args[2] == "merge" && args[3] == "") { // 3rd case -> merge + ascending
            cmd = LIST_MERGE_ASCEND;
        } else if (args[2] == "merge" && args[3] == "desc") { // case 4 -> merge + descending
            cmd = LIST_MERGE_DESCEND;
        }
    }

    return cmd;
}

// -> returns string arg to be passed to function
std::string parseArg(std::string line) {
    // parse arg and pass to correct function
    // copy string after space, should grab everything after command type
    std::string arg = line.substr(line.find(' ') + 1);

    // delete everything after word, starting with first space
    int pos = arg.find(' ');
    if(pos != std::string::npos) {
        arg.erase(pos);
    }

    return arg;
}