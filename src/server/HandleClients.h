/**
 * HandleClients class.
 * manager our threads
 */
#ifndef REVERSITESTS_SERVEROPERATIONS_H
#define REVERSITESTS_SERVEROPERATIONS_H

#include "Server.h"

class HandleClients {

public:
    /**
     * handleClient function.
     * @param arguments - ThreasArgs
     * @return void*
     */
    static void* handleClient(void* arguments);
    /**
     * swapClients function.
     * @param current - current clientSocket
     * @param opponent - second clientSocket
     */
    static void swapClients(int * current, int* opponent);
    /**
     * acceptClient function.
     * @param arguments - ThreasArgs
     * @return void*
     */
    static void* acceptClient(void* arguments);
    /**
     * preGameRequests function.
     * @param arguments - ThreasArgs
     * @return void*
     */
    static void * preGameRequests(void * arguments);
    /**
     * readCommandFromClient function.
     * @param arguments - ThreasArgs
     * @return void*
     */
    static string readCommandFromClient(int clientSocket);
    /**
     * splitCommand function.
     * @param command - command to be splitted
     * @return vector of the splited command
     */
    static vector<string> splitCommand(string command);
    /**
     * getClientSocket function
     * @param serverSocket - server socket int
     * @return
     */
    static int getClientSocket(int serverSocket);
};

#endif //REVERSITESTS_SERVEROPERATIONS_H
