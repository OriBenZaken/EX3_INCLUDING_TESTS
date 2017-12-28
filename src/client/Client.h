
#ifndef REVERSITESTS_CLIENT_H
#include <iostream>
#include "Board.h"
#include "Printer.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <vector>
#define MSG_BUFFER_SIZE 100
#define GAME_OVER -3
#define REVERSITESTS_CLIENT_H

using namespace std;

class Client {
public:
    /**
     * Client constructor.
     * @param serverIP - IP of server
     * @param serverPort - port of server
     */
    Client(const char *serverIP, int serverPort);
    /**
     * connectToServer function.
     * connects client to server
     */
    void connectToServer();
    /**
     * sendMoveToServer function.
     * @param x - x selected move of remote player
     * @param y - y selected move of remote player
     */
    pair<int,int> getMoveFromServer();
    /**
     * getType function.
     * @return integer
     */
    int getType();
    /**
     * sendStartNewGameRequest function.
     * @param name - game name
     * @return true if valid false otherwise
     */
    bool sendStartNewGameRequest(string name);
    /**
     * getGamesList function.
     * @return vector of rooms names
     */
    vector<string> getGamesList();
    /**
     * getGameListFromString function
     * @param buff - buffer of info from server
     * @return - vector of strings
     */
    static vector<string> getGameListFromString(char* buff);
    /**
     * sendJoinToGameRequest function
     * @param name - neme of new game
     * @return true if valid false otherwise
     */
    bool sendJoinToGameRequest(string name);
    /**
     * sendCloseGameRequest function.
     * @param name of game to be closed
     */
    void sendCloseGameRequest(string name);
    /**
     * sendPlayCommand function
     * @param x - x point
     * @param y - y point
     */
    void sendPlayCommand(int x, int y);
    /**
     * GetIntoGameRoom function
     * @param roomName - string room name
     * @param printer - printer obj
     */
    void GetIntoGameRoom(string &roomName, Printer* printer);
    /**
     * destructor
     */
    ~Client();
private:
    //members
    const char *serverIP;
    int serverPort;
    int clientSocket;
};

#endif //REVERSITESTS_CLIENT_H