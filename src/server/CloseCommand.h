
#ifndef REVERSITESTS_CLOSECOMMAND_H
#define REVERSITESTS_CLOSECOMMAND_H


#include "Command.h"
#include <iostream>
#define GAME_OVER -3
class CloseCommand: public Command {
public:
    CloseCommand(int clientSocket);

    virtual void execute(vector<string> args,vector<Room> &rooms);
};


#endif //REVERSITESTS_CLOSECOMMAND_H

