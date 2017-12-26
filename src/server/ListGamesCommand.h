
#ifndef REVERSITESTS_LISTGAMESCOMMAND_H
#define REVERSITESTS_LISTGAMESCOMMAND_H


#include "Command.h"
#include <iostream>
class ListGamesCommand: public Command {
public:
    ListGamesCommand(int clientSocket);


    virtual int execute(vector<string> args,vector<Room> &rooms,pthread_mutex_t &count_mutex);

private:

};


#endif //REVERSITESTS_LISTGAMESCOMMAND_H

