#include "linux_cmds.hpp"

// constructor
linux_cmds::linux_cmds() : list() {
    this->mPlayers = new player[MAX_PLAYERS];
    this->numPlayers = 0;
}

// destructor
linux_cmds::~linux_cmds() {
    delete this->mPlayers; // on tha heap -> delete it
}

// app entry point
void linux_cmds::run() {
    this->printLogo();
    int choice = -1;

    while (choice != EXIT) {
        this->printMenu();
        std::cout << "Please insert option number: ";
        std::cin >> choice;

        switch (choice) {
            case GAME_RULES:
                this->printGameRules();
                break;
            case NEW_GAME:
                this->startNewGame();
                break;
            case LOAD_GAME:
                this->loadPlayerData();
                break;
            case ADD_CMD:
                this->addCommand();
                break;
            case REMOVE_CMD:
                this->removeCommand();
                break;
            case PRINT_CMDS:
                this->printCommands();
                break;
            case EXIT:
                this->saveData();
                break;
            default:
                std::cout << "invalid input " << choice << ", try again." << std::endl;
                break;
        }
    }
}

// helpers
void linux_cmds::printMenu() {
    std::cout <<
        "1. Display Game Rules" << std::endl <<
        "2. Start New Game" << std::endl <<
        "3. Load Previous Game" << std::endl << 
        "4. Add Command" << std::endl << 
        "5. Remove Command" << std::endl << 
        "6. Display All Commands" << std::endl <<
        "7. Save and Exit" << std::endl;

}

void linux_cmds::printGameRules() {
    std::cout
    << "Select the correct description that matches the displayed linux command!\n"
    << "The more questions you get correct, the higher your score." << std::endl;
}

void linux_cmds::printCommands() {
    std::cout << "Command, Description" << std::endl;
    this->print();
}

void linux_cmds::printLogo() {
    std::cout <<
    "ooooo       ooooo oooo   oooo ooooo  oooo ooooo  oooo\n"
    "888         888   8888o  88   888    88     888  88  \n"
    "888         888   88 888o88   888    88       888    \n"
    "888      o  888   88   8888   888    88      88 888  \n"
    "o888ooooo88 o888o o88o    88    888oo88    o88o  o888o\n\n"
                                                        
    "oooooooo8    oooo     oooo ooooooooo                  \n"
    "o888     88   8888o   888   888    88o                \n"
    "888           88 888o8 88   888    888                \n"
    "888o     oo   88  888  88   888    888                \n"
    "888oooo88    o88o  8  o88o o888ooo88                  \n\n"
                                                        
    "ooooooo8        o      oooo     oooo ooooooooooo     \n"
    "o888    88     888      8888o   888   888    88      \n"
    "888    oooo   8  88     88 888o8 88   888ooo8        \n"
    "888o    88   8oooo88    88  888  88   888    oo      \n"
    "888ooo888  o88o  o888o o88o  8  o88o o888ooo8888    \n";
}

void linux_cmds::startNewGame() {
    bool ok = false;
    std::string name;
    int numQuestions;
    player* newPlayer;

    while (!ok) {
        std::cout << "Starting new game... please enter player name: ";
        std::cin >> name;
        
        newPlayer = this->findPlayerData(name);
        }
        if (newPlayer != nullptr) {
            std::cout << "please enter number of questions to answer: " << std::endl;
            std::cin >> numQuestions;
            if (numQuestions > 0) { ok = true; }
        } else {
            std::cout << "Player name not found, try again." << std::endl;
    }

    this->nextQuestion(newPlayer, this->mpHead, numQuestions);
}

player* linux_cmds::findPlayerData(std::string findName) {
    player* found = nullptr;

    for (int i = 0; i < this->numPlayers; i++) {
        found = &(this->mPlayers[i]);
        if (found->name == findName) { break; }
    }

    if (findName != found->name) { found = nullptr; }

    return found;
}
void linux_cmds::nextQuestion(player* player, node<linux_cmd_data>* pNode, int questionsLeft) {
    if (pNode != nullptr && questionsLeft > 0) {// check if end of list is hit

        // set up vars
        int choice = -1;
        linux_cmd_data data = pNode->getData();

        // set up MC ans
        std::string ans[4] = {"", "", "", ""};
        std::string fake = "bazinga";
        srand(time(0));
        int correct = rand() % 4;
        ans[correct] = data.getDescription();
        for (int i = 0; i < 4; i++) {
            if(ans[i] == "") {
                // make sure fake ans are unique before assignment
                while (fake != ans[0] || fake != ans[1] || 
                       fake != ans[2] || fake != ans[3]) {
                    fake = wrongAns[rand() % MAX_WRONG_ANS];
                }
                ans[i] = fake;
            }
        }

        while (choice != correct && choice != QUIT) {
            std::cout 
            << "Use linux command " << data.getName() << " to:\n"
            << "1. " << ans[0] << std::endl
            << "2. " << ans[1] << std::endl
            << "3. " << ans[2] << std::endl
            << "4. " << ans[3] << std::endl
            << "5. Quit"       << std::endl
            << "Select correct description: ";
            std::cin >> choice;
        }
        
        if (choice != QUIT) {
            player->points += 1; // add a point 
            this->nextQuestion(player, pNode->getNextPtr(), questionsLeft - 1);
        }
    } else {
        std::cout << "End of game, exiting..." << std::endl;
    }
}

void linux_cmds::addCommand() {
    std::string newCmd;
    std::cout << "please input new command to add to the list: " << std::endl;
    std::cin >> newCmd;
}

void linux_cmds::removeCommand() {
    this->printCommands();
    std::cout << "please type command name to remove from list: " << std::endl;
    std::string choice;
    std::cin >> choice;

    std::cout << std::endl << "Removing " << choice << " from list.";

    if (this->deleteNode(linux_cmd_data(choice, ""))) {
        std::cout << choice << " has been removed from list." << std::endl;
    } else {
        std::cout << "Deletion unsuccessful. " << choice << " not found." << std::endl;
    }
}

void linux_cmds::saveData() {

}