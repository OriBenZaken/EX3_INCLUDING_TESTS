//
// Created by ori on 03/12/17.
//

#include "Client.h"
#include "../Board.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
using namespace std;
Client::Client(const char *serverIP, int serverPort):
        serverIP(serverIP), serverPort(serverPort),
        clientSocket(0) {
    cout << "Client" << endl;
}
void Client::connectToServer() {
    // Create a socket point
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        throw "Error opening socket";
    }
    // Convert the ip string to a network address
    struct in_addr address;
    if (!inet_aton(serverIP, &address)) {
        throw "Can't parse IP address";
    }
    // Get a hostent structure for the given host address
    struct hostent *server;
    server = gethostbyaddr((const void *)&address, sizeof
            address, AF_INET);
    if (server == NULL) {
        throw "Host is unreachable";
    }
    // Create a structure for the server address
    struct sockaddr_in serverAddress;
    bzero((char *)&address, sizeof(address));
    serverAddress.sin_family = AF_INET;
    memcpy((char *)&serverAddress.sin_addr.s_addr, (char
    *)server->h_addr, server->h_length);
    // htons converts values between host and network byte orders
    serverAddress.sin_port = htons(serverPort);
    // Establish a connection with the TCP server
    if (connect(clientSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error connecting to server";
    }
    cout << "Connected to server" << endl;
}

int Client::getType() {
    // Read the result from the server
    int result;
    int n;
    Board::Cell type;
    n = read(clientSocket, &result, sizeof(result));
    if (n==-1) {
        throw "Error reading result from socket";
    }
    return result;
    /*else if (result==1) {
        type ==Board::Black;
    } else if (result==2) {
        type ==Board::White;
    } else if (result ==0) {

    }
    return type;*/

}



pair<int,int> Client:: getMoveFromServer() {
    int n;
    int x;
    int y;
    n = read(clientSocket, &x, sizeof(x));
    if (n == -1) {
        throw "Error reading x from socket";
    }
    n = read(clientSocket, &y, sizeof(y));
    if (n == -1) {
        throw "Error reading y from socket";
    }
    return make_pair(x,y);

}


void Client::sendMoveToServer(int x, int y) {
    int n = write(clientSocket, &x, sizeof(x));
    if (n == -1) {
        throw "Error writing x to socket";
    }
    n = write(clientSocket, &y, sizeof(y));
    if (n == -1) {
        throw "Error writing y to socket";
    }

}

int Client::sendExercise(int arg1, char op, int arg2) {
    // Write the exercise arguments to the socket
    int n = write(clientSocket, &arg1, sizeof(arg1));
    if (n == -1) {
        throw "Error writing arg1 to socket";
    }
    n = write(clientSocket, &op, sizeof(op));
    if (n == -1) {
        throw "Error writing op to socket";
    }
    n = write(clientSocket, &arg2, sizeof(arg2));
    if (n == -1) {
        throw "Error writing arg2 to socket";
    }
    // Read the result from the server
    int result;
    n = read(clientSocket, &result, sizeof(result));
    if (n == -1) {
        throw "Error reading result from socket";
    }
    return result;
}