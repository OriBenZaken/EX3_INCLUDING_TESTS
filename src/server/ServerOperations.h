//
// Created by liz on 24/12/17.
//

#ifndef REVERSITESTS_SERVEROPERATIONS_H
#define REVERSITESTS_SERVEROPERATIONS_H


#include "Server.h"

class ServerOperations {
 //sdd member of server
    //sdd to server - getrs by ref!!!!! and setters
public:

    static void* handleClient(void* arguments) ;
    static void swapClients(int * current, int* opponent,
                             CommandsManager* commandsManagerCurrentClient, CommandsManager* commandsManagerOtherClient);
    static void* acceptClient(void* arguments);

    static void * preGameRequests(void * arguments);
    static string readCommandFromClient(int clientSocket);
    static vector<string> splitCommand(string command);
    static int getClientSocket(int serverSocket);



};


#endif //REVERSITESTS_SERVEROPERATIONS_H
