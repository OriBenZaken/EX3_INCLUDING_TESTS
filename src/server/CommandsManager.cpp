#include "CommandsManager.h"

CommandsManager::CommandsManager(int clientSocket): clientSocket(clientSocket) {
    //todo: pass client socket to commands
    commandsMap["start"] = new StartCommand(clientSocket);
    commandsMap["list_games"] = new ListGamesCommand(clientSocket);
    commandsMap["join"] = new JoinCommand(clientSocket);
    commandsMap["play"] = new PlayCommand(clientSocket);
    commandsMap["close"] = new CloseCommand((*this).clientSocket);

}
CommandsManager::CommandsManager(){}
int CommandsManager::executeCommand(string command, vector<string> args,vector<Room> &rooms,pthread_mutex_t &count_mutex) {
    Command *commandObj = commandsMap[command];
    return commandObj->execute(args,rooms, count_mutex);
}

CommandsManager::~CommandsManager() {
    map<string, Command *>::iterator it;
   for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
        delete it ->second;
    }
}
