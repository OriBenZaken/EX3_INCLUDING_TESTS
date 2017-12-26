#include "CommandsManager.h"
#include "CloseCommand.h"
#include "JoinCommand.h"
#include "ListGamesCommand.h"
#include "PlayCommand.h"
#include "StartCommand.h"
CommandsManager::CommandsManager(int clientSocket): clientSocket(clientSocket) {
    //todo: pass client socket to commands
    commandsMap["start"] = new StartCommand(clientSocket);
    commandsMap["list_games"] = new ListGamesCommand(clientSocket);
    commandsMap["join"] = new JoinCommand(clientSocket);
    commandsMap["play"] = new PlayCommand(clientSocket);
    commandsMap["close"] = new CloseCommand((*this).clientSocket);

}
CommandsManager::CommandsManager(){}
int CommandsManager::executeCommand(string command, vector<string> args,vector<Room> &rooms) {
    static int i = 0;
    Command *commandObj = commandsMap[command];
    if (command == "play") {
        i++;
        cout << endl << i << endl;
        if (i == 3) {
            return 1;
        }
    }
    return commandObj->execute(args,rooms);
}

CommandsManager::~CommandsManager() {
    map<string, Command *>::iterator it;
   for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
        delete it ->second;
    }
}
