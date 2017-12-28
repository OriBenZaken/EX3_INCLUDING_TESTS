/**
 * JoinCommand class.
 * operate join command
 */
#ifndef REVERSITESTS_JOINCOMMAND_H
#define REVERSITESTS_JOINCOMMAND_H
#define BLACK_TYPE 1
#define WHITE_TYPE 2

#include "Command.h"
#include <iostream>
#include <fstream>
#include <unistd.h>

class JoinCommand: public Command {
public:
    /**
     * constructor.
     * @param clientSocket - client socket to talk with
     */
    JoinCommand(int clientSocket);
    /**
    * execute function.
    * @param args - command splitted args.
    * @param rooms - rooms of game.
    * @param count_mutex - mutex to lock the rooms
    * @return integer.
    */
    virtual int execute(vector<string> args,vector<Room> &rooms,pthread_mutex_t &count_mutex);

};


#endif //REVERSITESTS_JOINCOMMAND_H

