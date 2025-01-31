#ifndef LINUX_CMDS_HPP
#define LINUX_CMDS_HPP

#include <string>
#include <iostream>
#include <fstream>

#include "list.hpp"
#include "linux_cmd_data.hpp"

struct player {
    std::string name;
    int points;
};

#define MAX_PLAYERS 25
#define MAX_WRONG_ANS 25

class linux_cmds : public list<linux_cmd_data> {

    private:
        player* mPlayers;      // arr of player structs
        player* currentPlayer; // player data for current user

        // helpers
        void printGameRules(); // quick game description
        void printCommands();  // print all commands and descriptions to stdout
        void printLogo();      // print ASCII art logo
        void printMenu();      // print main menu
        void startNewGame();   // start MC question loop
        void loadPlayerData(); // select player profile from saved data
        void addCommand();     // take user input for new command and description
        void removeCommand();  // take user input to remove a command from the list
        void saveData();       // Write command and player data to file

        void readFiles();      // load application data from file

        player* findPlayerData(std::string name); // search player arr for specific name
        void printPlayers(); // p

        // Recursive function to traverse list, answer questions, and update points
        void nextQuestion(node<linux_cmd_data>* pNode, int questionsLeft);

    public:

        // constructor
        linux_cmds();

        // destructor
        ~linux_cmds();

        // getters

        // setters

        // methods
        void run(); // application entry point

};
typedef enum menu {
    GAME_RULES = 1,
    NEW_GAME,
    LOAD_GAME,
    ADD_CMD,
    REMOVE_CMD,
    PRINT_CMDS,
    EXIT,
}MENU;

// Pool of wrong answers!
const std::string wrongAns[MAX_WRONG_ANS] = {
    "\"shutdown pc\"",
    "\"make a beeping noise\"",
    "\"turn off fan\"",
    "\"turn terminal pink\"",
    "\"rename file\"",
    "\"give up\"",
    "\"launch firefox\"",
    "\"enable turbo mode\"",
    "\"start hacking\"",
    "\"take a screenshot\"",// 10
    "\"logout\"",
    "\"corrupt file\"",
    "\"unzip a file\"",
    "\"get the answer wrong\"",
    "\"change admin password\"",
    "\"reboot pc\"",
    "\"change shell\"",
    "\"check available memory\"",
    "\"compress a file\"",
    "\"delete some RAM\"",// 20
    "\"launch minesweeper\"",
    "\"download python\"",
    "\"close all open applications\"",
    "\"open most recent file\"",
    "\"change wallpaper\""// 25
};

#endif