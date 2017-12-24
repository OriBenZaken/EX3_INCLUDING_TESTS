
#ifndef REVERSITESTS_STARTCOMMAND_H
#define REVERSITESTS_STARTCOMMAND_H




#include "Command.h"
#include <iostream>
class StartCommand: public Command {
public:
    StartCommand(int clientSocket);

    virtual int execute(vector<string> args,vector<Room> &rooms);

};


#endif //REVERSITESTS_STARTCOMMAND_H

