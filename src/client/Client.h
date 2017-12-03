//
// Created by ori on 03/12/17.
//

#ifndef REVERSITESTS_CLIENT_H
#define REVERSITESTS_CLIENT_H

class Client {
public:
    Client(const char *serverIP, int serverPort);
    void connectToServer();
    int sendExercise(int arg1, char op, int arg2);
private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
};

#endif //REVERSITESTS_CLIENT_H
