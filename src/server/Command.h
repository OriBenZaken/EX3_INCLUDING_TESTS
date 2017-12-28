
//
// Created by liz on 22/12/17.
//

#ifndef REVERSITESTS_COMMAND_H
#define REVERSITESTS_COMMAND_H

#include <vector>
#include <string>
#include "Room.h"
#define ERROR -1
#define VALID 1


using namespace std;

class Command {

public:
    Command(int clientSocket):clientSocket(clientSocket) {

    }
    virtual int execute(vector<string> args,vector<Room> &rooms,pthread_mutex_t &count_mutex)=0;
    virtual ~Command() {}
protected:
    int clientSocket;
};


#endif //REVERSITESTS_COMMAND_H

