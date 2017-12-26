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
    int executeCommand(string command, vector<string> args,vector<Room> &rooms);
    //todo: move to private again
    int clientSocket;
private:
    map<string, Command *> commandsMap;
};


#endif //REVERSITESTS_COMMANDSMANAGER_H
