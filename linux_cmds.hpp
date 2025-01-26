#include <string>

#include "list.hpp"
#include "linux_cmd_data.hpp"

struct player {
    std::string name;
    int points;
};

#define MAX_PLAYERS 25

class linux_cmds : public list<linux_cmd_data> {

    private:
        player* mPlayers; // arr of player structs
        int numPlayers;

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