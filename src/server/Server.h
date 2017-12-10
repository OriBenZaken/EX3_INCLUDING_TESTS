
#ifndef SERVERREVERSI_SERVER_H
#define SERVERREVERSI_SERVER_H
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <cstdlib>

#define NO_MOVES -2
#define GAME_OVER -3
#define BLACK_TYPE 1
#define WHITE_TYPE 2
#define WAITING 0
#define KEEP_PLAYING -4
using namespace std;

//server class. manage interaction between two players.
class Server {
public:
    /**
     * Server constructor.
     * @param port number
     */
    Server(int port);
    /**
     * start function.
     * starts the server.
     */
    void start();
    /**
     * stop function.
     * stops the server.
     */
    void stop();
    /**
     * getPortFromFile function.
     * @param serverSettingsFileName - file name.
     * @return int
     */
     static int getPortFromFile(string serverSettingsFileName);
        private:
    /**
     * handleClient function.
     * interacts run function of remoteGame
     * @param clientSocket1 - first client socket
     * @param clientSocket2 - second client socket
     */
    void handleClient(int clientSocket1, int clientSocket2);
   /**
    * getClientSocket function.
    * @return client socket number.
    */
    int getClientSocket();
    /**
     * swapClients function.
     * @param current - current client socket
     * @param opponent - opponent client socket
     */
    void swapClients(int * current, int* opponent);
    //members
    int port;
    int serverSocket; //the socket's file descriptor
    int numberOfConnectedClients;
};


#endif //SERVERREVERSI_SERVER_H
