/**
 * ListGamesCommand class.
 * operates a command
 */
#ifndef REVERSITESTS_LISTGAMESCOMMAND_H
#define REVERSITESTS_LISTGAMESCOMMAND_H


#include "Command.h"
#include <iostream>
#include <unistd.h>

class ListGamesCommand: public Command {
public:
    /**
     * constructor.
     * @param clientSocket - client socket to talk with
     */
    ListGamesCommand(int clientSocket);

    /**
    * execute function.
    * @param args - command splitted args.
    * @param rooms - rooms of game.
    * @param count_mutex - mutex to lock the rooms
    * @return integer.
    */
    virtual int execute(vector<string> args,vector<Room> &rooms,pthread_mutex_t &count_mutex);

};


#endif //REVERSITESTS_LISTGAMESCOMMAND_H

