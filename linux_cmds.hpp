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
        player* mPlayers; // arr of player structs

        // helpers
        void printGameRules();
        void printCommands();
        void printLogo();
        void printMenu();
        void startNewGame();
        void loadPlayerData();
        void addCommand();
        void removeCommand();
        void saveData();

        void readFiles();

        std::string getOptions(std::string rightAns);
        player* findPlayerData(std::string name);
        void nextQuestion(player* player, node<linux_cmd_data>* pNode, int questionsLeft);

    public:

        // constructor
        linux_cmds();

        // destructor
        ~linux_cmds();

        // getters

        // setters

        // methods
        void run();

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

const std::string wrongAns[MAX_WRONG_ANS] = {
    "shutdown pc",
    "makes a beeping noise",
    "turn off fan",
    "turns terminal pink",
    "rename file",
    "give up",
    "launch firefox",
    "enable turbo mode",
    "start hacking",
    "take a screenshot",// 10
    "logout",
    "corrupt file",
    "unzip a file",
    "get the answer wrong",
    "change admin password",
    "reboot pc",
    "change shell",
    "check available memory",
    "compress a file",
    "delete some RAM",// 20
    "launch minesweeper",
    "download python",
    "close all open applications",
    "open most recent file",
    "change wallpaper"// 25
};

#endif