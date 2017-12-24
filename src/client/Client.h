
#ifndef REVERSITESTS_CLIENT_H
#define REVERSITESTS_CLIENT_H
#include <iostream>
#include "Board.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <vector>
#define MSG_BUFFER_SIZE 50

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
    void sendMoveToServer(int x, int y);
    /**
     * getMoveFromServer function.
     * @return pair of opponent move
     */
    pair<int,int> getMoveFromServer();
    /**
     * getOtherPlayerGameStatusFromServer function.
     * @return game status after opponent move from server.
     */
    int getOtherPlayerGameStatusFromServer();
    /**
     * sendGameStatusToServer function.
     * @param gameStatus - send current game status from server.
     */
    void sendGameStatusToServer(int gameStatus);
    /**
     * getType function.
     * @return type of player
     */
    int getType();

    //
    bool sendStartNewGameRequest(string name);
    vector<string> getGamesList();
    vector<string> getGameListFromString(char* buff);
    bool sendJoinToGameRequest(string name);
    void sendCloseGameRequest(string name);
    void sendPlayCommand(int x, int y);
    void Foo(string &roomName);
    ~Client();
private:
    //members
    const char *serverIP;
    int serverPort;
    int clientSocket;
};

#endif //REVERSITESTS_CLIENT_H
