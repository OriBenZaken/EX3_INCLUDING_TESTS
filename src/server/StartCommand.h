
/**
 * StartCommand class.
 * operates start command
 */
#ifndef REVERSITESTS_STARTCOMMAND_H
#define REVERSITESTS_STARTCOMMAND_H


#include "Command.h"
#include <iostream>
#include <unistd.h>

class StartCommand: public Command {
public:
    /**
     * constructor.
     * @param clientSocket - client socket to talk with
     */
    StartCommand(int clientSocket);
    /**
    * execute function.
    * @param args - command splitted args.
    * @param rooms - rooms of game.
    * @param count_mutex - mutex to lock the rooms
    * @return integer.
    */
    virtual int execute(vector<string> args,vector<Room> &rooms,pthread_mutex_t &count_mutex);

};


#endif //REVERSITESTS_STARTCOMMAND_H

