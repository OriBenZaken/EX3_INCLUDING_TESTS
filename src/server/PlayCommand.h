
#ifndef REVERSITESTS_PLAYCOMMAND_H
#define REVERSITESTS_PLAYCOMMAND_H



#include "Command.h"
#include <iostream>
class PlayCommand: public Command {
public:
    PlayCommand(int clientSocket);

    virtual void execute(vector<string> args,vector<Room> &rooms);

};


#endif //REVERSITESTS_PLAYCOMMAND_H

