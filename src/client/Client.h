//
// Created by ori on 03/12/17.
//

#ifndef REVERSITESTS_CLIENT_H
#define REVERSITESTS_CLIENT_H
#include <iostream>

using namespace std;

class Client {
public:
    Client(const char *serverIP, int serverPort);
    void connectToServer();
    void sendMoveToServer(int x, int y);
    pair<int,int> getMoveFromServer();
    int getOtherPlayerGameStatusFromServer();
    void sendGameStatusToServer(int gameStatus);
    int getType();
private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
};

#endif //REVERSITESTS_CLIENT_H
