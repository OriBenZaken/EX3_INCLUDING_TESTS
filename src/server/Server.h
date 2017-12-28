
#ifndef SERVERREVERSI_SERVER_H
#define SERVERREVERSI_SERVER_H
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <cstdlib>
#include <vector>
#include "Room.h"
#include "pthread.h"
#include "CommandsManager.h"
#include "RoomsCollection.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Server.h"
#include "HandleClients.h"
#include <fstream>
#include <sstream>
#include <algorithm>

#define NO_MOVES -2
#define GAME_OVER -3
#define MSG_SIZE 100
#define ERROR -1
#define VALID 1
#define  MAX_CONNECTED_CLIENTS 2



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

    typedef struct ThreadArgs {
        int clientSocket1;
        int clientSocket2;
        RoomsCollection* roomsCollection;
        Server *server;
    } ThreadArgs;

    int getServerSocket() const;
    vector<pthread_t> &getThreads();

private:
    //members
    int port;
    int serverSocket; //the socket's file descriptor
    int numberOfConnectedClients;
    vector<pthread_t> threads;
    int threadNum;

};

#endif //SERVERREVERSI_SERVER_H
