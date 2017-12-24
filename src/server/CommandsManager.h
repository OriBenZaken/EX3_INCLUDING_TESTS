#ifndef REVERSITESTS_COMMANDSMANAGER_H
#define REVERSITESTS_COMMANDSMANAGER_H


#include <map>
#include <string>
#include <vector>
#include "Command.h"
using namespace std;
class CommandsManager
{
public:
    CommandsManager(int clientSocket);
    CommandsManager();
    ~CommandsManager();
    void executeCommand(string command, vector<string> args,vector<Room> &rooms);
private:
    map<string, Command *> commandsMap;
    int clientSocket;
};


#endif //REVERSITESTS_COMMANDSMANAGER_H
