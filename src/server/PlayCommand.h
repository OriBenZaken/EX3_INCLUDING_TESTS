/**
 * PlayCommand class.
 * operates play command
 */
#ifndef REVERSITESTS_PLAYCOMMAND_H
#define REVERSITESTS_PLAYCOMMAND_H



#include "Command.h"
#include <iostream>
#include <unistd.h>

class PlayCommand: public Command {
public:
    /**
     * constructor.
     * @param clientSocket - client socket to talk with
     */
    PlayCommand(int clientSocket);
    /**
    * execute function.
    * @param args - command splitted args.
    * @param rooms - rooms of game.
    * @param count_mutex - mutex to lock the rooms
    * @return integer.
    */
    virtual int execute(vector<string> args,vector<Room> &rooms,pthread_mutex_t &count_mutex);

};


#endif //REVERSITESTS_PLAYCOMMAND_H

