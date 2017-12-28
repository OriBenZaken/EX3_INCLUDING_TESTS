/**
 * command class.
 * operates a command
 */
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
    /**
     * constructor.
     * @param clientSocket - client socket to talk with
     */
    Command(int clientSocket):clientSocket(clientSocket) {}
    /**
    * execute function.
    * @param args - command splitted args.
    * @param rooms - rooms of game.
    * @param count_mutex - mutex to lock the rooms
    * @return integer.
    */
    virtual int execute(vector<string> args,vector<Room> &rooms,pthread_mutex_t &count_mutex)=0;
    /**
     * destructor.
     */
    virtual ~Command() {}
protected:
    //members
    int clientSocket;
};


#endif //REVERSITESTS_COMMAND_H

