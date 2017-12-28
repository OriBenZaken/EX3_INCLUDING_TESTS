//
// Created by liz on 24/12/17.
//

#ifndef REVERSITESTS_SERVEROPERATIONS_H
#define REVERSITESTS_SERVEROPERATIONS_H


#include "Server.h"

class HandleClients {

public:

    static void* handleClient(void* arguments) ;
    static void swapClients(int * current, int* opponent);
    static void* acceptClient(void* arguments);

    static void * preGameRequests(void * arguments);
    static string readCommandFromClient(int clientSocket);
    static vector<string> splitCommand(string command);
    static int getClientSocket(int serverSocket);



};

#endif //REVERSITESTS_SERVEROPERATIONS_H
