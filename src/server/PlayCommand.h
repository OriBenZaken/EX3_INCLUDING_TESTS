
#ifndef REVERSITESTS_PLAYCOMMAND_H
#define REVERSITESTS_PLAYCOMMAND_H



#include "Command.h"
#include <iostream>
class PlayCommand: public Command {
public:
    PlayCommand(int clientSocket);

    virtual int execute(vector<string> args,vector<Room> &rooms,pthread_mutex_t &count_mutex);

};


#endif //REVERSITESTS_PLAYCOMMAND_H

