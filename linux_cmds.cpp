#include "linux_cmds.hpp"

// constructor
linux_cmds::linux_cmds() : list() {
    this->mPlayers = new player[MAX_PLAYERS];
    for (int i=0; i < MAX_PLAYERS; i++) { this->mPlayers[i] = {"", -1}; }
    this->currentPlayer = nullptr;
}

// destructor
linux_cmds::~linux_cmds() {
    delete this->mPlayers; // on tha heap -> delete it
}

// app entry point
void linux_cmds::run() {
    this->readFiles();
    this->printLogo();
    int choice = -1;

    while (choice != EXIT) {
        this->printMenu();
        std::cout << std::endl << "Please insert option number: ";
        std::cin.clear();
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
    << "The more questions you get correct, the higher your score." << std::endl
    << std::endl;
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
    "888ooo888  o88o  o888o o88o  8  o88o o888ooo8888    \n\n";
}

void linux_cmds::startNewGame() {
    bool ok = false;
    std::string name = "";
    int numQuestions = 3;

    while (!ok) {
        this->printPlayers();
        std::cout << std::endl << "Starting new game... please enter player name: ";
        std::cin >> name;
        std::cout << std::endl;
        
        this->currentPlayer = this->findPlayerData(name);
        if (this->currentPlayer != nullptr) {
            std::cout << "please enter number of questions to answer: " << std::endl;
            std::cin >> numQuestions;
            if (numQuestions > 0) { ok = true; }
        } else {
            std::cout << "Player name not found, try again." << std::endl;
        }
    }

    this->nextQuestion(this->mpHead, numQuestions);
}

void linux_cmds::loadPlayerData() {
    std::string s;
    this->printPlayers();
    std::cout
    << "enter player name from list to load player data: ";
    std::cin >> s;

    player* found = this->findPlayerData(s);
    if (found != nullptr) {
        std::cout << "loading data for " << found->name <<
        " and they current have " << found->points << "cumulative points"
        << std::endl;
    } else {
        std::cout << "The name " << s << " not found in list. Try again." << std::endl;
    }
}

void linux_cmds::printPlayers() {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (this->mPlayers[i].name != "") {
            std::cout << this->mPlayers[i].name << std::endl;
        }
    }
}

void linux_cmds::readFiles() {
    std::ifstream f;
    std::string s = "";
    player buffer = {"", 0};
    int i = 0;

    f.open("players.csv");
    while(f.peek() != EOF && i < MAX_PLAYERS) {
        std::getline(f, buffer.name, ','); // read in player name
        std::getline(f, s, '\n'); // read in points
        buffer.points = stoi(s);

        this->mPlayers[i++] = buffer;
    }
    f.close();

    linux_cmd_data cmd;

    f.open("commands.csv");
    while(f.peek() != EOF) {
        std::getline(f, s, ',');// cmd name
        cmd.setName(s);
        std::getline(f, s, ',');// cmd description
        cmd.setDescription(s);
        std::getline(f, s, '\n');// cmd point value
        cmd.setPoints(stoi(s));

        this->insertAtFront(cmd);
    }
    f.close();
}

player* linux_cmds::findPlayerData(std::string findName) {
    player* found = nullptr;

    for (int i = 0; i < MAX_PLAYERS; i++) {
        found = &(this->mPlayers[i]);
        if (found->name == findName) { break; }
    }

    if (findName != found->name) { found = nullptr; }

    return found;
}
void linux_cmds::nextQuestion(node<linux_cmd_data>* pNode, int questionsLeft) {
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
                fake = wrongAns[rand() % MAX_WRONG_ANS];
                while (fake == ans[0] || fake == ans[1] || 
                       fake == ans[2] || fake == ans[3]) {
                    fake = wrongAns[rand() % MAX_WRONG_ANS];
                }
                ans[i] = fake;
            }
        }

        while (choice != correct + 1 && choice != QUIT) {
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
            this->currentPlayer->points += 1; // add a point 
            this->nextQuestion(pNode->getNextPtr(), questionsLeft - 1);
        }
    } else {
        std::cout << "End of game, exiting..." << std::endl;
    }
}

void linux_cmds::addCommand() {
    std::string input;
    std::cout << "please input new command to add to the list: " << std::endl;
    std::cin >> input;

    linux_cmd_data cmd(input, "", 1);
    if (this->findNode(cmd) == nullptr) {// check if cmd exists

        std::cout << "please input what the command does: " << std::endl;
        std::cin >> input;
        cmd.setDescription(input);

        this->insertAtFront(cmd);
    } else {
        std::cout << "entered command already exists, please try again." << std::endl;
    }
}

void linux_cmds::removeCommand() {
    this->printCommands();
    std::cout << "please type command name to remove from list: " << std::endl;
    std::string choice;
    std::cin >> choice;

    std::cout << std::endl << "Removing " << choice << " from list.";

    if (this->deleteNode(linux_cmd_data(choice, "", 0))) {
        std::cout << choice << " has been removed from list." << std::endl;
    } else {
        std::cout << "Deletion unsuccessful. " << choice << " not found." << std::endl;
    }
}

void linux_cmds::saveData() {
    std::ofstream f;
    f.open("players.csv");

    for (int i = 0; i < MAX_PLAYERS; i++) {
        f << this->mPlayers[i].name + "," + std::to_string(this->mPlayers[i].points) << std::endl;
    }
    f.close();
}

void linux_cmds::test() {
    //pass
}