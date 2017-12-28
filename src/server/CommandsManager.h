/**
 * CommandsManager class.
 * operates commands
 */

#ifndef REVERSITESTS_COMMANDSMANAGER_H
#define REVERSITESTS_COMMANDSMANAGER_H


#include <map>
#include <string>
#include <vector>
#include "Command.h"
#include "CloseCommand.h"
#include "JoinCommand.h"
#include "ListGamesCommand.h"
#include "PlayCommand.h"
#include "StartCommand.h"

using namespace std;
class CommandsManager {
public:
    /**
     * constructor.
     * @param clientSocket - client socket to talk with
     */
    CommandsManager(int clientSocket);
    /**
     * constructor.
     */
    CommandsManager();
    /**
     * destructor.
     */
    ~CommandsManager();
    /**
     * executeCommand function.
     * @param command - the command to execute
     * @param args - splitted command args
     * @param rooms - rooms of game
     * @param count_mutex - lock mutex
     * @return integer
     */
    int executeCommand(string command, vector<string> args, vector<Room> &rooms, pthread_mutex_t &count_mutex);

private:
    //members
    map<string, Command *> commandsMap;
    int clientSocket;
};


#endif //REVERSITESTS_COMMANDSMANAGER_H
