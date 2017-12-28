
#ifndef REVERSITESTS_JOINCOMMAND_H
#define REVERSITESTS_JOINCOMMAND_H
#define BLACK_TYPE 1
#define WHITE_TYPE 2

#include "Command.h"
#include <iostream>
class JoinCommand: public Command {
public:
    JoinCommand(int clientSocket);

    virtual int execute(vector<string> args,vector<Room> &rooms,pthread_mutex_t &count_mutex);

};


#endif //REVERSITESTS_JOINCOMMAND_H
