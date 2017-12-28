/**
 * CloseCommand class.
 * operates close command.
 */
#ifndef REVERSITESTS_CLOSECOMMAND_H
#define REVERSITESTS_CLOSECOMMAND_H

#include <unistd.h>
#include "Command.h"
#include <iostream>
#define GAME_OVER -3
class CloseCommand: public Command {
public:
    /**
     * constructor.
     * @param clientSocket - client socket to talk with
     */
    CloseCommand(int clientSocket);

    /**
    * execute function.
    * @param args - command splitted args.
    * @param rooms - rooms of game.
    * @param count_mutex - mutex to lock the rooms
    * @return integer.
    */
    virtual int execute(vector<string> args, vector<Room> &rooms, pthread_mutex_t &count_mutex);
};


#endif //REVERSITESTS_CLOSECOMMAND_H

