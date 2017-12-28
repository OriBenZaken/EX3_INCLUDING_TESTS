
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

#define NO_MOVES -2
#define GAME_OVER -3

#define WAITING 0
#define KEEP_PLAYING -4
#define MSG_SIZE 100
#define ERROR -1
#define VALID 1

#define EXIT -1000
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

    vector<string> splitCommand(string command);

    void *preGameRequests(int clientsocket);


    typedef struct ThreadArgs {
        int clientSocket1;
        int clientSocket2;
        RoomsCollection* roomsCollection;
        Server *server;
    } ThreadArgs;


private:

    void *handleClient(int client1, int client2);

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
    void swapClients(int *current, int *opponent);

    void acceptClient();

    static string readCommandFromClient(int clientSocket);


    //members
    int port;
    int serverSocket; //the socket's file descriptor
    int numberOfConnectedClients;
   /* vector<Room> rooms;*/
    vector<pthread_t> threads;
    //index of thread
    int threadNum;
   /* pthread_mutex_t count_mutex;*/
public:
    int getPort() const;

    int getServerSocket() const;

    int getNumberOfConnectedClients() const;

   /* vector<Room> &getRooms();
*/
    vector<pthread_t> &getThreads();

    int getThreadNum() const;

   /* pthread_mutex_t &getCount_mutex();*/
};

#endif //SERVERREVERSI_SERVER_H
